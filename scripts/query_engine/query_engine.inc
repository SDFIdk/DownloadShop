<?php

/**
 * Populate args array depending on given cli options.
 *
 * @return array $args
 */
function qe_resolve_arguments() {
  $options_conf = array(
    'f:' => 'job-file:',
    't:' => 'job-type:',
  );

  $opt = getopt(
    implode('', array_keys($options_conf)),
    $options_conf
  );

  $args = array();
  // Define job type.
  $args['type'] = !empty($opt['t']) ? $opt['t'] : (!empty($opt['job-type']) ? $opt['job-type'] : FALSE);
  // Define file to import from.
  $args['filename'] = !empty($opt['f']) ? $opt['f'] : (!empty($opt['job-file']) ? $opt['job-file'] : FALSE);
  if(!$args['filename']) {
    qe_error("filename parameter is missing");
    exit(1);
  }
  else{
    $args['filepath'] = sprintf('%s/jobs/%s', KMS_OCI_QUEUE_ENGINE_ROOT, $args['filename']);
  }
  // Define job id.
  $args['jid'] = (int)preg_replace('#^([0-9]+).job$#', "$1", $args['filename']);
  if(!$args['jid']) {
    qe_error("filename is not formatted correctly (%filename)", array('%filename' => $args['filename']));
    exit(1);
  }

  return $args;
}

/**
 * Execute the generated sql and change job status upon success/failure.
 *
 * @param string $sql
 *   Generated sql to be executed.
 * @param array $args
 *   Arguments fetched from script options.
 */
function qe_execute_sql($sql) {
  // Run sql transaction.
  exec($sql, $message, $exit_code);
  // Do not include empty lines.
  $message = array_filter($message);

  return array(
    'exit_code' => $exit_code,
    'message' => $message
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
 */
function qe_generate_sql($db_conf, $sql_vars) {
  // Construct connection string.
  $conn = sprintf('%s/%s@%s/%s', $db_conf['user'], $db_conf['pass'], $db_conf['host'], $db_conf['db']);
  // Extract vars that are used in sql generation.
  extract($sql_vars);
  // Generate sql.
  return <<<EOD
sqlplus -s /nolog<<!!

connect $conn;

SET AUTOCOMMIT OFF
SET ECHO OFF
SET FEEDBACK OFF
SET HEADING OFF
SET LINESIZE 15000
WHENEVER SQLERROR EXIT FAILURE ROLLBACK
SELECT 'Processing job. Jid: $jid, type: $type, file: $filename',to_char(sysdate,'YYYYMMDD HH24:MI:SS') from dual;
START $filepath
SELECT 'Finishing job. Jid: $jid, type: $type, file: $filename',to_char(sysdate,'YYYYMMDD HH24:MI:SS') from dual;
EXIT COMMIT
!!
EOD;

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
  if(!$std_output_only) {
    KmsOciQueueJob::log(0, $message, $vars, WATCHDOG_ERROR);
  }
  echo strip_tags(format_string($message, $vars)) . "\n";
  exit(1);
}