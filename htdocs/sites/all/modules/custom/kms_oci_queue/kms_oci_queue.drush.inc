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
      'format' => 'Output formats: json, var_export',
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
      break;
  }
}

/**
 * Executes a data consistency check between postgres and oracle.
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
  ){
    return;
  }
  $postgres = new $class_name_postgres();
  $oracle = new $class_name_oracle();
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
        $result = $data_check->$method($mode_map[$mode]);
      }
    }
    else {
      $result = $data_check->$method();
    }

    if (is_array($result)) {
      $format = drush_get_option('format');
      switch ($format) {
        case 'var_export':
          echo "<?php\n";
          echo '$diff = ';
          var_export($result);
          echo ';';
          break;
        case 'json':
        default:
          echo kms_oci_queue_json_pretty_cli_format(json_encode($result));
          break;
      }
    }
    else {
      echo "$result\n";
    }

  }
}

function kms_oci_queue_consistency_generate_resolving_sql($data_type, $target_db) {
  include '/tmp/diff.inc';

  $protected_oracle_users = array(
    'AE6475A9DCDD5CC5E04400144FAD6027',
    '33191',
  );

  $wms_ids = kms_permissions_get_service_ids_by_type('wms');

  $sql_file = sprintf('temporary://kms_oci_queue_consistency_resolve_%s.sql', $target_db);
  if (file_exists($sql_file)) {
    unlink($sql_file);
  }
  $user_count = count($diff);

  switch($target_db) {
    case 'oracle':
      switch($data_type) {
        case 'services':
          $i = 0;
          foreach($diff as $userid => $data) {
            $i++;
            drush_print(dt(
              'Processing !i out of !total.',
              array('!i' => $i, '!total' => $user_count)
            ));
            $output = array();
            $services_postgres = array_unique($data['diff:Services:Postgres']);
            foreach($services_postgres as $sid) {
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

            if (in_array($userid, $protected_oracle_users)) {
              continue;
            }

            $services_oracle = array_unique($data['diff:Services:Oracle']);
            foreach($services_oracle as $sid) {
              $service_data = array(
                'userid' => $userid,
                'serviceid' => $sid,
              );
              $sql = new KmsOciQueueSql('services', $service_data);
              $output[] = $sql->generate('delete');
            }

            if(!empty($output)) {
              array_unshift($output, $sql->generateHeader());
              file_put_contents($sql_file, implode("\n", $output), FILE_APPEND);
            }

          }
          break;
      }
      break;

    case 'postgres':
      switch($data_type) {
        case 'services':
          break;
      }
      break;
  }

  drush_print(dt('Done.'));
}

/**
 * @param string $json
 * @return bool|string
 */
function kms_oci_queue_json_pretty_cli_format($json) {
  $tab = "  ";
  $new_json = "";
  $indent_level = 0;
  $in_string = FALSE;

  $len = strlen($json);

  for ($c = 0; $c < $len; $c++) {
    $char = $json[$c];
    switch ($char) {
      case '{':
      case '[':
        if (!$in_string) {
          $new_json .= $char . "\n" . str_repeat($tab, $indent_level + 1);
          $indent_level++;
        }
        else {
          $new_json .= $char;
        }
        break;
      case '}':
      case ']':
        if (!$in_string) {
          $indent_level--;
          $new_json .= "\n" . str_repeat($tab, $indent_level) . $char;
        }
        else {
          $new_json .= $char;
        }
        break;
      case ',':
        if (!$in_string) {
          $new_json .= ",\n" . str_repeat($tab, $indent_level);
        }
        else {
          $new_json .= $char;
        }
        break;
      case ':':
        if (!$in_string) {
          $new_json .= ": ";
        }
        else {
          $new_json .= $char;
        }
        break;
      case '"':
        if ($c > 0 && $json[$c - 1] != '\\') {
          $in_string = !$in_string;
        }
      default:
        $new_json .= $char;
        break;
    }
  }

  return $new_json;
}