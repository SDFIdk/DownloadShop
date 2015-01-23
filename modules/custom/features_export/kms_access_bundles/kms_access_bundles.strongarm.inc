<?php
/**
 * @file
 * kms_access_bundles.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function kms_access_bundles_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_access_bundle';
  $strongarm->value = 'edit-xmlsitemap';
  $export['additional_settings__active_tab_access_bundle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__access_bundle';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '17',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '16',
        ),
        'xmlsitemap' => array(
          'weight' => '15',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__access_bundle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_access_bundle';
  $strongarm->value = '0';
  $export['language_content_type_access_bundle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_access_bundle';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_access_bundle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_access_bundle';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_access_bundle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_access_bundle';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_access_bundle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_access_bundle';
  $strongarm->value = '0';
  $export['node_preview_access_bundle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_access_bundle';
  $strongarm->value = 1;
  $export['node_submitted_access_bundle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_access_bundle';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_access_bundle'] = $strongarm;

  return $export;
}
