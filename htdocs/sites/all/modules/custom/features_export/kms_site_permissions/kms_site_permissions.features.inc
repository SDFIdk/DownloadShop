<?php
/**
 * @file
 * kms_site_permissions.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kms_site_permissions_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
