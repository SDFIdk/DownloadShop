<?php
/**
 * @file
 * partnerpages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function partnerpages_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_10';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -22;
  $handler->conf = array(
    'title' => 'Partner',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'partner' => 'partner',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol_kms';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'main-content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '4f952ff1-081a-4554-9181-c1b1270a15f2';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_10';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2b11940a-85da-406f-8a8c-feb24a442242';
  $pane->panel = 'bottom';
  $pane->type = 'panels_mini';
  $pane->subtype = 'bottom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'bottom',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2b11940a-85da-406f-8a8c-feb24a442242';
  $display->content['new-2b11940a-85da-406f-8a8c-feb24a442242'] = $pane;
  $display->panels['bottom'][0] = 'new-2b11940a-85da-406f-8a8c-feb24a442242';
  $pane = new stdClass();
  $pane->pid = 'new-54b37507-cff1-4ccc-9a99-ada3b733478a';
  $pane->panel = 'main-content';
  $pane->type = 'page_messages';
  $pane->subtype = 'page_messages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '54b37507-cff1-4ccc-9a99-ada3b733478a';
  $display->content['new-54b37507-cff1-4ccc-9a99-ada3b733478a'] = $pane;
  $display->panels['main-content'][0] = 'new-54b37507-cff1-4ccc-9a99-ada3b733478a';
  $pane = new stdClass();
  $pane->pid = 'new-26e7176a-e4fa-4240-9a02-81f51f821208';
  $pane->panel = 'main-content';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_partner_top_img';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'topimage_partner',
      'image_link' => '',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'partner-topimg',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '26e7176a-e4fa-4240-9a02-81f51f821208';
  $display->content['new-26e7176a-e4fa-4240-9a02-81f51f821208'] = $pane;
  $display->panels['main-content'][1] = 'new-26e7176a-e4fa-4240-9a02-81f51f821208';
  $pane = new stdClass();
  $pane->pid = 'new-1849f9b2-f3fc-46ab-8f01-3309a9f43fd6';
  $pane->panel = 'main-content';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_partner_logo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'partner_logo',
      'image_link' => '',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'partner-logo',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '1849f9b2-f3fc-46ab-8f01-3309a9f43fd6';
  $display->content['new-1849f9b2-f3fc-46ab-8f01-3309a9f43fd6'] = $pane;
  $display->panels['main-content'][2] = 'new-1849f9b2-f3fc-46ab-8f01-3309a9f43fd6';
  $pane = new stdClass();
  $pane->pid = 'new-84de1bd7-6f4b-4e04-a195-760db79effce';
  $pane->panel = 'main-content';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '84de1bd7-6f4b-4e04-a195-760db79effce';
  $display->content['new-84de1bd7-6f4b-4e04-a195-760db79effce'] = $pane;
  $display->panels['main-content'][3] = 'new-84de1bd7-6f4b-4e04-a195-760db79effce';
  $pane = new stdClass();
  $pane->pid = 'new-b19ada5c-3893-4308-8ec5-1085741c4c4f';
  $pane->panel = 'main-content';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_text_column_1_partner';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'page-column first',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'b19ada5c-3893-4308-8ec5-1085741c4c4f';
  $display->content['new-b19ada5c-3893-4308-8ec5-1085741c4c4f'] = $pane;
  $display->panels['main-content'][4] = 'new-b19ada5c-3893-4308-8ec5-1085741c4c4f';
  $pane = new stdClass();
  $pane->pid = 'new-434c4efa-269c-44a8-8de9-a59480a9a4c8';
  $pane->panel = 'main-content';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_text_column_2_partner';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'page-column last',
  );
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '434c4efa-269c-44a8-8de9-a59480a9a4c8';
  $display->content['new-434c4efa-269c-44a8-8de9-a59480a9a4c8'] = $pane;
  $display->panels['main-content'][5] = 'new-434c4efa-269c-44a8-8de9-a59480a9a4c8';
  $pane = new stdClass();
  $pane->pid = 'new-76102362-2eef-43b6-8ff9-b5eb8ac2ad0a';
  $pane->panel = 'main-content';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_images_middle';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'colorbox',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'image_style' => '',
      'image_link' => '',
      'colorbox_node_style' => 'partner_image_middle',
      'colorbox_image_style' => 'partner_image_middle_large',
      'colorbox_gallery' => 'post',
      'colorbox_gallery_custom' => '',
      'colorbox_caption' => 'none',
      'colorbox_caption_custom' => '',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Cases / Referencer',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'partner-images-middle',
  );
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '76102362-2eef-43b6-8ff9-b5eb8ac2ad0a';
  $display->content['new-76102362-2eef-43b6-8ff9-b5eb8ac2ad0a'] = $pane;
  $display->panels['main-content'][6] = 'new-76102362-2eef-43b6-8ff9-b5eb8ac2ad0a';
  $pane = new stdClass();
  $pane->pid = 'new-3e46fffd-7a65-4f9b-8835-3fac30473418';
  $pane->panel = 'main-content';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_cases_referencer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'text_default',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Cases / Referencer',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'partner-cases-references',
  );
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '3e46fffd-7a65-4f9b-8835-3fac30473418';
  $display->content['new-3e46fffd-7a65-4f9b-8835-3fac30473418'] = $pane;
  $display->panels['main-content'][7] = 'new-3e46fffd-7a65-4f9b-8835-3fac30473418';
  $pane = new stdClass();
  $pane->pid = 'new-085bc350-a021-4dd0-af7c-81d3b8ba9805';
  $pane->panel = 'main-content';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_partner_contact';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Kontakt',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'partner-contact',
  );
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '085bc350-a021-4dd0-af7c-81d3b8ba9805';
  $display->content['new-085bc350-a021-4dd0-af7c-81d3b8ba9805'] = $pane;
  $display->panels['main-content'][8] = 'new-085bc350-a021-4dd0-af7c-81d3b8ba9805';
  $pane = new stdClass();
  $pane->pid = 'new-c109a93e-61eb-4599-8e90-5d1bcd2fd0da';
  $pane->panel = 'top';
  $pane->type = 'panels_mini';
  $pane->subtype = 'top';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c109a93e-61eb-4599-8e90-5d1bcd2fd0da';
  $display->content['new-c109a93e-61eb-4599-8e90-5d1bcd2fd0da'] = $pane;
  $display->panels['top'][0] = 'new-c109a93e-61eb-4599-8e90-5d1bcd2fd0da';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_10'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_9';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -23;
  $handler->conf = array(
    'title' => 'Partner list',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'partner_list' => 'partner_list',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol_kms';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'main-content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '040c4309-88f7-45d7-84f5-f9df315a6239';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_9';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-28d0aafb-20ba-4b1f-9e53-b6cb2b2b45a3';
  $pane->panel = 'bottom';
  $pane->type = 'panels_mini';
  $pane->subtype = 'bottom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'bottom',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '28d0aafb-20ba-4b1f-9e53-b6cb2b2b45a3';
  $display->content['new-28d0aafb-20ba-4b1f-9e53-b6cb2b2b45a3'] = $pane;
  $display->panels['bottom'][0] = 'new-28d0aafb-20ba-4b1f-9e53-b6cb2b2b45a3';
  $pane = new stdClass();
  $pane->pid = 'new-431070b3-3714-4e42-bfab-8185a4137f5e';
  $pane->panel = 'main-content';
  $pane->type = 'page_messages';
  $pane->subtype = 'page_messages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '431070b3-3714-4e42-bfab-8185a4137f5e';
  $display->content['new-431070b3-3714-4e42-bfab-8185a4137f5e'] = $pane;
  $display->panels['main-content'][0] = 'new-431070b3-3714-4e42-bfab-8185a4137f5e';
  $pane = new stdClass();
  $pane->pid = 'new-82fde441-acd3-4ac0-8ca9-3c1e9caee7cb';
  $pane->panel = 'main-content';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '82fde441-acd3-4ac0-8ca9-3c1e9caee7cb';
  $display->content['new-82fde441-acd3-4ac0-8ca9-3c1e9caee7cb'] = $pane;
  $display->panels['main-content'][1] = 'new-82fde441-acd3-4ac0-8ca9-3c1e9caee7cb';
  $pane = new stdClass();
  $pane->pid = 'new-71b5ff8a-9969-48b7-a92b-5eb9915567f9';
  $pane->panel = 'main-content';
  $pane->type = 'views_panes';
  $pane->subtype = 'partner-panel_pane_1';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'partner-list',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '71b5ff8a-9969-48b7-a92b-5eb9915567f9';
  $display->content['new-71b5ff8a-9969-48b7-a92b-5eb9915567f9'] = $pane;
  $display->panels['main-content'][2] = 'new-71b5ff8a-9969-48b7-a92b-5eb9915567f9';
  $pane = new stdClass();
  $pane->pid = 'new-989e0bda-515b-421d-bd0a-e190c0286f6b';
  $pane->panel = 'top';
  $pane->type = 'panels_mini';
  $pane->subtype = 'top';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '989e0bda-515b-421d-bd0a-e190c0286f6b';
  $display->content['new-989e0bda-515b-421d-bd0a-e190c0286f6b'] = $pane;
  $display->panels['top'][0] = 'new-989e0bda-515b-421d-bd0a-e190c0286f6b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_9'] = $handler;

  return $export;
}
