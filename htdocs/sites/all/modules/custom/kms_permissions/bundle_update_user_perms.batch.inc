<?php
/**
 * @file
 * User permissions updates by batch.
 */

/**
 * Batch operation callback.
 */
function kms_permissions_batch_default_bundle_update_users($bid, $uids, $user_count, $chunk_size, &$context) {

  foreach ($uids as $uid) {
    _kms_permissions_attach_default_bundles_to_user($uid, $bid);
  }

  $context['results'][] = $uids;
  $context['message'] = t(
    'Attaching default bundle to users. Processed %progress out of %max users',
    array('%progress' => count($context['results']) * $chunk_size, '%max' => $user_count)
  );
  // Empty field cache to reflect result.
  // Atodo; Make finish function work and move it there.
  field_cache_clear();
}

/**
 * Batch 'finished' callback.
 */
function kms_permissions_batch_default_bundle_update_users_finished($success, $results, $operations) {
  if ($success) {
    $message = count($results) . ' processed.';
    drupal_set_message($message);
    watchdog(
      'kms_permissons',
      'Successfully finished batchjob (kms_permissions_batch_bundle_update_user_perms)',
      array(),
      WATCHDOG_INFO
    );
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = t(
      'An error occurred while processing %error_operation with arguments: @arguments',
      array(
        '%error_operation' => $error_operation[0],
        '@arguments' => print_r($error_operation[1], TRUE),
      )
    );
    drupal_set_message($message, 'error');
    watchdog(
      'kms_permissons',
      'Unsuccessfully finished batchjob (kms_permissions_batch_bundle_update_user_perms): %message',
      array('%message' => $error_operation[0]),
      WATCHDOG_ERROR
    );
  }

}
