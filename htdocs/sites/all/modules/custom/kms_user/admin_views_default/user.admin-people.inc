<?php

/**
 * @file
 * Default view for user administration.
 */

$view = new view();
$view->name = 'admin_views_user';
$view->description = 'List, add, and edit users.';
$view->tag = 'admin';
$view->base_table = 'users';
$view->human_name = 'Administration: Users';
$view->core = 0;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Defaults */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->display->display_options['title'] = 'Users';
$handler->display->display_options['css_class'] = 'admin-views-view';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'menu';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
$handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
$handler->display->display_options['exposed_form']['options']['bef'] = array(
  'general' => array(
    'allow_secondary' => 0,
    'secondary_label' => 'Advanced options',
  ),
  'name' => array(
    'more_options' => array(
      'is_secondary' => 0,
      'bef_filter_description' => '',
      'tokens' => array(
        'available' => array(
          0 => 'global_types',
        ),
      ),
    ),
  ),
  'mail' => array(
    'more_options' => array(
      'is_secondary' => 0,
      'bef_filter_description' => '',
      'tokens' => array(
        'available' => array(
          0 => 'global_types',
        ),
      ),
    ),
  ),
  'rid' => array(
    'bef_format' => 'default',
    'more_options' => array(
      'bef_select_all_none' => FALSE,
      'bef_collapsible' => 0,
      'is_secondary' => 0,
      'bef_filter_description' => '',
      'tokens' => array(
        'available' => array(
          0 => 'global_types',
        ),
      ),
    ),
  ),
  'field_user_type_tid' => array(
    'bef_format' => 'default',
    'more_options' => array(
      'bef_select_all_none' => FALSE,
      'bef_collapsible' => 0,
      'is_secondary' => 0,
      'bef_filter_description' => '',
      'tokens' => array(
        'available' => array(
          0 => 'global_types',
        ),
      ),
    ),
  ),
  'created' => array(
    'bef_format' => 'bef_datepicker',
    'more_options' => array(
      'is_secondary' => 0,
      'bef_filter_description' => 'Select a range for the created date',
      'tokens' => array(
        'available' => array(
          0 => 'global_types',
        ),
      ),
    ),
  ),
  'status' => array(
    'bef_format' => 'default',
    'more_options' => array(
      'bef_select_all_none' => FALSE,
      'bef_collapsible' => 0,
      'is_secondary' => 0,
      'bef_filter_description' => '',
      'tokens' => array(
        'available' => array(
          0 => 'global_types',
        ),
      ),
    ),
  ),
);
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '25';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
$handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Users per page';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '25, 50, 75, 100';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'views_bulk_operations' => 'views_bulk_operations',
  'name' => 'name',
  'mail' => 'name',
  'status' => 'status',
  'rid' => 'rid',
  'created' => 'created',
  'access' => 'access',
  'edit_node' => 'edit_node',
  'cancel_node' => 'cancel_node',
);
$handler->display->display_options['style_options']['default'] = 'access';
$handler->display->display_options['style_options']['info'] = array(
  'views_bulk_operations' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '<br />',
    'empty_column' => 0,
  ),
  'mail' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'status' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'rid' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'created' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'access' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'edit_node' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'cancel_node' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['sticky'] = TRUE;
