<?php
/**
 * @file
 * gst2_news.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function gst2_news_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'nyheder';
  $page->task = 'page';
  $page->admin_title = 'Nyheder';
  $page->admin_description = '';
  $page->path = 'nyheder';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_nyheder_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'nyheder';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Main',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'gst-twocol-left';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
      'sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Nyheder';
  $display->uuid = '1f4fe296-c4c2-4817-96ec-6d6026415eef';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_nyheder_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ef1e82a9-ed05-4540-87e6-f825b9da72a1';
  $pane->panel = 'main';
  $pane->type = 'views';
  $pane->subtype = 'nyheder';
  $pane->shown = TRUE;
  $pane->access = array();
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
    'url' => '',
    'display' => 'default',
    'override_title' => 1,
    'override_title_text' => 'Nyheder',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'news-wrap',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ef1e82a9-ed05-4540-87e6-f825b9da72a1';
  $display->content['new-ef1e82a9-ed05-4540-87e6-f825b9da72a1'] = $pane;
  $display->panels['main'][0] = 'new-ef1e82a9-ed05-4540-87e6-f825b9da72a1';
  $pane = new stdClass();
  $pane->pid = 'new-fa4dcc65-4d6c-4f80-bb5e-fafec21d0974';
  $pane->panel = 'sidebar';
  $pane->type = 'menu_tree';
  $pane->subtype = 'main-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'main-menu',
    'parent_mlid' => 0,
    'parent' => 'main-menu:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '2',
    'follow' => 0,
    'depth' => '3',
    'expanded' => 0,
    'sort' => 0,
    'override_title' => 1,
    'override_title_text' => 'Nyheder',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'secondary-menu',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'fa4dcc65-4d6c-4f80-bb5e-fafec21d0974';
  $display->content['new-fa4dcc65-4d6c-4f80-bb5e-fafec21d0974'] = $pane;
  $display->panels['sidebar'][0] = 'new-fa4dcc65-4d6c-4f80-bb5e-fafec21d0974';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['nyheder'] = $page;

  return $pages;

}
