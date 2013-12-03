<?php
/**
 * @file
 * user_fields.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function user_fields_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_access_bundles|user|user|form';
  $field_group->group_name = 'group_access_bundles';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Access bundles',
    'weight' => '4',
    'children' => array(
      0 => 'field_access_bundles',
      1 => 'group_webservices',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_access_bundles|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bundles_n_services|user|user|form';
  $field_group->group_name = 'group_bundles_n_services';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bundles and services',
    'weight' => '3',
    'children' => array(
      0 => 'field_bundles',
      1 => 'field_webservices_extra',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Bundles and services',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_bundles_n_services|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_default_fields|user|user|form';
  $field_group->group_name = 'group_default_fields';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Standard felter',
    'weight' => '6',
    'children' => array(
      0 => 'metatags',
      1 => 'timezone',
      2 => 'locale',
      3 => 'wysiwyg',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Standard felter',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_default_fields|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_master_data|user|user|form';
  $field_group->group_name = 'group_master_data';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Stamdata',
    'weight' => '1',
    'children' => array(
      0 => 'field_phone',
      1 => 'field_pass_clear',
      2 => 'field_billing_address',
      3 => 'field_address',
      4 => 'account',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Stamdata',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_master_data|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_navision|user|user|form';
  $field_group->group_name = 'group_navision';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Navision',
    'weight' => '2',
    'children' => array(
      0 => 'field_kms_user_id',
      1 => 'field_debtor_nr',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Navision',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_navision|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_options|user|user|form';
  $field_group->group_name = 'group_options';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Valg',
    'weight' => '7',
    'children' => array(
      0 => 'field_newsletter',
      1 => 'field_contact_me',
      2 => 'field_terms_and_conditions',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Valg',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_options|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_other|user|user|form';
  $field_group->group_name = 'group_other';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Andet',
    'weight' => '5',
    'children' => array(
      0 => 'field_user_remark',
      1 => 'field_updated',
      2 => 'field_expire_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Andet',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_other|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_type|user|user|form';
  $field_group->group_name = 'group_user_type';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Brugertype',
    'weight' => '0',
    'children' => array(
      0 => 'field_user_type_info',
      1 => 'field_user_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Brugertype',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_user_type|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_webservices_geo|user|user|form';
  $field_group->group_name = 'group_webservices_geo';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_webservices';
  $field_group->data = array(
    'label' => 'GEO',
    'weight' => '48',
    'children' => array(
      0 => 'field_bundle_webservices_geo',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_webservices_geo|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_webservices_plot|user|user|form';
  $field_group->group_name = 'group_webservices_plot';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_webservices';
  $field_group->data = array(
    'label' => 'PLOT',
    'weight' => '53',
    'children' => array(
      0 => 'field_bundle_webservices_plot',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_webservices_plot|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_webservices_wcs|user|user|form';
  $field_group->group_name = 'group_webservices_wcs';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_webservices';
  $field_group->data = array(
    'label' => 'WCS',
    'weight' => '51',
    'children' => array(
      0 => 'field_bundle_webservices_wcs',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_webservices_wcs|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_webservices_wfs|user|user|form';
  $field_group->group_name = 'group_webservices_wfs';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_webservices';
  $field_group->data = array(
    'label' => 'WFS',
    'weight' => '52',
    'children' => array(
      0 => 'field_bundle_webservices_wfs',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_webservices_wfs|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_webservices_wms|user|user|form';
  $field_group->group_name = 'group_webservices_wms';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_webservices';
  $field_group->data = array(
    'label' => 'WMS',
    'weight' => '49',
    'children' => array(
      0 => 'field_bundle_webservices_wms',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_webservices_wms|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_webservices_wmts|user|user|form';
  $field_group->group_name = 'group_webservices_wmts';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_webservices';
  $field_group->data = array(
    'label' => 'WMTS',
    'weight' => '50',
    'children' => array(
      0 => 'field_bundle_webservices_wmts',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_webservices_wmts|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_webservices|user|user|form';
  $field_group->group_name = 'group_webservices';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_access_bundles';
  $field_group->data = array(
    'label' => 'Webservices',
    'weight' => '9',
    'children' => array(
      0 => 'group_webservices_geo',
      1 => 'group_webservices_wfs',
      2 => 'group_webservices_plot',
      3 => 'group_webservices_wms',
      4 => 'group_webservices_wmts',
      5 => 'group_webservices_wcs',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'label' => 'Webservices',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_webservices|user|user|form'] = $field_group;

  return $export;
}
