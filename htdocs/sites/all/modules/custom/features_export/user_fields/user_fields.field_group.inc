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
    'weight' => '5',
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
      0 => 'field_pass_clear',
      1 => 'field_address',
      2 => 'field_phone',
      3 => 'field_billing_address',
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
      0 => 'field_debtor_nr',
      1 => 'field_kms_user_id',
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
    'weight' => '6',
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
    'weight' => '4',
    'children' => array(
      0 => 'field_updated',
      1 => 'field_user_remark',
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

  return $export;
}
