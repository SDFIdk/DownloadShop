<?php

/**
 * Implements hook_drush_command().
 */
function kms_oci_queue_drush_command() {
  $items = array();
  $items['consistency-check'] = array(
    'callback' => 'kms_oci_queue_drush_consistency_check',
    'description' => dt('Run consistency check between postgres and oracle'),
    'arguments' => array(
      "data_type" => "Type of data (i.e.: 'services')",
      "method" => "Method of checking (i.e.: 'diff')",
    ),
    'options' => array(
      'mode' => 'Extra option to the called method. Currently supported by the diff method.',
    ),
    'required-arguments' => TRUE,
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_DATABASE,
  );
  $items['consistency-generate-resolving-sql'] = array(
    'callback' => 'kms_oci_queue_drush_consistency_generate_resolving_sql',
    'description' => dt('Generate sql needed to solve inconsistency.'),
    'arguments' => array(
      "data_type" => "Type of data (i.e.: 'services')",
      "db_target" => "oracle or postgres",
    ),
    'required-arguments' => TRUE,
  );
  return $items;
}

/**
 * Implements hook_drush_help().
 */
function kms_oci_queue_drush_help($section) {
  switch ($section) {
    case 'drush:consistency-check':
      return dt("Run consistency check between postgres and oracle. Specify data type and method [data_type] [method].");

  }
}

/**
 * Executes a data consistency check between postgres and oracle.
 *
 * Supports different "data types" and methods (diff etc.).
 *
 * @param string $data_type
 * @param string $method
 * @throws Exception
 */
function kms_oci_queue_drush_consistency_check($data_type, $method) {
  $time_start = microtime(TRUE);
  drupal_load('module', 'kms_oci_queue');
  kms_oci_queue_consistency_check($data_type, $method);
  $time_end = microtime(TRUE);
  drush_print(
    dt('Execution time: @seconds seconds', array('@seconds' => ($time_end - $time_start)))
  );
}

/**
 * Generates sql file that cleans up target database.
 *
 * @param string $data_type
 * @param string $target_db
 */
function kms_oci_queue_drush_consistency_generate_resolving_sql($data_type, $target_db) {
  $time_start = microtime(TRUE);
  kms_oci_queue_consistency_generate_resolving_sql($data_type, $target_db);
  $time_end = microtime(TRUE);
  drush_print(
    dt('Execution time: @seconds seconds', array('@seconds' => ($time_end - $time_start)))
  );
}
