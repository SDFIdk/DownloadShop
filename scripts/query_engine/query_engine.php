<?php
/**
 * @file
 * query_engine.php.
 * Used by the kms_oci_queue drupal module for oracle query execution.
 *
 * User: mikkel@adapt.dk
 * Date: 01/21/14 - 11:16 PM
 */

// Define paths.
define('QUERY_ENGINE_ROOT', dirname(__FILE__));
define('QUERY_ENGINE_RUN_MODE', 'cron');
define('DRUPAL_ROOT', realpath(QUERY_ENGINE_ROOT . '/../../htdocs'));

$_SERVER['HTTP_HOST']       = 'default';
$_SERVER['REMOTE_ADDR']     = '127.0.0.1';
$_SERVER['SERVER_SOFTWARE'] = NULL;
$_SERVER['REQUEST_METHOD']  = 'GET';
$_SERVER['QUERY_STRING']    = '';
$_SERVER['PHP_SELF']        = $_SERVER['REQUEST_URI'] = '/';
$_SERVER['HTTP_USER_AGENT'] = 'console';

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
require_once 'query_engine.inc';

drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

// Atodo: Fix this and do it otherwise.
// Somehow drupal_realpath($uri) cannot resolve the uri in the right way...
define(
  'KMS_OCI_QUEUE_ENGINE_ROOT',
  sprintf('%s/sites/default/files/%s', DRUPAL_ROOT, KMS_OCI_QUEUE_PREFIX)
);

// If kms_oci_queue is not enabled do nothing.
if (!module_exists('kms_oci_queue')) {
  qe_error('kms_oci_queue is not enabled');
}

// Run as admin.
$user = user_load(1);

switch (QUERY_ENGINE_RUN_MODE) {
  case 'cron':
    $opt = array();
    // Get job filename from file_scan_directory of jobs dir.
    $opt['f'] = qe_find_job_file_lowest_id();
    $file = qe_absolute_filepath($opt['f']);
    break;

  case 'cli':
    $opt = qe_set_options_from_cli();
    break;
}

// Create arguments from given script options.
$args = qe_resolve_arguments($opt);

// Get the current job.
$job = KmsOciQueueJobFactory::get($args['jid']);

// If job could not be loaded then exit.
if (!$job) {
  qe_error('No jobs existing with id: %jid', array('%jid' => $args['jid']));
}

// Only process job if it has an valid status.
if (!qe_job_has_valid_status($job)) {
  exit(1);
}

// If there are undone jobs before this one do not import it yet.
if (qe_undone_jobs_before_current_exists($job)) {
  exit(1);
}

// If the job file could not be loaded change job status and exit.
if (!file_exists($args['filepath'])) {
  $message = 'Query engine: File: %file does not exist';
  $vars = array('%file' => $args['filepath']);
  $job->changeStatus(KmsOciQueueJob::STATUS_FAILED, $message, $vars);
  qe_error($message, $vars, TRUE);
}

// Db connection settings.
$db_conf = KmsOciQueueJobDb::getConnectionSettings($job->cid);

// Get job info from job action if not specified.
$args['info'] = !empty($opt['i']) ? $opt['i'] : $job->action . ' | ' . $job->actionDetails;

// Generate sql string.
$sql = qe_generate_sql($db_conf, $args);

// Report sql execution.
$job->changeStatus(
  KmsOciQueueJob::STATUS_PROCESSING,
  'Query engine: %jid is being processed',
  array('%jid' => $job->jid)
);
// Execute generated sql and get result of it.
$result = qe_execute_sql($sql, $args);

// Move file to processed folder upon success.
if ($result['exit_code'] === 0) {
  // Move file.
  rename(
    qe_absolute_filepath($args['filename'], KMS_OCI_QUEUE_ENGINE_DIR_JOBS),
    qe_absolute_filepath($args['filename'], KMS_OCI_QUEUE_ENGINE_DIR_JOBS_PROCESSED)
  );
  // Report everything well and change status to 'done'.
  $job_status = KmsOciQueueJob::STATUS_DONE;
  $message = implode('; ', $result['message']);
}
else {
  $job_status = KmsOciQueueJob::STATUS_FAILED;
  if (!empty($result['message'])) {
    $message = implode('; ', $result['message']);
    $message_vars = array();
  }
  else {
    $message = 'Something went wrong with exit code: @exit_code.';
    $message_vars = array('@exit_code' => $result['exit_code']);
  }
}

// Change job status depending on exit code.
$job->changeStatus(
  $job_status,
  'Query engine: ' . $message,
  $message_vars
);

// Expose exit code.
exit($result['exit_code']);
