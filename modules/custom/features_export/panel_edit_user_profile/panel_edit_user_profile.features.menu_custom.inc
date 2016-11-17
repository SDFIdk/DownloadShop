<?php
/**
 * @file
 * panel_edit_user_profile.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function panel_edit_user_profile_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-profile-menu.
  $menus['menu-profile-menu'] = array(
    'menu_name' => 'menu-profile-menu',
    'title' => 'Profile menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Profile menu');


  return $menus;
}
