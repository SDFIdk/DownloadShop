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
  $user_count = count($uids);
  $line_num = 0;
  $perms = array();
  _kms_permissions_get_permissions_by_uid($source_uid, $perms);
  _kms_permissions_get_separate_perms_by_uid($source_uid, $perms);

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
  return _kms_oci_queue_process_perms_query_creator_queue_item($item);
}