$handler->display->display_options['style_options']['empty_table'] = TRUE;
/* No results behavior: Global: Unfiltered text */
$handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
$handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
$handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
$handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
$handler->display->display_options['empty']['area_text_custom']['content'] = 'No users available.';
/* Field: Bulk operations: User */
$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
$handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_result'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
  'action::system_block_ip_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 1,
    'override_label' => 1,
    'label' => 'Ban IP address of the current user',
  ),
  'action::user_block_user_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 1,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_delete_item' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 1,
    'label' => 'Delete',
  ),
  'action::views_bulk_operations_modify_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 1,
    'override_label' => 1,
    'label' => 'Change value',
    'settings' => array(
      'show_all_tokens' => 1,
      'display_values' => array(
        '_all_' => '_all_',
      ),
    ),
  ),
  'action::system_message_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_script_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_user_roles_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 1,
    'label' => 'Change user roles',
  ),
  'action::views_bulk_operations_argument_selector_action' => array(
    'selected' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'settings' => array(
      'url' => '',
    ),
  ),
  'action::system_goto_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::system_send_email_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 1,
    'label' => 'Send e-mail',
  ),
);
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
/* Field: User: Bundles */
$handler->display->display_options['fields']['field_access_bundles']['id'] = 'field_access_bundles';
$handler->display->display_options['fields']['field_access_bundles']['table'] = 'field_data_field_access_bundles';
$handler->display->display_options['fields']['field_access_bundles']['field'] = 'field_access_bundles';
$handler->display->display_options['fields']['field_access_bundles']['type'] = 'kms_permissions_bundles_reference';
$handler->display->display_options['fields']['field_access_bundles']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_access_bundles']['multi_type'] = 'ul';
/* Field: User: E-mail */
$handler->display->display_options['fields']['mail']['id'] = 'mail';
$handler->display->display_options['fields']['mail']['table'] = 'users';
$handler->display->display_options['fields']['mail']['field'] = 'mail';
$handler->display->display_options['fields']['mail']['label'] = '';
$handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['mail']['link_to_user'] = '0';
/* Field: User: Aktiv */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'users';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['not'] = 0;
/* Field: User: Roles */
$handler->display->display_options['fields']['rid']['id'] = 'rid';
$handler->display->display_options['fields']['rid']['table'] = 'users_roles';
$handler->display->display_options['fields']['rid']['field'] = 'rid';
$handler->display->display_options['fields']['rid']['type'] = 'ul';
/* Field: User: Created date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'users';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Member since';
$handler->display->display_options['fields']['created']['date_format'] = 'short';
/* Field: User: Last access */
$handler->display->display_options['fields']['access']['id'] = 'access';
$handler->display->display_options['fields']['access']['table'] = 'users';
$handler->display->display_options['fields']['access']['field'] = 'access';
$handler->display->display_options['fields']['access']['date_format'] = 'time ago';
/* Field: User: Edit link */
$handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['table'] = 'users';
$handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['label'] = '';
/* Field: User: Cancel link */
$handler->display->display_options['fields']['cancel_node']['id'] = 'cancel_node';
$handler->display->display_options['fields']['cancel_node']['table'] = 'users';
$handler->display->display_options['fields']['cancel_node']['field'] = 'cancel_node';
$handler->display->display_options['fields']['cancel_node']['label'] = '';
$handler->display->display_options['fields']['cancel_node']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['cancel_node']['hide_alter_empty'] = FALSE;
/* Sort criterion: User: Created date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'users';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Filter criterion: User: Name */
$handler->display->display_options['filters']['uid']['id'] = 'uid';
$handler->display->display_options['filters']['uid']['table'] = 'users';
$handler->display->display_options['filters']['uid']['field'] = 'uid';
$handler->display->display_options['filters']['uid']['operator'] = 'not in';
$handler->display->display_options['filters']['uid']['value'] = array(
  0 => 0,
);
$handler->display->display_options['filters']['uid']['group'] = 1;
/* Filter criterion: User: Name (raw) */
$handler->display->display_options['filters']['name']['id'] = 'name';
$handler->display->display_options['filters']['name']['table'] = 'users';
$handler->display->display_options['filters']['name']['field'] = 'name';
$handler->display->display_options['filters']['name']['operator'] = 'contains';
$handler->display->display_options['filters']['name']['group'] = 1;
$handler->display->display_options['filters']['name']['exposed'] = TRUE;
$handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
$handler->display->display_options['filters']['name']['expose']['label'] = 'Username';
$handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
$handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
$handler->display->display_options['filters']['name']['expose']['remember'] = TRUE;
$handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  6 => 0,
  7 => 0,
  8 => 0,
  9 => 0,
);
/* Filter criterion: User: E-mail */
$handler->display->display_options['filters']['mail']['id'] = 'mail';
$handler->display->display_options['filters']['mail']['table'] = 'users';
$handler->display->display_options['filters']['mail']['field'] = 'mail';
$handler->display->display_options['filters']['mail']['operator'] = 'contains';
$handler->display->display_options['filters']['mail']['group'] = 1;
$handler->display->display_options['filters']['mail']['exposed'] = TRUE;
$handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
$handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
$handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
$handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
$handler->display->display_options['filters']['mail']['expose']['remember'] = TRUE;
/* Filter criterion: User: Roles */
$handler->display->display_options['filters']['rid']['id'] = 'rid';
$handler->display->display_options['filters']['rid']['table'] = 'users_roles';
$handler->display->display_options['filters']['rid']['field'] = 'rid';
$handler->display->display_options['filters']['rid']['group'] = 1;
$handler->display->display_options['filters']['rid']['exposed'] = TRUE;
$handler->display->display_options['filters']['rid']['expose']['operator_id'] = 'rid_op';
$handler->display->display_options['filters']['rid']['expose']['label'] = 'Role';
$handler->display->display_options['filters']['rid']['expose']['operator'] = 'rid_op';
$handler->display->display_options['filters']['rid']['expose']['identifier'] = 'rid';
$handler->display->display_options['filters']['rid']['expose']['remember'] = TRUE;
/* Filter criterion: User: Brugertype (field_user_type) */
$handler->display->display_options['filters']['field_user_type_tid']['id'] = 'field_user_type_tid';
$handler->display->display_options['filters']['field_user_type_tid']['table'] = 'field_data_field_user_type';
$handler->display->display_options['filters']['field_user_type_tid']['field'] = 'field_user_type_tid';
$handler->display->display_options['filters']['field_user_type_tid']['group'] = 1;
$handler->display->display_options['filters']['field_user_type_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_user_type_tid']['expose']['operator_id'] = 'field_user_type_tid_op';
$handler->display->display_options['filters']['field_user_type_tid']['expose']['label'] = 'Brugertype (field_user_type)';
$handler->display->display_options['filters']['field_user_type_tid']['expose']['operator'] = 'field_user_type_tid_op';
$handler->display->display_options['filters']['field_user_type_tid']['expose']['identifier'] = 'field_user_type_tid';
$handler->display->display_options['filters']['field_user_type_tid']['expose']['remember'] = TRUE;
$handler->display->display_options['filters']['field_user_type_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  6 => 0,
  7 => 0,
  8 => 0,
  9 => 0,
);
$handler->display->display_options['filters']['field_user_type_tid']['group_info']['label'] = 'Brugertype (field_user_type)';
$handler->display->display_options['filters']['field_user_type_tid']['group_info']['identifier'] = 'field_user_type_tid';
$handler->display->display_options['filters']['field_user_type_tid']['group_info']['remember'] = FALSE;
$handler->display->display_options['filters']['field_user_type_tid']['group_info']['group_items'] = array(
  1 => array(),
  2 => array(),
  3 => array(),
);
$handler->display->display_options['filters']['field_user_type_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_user_type_tid']['vocabulary'] = 'user_type';
$handler->display->display_options['filters']['field_user_type_tid']['hierarchy'] = 1;
/* Filter criterion: User: Created date */
$handler->display->display_options['filters']['created']['id'] = 'created';
$handler->display->display_options['filters']['created']['table'] = 'users';
$handler->display->display_options['filters']['created']['field'] = 'created';
$handler->display->display_options['filters']['created']['operator'] = 'between';
$handler->display->display_options['filters']['created']['group'] = 1;
$handler->display->display_options['filters']['created']['exposed'] = TRUE;
$handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
$handler->display->display_options['filters']['created']['expose']['label'] = 'Created date';
$handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
$handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
$handler->display->display_options['filters']['created']['expose']['remember'] = TRUE;
$handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  6 => 0,
  7 => 0,
  8 => 0,
  9 => 0,
);
$handler->display->display_options['filters']['created']['group_info']['label'] = 'Created date';
$handler->display->display_options['filters']['created']['group_info']['identifier'] = 'created';
$handler->display->display_options['filters']['created']['group_info']['remember'] = FALSE;
$handler->display->display_options['filters']['created']['group_info']['group_items'] = array(
  1 => array(),
  2 => array(),
  3 => array(),
);
/* Filter criterion: User: Aktiv */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'users';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 'All';
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['exposed'] = TRUE;
$handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
$handler->display->display_options['filters']['status']['expose']['label'] = 'Active';
$handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
$handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
$handler->display->display_options['filters']['status']['expose']['remember'] = TRUE;
/* Filter criterion: User: Ja tak, jeg vil gerne modtage jeres nyhedsbrev (field_newsletter) */
$handler->display->display_options['filters']['field_newsletter_value']['id'] = 'field_newsletter_value';
$handler->display->display_options['filters']['field_newsletter_value']['table'] = 'field_data_field_newsletter';
$handler->display->display_options['filters']['field_newsletter_value']['field'] = 'field_newsletter_value';
$handler->display->display_options['filters']['field_newsletter_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_newsletter_value']['expose']['operator_id'] = 'field_newsletter_value_op';
$handler->display->display_options['filters']['field_newsletter_value']['expose']['label'] = 'Nyhedsbrev';
$handler->display->display_options['filters']['field_newsletter_value']['expose']['operator'] = 'field_newsletter_value_op';
$handler->display->display_options['filters']['field_newsletter_value']['expose']['identifier'] = 'field_newsletter_value';
$handler->display->display_options['filters']['field_newsletter_value']['expose']['remember'] = TRUE;
$handler->display->display_options['filters']['field_newsletter_value']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  6 => 0,
  7 => 0,
  8 => 0,
  9 => 0,
);
/* Filter criterion: User: Bundles (field_access_bundles) */
$handler->display->display_options['filters']['field_access_bundles_nid']['id'] = 'field_access_bundles_nid';
$handler->display->display_options['filters']['field_access_bundles_nid']['table'] = 'field_data_field_access_bundles';
$handler->display->display_options['filters']['field_access_bundles_nid']['field'] = 'field_access_bundles_nid';
$handler->display->display_options['filters']['field_access_bundles_nid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_access_bundles_nid']['expose']['operator_id'] = 'field_access_bundles_nid_op';
$handler->display->display_options['filters']['field_access_bundles_nid']['expose']['label'] = 'Bundles';
$handler->display->display_options['filters']['field_access_bundles_nid']['expose']['use_operator'] = TRUE;
$handler->display->display_options['filters']['field_access_bundles_nid']['expose']['operator'] = 'field_access_bundles_nid_op';
$handler->display->display_options['filters']['field_access_bundles_nid']['expose']['identifier'] = 'field_access_bundles_nid';
$handler->display->display_options['filters']['field_access_bundles_nid']['expose']['remember'] = TRUE;
$handler->display->display_options['filters']['field_access_bundles_nid']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_access_bundles_nid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  6 => 0,
  7 => 0,
  8 => 0,
  9 => 0,
);

