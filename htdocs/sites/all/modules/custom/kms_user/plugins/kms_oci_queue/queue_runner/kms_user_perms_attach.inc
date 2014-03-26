<?php
/**
 * @file
 * kms_user_perms_attach.inc
 *
 * Provides callback functions run by the queue handling functions.
 * Attaches specified bundles to a given user.
 */


$plugin = array(
  'type' => KMS_OCI_QUEUE_ACTION_PERMS_ATTACH,
  'query_creator_run' => array(
    'function' => 'kms_user_perms_attach_query_creator_run',
  ),
  'query_run' => array(
    'function' => 'kms_user_perms_attach_query_run',
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
function kms_user_perms_attach_query_creator_run($jid, $creator_item, $exe_queue) {
  $job = KmsOciQueueJobFactory::get($jid);
  $uid = $creator_item->params['uid'];
  $bids = $creator_item->params['bids'];
  $perms_diff = $creator_item->params['perms_diff'];
  $line_num = 0;

  $bundle_perms = array();
  foreach ($bids as $bid) {
    // Get permissions from a bundle and add them to $bundle_perms array.
    _kms_permissions_get_permissions_by_bid(
      $bid,
      $bundle_perms,
      array('key_prefix' => FALSE, 'flattened' => TRUE)
    );
  }
  $bundle_perms += array(
    'services' => array(),
    'applications' => array(),
  );

  $diff = array(
    'services' => array(
      'add' => array(),
      'remove' => array(),
    ),
    'applications' => array(
      'add' => array(),
      'remove' => array(),
    ),
  );
  $perms_oracle_rel = _kms_permissions_perms_oracle_relations();

  foreach ($perms_diff as $perm_type => $perm_diff) {
    $perm_conf = $perms_oracle_rel[$perm_type];
    // If the connection id of the job does not match the one in $perm_conf
    // do nothing.
    if ($job->cid != $perm_conf['cid']) {
      continue;
    }
    $type_diff = &$diff[$perm_type];
    if (!empty($perm_diff['add'])) {
      // Only use id's in add array that is not already in the bundle perms.
      $type_diff['add'] = array_diff($perm_diff['add'], $bundle_perms[$perm_type]);
      // Add bounding box to services.
      if ($perm_type == 'services') {
        foreach ($type_diff['add'] as &$sid) {
          $sid = kms_permissions_get_service_bounding_box($sid);
        }
      }
    }
    // Only use id's in remove array that is not already in the bundle perms.
    if (!empty($perm_diff['remove'])) {
      $type_diff['remove'] = array_diff($perm_diff['remove'], $bundle_perms[$perm_type]);
    }
  }
  // Queue the item.
  $exe_queue_item = array(
    'jid' => $jid,
    'action' => $creator_item->action,
    'diff' => $diff,
    'kms_id' => $uid,
    'is_last_item' => TRUE,
  );
  $exe_queue->createItem((object) $exe_queue_item);

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
function kms_user_perms_attach_query_run($item) {
  return kmsPermsDiff::createOciSqlFromPermDiff($item->diff, $item->kms_id);
}