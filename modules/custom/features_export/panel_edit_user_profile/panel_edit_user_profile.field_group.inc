<?php
/**
 * @file
 * panel_edit_user_profile.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function panel_edit_user_profile_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rss_1|config_pages|my_subscriptions_rss|form';
  $field_group->group_name = 'group_rss_1';
  $field_group->entity_type = 'config_pages';
  $field_group->bundle = 'my_subscriptions_rss';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'RSS feed 1',
    'weight' => '3',
    'children' => array(
      0 => 'field_rss_feed_1',
      1 => 'field_rss_title_1',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'RSS feed 1',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_rss_1|config_pages|my_subscriptions_rss|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rss_2|config_pages|my_subscriptions_rss|form';
  $field_group->group_name = 'group_rss_2';
  $field_group->entity_type = 'config_pages';
  $field_group->bundle = 'my_subscriptions_rss';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'RSS feed 2',
    'weight' => '4',
    'children' => array(
      0 => 'field_rss_title_2',
      1 => 'field_rss_feed_2',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'RSS feed 2',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_rss_2|config_pages|my_subscriptions_rss|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rss_text|config_pages|my_subscriptions_rss|form';
  $field_group->group_name = 'group_rss_text';
  $field_group->entity_type = 'config_pages';
  $field_group->bundle = 'my_subscriptions_rss';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Text',
    'weight' => '0',
    'children' => array(
      0 => 'field_config_page_body',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_rss_text|config_pages|my_subscriptions_rss|form'] = $field_group;

  return $export;
}
