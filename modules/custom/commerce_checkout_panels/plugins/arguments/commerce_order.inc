<?php
/**
 * @file
 *
 * Plugin to provide an argument handler for a commerce order (%commerce_order).
 */

$plugin = array(
  'title' => t("Commerce order"),
  // keyword to use for %substitution
  'keyword' => 'commerce_order',
  'description' => t('An argument that can be used to get the commerce order as a context.'),
  'context' => 'commerce_checkout_panels_argument_commerce_order',

  'placeholder form' => array(
    '#type' => 'fieldset',
    'content' => array(
      '#title' => t('Commerce order'),
      '#type' => 'textarea',
      '#default_value' => '<p>Order</p>',
    ),
  ),
  'no ui' => FALSE,
);

/**
 * Discover if this argument gives us the order we crave.
 */
function commerce_checkout_panels_argument_commerce_order($arg = NULL, $conf = NULL, $empty = FALSE) {
  // If unset it wants a generic, unfilled context.
  if ($empty) {
    return ctools_context_create_empty('commerce_order');
  }

  // Args should be an array providing the original hook_menu's callback,
  // include file, and the arguments that were provided by the menu handler.
  $context = ctools_context_create('commerce_order', $arg);
  $context->original_argument = $arg;

  return $context;
}
