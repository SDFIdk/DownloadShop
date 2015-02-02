<?php
/**
 * @file
 * partnerpages.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function partnerpages_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'partner';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Partner';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« Første';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ Forrige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'Næste ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'Sidste »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Topbillede */
  $handler->display->display_options['fields']['field_partner_top_img']['id'] = 'field_partner_top_img';
  $handler->display->display_options['fields']['field_partner_top_img']['table'] = 'field_data_field_partner_top_img';
  $handler->display->display_options['fields']['field_partner_top_img']['field'] = 'field_partner_top_img';
  $handler->display->display_options['fields']['field_partner_top_img']['label'] = '';
  $handler->display->display_options['fields']['field_partner_top_img']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_partner_top_img']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_top_img']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_partner_top_img']['settings'] = array(
    'image_style' => 'partnerlist',
    'image_link' => '',
  );
  /* Field: Content: Teaser-text */
  $handler->display->display_options['fields']['field_teaser_text']['id'] = 'field_teaser_text';
  $handler->display->display_options['fields']['field_teaser_text']['table'] = 'field_data_field_teaser_text';
  $handler->display->display_options['fields']['field_teaser_text']['field'] = 'field_teaser_text';
  $handler->display->display_options['fields']['field_teaser_text']['label'] = '';
  $handler->display->display_options['fields']['field_teaser_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_teaser_text']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['field_teaser_text']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_teaser_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser_text']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Partner logo */
  $handler->display->display_options['fields']['field_partner_logo']['id'] = 'field_partner_logo';
  $handler->display->display_options['fields']['field_partner_logo']['table'] = 'field_data_field_partner_logo';
  $handler->display->display_options['fields']['field_partner_logo']['field'] = 'field_partner_logo';
  $handler->display->display_options['fields']['field_partner_logo']['label'] = '';
  $handler->display->display_options['fields']['field_partner_logo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_partner_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_partner_logo']['settings'] = array(
    'image_style' => 'partner_logo',
    'image_link' => '',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="[path]">[field_partner_top_img]</a>
<div class="content">
<div class="logo">
<a href="[path]">
[field_partner_logo]
</a>
</div>
<div class="text">
<div class="read-more">
<a href="[path]">
Læs mere
</a>
</div>
</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'partner' => 'partner',
  );

  /* Display: Partnerlist */
  $handler = $view->new_display('panel_pane', 'Partnerlist', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_rel'] = '';
  /* Field: Content: Topbillede */
  $handler->display->display_options['fields']['field_partner_top_img']['id'] = 'field_partner_top_img';
  $handler->display->display_options['fields']['field_partner_top_img']['table'] = 'field_data_field_partner_top_img';
  $handler->display->display_options['fields']['field_partner_top_img']['field'] = 'field_partner_top_img';
  $handler->display->display_options['fields']['field_partner_top_img']['label'] = '';
  $handler->display->display_options['fields']['field_partner_top_img']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_partner_top_img']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_top_img']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_partner_top_img']['settings'] = array(
    'image_style' => 'partnerlist',
    'image_link' => '',
  );
  /* Field: Content: Teaser-text */
  $handler->display->display_options['fields']['field_teaser_text']['id'] = 'field_teaser_text';
  $handler->display->display_options['fields']['field_teaser_text']['table'] = 'field_data_field_teaser_text';
  $handler->display->display_options['fields']['field_teaser_text']['field'] = 'field_teaser_text';
  $handler->display->display_options['fields']['field_teaser_text']['label'] = '';
  $handler->display->display_options['fields']['field_teaser_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_teaser_text']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['field_teaser_text']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_teaser_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser_text']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Partner logo */
  $handler->display->display_options['fields']['field_partner_logo']['id'] = 'field_partner_logo';
  $handler->display->display_options['fields']['field_partner_logo']['table'] = 'field_data_field_partner_logo';
  $handler->display->display_options['fields']['field_partner_logo']['field'] = 'field_partner_logo';
  $handler->display->display_options['fields']['field_partner_logo']['label'] = '';
  $handler->display->display_options['fields']['field_partner_logo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_partner_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_partner_logo']['settings'] = array(
    'image_style' => 'partner_logo',
    'image_link' => '',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Rewrite */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Rewrite';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="[path]">[field_partner_top_img]</a>
<div class="content">
<div class="logo">
[title]
</div>
<div class="text">
<div class="read-more">
<a href="[path]">
Læs mere
</a>
</div>
</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $translatables['partner'] = array(
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
    t('<a href="[path]">[field_partner_top_img]</a>
<div class="content">
<div class="logo">
<a href="[path]">
[field_partner_logo]
</a>
</div>
<div class="text">
<div class="read-more">
<a href="[path]">
Læs mere
</a>
</div>
</div>
</div>'),
    t('Partnerlist'),
    t('<a href="[path]">[field_partner_top_img]</a>
<div class="content">
<div class="logo">
[title]
</div>
<div class="text">
<div class="read-more">
<a href="[path]">
Læs mere
</a>
</div>
</div>
</div>'),
    t('View panes'),
  );
  $export['partner'] = $view;

  return $export;
}
