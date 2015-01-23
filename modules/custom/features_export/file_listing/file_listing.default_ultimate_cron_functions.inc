<?php
/**
 * @file
 * file_listing.default_ultimate_cron_functions.inc
 */

/**
 * Implements hook_default_ultimate_cron_function().
 */
function file_listing_default_ultimate_cron_function() {
  $export = array();

  $name = new stdClass();
  $name->disabled = FALSE; /* Edit this to true to make a default name disabled initially */
  $name->api_version = 1;
  $name->name = 'kms_files_cron';
  $name->settings = array(
    'enabled' => 1,
    'rules' => array(
      0 => '*/5 * * * *',
    ),
    'catch_up' => '',
    'service_group' => '',
  );
  $export['kms_files_cron'] = $name;

  return $export;
}
