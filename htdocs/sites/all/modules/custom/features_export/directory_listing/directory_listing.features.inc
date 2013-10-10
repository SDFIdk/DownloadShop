<?php
/**
 * @file
 * directory_listing.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function directory_listing_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "ultimate_cron" && $api == "default_ultimate_cron_functions") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function directory_listing_views_api() {
  return array("version" => "3.0");
}
