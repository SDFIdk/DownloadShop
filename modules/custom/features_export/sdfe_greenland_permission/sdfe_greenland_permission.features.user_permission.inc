<?php
/**
 * @file
 * sdfe_greenland_permission.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function sdfe_greenland_permission_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'edit any greenland_permissions config_pages'.
  $permissions['edit any greenland_permissions config_pages'] = array(
    'name' => 'edit any greenland_permissions config_pages',
    'roles' => array(
      'product admin' => 'product admin',
      'superuser' => 'superuser',
    ),
    'module' => 'config_pages',
  );

  return $permissions;
}
