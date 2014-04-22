<?php
/**
 * @file
 * kms_permissions_bundle_save.inc
 *
 * Provides callback functions run by the queue handling functions.
 * Creates oracle queries with permissions for all the involved users.
 */

$plugin = array(
  'type' => KMS_OCI_QUEUE_ACTION_BUNDLE_SAVE,
  'query_creator_run' => array(
    'function' => 'kms_permissions_bundle_save_query_creator_run',
  ),
  'query_run' => array(
    'function' => 'kms_permissions_bundle_save_query_run',
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
function kms_permissions_bundle_save_query_creator_run($jid, $creator_item, $exe_queue) {
  $uids = $creator_item->params['uids'];
  $user_count = count($uids);
  $bid = $creator_item->params['bid'];
  $bundle_diff = $creator_item->params['bundle_diff'];
  // If bundle is not default bundle add subusers to uid array.
  // If it is a default bundle we know that all users are in the array
  // and the subusers do not need to be added.
  if (!in_array($bid, _kms_permissions_get_default_bundles())) {
    // Add subusers to user id array.
    kms_subuser_uids_add_subuser_uids($uids);
  }

  $i = 0;
  foreach ($uids as $uid) {
    $i++;
    // Queue the item.
    $exe_queue_item = array(
      'jid' => $jid,
      'action' => $creator_item->action,
      'bid' => $bid,
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
function kms_permissions_bundle_save_query_run($item) {
  // This function is depending on bundle_diff.
  // If not present return empty query string.
  if (empty($item->bundle_diff)) {
    return '';
  }
  $bid = $item->bid;
  $kms_userid = kms_user_get_userid(user_load($item->uid));
  $job = KmsOciQueueJobFactory::get($item->jid);
  // Get permissions from a user and add them to $user_perms array.
  $user_perms = array('services' => array(), 'applications' => array());
  $perms_options = array('key_prefix' => FALSE, 'flattened' => TRUE);
  $bids = kms_permissions_get_bids_by_uid($item->uid);
  // Do not include current bundle id.
  $bids = array_diff($bids, array($bid));

  foreach ($bids as $bid) {
    // Get permissions from a bundle and add them to $user_perms array.
    _kms_permissions_get_permissions_by_bid(
      $bid,
      $user_perms,
      $perms_options
    );
  }
  // Get separate perms and add them to $user_perms array.
  _kms_permissions_get_separate_perms_by_uid(
    $item->uid,
    $user_perms,
    $perms_options
  );
  $diff = KmsPermsDiff::defaultDiff();
  $perms_oracle_rel = _kms_permissions_perms_oracle_relations();
  foreach ($item->bundle_diff as $perm_type => $perm_diff) {
    $perm_conf = $perms_oracle_rel[$perm_type];
    // If the connection id of the job does not match the one in $perm_conf
    // do nothing.
    if ($job->cid != $perm_conf['cid']) {
      continue;
    }
    $type_diff = &$diff[$perm_type];
    if (!empty($perm_diff['add'])) {
      // Only use id's in add array that is not already in the bundle perms.
      $type_diff['add'] = array_diff($perm_diff['add'], $user_perms[$perm_type]);

      // Add bounding box to services.
      if ($perm_type == 'services') {
        foreach ($type_diff['add'] as &$sid) {
          $sid = kms_permissions_get_service_bounding_box($sid);
        }
      }
    }
    // Only use id's in remove array that is not already in the bundle perms.
    if (!empty($perm_diff['remove'])) {
      $type_diff['remove'] = array_diff($perm_diff['remove'], $user_perms[$perm_type]);
    }
  }

  $output = kmsPermsDiff::createOciSqlFromPermDiff($diff, $kms_userid);
  return $output;
}
