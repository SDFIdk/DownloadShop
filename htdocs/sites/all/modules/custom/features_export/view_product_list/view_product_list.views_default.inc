<?php
/**
 * @file
 * view_product_list.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function view_product_list_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'product_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Product list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_tags'] = array(
    0 => 'querylist',
  );
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« Første';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ Forrige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'Næste ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'Sidste »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<?php 
  global $user;
  $adminRoles= array( \'editor\',\'superuser\',\'product admin\' );
  if ( array_intersect($adminRoles, array_values($user->roles)) || $user->uid == 1 ) {
    $view = views_get_current_view();
    $args = array();
    foreach ( $view->exposed_input as $key => $value ) {  
       if ( $value != \'All\' ) $args[] = "$key=$value";
    }
    echo $GLOBALS[\'base_url\'] . \'/\' . drupal_get_path_alias(current_path()) .\'?\' .  join(\'&\',$args);
  }
?>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Der er ikke nogle resultater der matcher din søgning';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Product image */
  $handler->display->display_options['fields']['field_product_image']['id'] = 'field_product_image';
  $handler->display->display_options['fields']['field_product_image']['table'] = 'field_data_field_product_image';
  $handler->display->display_options['fields']['field_product_image']['field'] = 'field_product_image';
  $handler->display->display_options['fields']['field_product_image']['label'] = '';
  $handler->display->display_options['fields']['field_product_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_product_image']['alter']['text'] = '<a href="[path]">[field_product_image]</a>';
  $handler->display->display_options['fields']['field_product_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_product_image']['settings'] = array(
    'image_style' => 'product_list',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_product_image']['group_column'] = 'entity_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '<div class="content">
<div class="title">[title]</div>
<div class="body"><a href="[path]">[body]</a></div>
</div>';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '450';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '450',
  );
  $handler->display->display_options['fields']['body']['group_column'] = 'entity_id';
  /* Field: Field: Korttype */
  $handler->display->display_options['fields']['field_korttype']['id'] = 'field_korttype';
  $handler->display->display_options['fields']['field_korttype']['table'] = 'field_data_field_korttype';
  $handler->display->display_options['fields']['field_korttype']['field'] = 'field_korttype';
  $handler->display->display_options['fields']['field_korttype']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_korttype']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_korttype']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_korttype']['group_column'] = 'entity_id';
  /* Field: Field: Datastruktur */
  $handler->display->display_options['fields']['field_datastruktur']['id'] = 'field_datastruktur';
  $handler->display->display_options['fields']['field_datastruktur']['table'] = 'field_data_field_datastruktur';
  $handler->display->display_options['fields']['field_datastruktur']['field'] = 'field_datastruktur';
  $handler->display->display_options['fields']['field_datastruktur']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_datastruktur']['label'] = '';
  $handler->display->display_options['fields']['field_datastruktur']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_datastruktur']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datastruktur']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_datastruktur']['group_column'] = 'entity_id';
  /* Field: Field: Data skema */
  $handler->display->display_options['fields']['field_scheme']['id'] = 'field_scheme';
  $handler->display->display_options['fields']['field_scheme']['table'] = 'field_data_field_scheme';
  $handler->display->display_options['fields']['field_scheme']['field'] = 'field_scheme';
  $handler->display->display_options['fields']['field_scheme']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_scheme']['label'] = '';
  $handler->display->display_options['fields']['field_scheme']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_scheme']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_scheme']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field: Aktualitet */
  $handler->display->display_options['fields']['field_aktualitet']['id'] = 'field_aktualitet';
  $handler->display->display_options['fields']['field_aktualitet']['table'] = 'field_data_field_aktualitet';
  $handler->display->display_options['fields']['field_aktualitet']['field'] = 'field_aktualitet';
  $handler->display->display_options['fields']['field_aktualitet']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_aktualitet']['label'] = '';
  $handler->display->display_options['fields']['field_aktualitet']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_aktualitet']['alter']['text'] = '<div class="info">Korttype: [field_korttype], Datastruktur: [field_datastruktur], Aktualitet: [field_aktualitet], Dataskema: [field_scheme]</div>';
  $handler->display->display_options['fields']['field_aktualitet']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_aktualitet']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_aktualitet']['group_column'] = 'entity_id';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Korttype';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'field_korttype_tid_1';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'korttype';
  $handler->display->display_options['filters']['term_node_tid_depth']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '3';
  /* Filter criterion: Field: Korttype (field_korttype) */
  $handler->display->display_options['filters']['field_korttype_tid_1']['id'] = 'field_korttype_tid_1';
  $handler->display->display_options['filters']['field_korttype_tid_1']['table'] = 'field_data_field_korttype';
  $handler->display->display_options['filters']['field_korttype_tid_1']['field'] = 'field_korttype_tid';
  $handler->display->display_options['filters']['field_korttype_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_korttype_tid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_korttype_tid_1']['expose']['operator_id'] = 'field_korttype_tid_1_op';
  $handler->display->display_options['filters']['field_korttype_tid_1']['expose']['label'] = 'Korttype';
  $handler->display->display_options['filters']['field_korttype_tid_1']['expose']['operator'] = 'field_korttype_tid_1_op';
  $handler->display->display_options['filters']['field_korttype_tid_1']['expose']['identifier'] = 'field_korttype_tid_1a';
  $handler->display->display_options['filters']['field_korttype_tid_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_korttype_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_korttype_tid_1']['vocabulary'] = 'korttype';
  /* Filter criterion: Field: Aktualitet (field_aktualitet) */
  $handler->display->display_options['filters']['field_aktualitet_tid']['id'] = 'field_aktualitet_tid';
  $handler->display->display_options['filters']['field_aktualitet_tid']['table'] = 'field_data_field_aktualitet';
  $handler->display->display_options['filters']['field_aktualitet_tid']['field'] = 'field_aktualitet_tid';
  $handler->display->display_options['filters']['field_aktualitet_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_aktualitet_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_aktualitet_tid']['expose']['operator_id'] = 'field_aktualitet_tid_op';
  $handler->display->display_options['filters']['field_aktualitet_tid']['expose']['label'] = 'Aktualitet';
  $handler->display->display_options['filters']['field_aktualitet_tid']['expose']['operator'] = 'field_aktualitet_tid_op';
  $handler->display->display_options['filters']['field_aktualitet_tid']['expose']['identifier'] = 'field_aktualitet_tid';
  $handler->display->display_options['filters']['field_aktualitet_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_aktualitet_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_aktualitet_tid']['vocabulary'] = 'aktualitet';
  /* Filter criterion: Field: Datastruktur (field_datastruktur) */
  $handler->display->display_options['filters']['field_datastruktur_tid']['id'] = 'field_datastruktur_tid';
  $handler->display->display_options['filters']['field_datastruktur_tid']['table'] = 'field_data_field_datastruktur';
  $handler->display->display_options['filters']['field_datastruktur_tid']['field'] = 'field_datastruktur_tid';
  $handler->display->display_options['filters']['field_datastruktur_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_datastruktur_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_datastruktur_tid']['expose']['operator_id'] = 'field_datastruktur_tid_op';
  $handler->display->display_options['filters']['field_datastruktur_tid']['expose']['label'] = 'Datastruktur';
  $handler->display->display_options['filters']['field_datastruktur_tid']['expose']['operator'] = 'field_datastruktur_tid_op';
  $handler->display->display_options['filters']['field_datastruktur_tid']['expose']['identifier'] = 'field_datastruktur_tid';
  $handler->display->display_options['filters']['field_datastruktur_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_datastruktur_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_datastruktur_tid']['vocabulary'] = 'datastruktur';
  /* Filter criterion: Field: Data skema (field_scheme) */
  $handler->display->display_options['filters']['field_scheme_tid']['id'] = 'field_scheme_tid';
  $handler->display->display_options['filters']['field_scheme_tid']['table'] = 'field_data_field_scheme';
  $handler->display->display_options['filters']['field_scheme_tid']['field'] = 'field_scheme_tid';
  $handler->display->display_options['filters']['field_scheme_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_scheme_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_scheme_tid']['expose']['operator_id'] = 'field_scheme_tid_op';
  $handler->display->display_options['filters']['field_scheme_tid']['expose']['label'] = 'Data skema';
  $handler->display->display_options['filters']['field_scheme_tid']['expose']['operator'] = 'field_scheme_tid_op';
  $handler->display->display_options['filters']['field_scheme_tid']['expose']['identifier'] = 'field_scheme_tid';
  $handler->display->display_options['filters']['field_scheme_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_scheme_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_scheme_tid']['vocabulary'] = 'data_schema';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'content/kort-liste';
  $handler->display->display_options['inherit_panels_path'] = '0';
  $translatables['product_list'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« Første'),
    t('‹ Forrige'),
    t('Næste ›'),
    t('Sidste »'),
    t('<?php 
  global $user;
  $adminRoles= array( \'editor\',\'superuser\',\'product admin\' );
  if ( array_intersect($adminRoles, array_values($user->roles)) || $user->uid == 1 ) {
    $view = views_get_current_view();
    $args = array();
    foreach ( $view->exposed_input as $key => $value ) {  
       if ( $value != \'All\' ) $args[] = "$key=$value";
    }
    echo $GLOBALS[\'base_url\'] . \'/\' . drupal_get_path_alias(current_path()) .\'?\' .  join(\'&\',$args);
  }
?>'),
    t('Der er ikke nogle resultater der matcher din søgning'),
    t('<a href="[path]">[field_product_image]</a>'),
    t('<div class="content">
<div class="title">[title]</div>
<div class="body"><a href="[path]">[body]</a></div>
</div>'),
    t('Korttype'),
    t('<div class="info">Korttype: [field_korttype], Datastruktur: [field_datastruktur], Aktualitet: [field_aktualitet], Dataskema: [field_scheme]</div>'),
    t('Aktualitet'),
    t('Datastruktur'),
    t('Data skema'),
    t('Content pane'),
    t('View panes'),
  );
  $export['product_list'] = $view;

  return $export;
}
