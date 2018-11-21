<?php
/**
 * @file
 * file_listing.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function file_listing_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "ultimate_cron" && $api == "default_ultimate_cron_functions") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function file_listing_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
