<?php

$plugin = array(
  'title' => t('KMS info subuser'),
  'description' => t('Subuser info'),
  'category' => t('KMS'),
  'render callback' => 'info_subuser_render',
  'all contexts' => TRUE,
);

function info_subuser_render($subtype, $conf, $panel_args, $context) {
  $user = $context['context_user_1']->data;
  $master = relation_get_related_entity('user', $user->uid);
  $block = new stdClass();
  $block->subject = $block->subject = '';
  $block->content = $output = theme('subuser_info', array('user' => $user, 'master' => $master));
  return $block;
}
