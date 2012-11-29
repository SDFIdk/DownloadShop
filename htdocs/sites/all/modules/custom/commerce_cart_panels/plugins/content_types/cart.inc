<?php

/**
 * @file
 * Plugin to handle the 'cart' content type which allows the
 * commerce cart to be embedded into a panel.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Cart'),
  'single' => TRUE,
  'icon' => 'icon_page.png',
  'description' => t('Add the commerce cart as content.'),
  'category' => t('Commerce'),
);

/**
 * Output function for the 'cart' content type.
 *
 * Outputs the commerce cart for the site.
 */
function commerce_cart_panels_cart_content_type_render($subtype, $conf, $panel_args) {

  module_load_include('inc', 'commerce_cart', 'includes/commerce_cart.pages');

  $block = new stdClass();
  $block->module = 'commerce_cart';
  $block->delta = 'cart';
  $block->content = commerce_cart_view();

  return $block;
}
