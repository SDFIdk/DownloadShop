<?php
/**
 * @file
 * kms_access_bundles.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kms_access_bundles_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function kms_access_bundles_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function kms_access_bundles_node_info() {
  $items = array(
    'access_bundle' => array(
      'name' => t('Bundle'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
