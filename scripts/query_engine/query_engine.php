<?php
// Define paths
define('QUERY_ENGINE_ROOT', dirname(__FILE__));
define('DRUPAL_ROOT', realpath(QUERY_ENGINE_ROOT . '/../../htdocs'));

$_SERVER['REMOTE_ADDR'] = '127.0.0.1';

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
require_once 'query_engine.inc';

drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

// Atodo: Fix this and do it otherwise. Somehow drupal_realpath cannot resolve the uri in the right way...
define('KMS_OCI_QUEUE_ENGINE_ROOT', sprintf('%s/sites/default/files/%s', DRUPAL_ROOT, KMS_OCI_QUEUE_PREFIX));

// Run as admin.
$user = user_load(1);
// Create arguments from given script options.
$args = qe_resolve_arguments();

// If kms_oci_queue is not enabled do nothing.
if(!module_exists('kms_oci_queue')) {
  qe_error('kms_oci_queue is not enabled');
}

// Get the current job.
$job = KmsOciQueueJobFactory::get($args['jid']);

// If job could not be loaded then exit.
if(!$job) {
  $message = 'No jobs existing with id: %jid';
  $vars = array('%jid' => $args['jid']);
  qe_error($message, $vars);
}

// If the job file could not be loaded change job status and exit.
if(!file_exists($args['filepath'])) {
  $message = 'File: %file does not exist';
  $vars = array('%file' => $args['filepath']);
  $job->changeStatus(KmsOciQueueJob::STATUS_FAILED, $message, $vars);
  qe_error($message, $vars, TRUE);
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
// Execute generated sql and get result of it.
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
// Expose exit code.
exit($result['exit_code']);


