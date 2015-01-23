<?php
/**
 * @file
 * pagemanager_node_view.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pagemanager_node_view_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
