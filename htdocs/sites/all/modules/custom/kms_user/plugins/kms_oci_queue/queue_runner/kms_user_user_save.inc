<?php
/**
 * @file
 * kms_user_user_save.inc
 *
 * Provides callback functions run by the queue handling functions.
 * Creates oracle queries with user data for the involved user.
 */

$plugin = array(
  'type' => KMS_OCI_QUEUE_ACTION_USER_SAVE,
  'query_creator_run' => array(
    'function' => 'kms_user_user_save_query_creator_run',
  ),
  'query_run' => array(
    'function' => 'kms_user_user_save_query_run',
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
function kms_user_user_save_query_creator_run($jid, $creator_item, $exe_queue) {
  $num_exe_items = count($creator_item->params);
  $line_num = 0;
  array_walk(
    $creator_item->params,
    function ($query_data) use ($jid, $num_exe_items, $creator_item, &$exe_queue, &$line_num){
      $line_num++;
      list($data, $table, $is_new) = $query_data;
      kms_oci_filter_query_data($data);
      // Queue the item.
      $exe_queue_item = (object) array(
        'jid' => $jid,
        'action' => $creator_item->action,
        'data' => $data,
        'table' => $table,
        'kms_id' => $data['userid'],
        'is_new' => $is_new,
        'is_last_item' => $line_num == $num_exe_items,
      );
      $exe_queue->createItem($exe_queue_item);
    }
  );

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
function kms_user_user_save_query_run($item) {
  $sql = new KmsOciQueueSql('user', $item->data);
  $output = array();
  $statement_type = $item->is_new ? 'insert' : 'update';
  $data = $item->data;
  unset($data['userid']);
  $output[] = $sql->generate($statement_type, $item->table, $data);
  if (!$item->is_last_item) {
    array_unshift($output, $sql->generateWrapper('header'));
  }
  else {
    $output[] = $sql->generateWrapper('footer');
  }
  return implode("\n", $output);
}