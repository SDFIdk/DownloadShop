<?php
/**
 * @file
 * commerce_product_types.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function commerce_product_types_commerce_product_default_types() {
  $items = array(
    'fme_product' => array(
      'type' => 'fme_product',
      'name' => 'FME product',
      'description' => '',
      'help' => '',
      'revision' => '0',
    ),
    'product' => array(
      'type' => 'product',
      'name' => 'Product',
      'description' => 'Map product type.',
      'help' => '',
      'revision' => '0',
    ),
  );
  return $items;
}
