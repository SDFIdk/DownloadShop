<?php
/**
 * @file
 * kms_user_bundles_attach.inc
 *
 * Provides callback functions run by the queue handling functions.
 * Attaches specified bundles to a given user.
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
  $uid = $creator_item->params['uid'];
  $bids = $creator_item->params['bids'];
  $line_num = 0;
  array_walk($bids, function ($bid) use ($jid, $uid, $creator_item, &$exe_queue, &$line_num) {
    static $perms;

    if (empty($perms)) {
      _kms_permissions_get_separate_perms_by_uid($uid, $perms);
    }
    _kms_permissions_get_permissions_by_bid($bid, $perms);


    if (!empty($perms)) {
      $user = user_load($uid);
      // Queue the item.
      $exe_queue_item = array(
        'jid' => $jid,
        'action' => $creator_item->action,
        'perms' => $perms,
        'kms_id' => kms_user_get_userid($user),
        'is_last_item' => TRUE,
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
function kms_user_bundles_attach_query_run($item) {
  $output = $last_perm_name = '';
  array_walk(
    $item->perms,
    function($perms, $perm_name) use ($item, &$output) {
      $perms_oracle_rel = _kms_permissions_perms_oracle_relations();
      // Only handle permissions mentioned in in oracle relations.
      if (empty($perms_oracle_rel[$perm_name])) {
        return;
      }

      $job = KmsOciQueueJobFactory::get($item->jid);
      $perm_conf = $perms_oracle_rel[$perm_name];
      // If the connection id of the job does not match the one in $perm_conf
      // do nothing.
      if ($job->cid != $perm_conf['cid']) {
        return;
      }
      // Create sql line that deletes all data from table owned by current user.
      $output .= sprintf(
        "DELETE FROM %s WHERE USERID = '%s'\n",
        $perm_conf['table'],
        $item->kms_id
      );

      // Create data for insert query line.
      foreach ($perms as $perm) {
        $perm += $perm_conf['default_values'];
        switch ($perm_name) {
          case 'services':
            $data = array(
              ':USERID' => $item->kms_id,
              ':SERVICEID' => $perm['id'],
              ':MINX' => $perm['MINX'],
              ':MINY' => $perm['MINY'],
              ':MAXX' => $perm['MAXX'],
              ':MAXY' => $perm['MAXY'],
              ':MAXPIXELWIDTH' => $perm['MAXPIXELWIDTH'],
              ':MAXPIXELHEIGHT' => $perm['MAXPIXELHEIGHT'],
              ':FEATUREINFO' => $perm['FEATUREINFO'],
            );
            break;

          case 'applications':
            $data = array(
              ':USERID' => $item->kms_id,
              ':GROUPID' => $perm['id'],
            );
            break;
        }
        // Create insert query line.
        $output .= _kms_oci_queue_sql_generate_line(
          'insert',
          $data,
          $perm_conf['table']
        );

      }

    }

  );
  // Return all created query lines.
  return $output;
}