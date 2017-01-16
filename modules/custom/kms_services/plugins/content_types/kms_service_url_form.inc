<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('KMS service url form generation'),
  'description' => t('Form to generate url for service.'),
  'category' => t('GST'),
  'render callback' => 'kms_service_url_form_render',
  'defaults' => array(
    'text' => '',
  ),
  'all contexts' => TRUE,
);

/**
 *
 */
function kms_service_url_form_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  $block->title = '';
  module_load_include('inc', 'kms_services', 'inc/capability');
  $form = drupal_get_form('kms_services_url_form', NULL, NULL);
  $block->content = render($form);

  return $block;
}

