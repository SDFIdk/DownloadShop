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
  // Add subusers.
  kms_subuser_uids_add_subuser_uids($uids);
  $user_count = count($uids);
  $line_num = 0;
  $perms = array();
  $options = array(
    'key_prefix' => FALSE,
    'flattened' => TRUE,
  );
  _kms_permissions_get_permissions_by_uid($source_uid, $perms, $options);
  _kms_permissions_get_separate_perms_by_uid($source_uid, $perms, $options);

  array_walk($uids, function ($uid) use ($jid, $perms, $creator_item, $user_count, &$exe_queue, &$line_num) {
    if (!empty($perms)) {
      $line_num++;
      $user = user_load($uid);
      // Queue the item.
      $exe_queue_item = array(
        'jid' => $jid,
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
//  _adapt_debug('mikkel', $item->perms);
  $job = KmsOciQueueJobFactory::get($item->jid);

  $perms_oracle_rel = _kms_permissions_perms_oracle_relations();
//  _adapt_debug('mikkel', __FUNCTION__);
//  _adapt_debug('mikkel', __LINE__);
//  _adapt_debug('mikkel', $item->jid);
//  _adapt_debug('mikkel', $job->cid);
//  _adapt_debug('mikkel', str_repeat('^', 100));
  foreach($item->perms as $perm_type => $ids) {
    $perm_conf = $perms_oracle_rel[$perm_type];
    // If the connection id of the job does not match the one in $perm_conf
    // do nothing.
    if ($job->cid != $perm_conf['cid']) {
      continue;
    }


    if ($perm_type == 'services') {
//      _adapt_debug('mikkel', __FUNCTION__);
//      _adapt_debug('mikkel', __LINE__);
//      _adapt_debug('mikkel', str_repeat('^', 100));
      $output = array();
      $conf = KmsOciQueueSqlServices::$conf;
      array_walk($ids, function($sid) use (&$output, $item) {
        $service_values = kms_permissions_get_service_bounding_box($sid);
        $data = array(
          'featureinfo' => 0,
          'serviceid' => $sid,
        );
        $data += $service_values;
        $sql = new KmsOciQueueSql('services', $data);
        $output[] = $sql->generate('insert');
      });

      if (!empty($ids)) {
//        _adapt_debug('mikkel', __FUNCTION__);
//        _adapt_debug('mikkel', __LINE__);
//        _adapt_debug('mikkel', $data);
//        _adapt_debug('mikkel', str_repeat('^', 100));
        $data = array(
          'userid' => $item->kms_id,
        );
        $sql = new KmsOciQueueSql('services', $data);
        $delete = sprintf('DELETE FROM %s WHERE userid = :userid;', $conf['table']);
        array_unshift($output, $delete);
        array_unshift($output, $sql->generateHeader());

      }
    }
    elseif ($perm_type == 'applications') {
      $output = array();
      if (!empty($ids)) {
        $data = array(
          'userid' => $item->kms_id,
        );
        $sql = new KmsOciQueueSql('applications', $data);
        $output[] = $sql->generateHeader();
        $conf = KmsOciQueueSqlApplications::$conf;
        $output[] = sprintf('DELETE FROM %s WHERE userid = :userid;', $conf['table']);
        array_walk($ids, function($gid) use ($data, &$output) {
          $data['groupid'] = $gid;
//          _adapt_debug('mikkel', __FUNCTION__);
//          _adapt_debug('mikkel', __LINE__);
//          _adapt_debug('mikkel', $data);
//          _adapt_debug('mikkel', str_repeat('^', 100));
          $sql = new KmsOciQueueSql('applications', $data);
          $output[] = $sql->generate('insert');
        });
      }
    }
  }
  return implode("\n", $output);
}