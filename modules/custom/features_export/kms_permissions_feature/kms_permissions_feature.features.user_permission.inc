<?php
/**
 * @file
 * kms_permissions_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function kms_permissions_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: access administration menu.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      0 => 'editor',
      1 => 'product admin',
      2 => 'superuser',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: access administration pages.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      0 => 'editor',
      1 => 'product admin',
      2 => 'superuser',
    ),
    'module' => 'system',
  );

  // Exported permission: access all views.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'views',
  );

  // Exported permission: access any commerce_file_license.
  $permissions['access any commerce_file_license'] = array(
    'name' => 'access any commerce_file_license',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_file',
  );

  // Exported permission: access any commerce_file_license_log.
  $permissions['access any commerce_file_license_log'] = array(
    'name' => 'access any commerce_file_license_log',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_file',
  );

  // Exported permission: access checkout.
  $permissions['access checkout'] = array(
    'name' => 'access checkout',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
      2 => 'superuser',
    ),
    'module' => 'commerce_checkout',
  );

  // Exported permission: access content.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
      2 => 'product admin',
      3 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: access content overview.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      0 => 'editor',
      1 => 'product admin',
      2 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: access contextual links.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'contextual',
  );

  // Exported permission: access dashboard.
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'dashboard',
  );

  // Exported permission: access devel information.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(),
    'module' => 'devel',
  );

  // Exported permission: access kms user pages.
  $permissions['access kms user pages'] = array(
    'name' => 'access kms user pages',
    'roles' => array(
      0 => 'editor',
      1 => 'imported_user',
      2 => 'superuser',
    ),
    'module' => 'kms_user',
  );

  // Exported permission: access own commerce_file_license_log.
  $permissions['access own commerce_file_license_log'] = array(
    'name' => 'access own commerce_file_license_log',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_file',
  );

  // Exported permission: access private fields.
  $permissions['access private fields'] = array(
    'name' => 'access private fields',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: access relations.
  $permissions['access relations'] = array(
    'name' => 'access relations',
    'roles' => array(),
    'module' => 'relation',
  );

  // Exported permission: access rules debug.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'rules',
  );

  // Exported permission: access site in maintenance mode.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      0 => 'maintenance',
      1 => 'superuser',
    ),
    'module' => 'system',
  );

  // Exported permission: access site reports.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'system',
  );

  // Exported permission: access user profiles.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'user',
  );

  // Exported permission: administer actions.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'system',
  );

  // Exported permission: administer advanced pane settings.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'panels',
  );

  // Exported permission: administer background process.
  $permissions['administer background process'] = array(
    'name' => 'administer background process',
    'roles' => array(),
    'module' => 'background_process',
  );

  // Exported permission: administer blocks.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'block',
  );

  // Exported permission: administer checkout.
  $permissions['administer checkout'] = array(
    'name' => 'administer checkout',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_checkout',
  );

  // Exported permission: administer commerce file.
  $permissions['administer commerce file'] = array(
    'name' => 'administer commerce file',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_file',
  );

  // Exported permission: administer commerce_customer_profile entities.
  $permissions['administer commerce_customer_profile entities'] = array(
    'name' => 'administer commerce_customer_profile entities',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: administer commerce_extra.
  $permissions['administer commerce_extra'] = array(
    'name' => 'administer commerce_extra',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_extra',
  );

  // Exported permission: administer commerce_file field type.
  $permissions['administer commerce_file field type'] = array(
    'name' => 'administer commerce_file field type',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_file',
  );

  // Exported permission: administer commerce_file_license.
  $permissions['administer commerce_file_license'] = array(
    'name' => 'administer commerce_file_license',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_file',
  );

  // Exported permission: administer commerce_file_license_log.
  $permissions['administer commerce_file_license_log'] = array(
    'name' => 'administer commerce_file_license_log',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_file',
  );

  // Exported permission: administer commerce_order entities.
  $permissions['administer commerce_order entities'] = array(
    'name' => 'administer commerce_order entities',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: administer commerce_product entities.
  $permissions['administer commerce_product entities'] = array(
    'name' => 'administer commerce_product entities',
    'roles' => array(
      0 => 'product admin',
      1 => 'superuser',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: administer content types.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: administer custom content.
  $permissions['administer custom content'] = array(
    'name' => 'administer custom content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'ctools_custom_content',
  );

  // Exported permission: administer customer profile types.
  $permissions['administer customer profile types'] = array(
    'name' => 'administer customer profile types',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: administer features.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'features',
  );

  // Exported permission: administer field permissions.
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: administer fieldgroups.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_group',
  );

  // Exported permission: administer filters.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'filter',
  );

  // Exported permission: administer google analytics.
  $permissions['administer google analytics'] = array(
    'name' => 'administer google analytics',
    'roles' => array(),
    'module' => 'googleanalytics',
  );

  // Exported permission: administer honeypot.
  $permissions['administer honeypot'] = array(
    'name' => 'administer honeypot',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'honeypot',
  );

  // Exported permission: administer image styles.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'image',
  );

  // Exported permission: administer imce.
  $permissions['administer imce'] = array(
    'name' => 'administer imce',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'imce',
  );

  // Exported permission: administer kms oci queue.
  $permissions['administer kms oci queue'] = array(
    'name' => 'administer kms oci queue',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'kms_oci_queue',
  );

  // Exported permission: administer kms permissions.
  $permissions['administer kms permissions'] = array(
    'name' => 'administer kms permissions',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'kms_permissions',
  );

  // Exported permission: administer languages.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'locale',
  );

  // Exported permission: administer line item types.
  $permissions['administer line item types'] = array(
    'name' => 'administer line item types',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_line_item',
  );

  // Exported permission: administer line items.
  $permissions['administer line items'] = array(
    'name' => 'administer line items',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_line_item',
  );

  // Exported permission: administer masquerade.
  $permissions['administer masquerade'] = array(
    'name' => 'administer masquerade',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: administer menu.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'menu',
  );

  // Exported permission: administer menu positions.
  $permissions['administer menu positions'] = array(
    'name' => 'administer menu positions',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'menu_position',
  );

  // Exported permission: administer menu_per_role.
  $permissions['administer menu_per_role'] = array(
    'name' => 'administer menu_per_role',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'menu_per_role',
  );

  // Exported permission: administer meta tags.
  $permissions['administer meta tags'] = array(
    'name' => 'administer meta tags',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'metatag',
  );

  // Exported permission: administer mini panels.
  $permissions['administer mini panels'] = array(
    'name' => 'administer mini panels',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'panels_mini',
  );

  // Exported permission: administer modules.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'system',
  );

  // Exported permission: administer nodes.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      0 => 'product admin',
      1 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: administer page manager.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: administer pane access.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'panels',
  );

  // Exported permission: administer panel-nodes.
  $permissions['administer panel-nodes'] = array(
    'name' => 'administer panel-nodes',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'panels_node',
  );

  // Exported permission: administer panels layouts.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'panels',
  );

  // Exported permission: administer panels styles.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'panels',
  );

  // Exported permission: administer pathauto.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: administer permissions.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'user',
  );

  // Exported permission: administer product pricing.
  $permissions['administer product pricing'] = array(
    'name' => 'administer product pricing',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_product_pricing_ui',
  );

  // Exported permission: administer product types.
  $permissions['administer product types'] = array(
    'name' => 'administer product types',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: administer relation types.
  $permissions['administer relation types'] = array(
    'name' => 'administer relation types',
    'roles' => array(),
    'module' => 'relation',
  );

  // Exported permission: administer relations.
  $permissions['administer relations'] = array(
    'name' => 'administer relations',
    'roles' => array(),
    'module' => 'relation',
  );

  // Exported permission: administer rules.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'rules',
  );

  // Exported permission: administer search.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'search',
  );

  // Exported permission: administer shortcuts.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: administer site configuration.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'system',
  );

  // Exported permission: administer smtp module.
  $permissions['administer smtp module'] = array(
    'name' => 'administer smtp module',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'smtp',
  );

  // Exported permission: administer software updates.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'system',
  );

  // Exported permission: administer taxonomy.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      0 => 'editor',
      1 => 'product admin',
      2 => 'superuser',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: administer themes.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'system',
  );

  // Exported permission: administer ultimate cron.
  $permissions['administer ultimate cron'] = array(
    'name' => 'administer ultimate cron',
    'roles' => array(),
    'module' => 'ultimate_cron',
  );

  // Exported permission: administer url aliases.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'path',
  );

  // Exported permission: administer users.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'user',
  );

  // Exported permission: administer views.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'views',
  );

  // Exported permission: block IP addresses.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'system',
  );

  // Exported permission: bypass honeypot protection.
  $permissions['bypass honeypot protection'] = array(
    'name' => 'bypass honeypot protection',
    'roles' => array(
      0 => 'authenticated user',
      1 => 'superuser',
    ),
    'module' => 'honeypot',
  );

  // Exported permission: bypass node access.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: bypass rules access.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'rules',
  );

  // Exported permission: cancel account.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'user',
  );

  // Exported permission: change layouts in place editing.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'panels',
  );

  // Exported permission: change own username.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'user',
  );

  // Exported permission: configure order settings.
  $permissions['configure order settings'] = array(
    'name' => 'configure order settings',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: configure store.
  $permissions['configure store'] = array(
    'name' => 'configure store',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce',
  );

  // Exported permission: create access_bundle content.
  $permissions['create access_bundle content'] = array(
    'name' => 'create access_bundle content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create commerce_customer_profile entities.
  $permissions['create commerce_customer_profile entities'] = array(
    'name' => 'create commerce_customer_profile entities',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: create commerce_customer_profile entities of bundle billing.
  $permissions['create commerce_customer_profile entities of bundle billing'] = array(
    'name' => 'create commerce_customer_profile entities of bundle billing',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: create commerce_file_license.
  $permissions['create commerce_file_license'] = array(
    'name' => 'create commerce_file_license',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_file',
  );

  // Exported permission: create commerce_file_license_log.
  $permissions['create commerce_file_license_log'] = array(
    'name' => 'create commerce_file_license_log',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_file',
  );

  // Exported permission: create commerce_order entities.
  $permissions['create commerce_order entities'] = array(
    'name' => 'create commerce_order entities',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: create commerce_order entities of bundle commerce_order.
  $permissions['create commerce_order entities of bundle commerce_order'] = array(
    'name' => 'create commerce_order entities of bundle commerce_order',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: create commerce_product entities.
  $permissions['create commerce_product entities'] = array(
    'name' => 'create commerce_product entities',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: create commerce_product entities of bundle file_collection.
  $permissions['create commerce_product entities of bundle file_collection'] = array(
    'name' => 'create commerce_product entities of bundle file_collection',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: create commerce_product entities of bundle fme_product.
  $permissions['create commerce_product entities of bundle fme_product'] = array(
    'name' => 'create commerce_product entities of bundle fme_product',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: create commerce_product entities of bundle product.
  $permissions['create commerce_product entities of bundle product'] = array(
    'name' => 'create commerce_product entities of bundle product',
    'roles' => array(
      0 => 'product admin',
      1 => 'superuser',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: create downloads content.
  $permissions['create downloads content'] = array(
    'name' => 'create downloads content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: create field_access_bundles.
  $permissions['create field_access_bundles'] = array(
    'name' => 'create field_access_bundles',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_address.
  $permissions['create field_address'] = array(
    'name' => 'create field_address',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_applications.
  $permissions['create field_applications'] = array(
    'name' => 'create field_applications',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_billing_address.
  $permissions['create field_billing_address'] = array(
    'name' => 'create field_billing_address',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_bundle_webservices_geo.
  $permissions['create field_bundle_webservices_geo'] = array(
    'name' => 'create field_bundle_webservices_geo',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_bundle_webservices_plot.
  $permissions['create field_bundle_webservices_plot'] = array(
    'name' => 'create field_bundle_webservices_plot',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_bundle_webservices_wcs.
  $permissions['create field_bundle_webservices_wcs'] = array(
    'name' => 'create field_bundle_webservices_wcs',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_bundle_webservices_wfs.
  $permissions['create field_bundle_webservices_wfs'] = array(
    'name' => 'create field_bundle_webservices_wfs',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_bundle_webservices_wms.
  $permissions['create field_bundle_webservices_wms'] = array(
    'name' => 'create field_bundle_webservices_wms',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_bundle_webservices_wmts.
  $permissions['create field_bundle_webservices_wmts'] = array(
    'name' => 'create field_bundle_webservices_wmts',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_debtor_nr.
  $permissions['create field_debtor_nr'] = array(
    'name' => 'create field_debtor_nr',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_expire_date.
  $permissions['create field_expire_date'] = array(
    'name' => 'create field_expire_date',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_ftp_permissions.
  $permissions['create field_ftp_permissions'] = array(
    'name' => 'create field_ftp_permissions',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_kms_user_id.
  $permissions['create field_kms_user_id'] = array(
    'name' => 'create field_kms_user_id',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_pass_clear.
  $permissions['create field_pass_clear'] = array(
    'name' => 'create field_pass_clear',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_phone.
  $permissions['create field_phone'] = array(
    'name' => 'create field_phone',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_predefined_datacollections.
  $permissions['create field_predefined_datacollections'] = array(
    'name' => 'create field_predefined_datacollections',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_terms_and_conditions.
  $permissions['create field_terms_and_conditions'] = array(
    'name' => 'create field_terms_and_conditions',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
      2 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_updated.
  $permissions['create field_updated'] = array(
    'name' => 'create field_updated',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_user_remark.
  $permissions['create field_user_remark'] = array(
    'name' => 'create field_user_remark',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_user_type.
  $permissions['create field_user_type'] = array(
    'name' => 'create field_user_type',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_user_type_info.
  $permissions['create field_user_type_info'] = array(
    'name' => 'create field_user_type_info',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create front content.
  $permissions['create front content'] = array(
    'name' => 'create front content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: create kort_test content.
  $permissions['create kort_test content'] = array(
    'name' => 'create kort_test content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: create mini panels.
  $permissions['create mini panels'] = array(
    'name' => 'create mini panels',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'panels_mini',
  );

  // Exported permission: create page content.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: create panel content.
  $permissions['create panel content'] = array(
    'name' => 'create panel content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: create panel-nodes.
  $permissions['create panel-nodes'] = array(
    'name' => 'create panel-nodes',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'panels_node',
  );

  // Exported permission: create partner content.
  $permissions['create partner content'] = array(
    'name' => 'create partner content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create partner_list content.
  $permissions['create partner_list content'] = array(
    'name' => 'create partner_list content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create product_display content.
  $permissions['create product_display content'] = array(
    'name' => 'create product_display content',
    'roles' => array(
      0 => 'product admin',
      1 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: create product_listing content.
  $permissions['create product_listing content'] = array(
    'name' => 'create product_listing content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: create relations.
  $permissions['create relations'] = array(
    'name' => 'create relations',
    'roles' => array(),
    'module' => 'relation',
  );

  // Exported permission: create subuser 10.
  $permissions['create subuser 10'] = array(
    'name' => 'create subuser 10',
    'roles' => array(),
    'module' => 'subuser',
  );

  // Exported permission: create subuser 2.
  $permissions['create subuser 2'] = array(
    'name' => 'create subuser 2',
    'roles' => array(),
    'module' => 'subuser',
  );

  // Exported permission: create subuser 3.
  $permissions['create subuser 3'] = array(
    'name' => 'create subuser 3',
    'roles' => array(),
    'module' => 'subuser',
  );

  // Exported permission: create subuser 4.
  $permissions['create subuser 4'] = array(
    'name' => 'create subuser 4',
    'roles' => array(),
    'module' => 'subuser',
  );

  // Exported permission: create subuser 6.
  $permissions['create subuser 6'] = array(
    'name' => 'create subuser 6',
    'roles' => array(),
    'module' => 'subuser',
  );

  // Exported permission: create subuser 7.
  $permissions['create subuser 7'] = array(
    'name' => 'create subuser 7',
    'roles' => array(),
    'module' => 'subuser',
  );

  // Exported permission: create subuser 8.
  $permissions['create subuser 8'] = array(
    'name' => 'create subuser 8',
    'roles' => array(),
    'module' => 'subuser',
  );

  // Exported permission: create subuser 9.
  $permissions['create subuser 9'] = array(
    'name' => 'create subuser 9',
    'roles' => array(),
    'module' => 'subuser',
  );

  // Exported permission: create url aliases.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'path',
  );

  // Exported permission: create user_registration_form content.
  $permissions['create user_registration_form content'] = array(
    'name' => 'create user_registration_form content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: customize shortcut links.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: delete any access_bundle content.
  $permissions['delete any access_bundle content'] = array(
    'name' => 'delete any access_bundle content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any downloads content.
  $permissions['delete any downloads content'] = array(
    'name' => 'delete any downloads content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any front content.
  $permissions['delete any front content'] = array(
    'name' => 'delete any front content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any kort_test content.
  $permissions['delete any kort_test content'] = array(
    'name' => 'delete any kort_test content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any page content.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any panel content.
  $permissions['delete any panel content'] = array(
    'name' => 'delete any panel content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any panel-nodes.
  $permissions['delete any panel-nodes'] = array(
    'name' => 'delete any panel-nodes',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'panels_node',
  );

  // Exported permission: delete any partner content.
  $permissions['delete any partner content'] = array(
    'name' => 'delete any partner content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any partner_list content.
  $permissions['delete any partner_list content'] = array(
    'name' => 'delete any partner_list content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any product_display content.
  $permissions['delete any product_display content'] = array(
    'name' => 'delete any product_display content',
    'roles' => array(
      0 => 'product admin',
      1 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any product_listing content.
  $permissions['delete any product_listing content'] = array(
    'name' => 'delete any product_listing content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any user_registration_form content.
  $permissions['delete any user_registration_form content'] = array(
    'name' => 'delete any user_registration_form content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own access_bundle content.
  $permissions['delete own access_bundle content'] = array(
    'name' => 'delete own access_bundle content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own downloads content.
  $permissions['delete own downloads content'] = array(
    'name' => 'delete own downloads content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own front content.
  $permissions['delete own front content'] = array(
    'name' => 'delete own front content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own kort_test content.
  $permissions['delete own kort_test content'] = array(
    'name' => 'delete own kort_test content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own page content.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own panel content.
  $permissions['delete own panel content'] = array(
    'name' => 'delete own panel content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own panel-nodes.
  $permissions['delete own panel-nodes'] = array(
    'name' => 'delete own panel-nodes',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'panels_node',
  );

  // Exported permission: delete own partner content.
  $permissions['delete own partner content'] = array(
    'name' => 'delete own partner content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own partner_list content.
  $permissions['delete own partner_list content'] = array(
    'name' => 'delete own partner_list content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own product_display content.
  $permissions['delete own product_display content'] = array(
    'name' => 'delete own product_display content',
    'roles' => array(
      0 => 'product admin',
      1 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own product_listing content.
  $permissions['delete own product_listing content'] = array(
    'name' => 'delete own product_listing content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own user_registration_form content.
  $permissions['delete own user_registration_form content'] = array(
    'name' => 'delete own user_registration_form content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: delete relations.
  $permissions['delete relations'] = array(
    'name' => 'delete relations',
    'roles' => array(),
    'module' => 'relation',
  );

  // Exported permission: delete revisions.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: delete subusers.
  $permissions['delete subusers'] = array(
    'name' => 'delete subusers',
    'roles' => array(),
    'module' => 'subuser',
  );

  // Exported permission: delete terms in 10.
  $permissions['delete terms in 10'] = array(
    'name' => 'delete terms in 10',
    'roles' => array(
      0 => 'product admin',
      1 => 'superuser',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 14.
  $permissions['delete terms in 14'] = array(
    'name' => 'delete terms in 14',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 15.
  $permissions['delete terms in 15'] = array(
    'name' => 'delete terms in 15',
    'roles' => array(
      0 => 'product admin',
      1 => 'superuser',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 16.
  $permissions['delete terms in 16'] = array(
    'name' => 'delete terms in 16',
    'roles' => array(
      0 => 'product admin',
      1 => 'superuser',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 17.
  $permissions['delete terms in 17'] = array(
    'name' => 'delete terms in 17',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 18.
  $permissions['delete terms in 18'] = array(
    'name' => 'delete terms in 18',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 2.
  $permissions['delete terms in 2'] = array(
    'name' => 'delete terms in 2',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 3.
  $permissions['delete terms in 3'] = array(
    'name' => 'delete terms in 3',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 4.
  $permissions['delete terms in 4'] = array(
    'name' => 'delete terms in 4',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 7.
  $permissions['delete terms in 7'] = array(
    'name' => 'delete terms in 7',
    'roles' => array(
      0 => 'product admin',
      1 => 'superuser',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 8.
  $permissions['delete terms in 8'] = array(
    'name' => 'delete terms in 8',
    'roles' => array(
      0 => 'product admin',
      1 => 'superuser',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 9.
  $permissions['delete terms in 9'] = array(
    'name' => 'delete terms in 9',
    'roles' => array(
      0 => 'product admin',
      1 => 'superuser',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: display drupal links.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: edit any access_bundle content.
  $permissions['edit any access_bundle content'] = array(
    'name' => 'edit any access_bundle content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any commerce_customer_profile entity.
  $permissions['edit any commerce_customer_profile entity'] = array(
    'name' => 'edit any commerce_customer_profile entity',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: edit any commerce_customer_profile entity of bundle billing.
  $permissions['edit any commerce_customer_profile entity of bundle billing'] = array(
    'name' => 'edit any commerce_customer_profile entity of bundle billing',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: edit any commerce_file_license.
  $permissions['edit any commerce_file_license'] = array(
    'name' => 'edit any commerce_file_license',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_file',
  );

  // Exported permission: edit any commerce_file_license_log.
  $permissions['edit any commerce_file_license_log'] = array(
    'name' => 'edit any commerce_file_license_log',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_file',
  );

  // Exported permission: edit any commerce_order entity.
  $permissions['edit any commerce_order entity'] = array(
    'name' => 'edit any commerce_order entity',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: edit any commerce_order entity of bundle commerce_order.
  $permissions['edit any commerce_order entity of bundle commerce_order'] = array(
    'name' => 'edit any commerce_order entity of bundle commerce_order',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: edit any commerce_product entity.
  $permissions['edit any commerce_product entity'] = array(
    'name' => 'edit any commerce_product entity',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit any commerce_product entity of bundle file_collection.
  $permissions['edit any commerce_product entity of bundle file_collection'] = array(
    'name' => 'edit any commerce_product entity of bundle file_collection',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit any commerce_product entity of bundle fme_product.
  $permissions['edit any commerce_product entity of bundle fme_product'] = array(
    'name' => 'edit any commerce_product entity of bundle fme_product',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: edit any commerce_product entity of bundle product.
  $permissions['edit any commerce_product entity of bundle product'] = array(
    'name' => 'edit any commerce_product entity of bundle product',
    'roles' => array(
      0 => 'product admin',
      1 => 'superuser',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit any downloads content.
  $permissions['edit any downloads content'] = array(
    'name' => 'edit any downloads content',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any front content.
  $permissions['edit any front content'] = array(
    'name' => 'edit any front content',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any kort_test content.
  $permissions['edit any kort_test content'] = array(
    'name' => 'edit any kort_test content',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any page content.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any panel content.
  $permissions['edit any panel content'] = array(
    'name' => 'edit any panel content',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any panel-nodes.
  $permissions['edit any panel-nodes'] = array(
    'name' => 'edit any panel-nodes',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'panels_node',
  );

  // Exported permission: edit any partner content.
  $permissions['edit any partner content'] = array(
    'name' => 'edit any partner content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any partner_list content.
  $permissions['edit any partner_list content'] = array(
    'name' => 'edit any partner_list content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any product_display content.
  $permissions['edit any product_display content'] = array(
    'name' => 'edit any product_display content',
    'roles' => array(
      0 => 'editor',
      1 => 'product admin',
      2 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any product_listing content.
  $permissions['edit any product_listing content'] = array(
    'name' => 'edit any product_listing content',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any user_registration_form content.
  $permissions['edit any user_registration_form content'] = array(
    'name' => 'edit any user_registration_form content',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: edit field_access_bundles.
  $permissions['edit field_access_bundles'] = array(
    'name' => 'edit field_access_bundles',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_address.
  $permissions['edit field_address'] = array(
    'name' => 'edit field_address',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_applications.
  $permissions['edit field_applications'] = array(
    'name' => 'edit field_applications',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_billing_address.
  $permissions['edit field_billing_address'] = array(
    'name' => 'edit field_billing_address',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_bundle_webservices_geo.
  $permissions['edit field_bundle_webservices_geo'] = array(
    'name' => 'edit field_bundle_webservices_geo',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_bundle_webservices_plot.
  $permissions['edit field_bundle_webservices_plot'] = array(
    'name' => 'edit field_bundle_webservices_plot',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_bundle_webservices_wcs.
  $permissions['edit field_bundle_webservices_wcs'] = array(
    'name' => 'edit field_bundle_webservices_wcs',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_bundle_webservices_wfs.
  $permissions['edit field_bundle_webservices_wfs'] = array(
    'name' => 'edit field_bundle_webservices_wfs',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_bundle_webservices_wms.
  $permissions['edit field_bundle_webservices_wms'] = array(
    'name' => 'edit field_bundle_webservices_wms',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_bundle_webservices_wmts.
  $permissions['edit field_bundle_webservices_wmts'] = array(
    'name' => 'edit field_bundle_webservices_wmts',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_debtor_nr.
  $permissions['edit field_debtor_nr'] = array(
    'name' => 'edit field_debtor_nr',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_expire_date.
  $permissions['edit field_expire_date'] = array(
    'name' => 'edit field_expire_date',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_ftp_permissions.
  $permissions['edit field_ftp_permissions'] = array(
    'name' => 'edit field_ftp_permissions',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_kms_user_id.
  $permissions['edit field_kms_user_id'] = array(
    'name' => 'edit field_kms_user_id',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_pass_clear.
  $permissions['edit field_pass_clear'] = array(
    'name' => 'edit field_pass_clear',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_phone.
  $permissions['edit field_phone'] = array(
    'name' => 'edit field_phone',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_predefined_datacollections.
  $permissions['edit field_predefined_datacollections'] = array(
    'name' => 'edit field_predefined_datacollections',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_terms_and_conditions.
  $permissions['edit field_terms_and_conditions'] = array(
    'name' => 'edit field_terms_and_conditions',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_updated.
  $permissions['edit field_updated'] = array(
    'name' => 'edit field_updated',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_user_remark.
  $permissions['edit field_user_remark'] = array(
    'name' => 'edit field_user_remark',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_user_type.
  $permissions['edit field_user_type'] = array(
    'name' => 'edit field_user_type',
    'roles' => array(
      0 => 'authenticated user',
      1 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_user_type_info.
  $permissions['edit field_user_type_info'] = array(
    'name' => 'edit field_user_type_info',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit meta tags.
  $permissions['edit meta tags'] = array(
    'name' => 'edit meta tags',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'metatag',
  );

  // Exported permission: edit own access_bundle content.
  $permissions['edit own access_bundle content'] = array(
    'name' => 'edit own access_bundle content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own commerce_customer_profile entities.
  $permissions['edit own commerce_customer_profile entities'] = array(
    'name' => 'edit own commerce_customer_profile entities',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: edit own commerce_customer_profile entities of bundle billing.
  $permissions['edit own commerce_customer_profile entities of bundle billing'] = array(
    'name' => 'edit own commerce_customer_profile entities of bundle billing',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: edit own commerce_order entities.
  $permissions['edit own commerce_order entities'] = array(
    'name' => 'edit own commerce_order entities',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: edit own commerce_order entities of bundle commerce_order.
  $permissions['edit own commerce_order entities of bundle commerce_order'] = array(
    'name' => 'edit own commerce_order entities of bundle commerce_order',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: edit own commerce_product entities.
  $permissions['edit own commerce_product entities'] = array(
    'name' => 'edit own commerce_product entities',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit own commerce_product entities of bundle file_collection.
  $permissions['edit own commerce_product entities of bundle file_collection'] = array(
    'name' => 'edit own commerce_product entities of bundle file_collection',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit own commerce_product entities of bundle fme_product.
  $permissions['edit own commerce_product entities of bundle fme_product'] = array(
    'name' => 'edit own commerce_product entities of bundle fme_product',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: edit own commerce_product entities of bundle product.
  $permissions['edit own commerce_product entities of bundle product'] = array(
    'name' => 'edit own commerce_product entities of bundle product',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit own downloads content.
  $permissions['edit own downloads content'] = array(
    'name' => 'edit own downloads content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own field_access_bundles.
  $permissions['edit own field_access_bundles'] = array(
    'name' => 'edit own field_access_bundles',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_address.
  $permissions['edit own field_address'] = array(
    'name' => 'edit own field_address',
    'roles' => array(
      0 => 'authenticated user',
      1 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_applications.
  $permissions['edit own field_applications'] = array(
    'name' => 'edit own field_applications',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_billing_address.
  $permissions['edit own field_billing_address'] = array(
    'name' => 'edit own field_billing_address',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_bundle_webservices_geo.
  $permissions['edit own field_bundle_webservices_geo'] = array(
    'name' => 'edit own field_bundle_webservices_geo',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_bundle_webservices_plot.
  $permissions['edit own field_bundle_webservices_plot'] = array(
    'name' => 'edit own field_bundle_webservices_plot',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_bundle_webservices_wcs.
  $permissions['edit own field_bundle_webservices_wcs'] = array(
    'name' => 'edit own field_bundle_webservices_wcs',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_bundle_webservices_wfs.
  $permissions['edit own field_bundle_webservices_wfs'] = array(
    'name' => 'edit own field_bundle_webservices_wfs',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_bundle_webservices_wms.
  $permissions['edit own field_bundle_webservices_wms'] = array(
    'name' => 'edit own field_bundle_webservices_wms',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_bundle_webservices_wmts.
  $permissions['edit own field_bundle_webservices_wmts'] = array(
    'name' => 'edit own field_bundle_webservices_wmts',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_debtor_nr.
  $permissions['edit own field_debtor_nr'] = array(
    'name' => 'edit own field_debtor_nr',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_expire_date.
  $permissions['edit own field_expire_date'] = array(
    'name' => 'edit own field_expire_date',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_ftp_permissions.
  $permissions['edit own field_ftp_permissions'] = array(
    'name' => 'edit own field_ftp_permissions',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_kms_user_id.
  $permissions['edit own field_kms_user_id'] = array(
    'name' => 'edit own field_kms_user_id',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_pass_clear.
  $permissions['edit own field_pass_clear'] = array(
    'name' => 'edit own field_pass_clear',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_phone.
  $permissions['edit own field_phone'] = array(
    'name' => 'edit own field_phone',
    'roles' => array(
      0 => 'authenticated user',
      1 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_predefined_datacollections.
  $permissions['edit own field_predefined_datacollections'] = array(
    'name' => 'edit own field_predefined_datacollections',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_terms_and_conditions.
  $permissions['edit own field_terms_and_conditions'] = array(
    'name' => 'edit own field_terms_and_conditions',
    'roles' => array(
      0 => 'authenticated user',
      1 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_updated.
  $permissions['edit own field_updated'] = array(
    'name' => 'edit own field_updated',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_user_remark.
  $permissions['edit own field_user_remark'] = array(
    'name' => 'edit own field_user_remark',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_user_type.
  $permissions['edit own field_user_type'] = array(
    'name' => 'edit own field_user_type',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_user_type_info.
  $permissions['edit own field_user_type_info'] = array(
    'name' => 'edit own field_user_type_info',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own front content.
  $permissions['edit own front content'] = array(
    'name' => 'edit own front content',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own kort_test content.
  $permissions['edit own kort_test content'] = array(
    'name' => 'edit own kort_test content',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own page content.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own panel content.
  $permissions['edit own panel content'] = array(
    'name' => 'edit own panel content',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own panel-nodes.
  $permissions['edit own panel-nodes'] = array(
    'name' => 'edit own panel-nodes',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'panels_node',
  );

  // Exported permission: edit own partner content.
  $permissions['edit own partner content'] = array(
    'name' => 'edit own partner content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own partner_list content.
  $permissions['edit own partner_list content'] = array(
    'name' => 'edit own partner_list content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own product_display content.
  $permissions['edit own product_display content'] = array(
    'name' => 'edit own product_display content',
    'roles' => array(
      0 => 'product admin',
      1 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own product_listing content.
  $permissions['edit own product_listing content'] = array(
    'name' => 'edit own product_listing content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own user_registration_form content.
  $permissions['edit own user_registration_form content'] = array(
    'name' => 'edit own user_registration_form content',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: edit relations.
  $permissions['edit relations'] = array(
    'name' => 'edit relations',
    'roles' => array(),
    'module' => 'relation',
  );

  // Exported permission: edit subusers.
  $permissions['edit subusers'] = array(
    'name' => 'edit subusers',
    'roles' => array(),
    'module' => 'subuser',
  );

  // Exported permission: edit terms in 10.
  $permissions['edit terms in 10'] = array(
    'name' => 'edit terms in 10',
    'roles' => array(
      0 => 'product admin',
      1 => 'superuser',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 14.
  $permissions['edit terms in 14'] = array(
    'name' => 'edit terms in 14',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 15.
  $permissions['edit terms in 15'] = array(
    'name' => 'edit terms in 15',
    'roles' => array(
      0 => 'product admin',
      1 => 'superuser',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 16.
  $permissions['edit terms in 16'] = array(
    'name' => 'edit terms in 16',
    'roles' => array(
      0 => 'product admin',
      1 => 'superuser',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 17.
  $permissions['edit terms in 17'] = array(
    'name' => 'edit terms in 17',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 18.
  $permissions['edit terms in 18'] = array(
    'name' => 'edit terms in 18',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 2.
  $permissions['edit terms in 2'] = array(
    'name' => 'edit terms in 2',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 3.
  $permissions['edit terms in 3'] = array(
    'name' => 'edit terms in 3',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 4.
  $permissions['edit terms in 4'] = array(
    'name' => 'edit terms in 4',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 7.
  $permissions['edit terms in 7'] = array(
    'name' => 'edit terms in 7',
    'roles' => array(
      0 => 'product admin',
      1 => 'superuser',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 8.
  $permissions['edit terms in 8'] = array(
    'name' => 'edit terms in 8',
    'roles' => array(
      0 => 'product admin',
      1 => 'superuser',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 9.
  $permissions['edit terms in 9'] = array(
    'name' => 'edit terms in 9',
    'roles' => array(
      0 => 'product admin',
      1 => 'superuser',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: execute php code.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(),
    'module' => 'devel',
  );

  // Exported permission: export relation types.
  $permissions['export relation types'] = array(
    'name' => 'export relation types',
    'roles' => array(),
    'module' => 'relation',
  );

  // Exported permission: export taxonomy by csv.
  $permissions['export taxonomy by csv'] = array(
    'name' => 'export taxonomy by csv',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'taxonomy_csv',
  );

  // Exported permission: flush caches.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: grant content access.
  $permissions['grant content access'] = array(
    'name' => 'grant content access',
    'roles' => array(),
    'module' => 'content_access',
  );

  // Exported permission: grant own content access.
  $permissions['grant own content access'] = array(
    'name' => 'grant own content access',
    'roles' => array(),
    'module' => 'content_access',
  );

  // Exported permission: import taxonomy by csv.
  $permissions['import taxonomy by csv'] = array(
    'name' => 'import taxonomy by csv',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'taxonomy_csv',
  );

  // Exported permission: manage features.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'features',
  );

  // Exported permission: masquerade as admin.
  $permissions['masquerade as admin'] = array(
    'name' => 'masquerade as admin',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: masquerade as user.
  $permissions['masquerade as user'] = array(
    'name' => 'masquerade as user',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: migration information.
  $permissions['migration information'] = array(
    'name' => 'migration information',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'migrate_ui',
  );

  // Exported permission: notify of path changes.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: opt-in or out of tracking.
  $permissions['opt-in or out of tracking'] = array(
    'name' => 'opt-in or out of tracking',
    'roles' => array(),
    'module' => 'googleanalytics',
  );

  // Exported permission: override subuser relation.
  $permissions['override subuser relation'] = array(
    'name' => 'override subuser relation',
    'roles' => array(),
    'module' => 'subuser',
  );

  // Exported permission: revert revisions.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: search content.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
      2 => 'superuser',
    ),
    'module' => 'search',
  );

  // Exported permission: select account cancellation method.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'user',
  );

  // Exported permission: switch shortcut sets.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: switch users.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(),
    'module' => 'devel',
  );

  // Exported permission: translate content.
  $permissions['translate content'] = array(
    'name' => 'translate content',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'translation',
  );

  // Exported permission: translate interface.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'locale',
  );

  // Exported permission: use PHP for settings.
  $permissions['use PHP for settings'] = array(
    'name' => 'use PHP for settings',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'php',
  );

  // Exported permission: use PHP for tracking visibility.
  $permissions['use PHP for tracking visibility'] = array(
    'name' => 'use PHP for tracking visibility',
    'roles' => array(),
    'module' => 'googleanalytics',
  );

  // Exported permission: use advanced search.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'search',
  );

  // Exported permission: use page manager.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: use panels caching features.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'panels',
  );

  // Exported permission: use panels dashboard.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'panels',
  );

  // Exported permission: use panels in place editing.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'panels',
  );

  // Exported permission: use panels locks.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'panels',
  );

  // Exported permission: use text format ds_code.
  $permissions['use text format ds_code'] = array(
    'name' => 'use text format ds_code',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format filtered_html.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      0 => 'editor',
      1 => 'product admin',
      2 => 'superuser',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format php_code.
  $permissions['use text format php_code'] = array(
    'name' => 'use text format php_code',
    'roles' => array(
      0 => 'authenticated user',
      1 => 'superuser',
    ),
    'module' => 'filter',
  );

  // Exported permission: view any commerce_customer_profile entity.
  $permissions['view any commerce_customer_profile entity'] = array(
    'name' => 'view any commerce_customer_profile entity',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: view any commerce_customer_profile entity of bundle billing.
  $permissions['view any commerce_customer_profile entity of bundle billing'] = array(
    'name' => 'view any commerce_customer_profile entity of bundle billing',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: view any commerce_order entity.
  $permissions['view any commerce_order entity'] = array(
    'name' => 'view any commerce_order entity',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: view any commerce_order entity of bundle commerce_order.
  $permissions['view any commerce_order entity of bundle commerce_order'] = array(
    'name' => 'view any commerce_order entity of bundle commerce_order',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: view any commerce_product entity.
  $permissions['view any commerce_product entity'] = array(
    'name' => 'view any commerce_product entity',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view any commerce_product entity of bundle file_collection.
  $permissions['view any commerce_product entity of bundle file_collection'] = array(
    'name' => 'view any commerce_product entity of bundle file_collection',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
      2 => 'superuser',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view any commerce_product entity of bundle fme_product.
  $permissions['view any commerce_product entity of bundle fme_product'] = array(
    'name' => 'view any commerce_product entity of bundle fme_product',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: view any commerce_product entity of bundle product.
  $permissions['view any commerce_product entity of bundle product'] = array(
    'name' => 'view any commerce_product entity of bundle product',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
      2 => 'product admin',
      3 => 'superuser',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view field_access_bundles.
  $permissions['view field_access_bundles'] = array(
    'name' => 'view field_access_bundles',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_address.
  $permissions['view field_address'] = array(
    'name' => 'view field_address',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_applications.
  $permissions['view field_applications'] = array(
    'name' => 'view field_applications',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_billing_address.
  $permissions['view field_billing_address'] = array(
    'name' => 'view field_billing_address',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_bundle_webservices_geo.
  $permissions['view field_bundle_webservices_geo'] = array(
    'name' => 'view field_bundle_webservices_geo',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_bundle_webservices_plot.
  $permissions['view field_bundle_webservices_plot'] = array(
    'name' => 'view field_bundle_webservices_plot',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_bundle_webservices_wcs.
  $permissions['view field_bundle_webservices_wcs'] = array(
    'name' => 'view field_bundle_webservices_wcs',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_bundle_webservices_wfs.
  $permissions['view field_bundle_webservices_wfs'] = array(
    'name' => 'view field_bundle_webservices_wfs',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_bundle_webservices_wms.
  $permissions['view field_bundle_webservices_wms'] = array(
    'name' => 'view field_bundle_webservices_wms',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_bundle_webservices_wmts.
  $permissions['view field_bundle_webservices_wmts'] = array(
    'name' => 'view field_bundle_webservices_wmts',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_debtor_nr.
  $permissions['view field_debtor_nr'] = array(
    'name' => 'view field_debtor_nr',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_expire_date.
  $permissions['view field_expire_date'] = array(
    'name' => 'view field_expire_date',
    'roles' => array(
      0 => 'authenticated user',
      1 => 'editor',
      2 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_ftp_permissions.
  $permissions['view field_ftp_permissions'] = array(
    'name' => 'view field_ftp_permissions',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_kms_user_id.
  $permissions['view field_kms_user_id'] = array(
    'name' => 'view field_kms_user_id',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_pass_clear.
  $permissions['view field_pass_clear'] = array(
    'name' => 'view field_pass_clear',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_phone.
  $permissions['view field_phone'] = array(
    'name' => 'view field_phone',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_predefined_datacollections.
  $permissions['view field_predefined_datacollections'] = array(
    'name' => 'view field_predefined_datacollections',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_terms_and_conditions.
  $permissions['view field_terms_and_conditions'] = array(
    'name' => 'view field_terms_and_conditions',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_updated.
  $permissions['view field_updated'] = array(
    'name' => 'view field_updated',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_user_remark.
  $permissions['view field_user_remark'] = array(
    'name' => 'view field_user_remark',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_user_type.
  $permissions['view field_user_type'] = array(
    'name' => 'view field_user_type',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_user_type_info.
  $permissions['view field_user_type_info'] = array(
    'name' => 'view field_user_type_info',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own commerce_customer_profile entities.
  $permissions['view own commerce_customer_profile entities'] = array(
    'name' => 'view own commerce_customer_profile entities',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: view own commerce_customer_profile entities of bundle billing.
  $permissions['view own commerce_customer_profile entities of bundle billing'] = array(
    'name' => 'view own commerce_customer_profile entities of bundle billing',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: view own commerce_order entities.
  $permissions['view own commerce_order entities'] = array(
    'name' => 'view own commerce_order entities',
    'roles' => array(
      0 => 'authenticated user',
      1 => 'superuser',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: view own commerce_order entities of bundle commerce_order.
  $permissions['view own commerce_order entities of bundle commerce_order'] = array(
    'name' => 'view own commerce_order entities of bundle commerce_order',
    'roles' => array(
      0 => 'authenticated user',
      1 => 'superuser',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: view own commerce_product entities.
  $permissions['view own commerce_product entities'] = array(
    'name' => 'view own commerce_product entities',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view own commerce_product entities of bundle file_collection.
  $permissions['view own commerce_product entities of bundle file_collection'] = array(
    'name' => 'view own commerce_product entities of bundle file_collection',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view own commerce_product entities of bundle fme_product.
  $permissions['view own commerce_product entities of bundle fme_product'] = array(
    'name' => 'view own commerce_product entities of bundle fme_product',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: view own commerce_product entities of bundle product.
  $permissions['view own commerce_product entities of bundle product'] = array(
    'name' => 'view own commerce_product entities of bundle product',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view own field_access_bundles.
  $permissions['view own field_access_bundles'] = array(
    'name' => 'view own field_access_bundles',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_address.
  $permissions['view own field_address'] = array(
    'name' => 'view own field_address',
    'roles' => array(
      0 => 'authenticated user',
      1 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_applications.
  $permissions['view own field_applications'] = array(
    'name' => 'view own field_applications',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_billing_address.
  $permissions['view own field_billing_address'] = array(
    'name' => 'view own field_billing_address',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_bundle_webservices_geo.
  $permissions['view own field_bundle_webservices_geo'] = array(
    'name' => 'view own field_bundle_webservices_geo',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_bundle_webservices_plot.
  $permissions['view own field_bundle_webservices_plot'] = array(
    'name' => 'view own field_bundle_webservices_plot',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_bundle_webservices_wcs.
  $permissions['view own field_bundle_webservices_wcs'] = array(
    'name' => 'view own field_bundle_webservices_wcs',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_bundle_webservices_wfs.
  $permissions['view own field_bundle_webservices_wfs'] = array(
    'name' => 'view own field_bundle_webservices_wfs',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_bundle_webservices_wms.
  $permissions['view own field_bundle_webservices_wms'] = array(
    'name' => 'view own field_bundle_webservices_wms',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_bundle_webservices_wmts.
  $permissions['view own field_bundle_webservices_wmts'] = array(
    'name' => 'view own field_bundle_webservices_wmts',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_debtor_nr.
  $permissions['view own field_debtor_nr'] = array(
    'name' => 'view own field_debtor_nr',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_expire_date.
  $permissions['view own field_expire_date'] = array(
    'name' => 'view own field_expire_date',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_ftp_permissions.
  $permissions['view own field_ftp_permissions'] = array(
    'name' => 'view own field_ftp_permissions',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_kms_user_id.
  $permissions['view own field_kms_user_id'] = array(
    'name' => 'view own field_kms_user_id',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_pass_clear.
  $permissions['view own field_pass_clear'] = array(
    'name' => 'view own field_pass_clear',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_phone.
  $permissions['view own field_phone'] = array(
    'name' => 'view own field_phone',
    'roles' => array(
      0 => 'authenticated user',
      1 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_predefined_datacollections.
  $permissions['view own field_predefined_datacollections'] = array(
    'name' => 'view own field_predefined_datacollections',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_terms_and_conditions.
  $permissions['view own field_terms_and_conditions'] = array(
    'name' => 'view own field_terms_and_conditions',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
      2 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_updated.
  $permissions['view own field_updated'] = array(
    'name' => 'view own field_updated',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_user_remark.
  $permissions['view own field_user_remark'] = array(
    'name' => 'view own field_user_remark',
    'roles' => array(
      0 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_user_type.
  $permissions['view own field_user_type'] = array(
    'name' => 'view own field_user_type',
    'roles' => array(
      0 => 'authenticated user',
      1 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_user_type_info.
  $permissions['view own field_user_type_info'] = array(
    'name' => 'view own field_user_type_info',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'superuser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own unpublished content.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      0 => 'editor',
      1 => 'product admin',
      2 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: view pane admin links.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'panels',
  );

  // Exported permission: view revisions.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      0 => 'editor',
      1 => 'superuser',
    ),
    'module' => 'node',
  );

  // Exported permission: view subusers.
  $permissions['view subusers'] = array(
    'name' => 'view subusers',
    'roles' => array(),
    'module' => 'subuser',
  );

  // Exported permission: view the administration theme.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      0 => 'editor',
      1 => 'product admin',
      2 => 'superuser',
    ),
    'module' => 'system',
  );

  return $permissions;
}