/* Display: System */
$handler = $view->new_display('system', 'System', 'system_1');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Bulk operations: User */
$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
$handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_result'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
  'action::kms_user_vbo_add_access_bundles' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::system_block_ip_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 1,
    'override_label' => 1,
    'label' => 'Ban IP address of the current user',
  ),
  'action::user_block_user_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 1,
    'override_label' => 0,
    'label' => '',
  ),
  'action::kms_user_vbo_clear_access_bundles' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::kms_user_vbo_copy_user_services' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_delete_item' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 1,
    'label' => 'Delete',
  ),
  'action::system_message_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_script_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_modify_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 1,
    'override_label' => 1,
    'label' => 'Change value',
    'settings' => array(
      'show_all_tokens' => 1,
      'display_values' => array(
        '_all_' => '_all_',
      ),
    ),
  ),
  'action::views_bulk_operations_user_roles_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 1,
    'label' => 'Change user roles',
  ),
  'action::views_bulk_operations_argument_selector_action' => array(
    'selected' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'settings' => array(
      'url' => '',
    ),
  ),
  'action::system_goto_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::system_send_email_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 1,
    'label' => 'Send e-mail',
  ),
  'action::pathauto_user_update_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
);
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
/* Field: User: Bundles */
$handler->display->display_options['fields']['field_access_bundles']['id'] = 'field_access_bundles';
$handler->display->display_options['fields']['field_access_bundles']['table'] = 'field_data_field_access_bundles';
$handler->display->display_options['fields']['field_access_bundles']['field'] = 'field_access_bundles';
$handler->display->display_options['fields']['field_access_bundles']['type'] = 'kms_permissions_bundles_reference';
$handler->display->display_options['fields']['field_access_bundles']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_access_bundles']['multi_type'] = 'ul';
/* Field: User: E-mail */
$handler->display->display_options['fields']['mail']['id'] = 'mail';
$handler->display->display_options['fields']['mail']['table'] = 'users';
$handler->display->display_options['fields']['mail']['field'] = 'mail';
$handler->display->display_options['fields']['mail']['label'] = '';
$handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['mail']['link_to_user'] = '0';
/* Field: User: Aktiv */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'users';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['not'] = 0;
/* Field: User: Roles */
$handler->display->display_options['fields']['rid']['id'] = 'rid';
$handler->display->display_options['fields']['rid']['table'] = 'users_roles';
$handler->display->display_options['fields']['rid']['field'] = 'rid';
$handler->display->display_options['fields']['rid']['type'] = 'ul';
/* Field: User: Created date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'users';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Member since';
$handler->display->display_options['fields']['created']['date_format'] = 'short';
/* Field: User: Last access */
$handler->display->display_options['fields']['access']['id'] = 'access';
$handler->display->display_options['fields']['access']['table'] = 'users';
$handler->display->display_options['fields']['access']['field'] = 'access';
$handler->display->display_options['fields']['access']['date_format'] = 'time ago';
/* Field: User: Edit link */
$handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['table'] = 'users';
$handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['label'] = '';
/* Field: User: Cancel link */
$handler->display->display_options['fields']['cancel_node']['id'] = 'cancel_node';
$handler->display->display_options['fields']['cancel_node']['table'] = 'users';
$handler->display->display_options['fields']['cancel_node']['field'] = 'cancel_node';
$handler->display->display_options['fields']['cancel_node']['label'] = '';
$handler->display->display_options['fields']['cancel_node']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['cancel_node']['hide_alter_empty'] = FALSE;
$handler->display->display_options['path'] = 'admin/people';

