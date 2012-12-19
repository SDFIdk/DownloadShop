<?php
/**
 * @file
 * view_product_links.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function view_product_links_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'product_links';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_product';
  $view->human_name = 'Product links';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Commerce Product: Metadata */
  $handler->display->display_options['fields']['field_geodata_info_dk']['id'] = 'field_geodata_info_dk';
  $handler->display->display_options['fields']['field_geodata_info_dk']['table'] = 'field_data_field_geodata_info_dk';
  $handler->display->display_options['fields']['field_geodata_info_dk']['field'] = 'field_geodata_info_dk';
  $handler->display->display_options['fields']['field_geodata_info_dk']['label'] = '';
  $handler->display->display_options['fields']['field_geodata_info_dk']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geodata_info_dk']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_geodata_info_dk']['type'] = 'link_label';
  /* Field: Commerce Product: Læs mere */
  $handler->display->display_options['fields']['field_kms_dk']['id'] = 'field_kms_dk';
  $handler->display->display_options['fields']['field_kms_dk']['table'] = 'field_data_field_kms_dk';
  $handler->display->display_options['fields']['field_kms_dk']['field'] = 'field_kms_dk';
  $handler->display->display_options['fields']['field_kms_dk']['label'] = '';
  $handler->display->display_options['fields']['field_kms_dk']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_kms_dk']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_kms_dk']['type'] = 'link_label';
  /* Field: Commerce Product: Signaturforklaring */
  $handler->display->display_options['fields']['field_legend']['id'] = 'field_legend';
  $handler->display->display_options['fields']['field_legend']['table'] = 'field_data_field_legend';
  $handler->display->display_options['fields']['field_legend']['field'] = 'field_legend';
  $handler->display->display_options['fields']['field_legend']['label'] = '';
  $handler->display->display_options['fields']['field_legend']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_legend']['click_sort_column'] = 'url';
  /* Field: Commerce Product: Atom Feed */
  $handler->display->display_options['fields']['field_atom_feed']['id'] = 'field_atom_feed';
  $handler->display->display_options['fields']['field_atom_feed']['table'] = 'field_data_field_atom_feed';
  $handler->display->display_options['fields']['field_atom_feed']['field'] = 'field_atom_feed';
  $handler->display->display_options['fields']['field_atom_feed']['label'] = '';
  $handler->display->display_options['fields']['field_atom_feed']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_atom_feed']['alter']['text'] = '<a href="[field_atom_feed-url]"><img src="/sites/all/themes/custom/kms/images/rss.png"></a>';
  $handler->display->display_options['fields']['field_atom_feed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_atom_feed']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_atom_feed']['type'] = 'link_title_plain';
  /* Contextual filter: Commerce Product: Product ID */
  $handler->display->display_options['arguments']['product_id']['id'] = 'product_id';
  $handler->display->display_options['arguments']['product_id']['table'] = 'commerce_product';
  $handler->display->display_options['arguments']['product_id']['field'] = 'product_id';
  $handler->display->display_options['arguments']['product_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['product_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['product_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['product_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Commerce Product: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );
  $translatables['product_links'] = array(
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
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('<a href="[field_atom_feed-url]"><img src="/sites/all/themes/custom/kms/images/rss.png"></a>'),
    t('All'),
  );
  $export['product_links'] = $view;

  return $export;
}
