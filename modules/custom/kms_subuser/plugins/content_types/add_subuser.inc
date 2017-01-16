<?php

$plugin = array(
  'title' => t('KMS add subuser'),
  'description' => t('Add subuser and show subuser list'),
  'category' => t('KMS'),
  'render callback' => 'add_subuser_plugin_render',
);

function add_subuser_plugin_render($subtype, $conf, $panel_args, $context) {
  global $user;
  kms_user_js_settings();
  $block = new stdClass();
  $block->subject = $block->subject = '';
  if (!kms_subuser_is_subuser($user)) {
    $block->content = theme('subuser_add_user_popup', array('master_user' => $user));
    $block->content .= '<div id="subuser-view-wrapper"></div>';
  }
  return $block;
}