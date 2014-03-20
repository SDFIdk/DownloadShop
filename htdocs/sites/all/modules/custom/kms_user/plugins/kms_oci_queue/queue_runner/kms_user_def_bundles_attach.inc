<?php
/**
 * @file
 * kms_user_def_bundles_attach.inc
 *
 * Provides callback functions run by the queue handling functions.
 * Attaches specified bundles to a given user.
 */


$plugin = array(
  'type' => KMS_OCI_QUEUE_ACTION_DEF_BUNDLES_ATTACH,
  'query_creator_run' => array(
    'function' => 'kms_user_def_bundles_attach_query_creator_run',
  ),
  'query_run' => array(
    'function' => 'kms_user_def_bundles_attach_query_run',
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
function kms_user_def_bundles_attach_query_creator_run($jid, $creator_item, $exe_queue) {
  _adapt_debug('mikkel', var_export($jid, TRUE));
  _adapt_debug('mikkel', var_export($creator_item, TRUE));
  _adapt_debug('mikkel', var_export($exe_queue, TRUE));
  return;
//  _adapt_debug('mikkel', $jid);
  $uid = $creator_item->params['uid'];
  $bids = $creator_item->params['bids'];
  $perms_diff = $creator_item->params['perms_diff'];
  $line_num = 0;

//  'uid' => $userids['old'],
//      'bids' => $bids,
//      'perms_diff' => $perms_diff,
  $perms = array();
  foreach ($bids as $bid) {
    // Get permissions from a bundle and add them to $perms array.
    _kms_permissions_get_permissions_by_bid($bid, $perms);
  }

//  if (!empty($perms)) {
  foreach ($perms as $perm) {
    $line_num += count($perm);
  }
  // Queue the item.
  $exe_queue_item = array(
    'jid' => $jid,
    'action' => $creator_item->action,
    'perms' => $perms,
    'perms_diff' => $perms_diff,
    'kms_id' => $uid,
    'is_last_item' => TRUE,
  );
  $exe_queue->createItem((object) $exe_queue_item);
//  }

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
function kms_user_def_bundles_attach_query_run($item) {
  return _kms_oci_queue_process_perms_query_creator_queue_item($item);
}