<?php
/**
 * @file
 * kms_site_permissions.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function kms_site_permissions_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_product_display';
  $strongarm->value = array(
    'view_own' => array(
      0 => 4,
      1 => 8,
    ),
    'view' => array(
      0 => 4,
      1 => 8,
    ),
    'per_node' => 1,
  );
  $export['content_access_product_display'] = $strongarm;

  return $export;
}
