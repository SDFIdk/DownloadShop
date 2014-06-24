<?php

/*
 * Implements hook_drush_command().
 */
function kms_oci_queue_drush_command() {
  $items = array();
  $items['consistency_check'] = array(
    'callback' => 'kms_oci_queue_consistency_check',
    'description' => dt('Run consistency check between postgres and oracle'),
    'arguments' => array(
      "data_type" => "Type of data (i.e.: 'services')",
      "method" => "Method of checking (i.e.: 'diff')",
    ),
    'required-arguments' => TRUE,
  );
  return $items;
}

function kms_oci_queue_drush_help($section) {
  switch ($section) {
    case 'drush:consistency_check':
      return dt("Run consistency check between postgres and oracle. Specify data type and method [data_type] [method].");
      break;
  }
}

function kms_oci_queue_consistency_check($data_type, $method) {
  module_load_include('inc', 'kms_oci_queue', 'includes/kms_oci_queue.consistency');
  $class_name_prefix = 'cData' . ucfirst($data_type);
  $class_name_postgres = $class_name_prefix . 'Postgres';
  $class_name_oracle = $class_name_prefix . 'Oracle';
  // Check if classes are defined.
  if (
    !class_exists($class_name_postgres)
      && !class_exists($class_name_oracle)
  ){
    return;
  }
  $postgres = new $class_name_postgres();
  $oracle = new $class_name_oracle();
  $data_check = new cDataCheck($postgres, $oracle);
  if (method_exists($data_check, $method)) {
    $result = $data_check->$method();
    if (is_array($result)) {
      var_dump($result);
    }
    else {
      echo "$result\n";
    }
  }
}