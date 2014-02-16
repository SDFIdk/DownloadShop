<?php
/**
 * @file
 * query_engine.inc.
 * User: mikkel@adapt.dk
 * Date: 01/21/14 - 11:18 PM
 */

/**
 * Populate args array depending on given cli options.
 *
 * @return array
 *   $args
 */

/**
 * Resolve cli arguments (options).
 *
 * @param array $opt
 *   Options used for constructing arguments for the application.
 *
 * @return array
 *   Return resolved options as an argument array.
 */
function qe_resolve_arguments($opt) {
  $opt += array(
    'i' => '',
    'job-info' => '',
    'f' => '',
    'job-file' => '',
  );

  $args = array();
  // Define job info.
  $args['info'] = !empty($opt['i']) ? $opt['i'] : (!empty($opt['job-info']) ? $opt['job-info'] : FALSE);
  // Define file to import from.
  $args['filename'] = !empty($opt['f']) ? $opt['f'] : (!empty($opt['job-file']) ? $opt['job-file'] : FALSE);
  if (!$args['filename']) {
    qe_error("filename parameter is missing");
    exit(1);
  }
  else {
    $args['filepath'] = qe_absolute_filepath($args['filename']);
  }
  // Define job id.
  $args['jid'] = (int) preg_replace('#^([0-9]+).job$#', "$1", $args['filename']);
  if (!$args['jid']) {
    qe_error(
      'filename is not formatted correctly (%filename)',
      array('%filename' => $args['filename'])
    );
    exit(1);
  }

  return $args;
}

/**
 * Get options passed to the script at command line.
 *
 * @return array
 *   Options array.
 */
function qe_set_options_from_cli() {
  $options_conf = array(
    'f:' => 'job-file:',
    'i:' => 'job-info:',
  );
  return getopt(
    implode('', array_keys($options_conf)),
    $options_conf
  );
}

/**
 * Execute the generated sql and change job status upon success/failure.
 *
 * @param string $sql
 *   Generated sql to be executed.
 *
 * @return array
 *   exit code and output.
 */
function qe_execute_sql($sql) {
  // Run sql transaction.
  exec($sql, $message, $exit_code);
  // Do not include empty lines.
  $message = array_filter($message);

  return array(
    'exit_code' => $exit_code,
    'message' => $message,
  );
}

/**
 * Generate sql.
 *
 * @param array $db_conf
 *   Db settings used for connection.
 * @param array $sql_vars
 *   Variables used in sql statement.
 *
 * @return string
 *   Generated sql.
 */
function qe_generate_sql($db_conf, $sql_vars) {
  // Construct connection string.
  $conn = sprintf(
    '%s/%s@%s/%s',
    $db_conf['user'],
    $db_conf['pass'],
    $db_conf['host'],
    $db_conf['db']
  );
  // Extract vars that are used in sql generation.
  extract($sql_vars);
  // Generate sql.
  $sql = <<<EOD
sqlplus -s /nolog<<!!

connect $conn;

SET AUTOCOMMIT OFF
SET ECHO OFF
SET FEEDBACK OFF
SET HEADING OFF
SET LINESIZE 15000
WHENEVER SQLERROR EXIT FAILURE ROLLBACK
SELECT 'Oracle import start. Jid: $jid, type: $info, file: $filename',to_char(sysdate,'YYYYMMDD HH24:MI:SS') from dual;
START $filepath
SELECT 'Oracle import end. Jid: $jid, type: $info, file: $filename',to_char(sysdate,'YYYYMMDD HH24:MI:SS') from dual;
EXIT COMMIT
!!
EOD;

  _adapt_debug('mikkel', $sql);

  return $sql;

}

/**
 * Generate exit error and print/log message.
 *
 * @param string $message
 *   Error message.
 * @param array $vars
 *   Placeholders and values.
 * @param bool $std_output_only
 *   Should the error message only be printed and not logged?
 */
function qe_error($message, $vars = array(), $std_output_only = FALSE) {
  if (!$std_output_only) {
    KmsOciQueueJob::log(0, $message, $vars, WATCHDOG_ERROR);
  }
  echo strip_tags(format_string($message, $vars)) . "\n";
  exit(1);
}

/**
 * Find job file with the lowest job id.
 *
 * @return bool|string
 *   If file found return filename otherwise FALSE.
 */
function qe_find_job_file_lowest_id() {
  $job_files = file_scan_directory(
    KMS_OCI_QUEUE_ENGINE_ROOT . '/' . KMS_OCI_QUEUE_ENGINE_DIR_JOBS,
    '/^[0-9]+\.job$/',
    array('key' => 'filename')
  );
  if (!empty($job_files)) {
    // Order latest job files first.
    asort($job_files);
    // Pick the first job file.
    return key($job_files);
  }
  return FALSE;
}

/**
 * Get absolute path to job file.
 *
 * @param string $filename
 *   The name of the job file.
 * @param string $subdir
 *   The name of the subdir.
 *
 * @return string
 *   Absolute path to the file.
 */
function qe_absolute_filepath($filename, $subdir = KMS_OCI_QUEUE_ENGINE_DIR_JOBS) {
  return implode(
    '/',
    array(
      KMS_OCI_QUEUE_ENGINE_ROOT,
      $subdir,
      $filename,
    )
  );
}

/**
 * Get job type from file.
 *
 * @param string $filepath
 *   The path to the job file.
 *
 * @return string
 *   Either 'unknown' or one of the known (kms_oci_queue) types.
 */
function qe_get_job_type_from_file($filepath) {
  $type = 'unknown';
  if ($f = fopen($filepath, 'r')) {
    $line = fgets($f);
    fclose($f);
    $type_line = preg_replace('#^-- type:([a-z_]+)[\r\n]+#', "$1", $line, -1, $c);
    $type = $c ? $type_line : $type;
  }
  return $type;
}

/**
 * Do we have undone jobs with a job id less than this one.
 *
 * @param object $job
 *   Kms oci queue job.
 *
 * @return bool
 *   Undone jobs before this one exist?
 */
function qe_undone_jobs_before_current_exists($job) {
  $undone_jobs = kms_oci_queue_get_job_ids(
    array('exclude' => array(KmsOciQueueJob::STATUS_DONE))
  );
  $undone_jobs_b4 = array_filter($undone_jobs, function($jid) use ($job) {
    return intval($jid) < intval($job->jid);
  });

  return (bool) count($undone_jobs_b4);
}