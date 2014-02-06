<?php
/**
 * @file
 * kms_user_user_insert.inc
 *
 * Provides callback functions run by the queue handling functions.
 * Creates oracle queries with user data for the involved user.
 */

$plugin = array(
  'type' => KMS_OCI_QUEUE_ACTION_USER_INSERT,
  'query_creator_run' => array(
    'function' => 'kms_user_user_insert_query_creator_run',
  ),
  'query_run' => array(
    'function' => 'kms_user_user_insert_query_run',
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
function kms_user_user_insert_query_creator_run($jid, $creator_item, $exe_queue) {
  $num_exe_items = count($creator_item->params);
  $line_num = 0;
  array_walk(
    $creator_item->params,
    function ($user_query) use ($jid, $num_exe_items, $creator_item, &$exe_queue, &$line_num){
      $line_num++;
      list($data, $table) = $user_query;
      kms_oci_filter_query_data($data);
      $query = kms_oci_generate_query(
        'insert',
        $data,
        array('table' => $table)
      );
      // Queue the item.
      $exe_queue_item = (object) array(
        'jid' => $jid,
        'action' => $creator_item->action,
        'query' => $query,
        'data' => $data,
        'table' => $table,
        'kms_id' => $data[':userid'],
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
function kms_user_user_insert_query_run($item) {
  $output = sprintf("DELETE FROM %s WHERE USERID = '%s'", $item->table, $item->kms_id);
  $output .= ";\n";
  $patterns = $replacements = array();
  array_walk($item->data, function($v, $k) use(&$patterns, &$replacements){
    $patterns[] = '#\\' . $k . '#';
    $replacements[] = "'$v'";
  });
  $output .= preg_replace($patterns, $replacements, $item->query, 1) . ";\n";
  return $output;
}