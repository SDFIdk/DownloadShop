<?php
/**
 * @file
 * KMS products and services, product pane.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('My products'),
  'description' => t('My products'),
  'category' => t('KMS'),
  'render callback' => 'kms_pands_products_render',
  'all contexts' => TRUE,
);

/**
 * Custom panel pane to show user products.
 */
function kms_pands_products_render($subtype, $conf, $args, $contexts) {
  $form = drupal_get_form('kms_pands_product_list_form');
  $block = new stdClass();
  $block->content = drupal_render($form);
  return $block;
}