/* Display: Data export */
$handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
$translatables['admin_views_user'] = array(
  t('Defaults'),
  t('Users'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Users per page'),
  t('- All -'),
  t('Offset'),
  t('« first'),
  t('‹ previous'),
  t('next ›'),
  t('last »'),
  t('No users available.'),
  t('Name'),
  t('Bundles'),
  t('Aktiv'),
  t('Roles'),
  t('Member since'),
  t('Last access'),
  t('Username'),
  t('E-mail'),
  t('Role'),
  t('Brugertype (field_user_type)'),
  t('Created date'),
  t('Active'),
  t('Nyhedsbrev'),
  t('System'),
  t('Data export'),
);
$view = new view();
$view->name = 'admin_views_user';
$view->description = 'List, add, and edit users.';
$view->tag = 'admin';
$view->base_table = 'users';
$view->human_name = 'Administration: Users';
$view->core = 0;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Defaults */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->display->display_options['title'] = 'Users';
$handler->display->display_options['css_class'] = 'admin-views-view';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'menu';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
$handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
$handler->display->display_options['exposed_form']['options']['bef'] = array(
  'general' => array(
    'allow_secondary' => 0,
    'secondary_label' => 'Advanced options',
  ),
  'name' => array(
    'more_options' => array(
      'is_secondary' => 0,
      'bef_filter_description' => '',
      'tokens' => array(
        'available' => array(
          0 => 'global_types',
        ),
      ),
    ),
  ),
  'mail' => array(
    'more_options' => array(
      'is_secondary' => 0,
      'bef_filter_description' => '',
      'tokens' => array(
        'available' => array(
          0 => 'global_types',
        ),
      ),
    ),
  ),
  'rid' => array(
    'bef_format' => 'default',
    'more_options' => array(
      'bef_select_all_none' => FALSE,
      'bef_collapsible' => 0,
      'is_secondary' => 0,
      'bef_filter_description' => '',
      'tokens' => array(
        'available' => array(
          0 => 'global_types',
        ),
      ),
    ),
  ),
  'field_user_type_tid' => array(
    'bef_format' => 'default',
    'more_options' => array(
      'bef_select_all_none' => FALSE,
      'bef_collapsible' => 0,
      'is_secondary' => 0,
      'bef_filter_description' => '',
      'tokens' => array(
        'available' => array(
          0 => 'global_types',
        ),
      ),
    ),
  ),
  'created' => array(
    'bef_format' => 'bef_datepicker',
    'more_options' => array(
      'is_secondary' => 0,
      'bef_filter_description' => 'Select a range for the created date',
      'tokens' => array(
        'available' => array(
          0 => 'global_types',
        ),
      ),
    ),
  ),
  'status' => array(
    'bef_format' => 'default',
    'more_options' => array(
      'bef_select_all_none' => FALSE,
      'bef_collapsible' => 0,
      'is_secondary' => 0,
      'bef_filter_description' => '',
      'tokens' => array(
        'available' => array(
          0 => 'global_types',
        ),
      ),
    ),
  ),
);
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '25';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
$handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Users per page';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '25, 50, 75, 100';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'views_bulk_operations' => 'views_bulk_operations',
  'name' => 'name',
  'mail' => 'name',
  'status' => 'status',
  'rid' => 'rid',
  'created' => 'created',
  'access' => 'access',
  'edit_node' => 'edit_node',
  'cancel_node' => 'cancel_node',
);
$handler->display->display_options['style_options']['default'] = 'access';
$handler->display->display_options['style_options']['info'] = array(
  'views_bulk_operations' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '<br />',
    'empty_column' => 0,
  ),
  'mail' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'status' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'rid' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'created' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'access' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'edit_node' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'cancel_node' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['sticky'] = TRUE;
