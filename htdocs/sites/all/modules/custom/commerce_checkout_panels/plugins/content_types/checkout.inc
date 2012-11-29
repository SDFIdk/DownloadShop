<?php
/**
 * @file
 * Plugin to handle the 'checkout' content type which allows the
 * commerce checkout panes to be embedded into a panel.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Checkout'),
  'single' => TRUE,
  'icon' => 'icon_page.png',
  'description' => t('Add the commerce checkout as content.'),
  'required context' => array(
    new ctools_context_required(t('Commerce order'), 'commerce_order'),
    new ctools_context_required(t('Commerce checkout page'), 'commerce_checkout_page'),
  ),
  'category' => t('Commerce'),
);

/**
 * Output function for the 'cart' content type.
 *
 * Outputs the commerce cart for the site.
 */
function commerce_checkout_panels_checkout_content_type_render($subtype, $conf, $panel_args, $context) {
  // Check for valid contexts.
  if (empty($context) || count($context) < 2) {
    return;
  }

  $commerce_order = $context[0]->data;
  // $commerce_checkout_page might not be set: default to NULL if not available.
  $commerce_checkout_page = ($context[1]->type == 'commerce_checkout_page') ? $context[1]->data : NULL;

  // Reimplement the checkout router callback.
  module_load_include('inc', 'commerce_checkout', 'includes/commerce_checkout.pages');


  $block = new stdClass();
  $block->module = 'commerce_checkout';
  $block->delta = 'checkout';
  $block->content = commerce_checkout_router($commerce_order, $commerce_checkout_page);

  return $block;
}
