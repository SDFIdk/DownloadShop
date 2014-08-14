<?php
/**
 * @file
 * kms_permissions_clone_user_perms.inc
 *
 * Provides callback functions run by the queue handling functions.
 * Creates oracle queries with permissions for all the involved users.
 */

$plugin = array(
  'type' => KMS_OCI_QUEUE_ACTION_CLONE_USER_PERMS,
  'query_creator_run' => array(
    'function' => 'kms_permissions_clone_user_perms_query_creator_run',
  ),
  'query_run' => array(
    'function' => 'kms_permissions_clone_user_perms_query_run',
  ),
);

/**
 * Query creator run function.
 *
 * @param int $jid
 *   Kms oci queue job id.
 * @param object $creator_item
 *   Queue item.
 * @param object $exe_queue
 *   Execute queue that is being populated with items.
 *
 * @return int
 *   Number of query lines to be written.
 */
function kms_permissions_clone_user_perms_query_creator_run($jid, $creator_item, $exe_queue) {
  $source_uid = $creator_item->params['source_uid'];
  $uids = $creator_item->params['uids'];
  $job = KmsOciQueueJobFactory::get($jid);
  // Add subusers.
  kms_subuser_uids_add_subuser_uids($uids);
  $user_count = count($uids);
  $line_num = 0;
  $perms = array();
  $options = array(
    'key_prefix' => FALSE,
    'flattened' => TRUE,
  );
  _kms_permissions_get_bundle_perms_by_uid($source_uid, $perms, $options);
  _kms_permissions_get_separate_perms_by_uid($source_uid, $perms, $options);

  array_walk($uids, function ($uid) use ($job, $perms, $creator_item, $user_count, &$exe_queue, &$line_num) {
    if (!empty($perms)) {
      $line_num++;
      $user = user_load($uid);
      // Queue the item.
      $exe_queue_item = array(
        'jid' => $job->jid,
        'cid' => $job->cid,
        'action' => $creator_item->action,
        'perms' => $perms,
        'kms_id' => kms_user_get_userid($user),
        'is_last_item' => $line_num == $user_count,
      );

      $exe_queue->createItem((object)$exe_queue_item);
    }
  });

  return $line_num;
}

/**
 * Query run function.
 *
 * Creates query queue items ready to be written in an job file.
 *
 * @param object $item
 *   Queue item.
 *
 * @return string
 *   Generated oracle queries.
 */
function kms_permissions_clone_user_perms_query_run($item) {
  $connection_id = $item->cid;

  $perms_oracle_rel = _kms_permissions_perms_oracle_relations();
  foreach($item->perms as $perm_type => $ids) {
    $perm_conf = $perms_oracle_rel[$perm_type];
    // If the connection id of the job does not match the one in $perm_conf
    // do nothing.
    if ($connection_id != $perm_conf['cid']) {
      continue;
    }


    if ($perm_type == 'services') {
      $output = array();
      $conf = KmsOciQueueSqlServices::$conf;
      $wms_ids = kms_permissions_get_service_ids_by_type('wms');
      array_walk($ids, function($sid) use (&$output, $item, $wms_ids) {
        $service_values = kms_permissions_get_service_bounding_box($sid);
        $data = array(
          'featureinfo' => 0,
          'serviceid' => $sid,
        );
        $data += $service_values;
        if (in_array($sid, $wms_ids)) {
          $data['featureinfo'] = 1;
        }
        $sql = new KmsOciQueueSql('services', $data);
        $output[] = $sql->generate('insert');
      });

      if (!empty($ids)) {
        $data = array(
          'userid' => $item->kms_id,
        );
        $sql = new KmsOciQueueSql('services', $data);
        $delete = sprintf('DELETE FROM %s WHERE userid = v_userid;', $conf['table']);
        array_unshift($output, $delete);
        array_unshift($output, $sql->generateWrapper('header'));
        $output[] = $sql->generateWrapper('footer');
      }
    }
    elseif ($perm_type == 'applications') {
      $output = array();
      if (!empty($ids)) {
        $data = array(
          'userid' => $item->kms_id,
        );
        $sql = new KmsOciQueueSql('applications', $data);
        $output[] = $sql->generateWrapper('header');
        $conf = KmsOciQueueSqlApplications::$conf;
        $output[] = sprintf('DELETE FROM %s WHERE userid = v_userid;', $conf['table']);
        array_walk($ids, function($gid) use ($data, &$output) {
          $data['groupid'] = $gid;
          $sql = new KmsOciQueueSql('applications', $data);
          $output[] = $sql->generate('insert');
        });
        $output[] = $sql->generateWrapper('footer');
      }
    }
  }
  return implode("\n", $output);
}