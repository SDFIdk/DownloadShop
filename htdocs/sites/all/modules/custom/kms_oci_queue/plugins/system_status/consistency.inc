<?php
/**
 * @file
 * KMS System Status plugin.
 */

$plugin = array(
  'get' => array(
    'function' => 'get_status',
  ),
);

/**
 * Get the status of kmsOciQueue consistency diff.
 *
 * @param string $mode
 *   Simple or advanced.
 */
function get_status($type, $mode) {
  $output = array(
    'status' => NULL,
    'data' => array(),
  );

  switch($type) {
    case 'services':
      module_load_include('inc', 'kms_oci_queue', 'includes/kms_oci_queue.consistency');
      $dir = cHelper::dirConsistencyDiff;
      $files = file_scan_directory($dir, '/.*\.xml$/');
      // Get running service diff process if any.
      $function = 'kms_oci_queue_consistency_check_services_diff';
      $uc_prefix = variable_get('ultimate_cron_handle_prefix', ULTIMATE_CRON_HANDLE_PREFIX);
      $process = background_process_get_process($uc_prefix . $function);
      // If there is a consistency diff process running
      // or last consistency diff went wrong
      // set not ready status and break.
      $log = ultimate_cron_get_log($function);
      if (!empty($process) || ($log['severity'] >= WATCHDOG_EMERGENCY && $log['severity'] <= WATCHDOG_WARNING)) {
        $output['status'] = KMS_SYSTEM_STATUS_CODE_NOT_READY;
        break;
      }
      // If there are diff files we set status to error
      // and optionally expose the diff.
      elseif (!empty($files)) {
        $output['status'] = KMS_SYSTEM_STATUS_CODE_ERROR;
        if ($mode == 'advanced') {
          foreach ($files as $file) {
            $xml = simplexml_load_file($file->uri);
            foreach ($xml->user as $user) {
              $userid = (string) $user->id;
              $row = &$output['data'][$userid];
              $postgres = array_unique((array) $user->{'diff-Services-Postgres'});
              $oracle = array_unique((array) $user->{'diff-Services-Oracle'});
              $row['postgres'] = array_values($postgres);
              $row['oracle'] = array_values($oracle);
            }
          }
        }
      }
      break;
  }

  drupal_json_output($output);
  die;
}