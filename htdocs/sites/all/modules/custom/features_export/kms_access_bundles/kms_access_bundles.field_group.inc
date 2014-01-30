<?php
/**
 * @file
 * kms_access_bundles.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function kms_access_bundles_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_range_size|node|access_bundle|form';
  $field_group->group_name = 'group_range_size';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'access_bundle';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Range size',
    'weight' => '5',
    'children' => array(
      0 => 'field_bundle_maxpixelheight',
      1 => 'field_bundle_maxpixelwidth',
      2 => 'field_bundle_maxx',
      3 => 'field_bundle_maxy',
      4 => 'field_bundle_minx',
      5 => 'field_bundle_miny',
      6 => 'field_bundle_featureinfo',
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
  $export['group_range_size|node|access_bundle|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_applications|node|access_bundle|form';
  $field_group->group_name = 'group_tab_applications';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'access_bundle';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_webservices';
  $field_group->data = array(
    'label' => 'Applications',
    'weight' => '27',
    'children' => array(
      0 => 'field_applications',
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
  $export['group_tab_applications|node|access_bundle|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_ftp|node|access_bundle|form';
  $field_group->group_name = 'group_tab_ftp';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'access_bundle';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_webservices';
  $field_group->data = array(
    'label' => 'FTP',
    'weight' => '28',
    'children' => array(
      0 => 'field_ftp_permissions',
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
  $export['group_tab_ftp|node|access_bundle|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tab_predefined|node|access_bundle|form';
  $field_group->group_name = 'group_tab_predefined';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'access_bundle';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_webservices';
  $field_group->data = array(
    'label' => 'Predefined datacollections',
    'weight' => '26',
    'children' => array(
      0 => 'field_predefined_datacollections',
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
  $export['group_tab_predefined|node|access_bundle|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_webservices_geo|node|access_bundle|form';
  $field_group->group_name = 'group_webservices_geo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'access_bundle';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_webservices';
  $field_group->data = array(
    'label' => 'GEO',
    'weight' => '20',
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
  $export['group_webservices_geo|node|access_bundle|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_webservices_plot|node|access_bundle|form';
  $field_group->group_name = 'group_webservices_plot';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'access_bundle';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_webservices';
  $field_group->data = array(
    'label' => 'PLOT',
    'weight' => '25',
    'children' => array(
      0 => 'field_bundle_webservices_plot',
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
  $export['group_webservices_plot|node|access_bundle|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_webservices_wcs|node|access_bundle|form';
  $field_group->group_name = 'group_webservices_wcs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'access_bundle';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_webservices';
  $field_group->data = array(
    'label' => 'WCS',
    'weight' => '23',
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
  $export['group_webservices_wcs|node|access_bundle|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_webservices_wfs|node|access_bundle|form';
  $field_group->group_name = 'group_webservices_wfs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'access_bundle';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_webservices';
  $field_group->data = array(
    'label' => 'WFS',
    'weight' => '21',
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
  $export['group_webservices_wfs|node|access_bundle|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_webservices_wms|node|access_bundle|form';
  $field_group->group_name = 'group_webservices_wms';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'access_bundle';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_webservices';
  $field_group->data = array(
    'label' => 'WMS',
    'weight' => '24',
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
  $export['group_webservices_wms|node|access_bundle|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_webservices_wmts|node|access_bundle|form';
  $field_group->group_name = 'group_webservices_wmts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'access_bundle';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_webservices';
  $field_group->data = array(
    'label' => 'WMTS',
    'weight' => '22',
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
  $export['group_webservices_wmts|node|access_bundle|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_webservices|node|access_bundle|form';
  $field_group->group_name = 'group_webservices';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'access_bundle';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Webservices',
    'weight' => '7',
    'children' => array(
      0 => 'group_tab_ftp',
      1 => 'group_tab_applications',
      2 => 'group_tab_predefined',
      3 => 'group_webservices_geo',
      4 => 'group_webservices_wmts',
      5 => 'group_webservices_plot',
      6 => 'group_webservices_wcs',
      7 => 'group_webservices_wfs',
      8 => 'group_webservices_wms',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_webservices|node|access_bundle|form'] = $field_group;

  return $export;
}
