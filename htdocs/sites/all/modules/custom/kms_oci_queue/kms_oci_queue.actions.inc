<?php
/**
 * kms_oci_queue.actions.inc.
 * User: mikkel@adapt.dk
 * Date: 3/5/14 - 9:31 AM
 */

function kms_oci_queue_job_action_user_insert(&$jobs, $data, $message = '', $vars = array()) {
  $params = array();
  if (!empty($data['user'])) {
    $params[] = array($data['user'], 'smuser', TRUE);
  }
  if (!empty($data['user_extra'])) {
    $params[] = array($data['user_extra'], 'smuser_extra', TRUE);
  }
  $jobs[] = KmsOciQueueJob::create(array(
    'action' => KMS_OCI_QUEUE_ACTION_USER_SAVE,
    'action_details' => format_string($message, $vars),
    'params' => $params,
  ));
}

function kms_oci_queue_job_action_user_update(&$jobs, $data, $message = '', $vars = array()) {
  $params = array();
  if (!empty($data['user'])) {
    $params[] = array($data['user'], 'smuser', FALSE);
  }
  if (!empty($data['user_extra'])) {
    $params[] = array($data['user_extra'], 'smuser_extra', FALSE);
  }
  $jobs[] = KmsOciQueueJob::create(array(
    'action' => KMS_OCI_QUEUE_ACTION_USER_SAVE,
    'action_details' => format_string($message, $vars),
    'params' => $params,
  ));
}

function kms_oci_queue_job_action_perms_attach(&$jobs, $uid, $bids, $perms_diff, $message = '', $vars = array()) {
  if (empty($message)) {
    $message =<<<EOD
Administer permissions on user: @user.
Bundles: @bids.
Permissions:
&nbsp;&nbsp;Services
&nbsp;&nbsp;&nbsp;&nbsp;Add: @add_services
&nbsp;&nbsp;&nbsp;&nbsp;Remove: @remove_services
&nbsp;&nbsp;Applications
&nbsp;&nbsp;&nbsp;&nbsp;Add: @add_applications
&nbsp;&nbsp;&nbsp;&nbsp;Remove: @remove_applications
EOD;
  }
  if (empty($vars)) {
    $vars = array(
      '@bids' => implode(', ', $bids),
      '@add_services' => implode(', ', $perms_diff['services']['add']),
      '@remove_services' => implode(', ', $perms_diff['services']['remove']),
      '@add_applications' => implode(', ', $perms_diff['applications']['add']),
      '@remove_applications' => implode(', ', $perms_diff['applications']['remove']),
    );
  }
  $job_params = array(
    'action' => KMS_OCI_QUEUE_ACTION_PERMS_ATTACH,
    'action_details' => format_string(
      nl2br($message),
      $vars
    ),
    'params' => array(
      'uid' => $uid,
      'bids' => $bids,
      'perms_diff' => $perms_diff,
    ),
  );

  $jobs[] = KmsOciQueueJob::create($job_params);
  $jobs[] = KmsOciQueueJob::create($job_params, 'kms_permissions');
}

function kms_oci_queue_job_action_clone_user_perms(&$jobs, $source_user, $uids) {
  $job_params = array(
    'action' => KMS_OCI_QUEUE_ACTION_CLONE_USER_PERMS,
    'action_details' => format_string(
      'Cloning user permissions from: @source_user. Affects @user_count.',
      array(
        '@source_user' => $source_user->name,
        '@user_count' => count($uids),
      )
    ),
    'params' => array(
      'source_uid' => $source_user->uid,
      'uids' => $uids,
    ),
  );

  $jobs[] = KmsOciQueueJob::create($job_params);
  $jobs[] = KmsOciQueueJob::create($job_params, 'kms_permissions');
}