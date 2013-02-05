<?php
/**
 * @file
 * contenttype_product_display.features.inc
 */

/**
 * Implements hook_node_info().
 */
function contenttype_product_display_node_info() {
  $items = array(
    'product_display' => array(
      'name' => t('Product display'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
