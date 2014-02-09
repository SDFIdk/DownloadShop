<?php
/**
 * @file
 * kms_user_user_delete.inc
 *
 * Provides callback functions run by the queue handling functions.
 * Creates oracle queries with user data for the involved user.
 */

$plugin = array(
  'type' => KMS_OCI_QUEUE_ACTION_USER_DELETE,
  'query_creator_run' => array(
    'function' => 'kms_user_user_delete_query_creator_run',
  ),
  'query_run' => array(
    'function' => 'kms_user_user_delete_query_run',
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
function kms_user_user_delete_query_creator_run($jid, $creator_item, $exe_queue) {
  $job = KmsOciQueueJobFactory::get($jid);
  $queries['default'] = array();
  $queries['kms_permissions'] = array();
  $table_conf = array(
    array('table' => 'SMUSER', 'cid' => 'default'),
    array('table' => 'SMUSER_EXTRA', 'cid' => 'default'),
  );
  $table_conf = array_merge($table_conf, _kms_permissions_perms_oracle_relations());
  foreach($table_conf as $conf) {
    $query = sprintf(
      "DELETE FROM %s WHERE USERID = '%s'",
      $conf['table'],
      $creator_item->params['kms_id']
    );
    $query .= ";\n";
    $queries[$conf['cid']][] = $query;
  }
  // Queue the item.
  $exe_queue_item = (object) array(
    'jid' => $jid,
    'action' => $creator_item->action,
    'query' => implode('', $queries[$job->cid]),
    'is_last_item' => TRUE,
  );
  $exe_queue->createItem($exe_queue_item);
  return count($table_conf);
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
function kms_user_user_delete_query_run($item) {
  return $item->query;
}