<?php

/**
 * Implements hook_drush_command().
 */
function kms_oci_queue_drush_command() {
  $items = array();
  $items['consistency-check'] = array(
    'callback' => 'kms_oci_queue_consistency_check',
    'description' => dt('Run consistency check between postgres and oracle'),
    'arguments' => array(
      "data_type" => "Type of data (i.e.: 'services')",
      "method" => "Method of checking (i.e.: 'diff')",
    ),
    'options' => array(
      'mode' => 'Extra option to the called method. Currently supported by the diff method.',
    ),
    'required-arguments' => TRUE,
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_DATABASE,
  );
  $items['consistency-generate-resolving-sql'] = array(
    'callback' => 'kms_oci_queue_consistency_generate_resolving_sql',
    'description' => dt('Generate sql needed to solve inconsistency.'),
    'arguments' => array(
      "data_type" => "Type of data (i.e.: 'services')",
      "db_target" => "oracle or postgres",
    ),
    'required-arguments' => TRUE,
  );
  return $items;
}

/**
 * Implements hook_drush_help().
 */
function kms_oci_queue_drush_help($section) {
  switch ($section) {
    case 'drush:consistency-check':
      return dt("Run consistency check between postgres and oracle. Specify data type and method [data_type] [method].");

  }
}

/**
 * Executes a data consistency check between postgres and oracle.
 *
 * Supports different "data types" and methods (diff etc.).
 *
 * @param string $data_type
 * @param string $method
 * @throws Exception
 */
function kms_oci_queue_consistency_check($data_type, $method) {
  module_load_include('inc', 'kms_oci_queue', 'includes/kms_oci_queue.consistency');
  $class_name_prefix = 'cData' . ucfirst($data_type);
  $class_name_postgres = $class_name_prefix . 'Postgres';
  $class_name_oracle = $class_name_prefix . 'Oracle';
  // Check if classes are defined.
  if (
    !class_exists($class_name_postgres)
    && !class_exists($class_name_oracle)
  ) {
    return;
  }

  $dir_name = cHelper::dirConsistencyDiff;
  $mkdir = FALSE;
  $del_files = file_unmanaged_delete_recursive($dir_name);
  if ($del_files) {
    $mkdir = file_prepare_directory($dir_name, FILE_CREATE_DIRECTORY);
  }
  if (!$del_files || !$mkdir) {
    return;
  }

  $i = $user_count = 0;
  $chunks = cHelper::getUidChunks();
  drush_print(
    dt('Working on: !dir_name.', array('!dir_name' => $dir_name))
  );
  drush_print(
    dt('Chunk count: !chunk_count.', array('!chunk_count' => count($chunks)))
  );
  drush_print(
    dt('Chunk size: !chunk_size.', array('!chunk_size' => cHelper::uidChunkSize))
  );
  foreach ($chunks as $uids) {
    $postgres = new $class_name_postgres($uids);
    $oracle = new $class_name_oracle($uids);
    $data_check = new cDataCheck($postgres, $oracle);
    if (method_exists($data_check, $method)) {
      if ($method == 'diff' && $mode = drush_get_option('mode')) {
        $mode_map = array(
          'postgres' => 'a',
          'oracle' => 'b',
        );
        if (empty($mode_map[$mode])) {
          throw new Exception('Mode type does not exist.');
        }
        else {
          $result = $data_check->diff($mode_map[$mode]);
        }
      }
      else {
        $result = $data_check->diff();
      }

      $xml = new SimpleXMLElement('<?xml version="1.0" encoding="utf-8"?><user_diffs></user_diffs>');
      foreach ($result as $uid => $diffs) {
        $user = $xml->addChild('user');
        $user->addChild('id', $uid);
        foreach ($diffs as $diff_key => $ids) {
          $diff_key = str_replace(':', '-', $diff_key);
          $diff_ids = $user->addChild($diff_key);
          foreach ($ids as $id) {
            $diff_ids->addChild('id', $id);
          }
        }
      }
      $file = fopen(sprintf('%s/diff%s.xml', $dir_name, $i ? "_$i" : ''), "w");
      fwrite($file, $xml->asXML());
      fclose($file);
      $i++;
      $user_count += count($uids);
      drush_print(
        dt('!user_count users processed...', array('!user_count' => $user_count))
      );
    }
  }

  drush_print(dt('Done.'));
}

/**
 * Generates sql file that cleans up target database.
 *
 * @param string $data_type
 * @param string $target_db
 */
function kms_oci_queue_consistency_generate_resolving_sql($data_type, $target_db) {
  module_load_include('inc', 'kms_oci_queue', 'includes/kms_oci_queue.consistency');

  $protected_oracle_users = array(
    'AE6475A9DCDD5CC5E04400144FAD6027',
    '33191',
  );

  $wms_ids = kms_permissions_get_service_ids_by_type('wms');

  $sql_file = sprintf(
    '%s/kms_oci_queue_consistency_resolve_%s.sql',
    cHelper::dirConsistencyDiff,
    $target_db
  );
  if (file_exists($sql_file)) {
    unlink($sql_file);
  }

  switch ($target_db) {
    case 'oracle':
      switch ($data_type) {
        case 'services':
          $files = file_scan_directory(cHelper::dirConsistencyDiff, '/.*\.xml$/');
          if (empty($files)) {
            drush_print(dt('No diff files found.'));
            return;
          }
          ksort($files);
          $i = 0;
          foreach ($files as $file) {
            drush_print(
              dt('Processing file: !filename.', array('!filename' => $file->filename))
            );
            $xml = simplexml_load_file($file->uri);
            foreach ($xml->user as $user) {
              $userid = (string) $user->id;
              $output = array();
              $sids_postgres = array_unique((array) $user->{'diff-Services-Postgres'});
              $sids_postgres = !empty($sids_postgres['id']) ? $sids_postgres['id'] : array();

              if (!is_array($sids_postgres)) {
                $sids_postgres = array($sids_postgres);
              }
              foreach ($sids_postgres as $sid) {
                $service_data = array(
                  'userid' => $userid,
                  'serviceid' => $sid,
                  'featureinfo' => 0,
                );

                $service_data += kms_permissions_get_service_bounding_box($sid);
                // If a service is a wms service then set feature info to 1.
                if (in_array($sid, $wms_ids)) {
                  $service_data['featureinfo'] = 1;
                }
                $sql = new KmsOciQueueSql('services', $service_data);
                $output[] = $sql->generate('insert');
              }

              if (!in_array($userid, $protected_oracle_users)) {
                $sids_oracle = array_unique((array) $user->{'diff-Services-Oracle'});
                $sids_oracle = !empty($sids_oracle['id']) ? $sids_oracle['id'] : array();
                if (!is_array($sids_oracle)) {
                  $sids_oracle = array($sids_oracle);
                }
                foreach ($sids_oracle as $sid) {
                  $service_data = array(
                    'userid' => $userid,
                    'serviceid' => $sid,
                  );
                  $sql = new KmsOciQueueSql('services', $service_data);
                  $output[] = $sql->generate('delete');
                }
              }

              if (!empty($output)) {
                array_unshift($output, $sql->generateWrapper('header'));
                $output[] = $sql->generateWrapper('footer');
                file_put_contents($sql_file, implode("\n", $output), FILE_APPEND);
              }
              $i++;
              drush_print(format_plural($i, '1 user', '@count users') . dt(' processed.'));
            }
          }
          break;
      }
      break;

    case 'postgres':
      switch ($data_type) {
        case 'services':
          break;
      }
      break;
  }

  drush_print(dt('Done.'));
}