$handler->display->display_options['style_options']['empty_table'] = TRUE;
/* No results behavior: Global: Unfiltered text */
$handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
$handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
$handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
$handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
$handler->display->display_options['empty']['area_text_custom']['content'] = 'No users available.';
/* Field: Bulk operations: User */
$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
$handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_result'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
  'action::system_block_ip_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 1,
    'override_label' => 1,
    'label' => 'Ban IP address of the current user',
  ),
  'action::user_block_user_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 1,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_delete_item' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 1,
    'label' => 'Delete',
  ),
  'action::views_bulk_operations_modify_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 1,
    'override_label' => 1,
    'label' => 'Change value',
    'settings' => array(
      'show_all_tokens' => 1,
      'display_values' => array(
        '_all_' => '_all_',
      ),
    ),
  ),
  'action::system_message_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_script_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_user_roles_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 1,
    'label' => 'Change user roles',
  ),
  'action::views_bulk_operations_argument_selector_action' => array(
    'selected' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'settings' => array(
      'url' => '',
    ),
  ),
  'action::system_goto_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::system_send_email_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 1,
    'label' => 'Send e-mail',
  ),
);
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
/* Field: User: Bundles */
$handler->display->display_options['fields']['field_access_bundles']['id'] = 'field_access_bundles';
$handler->display->display_options['fields']['field_access_bundles']['table'] = 'field_data_field_access_bundles';
$handler->display->display_options['fields']['field_access_bundles']['field'] = 'field_access_bundles';
$handler->display->display_options['fields']['field_access_bundles']['type'] = 'kms_permissions_bundles_reference';
$handler->display->display_options['fields']['field_access_bundles']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_access_bundles']['multi_type'] = 'ul';
/* Field: User: E-mail */
$handler->display->display_options['fields']['mail']['id'] = 'mail';
$handler->display->display_options['fields']['mail']['table'] = 'users';
$handler->display->display_options['fields']['mail']['field'] = 'mail';
$handler->display->display_options['fields']['mail']['label'] = '';
$handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['mail']['link_to_user'] = '0';
/* Field: User: Aktiv */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'users';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['not'] = 0;
/* Field: User: Roles */
$handler->display->display_options['fields']['rid']['id'] = 'rid';
$handler->display->display_options['fields']['rid']['table'] = 'users_roles';
$handler->display->display_options['fields']['rid']['field'] = 'rid';
$handler->display->display_options['fields']['rid']['type'] = 'ul';
/* Field: User: Created date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'users';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Member since';
$handler->display->display_options['fields']['created']['date_format'] = 'short';
/* Field: User: Last access */
$handler->display->display_options['fields']['access']['id'] = 'access';
$handler->display->display_options['fields']['access']['table'] = 'users';
$handler->display->display_options['fields']['access']['field'] = 'access';
$handler->display->display_options['fields']['access']['date_format'] = 'time ago';
/* Field: User: Edit link */
$handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['table'] = 'users';
$handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['label'] = '';
/* Field: User: Cancel link */
$handler->display->display_options['fields']['cancel_node']['id'] = 'cancel_node';
$handler->display->display_options['fields']['cancel_node']['table'] = 'users';
$handler->display->display_options['fields']['cancel_node']['field'] = 'cancel_node';
$handler->display->display_options['fields']['cancel_node']['label'] = '';
$handler->display->display_options['fields']['cancel_node']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['cancel_node']['hide_alter_empty'] = FALSE;
/* Sort criterion: User: Created date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'users';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Filter criterion: User: Name */
$handler->display->display_options['filters']['uid']['id'] = 'uid';
$handler->display->display_options['filters']['uid']['table'] = 'users';
$handler->display->display_options['filters']['uid']['field'] = 'uid';
$handler->display->display_options['filters']['uid']['operator'] = 'not in';
$handler->display->display_options['filters']['uid']['value'] = array(
  0 => 0,
);
$handler->display->display_options['filters']['uid']['group'] = 1;
/* Filter criterion: User: Name (raw) */
$handler->display->display_options['filters']['name']['id'] = 'name';
$handler->display->display_options['filters']['name']['table'] = 'users';
$handler->display->display_options['filters']['name']['field'] = 'name';
$handler->display->display_options['filters']['name']['operator'] = 'contains';
$handler->display->display_options['filters']['name']['group'] = 1;
$handler->display->display_options['filters']['name']['exposed'] = TRUE;
$handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
$handler->display->display_options['filters']['name']['expose']['label'] = 'Username';
$handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
$handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
$handler->display->display_options['filters']['name']['expose']['remember'] = TRUE;
$handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  6 => 0,
  7 => 0,
  8 => 0,
  9 => 0,
);
/* Filter criterion: User: E-mail */
$handler->display->display_options['filters']['mail']['id'] = 'mail';
$handler->display->display_options['filters']['mail']['table'] = 'users';
$handler->display->display_options['filters']['mail']['field'] = 'mail';
$handler->display->display_options['filters']['mail']['operator'] = 'contains';
$handler->display->display_options['filters']['mail']['group'] = 1;
$handler->display->display_options['filters']['mail']['exposed'] = TRUE;
$handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
$handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
$handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
$handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
$handler->display->display_options['filters']['mail']['expose']['remember'] = TRUE;
/* Filter criterion: User: Roles */
$handler->display->display_options['filters']['rid']['id'] = 'rid';
$handler->display->display_options['filters']['rid']['table'] = 'users_roles';
$handler->display->display_options['filters']['rid']['field'] = 'rid';
$handler->display->display_options['filters']['rid']['group'] = 1;
$handler->display->display_options['filters']['rid']['exposed'] = TRUE;
$handler->display->display_options['filters']['rid']['expose']['operator_id'] = 'rid_op';
$handler->display->display_options['filters']['rid']['expose']['label'] = 'Role';
$handler->display->display_options['filters']['rid']['expose']['operator'] = 'rid_op';
$handler->display->display_options['filters']['rid']['expose']['identifier'] = 'rid';
$handler->display->display_options['filters']['rid']['expose']['remember'] = TRUE;
/* Filter criterion: User: Brugertype (field_user_type) */
$handler->display->display_options['filters']['field_user_type_tid']['id'] = 'field_user_type_tid';
$handler->display->display_options['filters']['field_user_type_tid']['table'] = 'field_data_field_user_type';
$handler->display->display_options['filters']['field_user_type_tid']['field'] = 'field_user_type_tid';
$handler->display->display_options['filters']['field_user_type_tid']['group'] = 1;
$handler->display->display_options['filters']['field_user_type_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_user_type_tid']['expose']['operator_id'] = 'field_user_type_tid_op';
$handler->display->display_options['filters']['field_user_type_tid']['expose']['label'] = 'Brugertype (field_user_type)';
$handler->display->display_options['filters']['field_user_type_tid']['expose']['operator'] = 'field_user_type_tid_op';
$handler->display->display_options['filters']['field_user_type_tid']['expose']['identifier'] = 'field_user_type_tid';
$handler->display->display_options['filters']['field_user_type_tid']['expose']['remember'] = TRUE;
$handler->display->display_options['filters']['field_user_type_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  6 => 0,
  7 => 0,
  8 => 0,
  9 => 0,
);
$handler->display->display_options['filters']['field_user_type_tid']['group_info']['label'] = 'Brugertype (field_user_type)';
$handler->display->display_options['filters']['field_user_type_tid']['group_info']['identifier'] = 'field_user_type_tid';
$handler->display->display_options['filters']['field_user_type_tid']['group_info']['remember'] = FALSE;
$handler->display->display_options['filters']['field_user_type_tid']['group_info']['group_items'] = array(
  1 => array(),
  2 => array(),
  3 => array(),
);
$handler->display->display_options['filters']['field_user_type_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_user_type_tid']['vocabulary'] = 'user_type';
$handler->display->display_options['filters']['field_user_type_tid']['hierarchy'] = 1;
/* Filter criterion: User: Created date */
$handler->display->display_options['filters']['created']['id'] = 'created';
$handler->display->display_options['filters']['created']['table'] = 'users';
$handler->display->display_options['filters']['created']['field'] = 'created';
$handler->display->display_options['filters']['created']['operator'] = 'between';
$handler->display->display_options['filters']['created']['group'] = 1;
$handler->display->display_options['filters']['created']['exposed'] = TRUE;
$handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
$handler->display->display_options['filters']['created']['expose']['label'] = 'Created date';
$handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
$handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
$handler->display->display_options['filters']['created']['expose']['remember'] = TRUE;
$handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  6 => 0,
  7 => 0,
  8 => 0,
  9 => 0,
);
$handler->display->display_options['filters']['created']['group_info']['label'] = 'Created date';
$handler->display->display_options['filters']['created']['group_info']['identifier'] = 'created';
$handler->display->display_options['filters']['created']['group_info']['remember'] = FALSE;
$handler->display->display_options['filters']['created']['group_info']['group_items'] = array(
  1 => array(),
  2 => array(),
  3 => array(),
);
/* Filter criterion: User: Aktiv */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'users';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 'All';
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['exposed'] = TRUE;
$handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
$handler->display->display_options['filters']['status']['expose']['label'] = 'Active';
$handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
$handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
$handler->display->display_options['filters']['status']['expose']['remember'] = TRUE;
/* Filter criterion: User: Ja tak, jeg vil gerne modtage jeres nyhedsbrev (field_newsletter) */
$handler->display->display_options['filters']['field_newsletter_value']['id'] = 'field_newsletter_value';
$handler->display->display_options['filters']['field_newsletter_value']['table'] = 'field_data_field_newsletter';
$handler->display->display_options['filters']['field_newsletter_value']['field'] = 'field_newsletter_value';
$handler->display->display_options['filters']['field_newsletter_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_newsletter_value']['expose']['operator_id'] = 'field_newsletter_value_op';
$handler->display->display_options['filters']['field_newsletter_value']['expose']['label'] = 'Nyhedsbrev';
$handler->display->display_options['filters']['field_newsletter_value']['expose']['operator'] = 'field_newsletter_value_op';
$handler->display->display_options['filters']['field_newsletter_value']['expose']['identifier'] = 'field_newsletter_value';
$handler->display->display_options['filters']['field_newsletter_value']['expose']['remember'] = TRUE;
$handler->display->display_options['filters']['field_newsletter_value']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  6 => 0,
  7 => 0,
  8 => 0,
  9 => 0,
);
/* Filter criterion: User: Bundles (field_access_bundles) */
$handler->display->display_options['filters']['field_access_bundles_nid']['id'] = 'field_access_bundles_nid';
$handler->display->display_options['filters']['field_access_bundles_nid']['table'] = 'field_data_field_access_bundles';
$handler->display->display_options['filters']['field_access_bundles_nid']['field'] = 'field_access_bundles_nid';
$handler->display->display_options['filters']['field_access_bundles_nid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_access_bundles_nid']['expose']['operator_id'] = 'field_access_bundles_nid_op';
$handler->display->display_options['filters']['field_access_bundles_nid']['expose']['label'] = 'Bundles';
$handler->display->display_options['filters']['field_access_bundles_nid']['expose']['use_operator'] = TRUE;
$handler->display->display_options['filters']['field_access_bundles_nid']['expose']['operator'] = 'field_access_bundles_nid_op';
$handler->display->display_options['filters']['field_access_bundles_nid']['expose']['identifier'] = 'field_access_bundles_nid';
$handler->display->display_options['filters']['field_access_bundles_nid']['expose']['remember'] = TRUE;
$handler->display->display_options['filters']['field_access_bundles_nid']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_access_bundles_nid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  6 => 0,
  7 => 0,
  8 => 0,
  9 => 0,
);

