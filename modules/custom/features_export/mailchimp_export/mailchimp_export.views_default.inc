<?php
/**
 * @file
 * mailchimp_export.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function mailchimp_export_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'export_users_with_consent';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Export users with consent';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Export users to mailchimp';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer users';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'mail' => 'mail',
    'field_address_last_name' => 'field_address_last_name',
    'field_address_first_name' => 'field_address_first_name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_address_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_address_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Brugernavn';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Address - Efternavn */
  $handler->display->display_options['fields']['field_address_last_name']['id'] = 'field_address_last_name';
  $handler->display->display_options['fields']['field_address_last_name']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_last_name']['field'] = 'field_address_last_name';
  $handler->display->display_options['fields']['field_address_last_name']['label'] = 'Efternavn';
  $handler->display->display_options['fields']['field_address_last_name']['element_label_colon'] = FALSE;
  /* Field: User: Address - Fornavn */
  $handler->display->display_options['fields']['field_address_first_name']['id'] = 'field_address_first_name';
  $handler->display->display_options['fields']['field_address_first_name']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_first_name']['field'] = 'field_address_first_name';
  $handler->display->display_options['fields']['field_address_first_name']['label'] = 'Fornavn';
  $handler->display->display_options['fields']['field_address_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Brugertype */
  $handler->display->display_options['fields']['field_user_type']['id'] = 'field_user_type';
  $handler->display->display_options['fields']['field_user_type']['table'] = 'field_data_field_user_type';
  $handler->display->display_options['fields']['field_user_type']['field'] = 'field_user_type';
  $handler->display->display_options['fields']['field_user_type']['label'] = 'Type1';
  $handler->display->display_options['fields']['field_user_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_type']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_user_type']['delta_offset'] = '0';
  /* Field: User: Brugertype */
  $handler->display->display_options['fields']['field_user_type_1']['id'] = 'field_user_type_1';
  $handler->display->display_options['fields']['field_user_type_1']['table'] = 'field_data_field_user_type';
  $handler->display->display_options['fields']['field_user_type_1']['field'] = 'field_user_type';
  $handler->display->display_options['fields']['field_user_type_1']['label'] = 'Type2';
  $handler->display->display_options['fields']['field_user_type_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_type_1']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_type_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_user_type_1']['delta_offset'] = '1';
  /* Field: User: Brugertype */
  $handler->display->display_options['fields']['field_user_type_2']['id'] = 'field_user_type_2';
  $handler->display->display_options['fields']['field_user_type_2']['table'] = 'field_data_field_user_type';
  $handler->display->display_options['fields']['field_user_type_2']['field'] = 'field_user_type';
  $handler->display->display_options['fields']['field_user_type_2']['label'] = 'Type3';
  $handler->display->display_options['fields']['field_user_type_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_type_2']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_type_2']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_user_type_2']['delta_offset'] = '2';
  /* Field: User: Brugertype */
  $handler->display->display_options['fields']['field_user_type_3']['id'] = 'field_user_type_3';
  $handler->display->display_options['fields']['field_user_type_3']['table'] = 'field_data_field_user_type';
  $handler->display->display_options['fields']['field_user_type_3']['field'] = 'field_user_type';
  $handler->display->display_options['fields']['field_user_type_3']['label'] = 'Type4';
  $handler->display->display_options['fields']['field_user_type_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_type_3']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_type_3']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_user_type_3']['delta_offset'] = '3';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Aktiv */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Geodatastyrelsen må gerne kontakte mig i forbindelse med tilfredshed- og brugerundersøgelser (field_contact_me) */
  $handler->display->display_options['filters']['field_contact_me_value']['id'] = 'field_contact_me_value';
  $handler->display->display_options['filters']['field_contact_me_value']['table'] = 'field_data_field_contact_me';
  $handler->display->display_options['filters']['field_contact_me_value']['field'] = 'field_contact_me_value';
  $handler->display->display_options['filters']['field_contact_me_value']['value'] = array(
    1 => '1',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/people/users-with-consent';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Export users to mailchimp';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'admin/people/mailchimp';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $translatables['export_users_with_consent'] = array(
    t('Master'),
    t('Export users to mailchimp'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Brugernavn'),
    t('E-mail'),
    t('Efternavn'),
    t('Fornavn'),
    t('Type1'),
    t('Type2'),
    t('Type3'),
    t('Type4'),
    t('Page'),
    t('Data export'),
  );
  $export['export_users_with_consent'] = $view;

  return $export;
}
