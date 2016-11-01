<?php
/**
 * @file
 * panel_edit_user_profile.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function panel_edit_user_profile_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-profile-menu:edit/profile
  $menu_links['menu-profile-menu:edit/profile'] = array(
    'menu_name' => 'menu-profile-menu',
    'link_path' => 'edit/profile',
    'router_path' => 'edit/profile',
    'link_title' => 'Min profil',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-profile-menu:edit/profile/newsletter
  $menu_links['menu-profile-menu:edit/profile/newsletter'] = array(
    'menu_name' => 'menu-profile-menu',
    'link_path' => 'edit/profile/newsletter',
    'router_path' => 'edit/profile/newsletter',
    'link_title' => 'Tilmeld nyheder & Tweets',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: menu-profile-menu:edit/profile/subuser
  $menu_links['menu-profile-menu:edit/profile/subuser'] = array(
    'menu_name' => 'menu-profile-menu',
    'link_path' => 'edit/profile/subuser',
    'router_path' => 'edit/profile/subuser',
    'link_title' => 'Administrér underbrugere',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Administrér underbrugere');
  t('Min profil');
  t('Tilmeld nyheder & Tweets');


  return $menu_links;
}
