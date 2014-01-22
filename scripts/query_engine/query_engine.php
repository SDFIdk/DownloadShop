<?php
// Define paths
define('KMS_OCI_QUEUE_ENGINE_ROOT', dirname(__FILE__));
define('DRUPAL_ROOT', realpath(KMS_OCI_QUEUE_ENGINE_ROOT . '/../../htdocs'));
$_SERVER['REMOTE_ADDR'] = '127.0.0.1';

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
require_once 'query_engine.inc';

drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

// Run as admin.
$user = user_load(1);
// Create arguments from given script options.
$args = qe_resolve_arguments();

// Get the current job.
$job = KmsOciQueueJobFactory::get($args['jid']);
// If job could not be loaded then exit.
if(!$job) {
  exit(1);
}

// If the job file could not be loaded change job status and exit.
if(!file_exists($args['filepath'])) {
  $job->changeStatus(
    KmsOciQueueJob::STATUS_FAILED,
    'File: %file does not exist',
    array('%file' => $args['filepath'])
  );
  exit(1);
}

// Db connection settings.
$db_conf = array(
  'user' =>  $conf['kms_oci_conn_user'],
  'pass' => $conf['kms_oci_conn_pass'],
  'host' => $conf['kms_oci_conn_host'],
  'db' => $conf['kms_oci_conn_db'],
);
// Generate sql string.
$sql = qe_generate_sql($db_conf, $args);
// Execute generated sql.
$result = qe_execute_sql($sql, $args);
// Move file to processed folder upon success.
if($result['exit_code'] === 0) {
  // Move file.
  rename(
    sprintf('%s/jobs/%s', KMS_OCI_QUEUE_ENGINE_ROOT, $args['filename']),
    sprintf('%s/jobs_processed/%s', KMS_OCI_QUEUE_ENGINE_ROOT, $args['filename'])
  );
  // Report everything well and change status to 'done'.
  $job->changeStatus(KmsOciQueueJob::STATUS_DONE, implode('; ', $result['message']));
}
else {
  // Report that the job has failed.
  $job->changeStatus(KmsOciQueueJob::STATUS_FAILED, implode('; ', $result['message']));
}
// Atodo: Check if php can return exit code like this...
exit($result['exit_code']);


