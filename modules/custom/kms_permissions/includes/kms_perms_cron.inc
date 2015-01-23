<?php
/**
 * @file
 * Cron functions for the kms_permissions module.
 */

/**
 * Delete dead services.
 *
 * A dead service is a service that lives only in postgres.
 */
function kms_permissions_cron_cleanup_dead_services() {
  module_load_include('inc', 'kms_oci_queue', 'includes/kms_oci_queue.consistency');
  $sids_pg = cHelper::getAllServiceIdsPostgres();
  $sids_valid = cHelper::getValidServiceIds();
  // Find dead services.
  $sids_diff = array_diff($sids_pg, $sids_valid);
  // If no dead services are found do nothing.
  if (empty($sids_diff)) {
    return;
  }
  // Loop over known service types and delete services from tables.
  foreach (kms_permissions_widget_type_options() as $type) {
    $type = strtolower($type);
    $tables = array(
      sprintf("field_data_field_bundle_webservices_%s", $type),
      sprintf("field_revision_field_bundle_webservices_%s", $type),
    );
    $field = sprintf("field_bundle_webservices_%s_value", $type);
    if (!empty($sids_diff)) {
      foreach ($tables as $table) {
        db_delete($table)->condition($field, $sids_diff, 'IN')->execute();
      }
    }
  }
  watchdog(
    'kms_permission_cron',
    'Deleted services in postgres: !sids',
    array('!sids' => implode(', ', $sids_diff))
  );
  // Clear field cache in order so we are sure that the UI reflects the truth.
  field_cache_clear();
}
