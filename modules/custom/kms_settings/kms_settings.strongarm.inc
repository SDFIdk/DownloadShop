<?php
/**
 * @file
 * kms_settings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function kms_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bakery_domain';
  $strongarm->value = '.kortforsyningen.dk';
  $export['bakery_domain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bakery_freshness';
  $strongarm->value = '3600';
  $export['bakery_freshness'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bakery_is_master';
  $strongarm->value = 1;
  $export['bakery_is_master'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bakery_master';
  $strongarm->value = 'http://download.kortforsyningen.dk/';
  $export['bakery_master'] = $strongarm;


  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hide_submit_abtext';
  $strongarm->value = '';
  $export['hide_submit_abtext'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hide_submit_atext';
  $strongarm->value = '';
  $export['hide_submit_atext'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hide_submit_hide_fx';
  $strongarm->value = 0;
  $export['hide_submit_hide_fx'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hide_submit_hide_text';
  $strongarm->value = 'Processing...';
  $export['hide_submit_hide_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hide_submit_method';
  $strongarm->value = 'hide';
  $export['hide_submit_method'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hide_submit_reset_time';
  $strongarm->value = '0';
  $export['hide_submit_reset_time'] = $strongarm;

  return $export;
}
