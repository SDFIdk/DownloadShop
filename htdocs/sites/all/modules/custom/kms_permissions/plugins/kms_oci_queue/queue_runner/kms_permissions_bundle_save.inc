<?php

$plugin = array(
  'type' => KMS_OCI_QUEUE_ACTION_BUNDLE_SAVE,
  'query_creator_run' => array(
    'function' => 'kms_permissions_bundle_save_query_creator_run',
  ),
  'query_run' => array(
    'function' => 'kms_permissions_bundle_save_query_run',
  ),
);

function kms_permissions_bundle_save_query_creator_run($jid, $creator_item, $exe_queue) {
  $uids = $creator_item->params['uids'];
  $user_count = count($uids);
  $bid = $creator_item->params['bid'];
  $line_num = 0;
  array_walk($uids, function ($uid) use ($jid, $bid, $creator_item, $user_count, &$exe_queue, &$line_num) {
    $perms = array();
    _kms_permissions_get_permissions_by_uid($uid, $perms);
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
//      $exe_queue_item += $perms;
      $exe_queue->createItem((object)$exe_queue_item);
      $line_num = $line_num + count(array_keys($perms));
    }
  });
  return $line_num;
}

function kms_permissions_bundle_save_query_run($item) {

  $perms_conf = array(
    'services' => array(
      'table' => 'USERRESTRICTIONS2',
      'cid' => 'kms_permissions'
    ),
    'applications' => array(
      'table' => 'SMUSERGROUP',
      'cid' => 'default',
    ),
  );

  $output = $last_perm_name = '';
  array_walk(
    $item->perms,
    function($perms, $perm_name) use ($item, $perms_conf, &$output) {
      if (empty($perms_conf[$perm_name])) {
        return;
      }
      $job = KmsOciQueueJobFactory::get($item->jid);
      $perm_conf = $perms_conf[$perm_name];
      if ($job->cid != $perm_conf['cid']) {
        return;
      }

      $output .= sprintf("DELETE FROM %s WHERE USERID = '%s'\n", $perm_conf['table'], $item->kms_id);

      foreach ($perms as $perm) {
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
        $query = kms_oci_generate_query('insert', $data, array('table' => $perm_conf['table']));
        $patterns = $replacements = array();
        array_walk($data, function($v, $k) use(&$patterns, &$replacements){
          $patterns[] = '#\\' . $k . '#';
          $replacements[] = "'$v'";
        });
        $output .= preg_replace($patterns, $replacements, $query, 1) . ";\n";
      }

    }

  );

  return $output;
}
