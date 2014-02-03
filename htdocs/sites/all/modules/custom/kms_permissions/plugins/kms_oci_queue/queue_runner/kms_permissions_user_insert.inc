<?php

$plugin = array(
  'type' => KMS_OCI_QUEUE_ACTION_USER_INSERT,
  'query_creator_run' => array(
    'function' => 'kms_permissions_user_insert_query_creator_run',
  ),
  'query_run' => array(
    'function' => 'kms_permissions_user_insert_query_run',
  ),
);

function kms_permissions_user_insert_query_creator_run($jid, $creator_item, $exe_queue) {
  $num_exe_items = count($creator_item->params);
  $i = 0;
  array_walk(
    $creator_item->params,
    function ($user_query) use ($jid, $num_exe_items, $creator_item, &$exe_queue, &$i){
      $i++;
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
        'is_last_item' => $i == $num_exe_items,
      );
      $exe_queue->createItem($exe_queue_item);
    }
  );

  if ($i) {
    KmsOciQueueJob::log(
      $jid,
      '%lines lines to be written in job file.',
      array('%lines' => $i)
    );
  }

}

function kms_permissions_user_insert_query_run($item) {
  $output = sprintf("DELETE FROM %s WHERE USERID = '%s';\n", $item->table, $item->kms_id);
  $patterns = $replacements = array();
  array_walk($item->data, function($v, $k) use(&$patterns, &$replacements){
    $patterns[] = '#\\' . $k . '#';
    $replacements[] = "'$v'";
  });
  $output .= preg_replace($patterns, $replacements, $item->query, 1) . ";\n";
  return $output;
}