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
    break;

  case 'cli':
    $opt = qe_set_options_from_cli();
    break;
}

// Get the current job.
$job = KmsOciQueueJobFactory::get($args['jid']);

// If job is a standalone job only process that one.
// Or if the run mode is cli then only process one job at a time.
if (!$job->gid || QUERY_ENGINE_RUN_MODE == 'cli') {
  // Create arguments from given script options.
  $args = qe_resolve_arguments($opt);
  // Check if the state of the job is valid.
  qe_job_validate_state($job, $args);
  // Go for it.
  qe_process_job($job, $args, $opt);
}
// Otherwise process group of jobs.
else {
  $jids = KmsOciQueueJobGroup::getJidsFromGid($job->gid);
  foreach ($jids as $jid) {
    // Only process current job and latter ones in group.
    if ($jid < $job->jid) {
      continue;
    }
    $job = KmsOciQueueJobFactory::get($jid);
    $opt['f'] = $job->jid . '.job';
    // Create arguments from given script options.
    $args = qe_resolve_arguments($opt);
    // Check if the state of the job is valid.
    qe_job_validate_state($job, $args);
    // Go for it.
    qe_process_job($job, $args, $opt);
  }
}
