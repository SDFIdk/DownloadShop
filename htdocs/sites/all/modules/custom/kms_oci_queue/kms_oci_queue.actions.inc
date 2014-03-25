<?php
/**
 * kms_oci_queue.actions.inc.
 * User: mikkel@adapt.dk
 * Date: 3/5/14 - 9:31 AM
 */


function kms_oci_queue_job_action_bundle_save($uids, $bid, $message, $vars = array()) {
  //Atodo: test den her som det næste!
  foreach (array_chunk($uids, 2000) as $uids) {
    $job_params = array(
      'action' => KMS_OCI_QUEUE_ACTION_BUNDLE_SAVE,
      'params' => array(
        'uids' => $uids,
        'bid' => $bid,
      ),
    );
    $job_params['action_details'] = format_string(
      $message,
      $vars
    );

    KmsOciQueueJob::create($job_params);
    KmsOciQueueJob::create($job_params, 'kms_permissions');
  }

}

function kms_oci_queue_job_action_bundles_attach($uid, $bids, $perms, $message, $vars = array()) {
  $job_params = array(
    'action' => KMS_OCI_QUEUE_ACTION_PERMS_ATTACH,
    'action_details' => format_string(
      $message,
      $vars
    ),
    'params' => array(
      'uid' => $uid,
      'bids' => $bids,
      'perms' => $perms,
    ),
  );
  KmsOciQueueJob::create($job_params);
  KmsOciQueueJob::create($job_params, 'kms_permissions');
}