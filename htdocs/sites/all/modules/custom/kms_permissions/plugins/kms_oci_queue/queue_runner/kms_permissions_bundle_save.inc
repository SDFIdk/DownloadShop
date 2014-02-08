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
  $line_num = 0;
  array_walk($uids, function ($uid) use ($jid, $bid, $creator_item, $user_count, &$exe_queue, &$line_num) {
    $perms = array();
    _kms_permissions_get_permissions_by_uid($uid, $perms);

    _kms_permissions_get_separate_perms_by_uid($uid, $perms);

    if (!empty($perms)) {
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
      $line_num = $line_num + count(array_keys($perms));
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
function kms_permissions_bundle_save_query_run($item) {
  return _kms_oci_queue_process_perms_query_creator_queue_item($item);
}
