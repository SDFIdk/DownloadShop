<?php
/**
 * @file
 * kms_user_remove_all_bundles.inc
 *
 * Provides callback functions run by the queue handling functions.
 * Removes all bundles except default from users..
 */


$plugin = array(
  'type' => KMS_OCI_QUEUE_ACTION_REMOVE_ALL_BUNDLES,
  'query_creator_run' => array(
    'function' => 'kms_user_remove_all_bundles_query_creator_run',
  ),
  'query_run' => array(
    'function' => 'kms_user_remove_all_bundles_query_run',
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
function kms_user_remove_all_bundles_query_creator_run($jid, $creator_item, $exe_queue) {
  $uids = $creator_item->params['uids'];
  $job = KmsOciQueueJobFactory::get($jid);
  // Add subusers to user id array.
  kms_subuser_uids_add_subuser_uids($uids);
  $user_count = count($uids);
  $perms_options = array('key_prefix' => FALSE, 'flattened' => TRUE);

  $default_bundle_diff = KmsPermsDiff::defaultDiff();
  // Populate bundle add diff arrays.
  $perms = array();
  foreach (_kms_permissions_get_default_bundles() as $bid) {
    _kms_permissions_get_permissions_by_bid($bid, $perms, $perms_options);
    if (!empty($perms['services'])) {
      $default_bundle_diff['services']['add'] += $perms['services'];
    }
    if (!empty($perms['applications'])) {
      $default_bundle_diff['applications']['add'] += $perms['applications'];
    }
  }

  $i = 0;
  foreach ($uids as $uid) {
    $i++;
    // Queue the item.
    $exe_queue_item = array(
      'jid' => $job->jid,
      'cid' => $job->cid,
      'action' => $creator_item->action,
      'uid' => $uid,
      'default_bundle_diff' => $default_bundle_diff,
      'is_last_item' => $i == $user_count,
    );

    $exe_queue->createItem((object) $exe_queue_item);
  }

  return $i;
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
function kms_user_remove_all_bundles_query_run($item) {
  $connection_id = $item->cid;
  $kms_userid = kms_user_get_userid(user_load($item->uid));

  $user_perms = array(
    'services' => array(),
    'applications' => array(),
  );
  // Get separate perms and add then to $user_perms array.
  _kms_permissions_get_separate_perms_by_uid(
    $item->uid,
    $user_perms,
    array('key_prefix' => FALSE, 'flattened' => TRUE)
  );

  $diff = KmsPermsDiff::defaultDiff();
  $perms_oracle_rel = _kms_permissions_perms_oracle_relations();
  foreach ($item->default_bundle_diff as $perm_type => $perm_diff) {
    $perm_conf = $perms_oracle_rel[$perm_type];
    // If the connection id of the job does not match the one in $perm_conf
    // do nothing.
    if ($connection_id != $perm_conf['cid']) {
      continue;
    }
    $type_diff = &$diff[$perm_type];
    // Only handle 'add', because we wipe everything first.
    if (!empty($perm_diff['add'])) {
      $type_diff['add'] = $perm_diff['add'] + $user_perms[$perm_type];

      // Add bounding box to services.
      if ($perm_type == 'services') {
        foreach ($type_diff['add'] as &$sid) {
          $sid = kms_permissions_get_service_bounding_box($sid);
        }
      }
    }
    // Generate header here because we need the userid for the DELETE statement.
    $data = array('userid' => $kms_userid);
    $sql = new KmsOciQueueSql($perm_type, $data);
    $output = array($sql->generateWrapper('header'));
    // Wipe all permissions for user before writing.
    // This is done because we do not know about the eventual 'removed' bundles
    // for the user at this point.
    $output[] = sprintf(
      "DELETE FROM %s WHERE userid = userid;",
      $perm_conf['table']
    );
  }
  // Create permission sql statements.
  $output[] = kmsPermsDiff::createOciSqlFromPermDiff($diff, $kms_userid, TRUE);
  $output[] = $sql->generateWrapper('footer');
  // Return sql.
  return implode("\n", $output);
}