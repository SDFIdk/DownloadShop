<?php

/**
* Batch Operation Callback
*
* @param $bid - The bundle id
* @param context
*   $context is an array that will contain information about the
*   status of the batch. The values in $context will retain their
*   values as the batch progresses.
*/
function kms_permissions_batch_update_permissions($uids, &$context) {
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_uid'] = 0;
    $context['sandbox']['max'] = sizeof($uids);
  }

  // Process 5 users at a time
  $limit = ($context['sandbox']['progress'] + 5 > $context['sandbox']['max'] ? $context['sandbox']['max'] - $context['sandbox']['progress'] : 5);

  // With each pass through the callback, process the next group of uids.
  for ($i = 0; $i < $limit; $i++) {
    //watchdog('kms_permissons', 'processing @user', array('@user' => $context['sandbox']['current_uid']), WATCHDOG_INFO);
    
    $permissions = array();
    _kms_permissions_get_permissions_by_uid($uids[$context['sandbox']['current_uid']], $permissions);
    kms_permissions_save_permissions($uids[$context['sandbox']['current_uid']], $permissions);    

    // Store some result for post-processing in the finished callback.
    $context['results'][] = $uids[$context['sandbox']['current_uid']];

    // Update our progress information.
    $context['message'] = t('Now processing %user', array('%user' => $uids[$context['sandbox']['current_uid']]));
    $context['sandbox']['progress']++;
    $context['sandbox']['current_uid']++;
  }    

  // Inform the batch engine that we are not finished,
  // and provide an estimation of the completion level we reached.
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

/**
 * Save all permissions for a given user to a temporary table (in psql)
 * @param object $uid - the user id
 * @param array $permissions - the permissions
 */
function kms_permissions_batch_save_temp_permissions($uid, $permissions) {
  _kms_permissions_get_permissions_by_uid($uid, $permissions);
  $user = user_load($uid);
  //Check if Oracle smuser exists
  if (kms_user_smuser_exists($user)) {
    $kms_id = kms_user_get_userid($user);
    //Write services permissions to db
    if (!empty($permissions['services'])) {
      // Delete existing entries for user
      db_delete('temp_service_perm_user')
        ->condition('USERID', $kms_id, '=')
        ->execute();
      foreach ($permissions['services'] as $serv_perms) {
        $fields = array(
          'USERID' => $kms_id,
          'SERVICEID' => $serv_perms['id'],
          'MINX' => $serv_perms['MINX'],
          'MINY' => $serv_perms['MINY'],
          'MAXX' => $serv_perms['MAXX'],
          'MAXY' => $serv_perms['MAXY'],
          'MAXPIXELWIDTH' => $serv_perms['MAXPIXELWIDTH'],
          'MAXPIXELHEIGHT' => $serv_perms['MAXPIXELHEIGHT'],
          'FEATUREINFO' => $serv_perms['FEATUREINFO'],
        );
        //Write to DB
        drupal_write_record('temp_service_perm_user', $fields);
      }
    }

    //Write applications permissions to db
    if (!empty($permissions['applications'])) {
      // Delete existing entries for user
      db_delete('temp_application_perm_user')
        ->condition('USERID', $kms_id, '=')
        ->execute();
      foreach ($permissions['applications'] as $app_perms) {
        $fields = array(
          'USERID' => $kms_id,
          'GROUPID' => $app_perms['id'],
        );
        //Write to DB
        drupal_write_record('temp_application_perm_user', $fields);
      }
    }
  }
}

/**
* Batch 'finished' callback
*/
function kms_permissions_batch_update_permissions_finished($success, $results, $operations) {
  if ($success) {
    $message = count($results) .' processed.';
    drupal_set_message($message);
    watchdog('kms_permissons', 'Successfully finished batchjob', array(), WATCHDOG_INFO);
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array('%error_operation' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
    drupal_set_message($message, 'error');
    watchdog('kms_permissons', 'Unsuccessfully finished batchjob: %message', array('%message' => $error_operation[0]), WATCHDOG_ERROR);
  }
}