/* Display: System */
$handler = $view->new_display('system', 'System', 'system_1');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Bulk operations: User */
$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
$handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_result'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
  'action::kms_user_vbo_add_access_bundles' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::system_block_ip_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 1,
    'override_label' => 1,
    'label' => 'Ban IP address of the current user',
  ),
  'action::user_block_user_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 1,
    'override_label' => 0,
    'label' => '',
  ),
  'action::kms_user_vbo_clear_access_bundles' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::kms_permissions_vbo_copy_user_services' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_delete_item' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 1,
    'label' => 'Delete',
  ),
  'action::system_message_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_script_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_modify_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 1,
    'override_label' => 1,
    'label' => 'Change value',
    'settings' => array(
      'show_all_tokens' => 1,
      'display_values' => array(
        '_all_' => '_all_',
      ),
    ),
  ),
  'action::views_bulk_operations_user_roles_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 1,
    'label' => 'Change user roles',
  ),
  'action::views_bulk_operations_argument_selector_action' => array(
    'selected' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'settings' => array(
      'url' => '',
    ),
  ),
  'action::system_goto_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::system_send_email_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 1,
    'label' => 'Send e-mail',
  ),
  'action::pathauto_user_update_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
);
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
/* Field: User: Bundles */
$handler->display->display_options['fields']['field_access_bundles']['id'] = 'field_access_bundles';
$handler->display->display_options['fields']['field_access_bundles']['table'] = 'field_data_field_access_bundles';
$handler->display->display_options['fields']['field_access_bundles']['field'] = 'field_access_bundles';
$handler->display->display_options['fields']['field_access_bundles']['type'] = 'kms_permissions_bundles_reference';
$handler->display->display_options['fields']['field_access_bundles']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_access_bundles']['multi_type'] = 'ul';
/* Field: User: E-mail */
$handler->display->display_options['fields']['mail']['id'] = 'mail';
$handler->display->display_options['fields']['mail']['table'] = 'users';
$handler->display->display_options['fields']['mail']['field'] = 'mail';
$handler->display->display_options['fields']['mail']['label'] = '';
$handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['mail']['link_to_user'] = '0';
/* Field: User: Aktiv */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'users';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['not'] = 0;
/* Field: User: Roles */
$handler->display->display_options['fields']['rid']['id'] = 'rid';
$handler->display->display_options['fields']['rid']['table'] = 'users_roles';
$handler->display->display_options['fields']['rid']['field'] = 'rid';
$handler->display->display_options['fields']['rid']['type'] = 'ul';
/* Field: User: Created date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'users';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Member since';
$handler->display->display_options['fields']['created']['date_format'] = 'short';
/* Field: User: Last access */
$handler->display->display_options['fields']['access']['id'] = 'access';
$handler->display->display_options['fields']['access']['table'] = 'users';
$handler->display->display_options['fields']['access']['field'] = 'access';
$handler->display->display_options['fields']['access']['date_format'] = 'time ago';
/* Field: User: Edit link */
$handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['table'] = 'users';
$handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['label'] = '';
/* Field: User: Cancel link */
$handler->display->display_options['fields']['cancel_node']['id'] = 'cancel_node';
$handler->display->display_options['fields']['cancel_node']['table'] = 'users';
$handler->display->display_options['fields']['cancel_node']['field'] = 'cancel_node';
$handler->display->display_options['fields']['cancel_node']['label'] = '';
$handler->display->display_options['fields']['cancel_node']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['cancel_node']['hide_alter_empty'] = FALSE;
$handler->display->display_options['path'] = 'admin/people';

/* Display: Data export */
$handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
$translatables['admin_views_user'] = array(
  t('Defaults'),
  t('Users'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Users per page'),
  t('- All -'),
  t('Offset'),
  t('« first'),
  t('‹ previous'),
  t('next ›'),
  t('last »'),
  t('No users available.'),
  t('Name'),
  t('Bundles'),
  t('Aktiv'),
  t('Roles'),
  t('Member since'),
  t('Last access'),
  t('Username'),
  t('E-mail'),
  t('Role'),
  t('Brugertype (field_user_type)'),
  t('Created date'),
  t('Active'),
  t('Nyhedsbrev'),
  t('System'),
  t('Data export'),
);
