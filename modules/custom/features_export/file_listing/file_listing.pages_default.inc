<?php
/**
 * @file
 * file_listing.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function file_listing_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'directory_listing';
  $page->task = 'page';
  $page->admin_title = 'Directory listing';
  $page->admin_description = 'A page showing the content of public://feeds/';
  $page->path = 'feeds';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_directory_listing_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'directory_listing';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Directory listing',
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
  $display->uuid = 'bdac4534-c5d1-4e10-bcfc-05c129c53073';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_directory_listing_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-7087e2ff-e8a0-444c-90af-f20f8c620992';
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
  $pane->uuid = '7087e2ff-e8a0-444c-90af-f20f8c620992';
  $display->content['new-7087e2ff-e8a0-444c-90af-f20f8c620992'] = $pane;
  $display->panels['bottom'][0] = 'new-7087e2ff-e8a0-444c-90af-f20f8c620992';
  $pane = new stdClass();
  $pane->pid = 'new-cac77614-7dfe-4c45-a1e6-cf306b6c0410';
  $pane->panel = 'left';
  $pane->type = 'views';
  $pane->subtype = 'directory_listing';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'default',
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
  $pane->uuid = 'cac77614-7dfe-4c45-a1e6-cf306b6c0410';
  $display->content['new-cac77614-7dfe-4c45-a1e6-cf306b6c0410'] = $pane;
  $display->panels['left'][0] = 'new-cac77614-7dfe-4c45-a1e6-cf306b6c0410';
  $pane = new stdClass();
  $pane->pid = 'new-d6736d67-95ff-453b-9702-710eca5cda44';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'user-login';
  $pane->shown = TRUE;
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
  $pane->uuid = 'd6736d67-95ff-453b-9702-710eca5cda44';
  $display->content['new-d6736d67-95ff-453b-9702-710eca5cda44'] = $pane;
  $display->panels['right'][0] = 'new-d6736d67-95ff-453b-9702-710eca5cda44';
  $pane = new stdClass();
  $pane->pid = 'new-7d8d3cf3-00d2-4953-9a4d-b14c66288dbf';
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
  $pane->uuid = '7d8d3cf3-00d2-4953-9a4d-b14c66288dbf';
  $display->content['new-7d8d3cf3-00d2-4953-9a4d-b14c66288dbf'] = $pane;
  $display->panels['top'][0] = 'new-7d8d3cf3-00d2-4953-9a4d-b14c66288dbf';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-7d8d3cf3-00d2-4953-9a4d-b14c66288dbf';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['directory_listing'] = $page;

  return $pages;

}
