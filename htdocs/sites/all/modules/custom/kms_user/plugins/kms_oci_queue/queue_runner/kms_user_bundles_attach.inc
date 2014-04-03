<?php
/**
 * @file
 * kms_user_bundles_attach.inc
 *
 * Provides callback functions run by the queue handling functions.
 */


$plugin = array(
  'type' => KMS_OCI_QUEUE_ACTION_BUNDLES_ATTACH,
  'query_creator_run' => array(
    'function' => 'kms_user_bundles_attach_query_creator_run',
  ),
  'query_run' => array(
    'function' => 'kms_user_bundles_attach_query_run',
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
function kms_user_bundles_attach_query_creator_run($jid, $creator_item, $exe_queue) {
  $uids = $creator_item->params['uids'];
  $bids = $creator_item->params['bids'];
  // Add subusers to user id array.
  kms_subuser_uids_add_subuser_uids($uids);
  $user_count = count($uids);
  $perms_options = array('key_prefix' => FALSE, 'flattened' => TRUE);

  $bundle_diff = KmsPermsDiff::defaultDiff();
  // Populate bundle add diff arrays.
  $perms = array();
  foreach ($bids as $bid) {
    _kms_permissions_get_permissions_by_bid($bid, $perms, $perms_options);
    if (!empty($perms['services'])) {
      $bundle_diff['services']['add'] += $perms['services'];
    }
    if (!empty($perms['applications'])) {
      $bundle_diff['applications']['add'] += $perms['applications'];
    }
  }

  $i = 0;
  foreach ($uids as $uid) {
    $i++;
    // Queue the item.
    $exe_queue_item = array(
      'jid' => $jid,
      'action' => $creator_item->action,
      'uid' => $uid,
      'bundle_diff' => $bundle_diff,
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
function kms_user_bundles_attach_query_run($item) {
  $job = KmsOciQueueJobFactory::get($item->jid);
  $uid = $item->uid;
  $bundle_diff = $item->bundle_diff;
  $kms_userid = kms_user_get_userid(user_load($uid));

  $user_diff = KmsPermsDiffDb::loadDiff($uid, 'user');
  KmsPermsDiffDb::deleteDiff($uid, 'user');
  if (empty($user_diff)) {
    $user_diff = KmsPermsDiff::defaultDiff();
  }
  $diff = KmsPermsDiff::defaultDiff();
  $perms_oracle_rel = _kms_permissions_perms_oracle_relations();
  foreach ($bundle_diff as $perm_type => $perm_diff) {
    $perm_conf = $perms_oracle_rel[$perm_type];
    // If the connection id of the job does not match the one in $perm_conf
    // do nothing.
    if ($job->cid != $perm_conf['cid']) {
      continue;
    }
    $type_diff = &$diff[$perm_type];
    if (!empty($perm_diff['add'])) {
      // Only use id's in add array that is not already in the bundle perms.
      $type_diff['add'] = array_diff($perm_diff['add'], $user_diff[$perm_type]['add']);

      // Add bounding box to services.
      if ($perm_type == 'services') {
        foreach ($type_diff['add'] as &$sid) {
          $sid = kms_permissions_get_service_bounding_box($sid);
        }
      }
    }
  }
  // Create permission sql statements.
  $output = kmsPermsDiff::createOciSqlFromPermDiff($diff, $kms_userid);
  // Return sql.
  return $output;
}