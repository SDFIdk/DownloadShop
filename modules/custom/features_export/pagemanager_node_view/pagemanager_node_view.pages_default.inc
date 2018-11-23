<?php
/**
 * @file
 * pagemanager_node_view.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function pagemanager_node_view_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Product listing',
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
              'product_listing' => 'product_listing',
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
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '396504e9-63d4-42f5-a068-4760321a0160';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9d543751-db12-41bd-9713-aa28197e2200';
  $pane->panel = 'bottom';
  $pane->type = 'panels_mini';
  $pane->subtype = 'bottom';
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
  $pane->uuid = '9d543751-db12-41bd-9713-aa28197e2200';
  $display->content['new-9d543751-db12-41bd-9713-aa28197e2200'] = $pane;
  $display->panels['bottom'][0] = 'new-9d543751-db12-41bd-9713-aa28197e2200';
  $pane = new stdClass();
  $pane->pid = 'new-831901c5-9690-4e61-bc3a-1313c1dce26f';
  $pane->panel = 'left';
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
  $pane->uuid = '831901c5-9690-4e61-bc3a-1313c1dce26f';
  $display->content['new-831901c5-9690-4e61-bc3a-1313c1dce26f'] = $pane;
  $display->panels['left'][0] = 'new-831901c5-9690-4e61-bc3a-1313c1dce26f';
  $pane = new stdClass();
  $pane->pid = 'new-fb398a78-5ac1-4ab0-b4f1-a406d2598492';
  $pane->panel = 'left';
  $pane->type = 'views';
  $pane->subtype = 'product_list';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
            1 => 4,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '10',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => 'content/geodataprodukter',
    'display' => 'default',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'product-list',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'fb398a78-5ac1-4ab0-b4f1-a406d2598492';
  $display->content['new-fb398a78-5ac1-4ab0-b4f1-a406d2598492'] = $pane;
  $display->panels['left'][1] = 'new-fb398a78-5ac1-4ab0-b4f1-a406d2598492';
  $pane = new stdClass();
  $pane->pid = 'new-9ec9aaf8-119a-4ae1-818d-b65bf47c4221';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'user-login';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Log ind',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9ec9aaf8-119a-4ae1-818d-b65bf47c4221';
  $display->content['new-9ec9aaf8-119a-4ae1-818d-b65bf47c4221'] = $pane;
  $display->panels['right'][0] = 'new-9ec9aaf8-119a-4ae1-818d-b65bf47c4221';
  $pane = new stdClass();
  $pane->pid = 'new-1eba9445-f2e1-4e5c-9820-375b0e4ce54b';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'commerce_cart-cart';
  $pane->shown = FALSE;
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '1eba9445-f2e1-4e5c-9820-375b0e4ce54b';
  $display->content['new-1eba9445-f2e1-4e5c-9820-375b0e4ce54b'] = $pane;
  $display->panels['right'][1] = 'new-1eba9445-f2e1-4e5c-9820-375b0e4ce54b';
  $pane = new stdClass();
  $pane->pid = 'new-db68aa4a-24ce-4127-95d4-638b9610c202';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_right_box';
  $pane->shown = FALSE;
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'db68aa4a-24ce-4127-95d4-638b9610c202';
  $display->content['new-db68aa4a-24ce-4127-95d4-638b9610c202'] = $pane;
  $display->panels['right'][2] = 'new-db68aa4a-24ce-4127-95d4-638b9610c202';
  $pane = new stdClass();
  $pane->pid = 'new-506f1141-8119-4fdb-af64-ac91b68dae92';
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
  $pane->uuid = '506f1141-8119-4fdb-af64-ac91b68dae92';
  $display->content['new-506f1141-8119-4fdb-af64-ac91b68dae92'] = $pane;
  $display->panels['top'][0] = 'new-506f1141-8119-4fdb-af64-ac91b68dae92';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Front',
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
              'front' => 'front',
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
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '40e49900-30e3-4c3c-bc69-f80739d840ea';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-cc3e9a85-ad9e-472b-bff7-280a477a2ef2';
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
  $pane->uuid = 'cc3e9a85-ad9e-472b-bff7-280a477a2ef2';
  $display->content['new-cc3e9a85-ad9e-472b-bff7-280a477a2ef2'] = $pane;
  $display->panels['bottom'][0] = 'new-cc3e9a85-ad9e-472b-bff7-280a477a2ef2';
  $pane = new stdClass();
  $pane->pid = 'new-00b5b1f8-8109-4b2a-af98-e7ba9c42b38a';
  $pane->panel = 'left';
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
  $pane->uuid = '00b5b1f8-8109-4b2a-af98-e7ba9c42b38a';
  $display->content['new-00b5b1f8-8109-4b2a-af98-e7ba9c42b38a'] = $pane;
  $display->panels['left'][0] = 'new-00b5b1f8-8109-4b2a-af98-e7ba9c42b38a';
  $pane = new stdClass();
  $pane->pid = 'new-ce8bb0ed-846c-4c43-b6fb-947462a06e90';
  $pane->panel = 'left';
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
  $pane->uuid = 'ce8bb0ed-846c-4c43-b6fb-947462a06e90';
  $display->content['new-ce8bb0ed-846c-4c43-b6fb-947462a06e90'] = $pane;
  $display->panels['left'][1] = 'new-ce8bb0ed-846c-4c43-b6fb-947462a06e90';
  $pane = new stdClass();
  $pane->pid = 'new-88a9e9b3-0dce-4773-a19f-e4f4200f538b';
  $pane->panel = 'left';
  $pane->type = 'node_body';
  $pane->subtype = 'node_body';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '88a9e9b3-0dce-4773-a19f-e4f4200f538b';
  $display->content['new-88a9e9b3-0dce-4773-a19f-e4f4200f538b'] = $pane;
  $display->panels['left'][2] = 'new-88a9e9b3-0dce-4773-a19f-e4f4200f538b';
  $pane = new stdClass();
  $pane->pid = 'new-200f4729-f3e2-4886-b8b3-4b4fe2ea6c5d';
  $pane->panel = 'left';
  $pane->type = 'views_panes';
  $pane->subtype = 'products_front-panel_pane_1';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'products-front',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '200f4729-f3e2-4886-b8b3-4b4fe2ea6c5d';
  $display->content['new-200f4729-f3e2-4886-b8b3-4b4fe2ea6c5d'] = $pane;
  $display->panels['left'][3] = 'new-200f4729-f3e2-4886-b8b3-4b4fe2ea6c5d';
  $pane = new stdClass();
  $pane->pid = 'new-2606a862-986e-4516-8d01-63745c984a7b';
  $pane->panel = 'left';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'Gå til download.kortforsyning.dk',
    'title_heading' => 'h2',
    'body' => '<p>&nbsp;</p><p>Vi afbryder lige din surfing.</p><p>&nbsp;</p><p>&nbsp;</p><p>Du er kommet på afveje og skal fortsætte på <a href="https://download.kortforsyningen.dk">https://www.download.kortforsyningen.dk</a></p>',
    'format' => 'filtered_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '2606a862-986e-4516-8d01-63745c984a7b';
  $display->content['new-2606a862-986e-4516-8d01-63745c984a7b'] = $pane;
  $display->panels['left'][4] = 'new-2606a862-986e-4516-8d01-63745c984a7b';
  $pane = new stdClass();
  $pane->pid = 'new-379d717a-184a-4175-ad2a-ddebe16563cb';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'user-login';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Log ind',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '379d717a-184a-4175-ad2a-ddebe16563cb';
  $display->content['new-379d717a-184a-4175-ad2a-ddebe16563cb'] = $pane;
  $display->panels['right'][0] = 'new-379d717a-184a-4175-ad2a-ddebe16563cb';
  $pane = new stdClass();
  $pane->pid = 'new-4a89459d-ad24-4af9-ba95-3595c36501bb';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'commerce_cart-cart';
  $pane->shown = FALSE;
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '4a89459d-ad24-4af9-ba95-3595c36501bb';
  $display->content['new-4a89459d-ad24-4af9-ba95-3595c36501bb'] = $pane;
  $display->panels['right'][1] = 'new-4a89459d-ad24-4af9-ba95-3595c36501bb';
  $pane = new stdClass();
  $pane->pid = 'new-34614434-5898-4960-bcef-79d7ad76832b';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_right_box';
  $pane->shown = FALSE;
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
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '34614434-5898-4960-bcef-79d7ad76832b';
  $display->content['new-34614434-5898-4960-bcef-79d7ad76832b'] = $pane;
  $display->panels['right'][2] = 'new-34614434-5898-4960-bcef-79d7ad76832b';
  $pane = new stdClass();
  $pane->pid = 'new-f325212a-41a2-45f0-a407-534e0537c8ec';
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
  $pane->uuid = 'f325212a-41a2-45f0-a407-534e0537c8ec';
  $display->content['new-f325212a-41a2-45f0-a407-534e0537c8ec'] = $pane;
  $display->panels['top'][0] = 'new-f325212a-41a2-45f0-a407-534e0537c8ec';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_3';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -21;
  $handler->conf = array(
    'title' => 'Default',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a6d0841e-cf81-46fd-8f55-674ad383ef42';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-7dd19b7f-16c6-4d75-9d20-443e9fd0d2e8';
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
  $pane->uuid = '7dd19b7f-16c6-4d75-9d20-443e9fd0d2e8';
  $display->content['new-7dd19b7f-16c6-4d75-9d20-443e9fd0d2e8'] = $pane;
  $display->panels['bottom'][0] = 'new-7dd19b7f-16c6-4d75-9d20-443e9fd0d2e8';
  $pane = new stdClass();
  $pane->pid = 'new-1e4c93b8-6ff0-4a92-a7d9-5acc97fbaf92';
  $pane->panel = 'left';
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
  $pane->uuid = '1e4c93b8-6ff0-4a92-a7d9-5acc97fbaf92';
  $display->content['new-1e4c93b8-6ff0-4a92-a7d9-5acc97fbaf92'] = $pane;
  $display->panels['left'][0] = 'new-1e4c93b8-6ff0-4a92-a7d9-5acc97fbaf92';
  $pane = new stdClass();
  $pane->pid = 'new-f22bf65c-d3cd-4b9c-9d11-27fd844dc75b';
  $pane->panel = 'left';
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
  $pane->uuid = 'f22bf65c-d3cd-4b9c-9d11-27fd844dc75b';
  $display->content['new-f22bf65c-d3cd-4b9c-9d11-27fd844dc75b'] = $pane;
  $display->panels['left'][1] = 'new-f22bf65c-d3cd-4b9c-9d11-27fd844dc75b';
  $pane = new stdClass();
  $pane->pid = 'new-20c2a56d-9b5a-4967-816f-65fafaf7a9a5';
  $pane->panel = 'left';
  $pane->type = 'node_body';
  $pane->subtype = 'node_body';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '20c2a56d-9b5a-4967-816f-65fafaf7a9a5';
  $display->content['new-20c2a56d-9b5a-4967-816f-65fafaf7a9a5'] = $pane;
  $display->panels['left'][2] = 'new-20c2a56d-9b5a-4967-816f-65fafaf7a9a5';
  $pane = new stdClass();
  $pane->pid = 'new-00d96e7f-789e-403a-b34c-dd525606d650';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'user-login';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Log ind',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '00d96e7f-789e-403a-b34c-dd525606d650';
  $display->content['new-00d96e7f-789e-403a-b34c-dd525606d650'] = $pane;
  $display->panels['right'][0] = 'new-00d96e7f-789e-403a-b34c-dd525606d650';
  $pane = new stdClass();
  $pane->pid = 'new-57b89f72-084f-42eb-8162-44e42203e23b';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_right_box';
  $pane->shown = FALSE;
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '57b89f72-084f-42eb-8162-44e42203e23b';
  $display->content['new-57b89f72-084f-42eb-8162-44e42203e23b'] = $pane;
  $display->panels['right'][1] = 'new-57b89f72-084f-42eb-8162-44e42203e23b';
  $pane = new stdClass();
  $pane->pid = 'new-d8f36741-bc87-4f23-8b3a-91685159e6c6';
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
  $pane->uuid = 'd8f36741-bc87-4f23-8b3a-91685159e6c6';
  $display->content['new-d8f36741-bc87-4f23-8b3a-91685159e6c6'] = $pane;
  $display->panels['top'][0] = 'new-d8f36741-bc87-4f23-8b3a-91685159e6c6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_3'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_5';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'User registration form',
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
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'user_registration_form' => 'user_registration_form',
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
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e13f66a9-f258-430d-be33-50bab2327b88';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_5';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e9e99ecb-6a70-429d-a1be-d89c8d48dc8f';
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
  $pane->uuid = 'e9e99ecb-6a70-429d-a1be-d89c8d48dc8f';
  $display->content['new-e9e99ecb-6a70-429d-a1be-d89c8d48dc8f'] = $pane;
  $display->panels['bottom'][0] = 'new-e9e99ecb-6a70-429d-a1be-d89c8d48dc8f';
  $pane = new stdClass();
  $pane->pid = 'new-68eab971-f7ce-4dba-84db-d2d09c0607ec';
  $pane->panel = 'left';
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
  $pane->uuid = '68eab971-f7ce-4dba-84db-d2d09c0607ec';
  $display->content['new-68eab971-f7ce-4dba-84db-d2d09c0607ec'] = $pane;
  $display->panels['left'][0] = 'new-68eab971-f7ce-4dba-84db-d2d09c0607ec';
  $pane = new stdClass();
  $pane->pid = 'new-3994a691-e8f2-46f0-8c75-8d7520e9e72d';
  $pane->panel = 'left';
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
  $pane->uuid = '3994a691-e8f2-46f0-8c75-8d7520e9e72d';
  $display->content['new-3994a691-e8f2-46f0-8c75-8d7520e9e72d'] = $pane;
  $display->panels['left'][1] = 'new-3994a691-e8f2-46f0-8c75-8d7520e9e72d';
  $pane = new stdClass();
  $pane->pid = 'new-6e746d3e-1e9b-442b-8330-e111f2162c2c';
  $pane->panel = 'left';
  $pane->type = 'kms_user_register_pane';
  $pane->subtype = 'kms_user_register_pane';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'registration-form',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '6e746d3e-1e9b-442b-8330-e111f2162c2c';
  $display->content['new-6e746d3e-1e9b-442b-8330-e111f2162c2c'] = $pane;
  $display->panels['left'][2] = 'new-6e746d3e-1e9b-442b-8330-e111f2162c2c';
  $pane = new stdClass();
  $pane->pid = 'new-fe36f1f5-0166-4003-89e3-8f706bb9ef5e';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_right_box';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'user-register',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'fe36f1f5-0166-4003-89e3-8f706bb9ef5e';
  $display->content['new-fe36f1f5-0166-4003-89e3-8f706bb9ef5e'] = $pane;
  $display->panels['right'][0] = 'new-fe36f1f5-0166-4003-89e3-8f706bb9ef5e';
  $pane = new stdClass();
  $pane->pid = 'new-b566e311-d14c-49e2-b15d-feb25958c1ed';
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
  $pane->uuid = 'b566e311-d14c-49e2-b15d-feb25958c1ed';
  $display->content['new-b566e311-d14c-49e2-b15d-feb25958c1ed'] = $pane;
  $display->panels['top'][0] = 'new-b566e311-d14c-49e2-b15d-feb25958c1ed';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_5'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_6';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Product display',
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
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'product_display' => 'product_display',
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
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0d5f0439-d167-47d6-be95-7b72af478253';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_6';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-6c4a1d62-c342-4d76-b1b3-82247da688f0';
  $pane->panel = 'bottom';
  $pane->type = 'panels_mini';
  $pane->subtype = 'bottom';
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
  $pane->uuid = '6c4a1d62-c342-4d76-b1b3-82247da688f0';
  $display->content['new-6c4a1d62-c342-4d76-b1b3-82247da688f0'] = $pane;
  $display->panels['bottom'][0] = 'new-6c4a1d62-c342-4d76-b1b3-82247da688f0';
  $pane = new stdClass();
  $pane->pid = 'new-1ab25f07-9998-47eb-a5b8-488287344eca';
  $pane->panel = 'left';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
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
  $pane->uuid = '1ab25f07-9998-47eb-a5b8-488287344eca';
  $display->content['new-1ab25f07-9998-47eb-a5b8-488287344eca'] = $pane;
  $display->panels['left'][0] = 'new-1ab25f07-9998-47eb-a5b8-488287344eca';
  $pane = new stdClass();
  $pane->pid = 'new-4b81800d-a803-4e2a-ac5b-9c82e105e9bc';
  $pane->panel = 'left';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '4b81800d-a803-4e2a-ac5b-9c82e105e9bc';
  $display->content['new-4b81800d-a803-4e2a-ac5b-9c82e105e9bc'] = $pane;
  $display->panels['left'][1] = 'new-4b81800d-a803-4e2a-ac5b-9c82e105e9bc';
  $pane = new stdClass();
  $pane->pid = 'new-e82a851a-539d-4e0c-930f-0a7d1b28fe01';
  $pane->panel = 'left';
  $pane->type = 'kms_mapwidget_pane';
  $pane->subtype = 'kms_mapwidget_pane';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'e82a851a-539d-4e0c-930f-0a7d1b28fe01';
  $display->content['new-e82a851a-539d-4e0c-930f-0a7d1b28fe01'] = $pane;
  $display->panels['left'][2] = 'new-e82a851a-539d-4e0c-930f-0a7d1b28fe01';
  $pane = new stdClass();
  $pane->pid = 'new-92fc627f-4add-4b68-9ca7-b974d4a150c1';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'user-login';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Log ind',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '92fc627f-4add-4b68-9ca7-b974d4a150c1';
  $display->content['new-92fc627f-4add-4b68-9ca7-b974d4a150c1'] = $pane;
  $display->panels['right'][0] = 'new-92fc627f-4add-4b68-9ca7-b974d4a150c1';
  $pane = new stdClass();
  $pane->pid = 'new-fda8dc64-cd98-470f-9530-99c672c865bb';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'commerce_cart-cart';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => 'Indkøbskurv',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'fda8dc64-cd98-470f-9530-99c672c865bb';
  $display->content['new-fda8dc64-cd98-470f-9530-99c672c865bb'] = $pane;
  $display->panels['right'][1] = 'new-fda8dc64-cd98-470f-9530-99c672c865bb';
  $pane = new stdClass();
  $pane->pid = 'new-4464c0f0-602d-44bf-ac66-328f6d32a283';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_right_box';
  $pane->shown = FALSE;
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '4464c0f0-602d-44bf-ac66-328f6d32a283';
  $display->content['new-4464c0f0-602d-44bf-ac66-328f6d32a283'] = $pane;
  $display->panels['right'][2] = 'new-4464c0f0-602d-44bf-ac66-328f6d32a283';
  $pane = new stdClass();
  $pane->pid = 'new-4ae20319-524b-4b08-b415-c9435389ad92';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'how_to_order';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '',
    'format' => 'filtered_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '4ae20319-524b-4b08-b415-c9435389ad92';
  $display->content['new-4ae20319-524b-4b08-b415-c9435389ad92'] = $pane;
  $display->panels['right'][3] = 'new-4ae20319-524b-4b08-b415-c9435389ad92';
  $pane = new stdClass();
  $pane->pid = 'new-a95a0a9e-196f-4331-8d70-728676af59b7';
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
  $pane->uuid = 'a95a0a9e-196f-4331-8d70-728676af59b7';
  $display->content['new-a95a0a9e-196f-4331-8d70-728676af59b7'] = $pane;
  $display->panels['top'][0] = 'new-a95a0a9e-196f-4331-8d70-728676af59b7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_6'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_7';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -25;
  $handler->conf = array(
    'title' => 'My downloads',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'User',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'downloads' => 'downloads',
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
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Mine downloads';
  $display->uuid = 'd418e7f9-721e-427a-993b-e3ab8c8ab32f';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_7';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1975c8d7-248a-4623-a6f1-4fb6fead62b4';
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
  $pane->uuid = '1975c8d7-248a-4623-a6f1-4fb6fead62b4';
  $display->content['new-1975c8d7-248a-4623-a6f1-4fb6fead62b4'] = $pane;
  $display->panels['bottom'][0] = 'new-1975c8d7-248a-4623-a6f1-4fb6fead62b4';
  $pane = new stdClass();
  $pane->pid = 'new-d9a97ae7-dae6-4aeb-9fe7-2e9613e64d01';
  $pane->panel = 'left';
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
  $pane->uuid = 'd9a97ae7-dae6-4aeb-9fe7-2e9613e64d01';
  $display->content['new-d9a97ae7-dae6-4aeb-9fe7-2e9613e64d01'] = $pane;
  $display->panels['left'][0] = 'new-d9a97ae7-dae6-4aeb-9fe7-2e9613e64d01';
  $pane = new stdClass();
  $pane->pid = 'new-ddfab662-d86c-48b5-8fbd-a0dca0953ac7';
  $pane->panel = 'left';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
    'override_title' => 0,
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
  $pane->uuid = 'ddfab662-d86c-48b5-8fbd-a0dca0953ac7';
  $display->content['new-ddfab662-d86c-48b5-8fbd-a0dca0953ac7'] = $pane;
  $display->panels['left'][1] = 'new-ddfab662-d86c-48b5-8fbd-a0dca0953ac7';
  $pane = new stdClass();
  $pane->pid = 'new-3adbb5c8-58f9-4a28-b6b8-ee1e51869aa2';
  $pane->panel = 'left';
  $pane->type = 'kms_mydownloads';
  $pane->subtype = 'kms_mydownloads';
  $pane->shown = FALSE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'context_user_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '3adbb5c8-58f9-4a28-b6b8-ee1e51869aa2';
  $display->content['new-3adbb5c8-58f9-4a28-b6b8-ee1e51869aa2'] = $pane;
  $display->panels['left'][2] = 'new-3adbb5c8-58f9-4a28-b6b8-ee1e51869aa2';
  $pane = new stdClass();
  $pane->pid = 'new-29ffb7c7-2027-4cf2-a2d0-ba32f6fd6ce2';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'user-login';
  $pane->shown = FALSE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 1,
          ),
        ),
        'context' => 'context_user_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
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
  $pane->uuid = '29ffb7c7-2027-4cf2-a2d0-ba32f6fd6ce2';
  $display->content['new-29ffb7c7-2027-4cf2-a2d0-ba32f6fd6ce2'] = $pane;
  $display->panels['left'][3] = 'new-29ffb7c7-2027-4cf2-a2d0-ba32f6fd6ce2';
  $pane = new stdClass();
  $pane->pid = 'new-80660b9d-c426-4f66-ad1c-a7c1c4e875f6';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_right_box';
  $pane->shown = FALSE;
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
  $pane->uuid = '80660b9d-c426-4f66-ad1c-a7c1c4e875f6';
  $display->content['new-80660b9d-c426-4f66-ad1c-a7c1c4e875f6'] = $pane;
  $display->panels['right'][0] = 'new-80660b9d-c426-4f66-ad1c-a7c1c4e875f6';
  $pane = new stdClass();
  $pane->pid = 'new-1a2045f1-8dd4-4a17-927d-ba5ddc2dba99';
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
  $pane->uuid = '1a2045f1-8dd4-4a17-927d-ba5ddc2dba99';
  $display->content['new-1a2045f1-8dd4-4a17-927d-ba5ddc2dba99'] = $pane;
  $display->panels['top'][0] = 'new-1a2045f1-8dd4-4a17-927d-ba5ddc2dba99';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_7'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_8';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -24;
  $handler->conf = array(
    'title' => 'Bundle display',
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
              'access_bundle' => 'access_bundle',
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Bundle display';
  $display->uuid = '10f8da5d-d75d-4362-b0e2-8c5f5e9ae2b0';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_8';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-71b0c675-1cce-4d0f-bf93-80efbb182d05';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'top';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'is_colorbox_node',
        'settings' => NULL,
        'not' => TRUE,
      ),
    ),
  );
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
  $pane->uuid = '71b0c675-1cce-4d0f-bf93-80efbb182d05';
  $display->content['new-71b0c675-1cce-4d0f-bf93-80efbb182d05'] = $pane;
  $display->panels['middle'][0] = 'new-71b0c675-1cce-4d0f-bf93-80efbb182d05';
  $pane = new stdClass();
  $pane->pid = 'new-425434ec-d9be-462f-b0f7-77b7188ff993';
  $pane->panel = 'middle';
  $pane->type = 'node_title';
  $pane->subtype = 'node_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'link' => 0,
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '425434ec-d9be-462f-b0f7-77b7188ff993';
  $display->content['new-425434ec-d9be-462f-b0f7-77b7188ff993'] = $pane;
  $display->panels['middle'][1] = 'new-425434ec-d9be-462f-b0f7-77b7188ff993';
  $pane = new stdClass();
  $pane->pid = 'new-d283b66a-f9c7-4e10-843e-7fa317374520';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
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
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'd283b66a-f9c7-4e10-843e-7fa317374520';
  $display->content['new-d283b66a-f9c7-4e10-843e-7fa317374520'] = $pane;
  $display->panels['middle'][2] = 'new-d283b66a-f9c7-4e10-843e-7fa317374520';
  $pane = new stdClass();
  $pane->pid = 'new-d4934202-97f8-465b-a7b5-cd876a99afd4';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_bundle_webservices_geo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'kms_permissions_service_bundles',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
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
  $pane->uuid = 'd4934202-97f8-465b-a7b5-cd876a99afd4';
  $display->content['new-d4934202-97f8-465b-a7b5-cd876a99afd4'] = $pane;
  $display->panels['middle'][3] = 'new-d4934202-97f8-465b-a7b5-cd876a99afd4';
  $pane = new stdClass();
  $pane->pid = 'new-d9cd9270-d80c-43e4-a059-6ff0a29b6d8c';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_bundle_webservices_wms';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'kms_permissions_service_bundles',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'd9cd9270-d80c-43e4-a059-6ff0a29b6d8c';
  $display->content['new-d9cd9270-d80c-43e4-a059-6ff0a29b6d8c'] = $pane;
  $display->panels['middle'][4] = 'new-d9cd9270-d80c-43e4-a059-6ff0a29b6d8c';
  $pane = new stdClass();
  $pane->pid = 'new-e301c265-8b93-402a-9a23-052fc1d8b516';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_bundle_webservices_wmts';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'kms_permissions_service_bundles',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'e301c265-8b93-402a-9a23-052fc1d8b516';
  $display->content['new-e301c265-8b93-402a-9a23-052fc1d8b516'] = $pane;
  $display->panels['middle'][5] = 'new-e301c265-8b93-402a-9a23-052fc1d8b516';
  $pane = new stdClass();
  $pane->pid = 'new-6da1b952-f8f2-4260-b866-0642423c0081';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_bundle_webservices_wcs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'kms_permissions_service_bundles',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '6da1b952-f8f2-4260-b866-0642423c0081';
  $display->content['new-6da1b952-f8f2-4260-b866-0642423c0081'] = $pane;
  $display->panels['middle'][6] = 'new-6da1b952-f8f2-4260-b866-0642423c0081';
  $pane = new stdClass();
  $pane->pid = 'new-dc814051-af36-45e2-b28a-a9f351bf1138';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_bundle_webservices_wfs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'kms_permissions_service_bundles',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'dc814051-af36-45e2-b28a-a9f351bf1138';
  $display->content['new-dc814051-af36-45e2-b28a-a9f351bf1138'] = $pane;
  $display->panels['middle'][7] = 'new-dc814051-af36-45e2-b28a-a9f351bf1138';
  $pane = new stdClass();
  $pane->pid = 'new-21b8d7fd-518a-4707-9a5d-789489491459';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_bundle_webservices_plot';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'kms_permissions_service_bundles',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '21b8d7fd-518a-4707-9a5d-789489491459';
  $display->content['new-21b8d7fd-518a-4707-9a5d-789489491459'] = $pane;
  $display->panels['middle'][8] = 'new-21b8d7fd-518a-4707-9a5d-789489491459';
  $pane = new stdClass();
  $pane->pid = 'new-3a3ff6e3-b268-4ed4-92c2-59abc218b8ab';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_applications';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'kms_permissions_applications',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = '3a3ff6e3-b268-4ed4-92c2-59abc218b8ab';
  $display->content['new-3a3ff6e3-b268-4ed4-92c2-59abc218b8ab'] = $pane;
  $display->panels['middle'][9] = 'new-3a3ff6e3-b268-4ed4-92c2-59abc218b8ab';
  $pane = new stdClass();
  $pane->pid = 'new-3eacb4fd-f05e-4712-967d-e928e517c1c7';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_predefined_datacollections';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 0,
      'view_mode' => 'full',
      'links' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 10;
  $pane->locks = array();
  $pane->uuid = '3eacb4fd-f05e-4712-967d-e928e517c1c7';
  $display->content['new-3eacb4fd-f05e-4712-967d-e928e517c1c7'] = $pane;
  $display->panels['middle'][10] = 'new-3eacb4fd-f05e-4712-967d-e928e517c1c7';
  $pane = new stdClass();
  $pane->pid = 'new-7ae52320-a4dc-4ade-a8e3-94df6f48f38e';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'bottom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'is_colorbox_node',
        'settings' => NULL,
        'not' => TRUE,
      ),
    ),
  );
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
  $pane->position = 11;
  $pane->locks = array();
  $pane->uuid = '7ae52320-a4dc-4ade-a8e3-94df6f48f38e';
  $display->content['new-7ae52320-a4dc-4ade-a8e3-94df6f48f38e'] = $pane;
  $display->panels['middle'][11] = 'new-7ae52320-a4dc-4ade-a8e3-94df6f48f38e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_8'] = $handler;

  return $export;
}
