<?php
/**
 * @file
 *
 * Plugin to provide an argument handler for a commerce order (%commerce_order).
 */

$plugin = array(
  'title' => t("Commerce checkout page"),
  // keyword to use for %substitution
  'keyword' => 'commerce_checkout_page',
  'description' => t('An argument that can be used to get the commerce checkout page as a context.'),
  'context' => 'commerce_checkout_panels_argument_commerce_checkout_page',

  'placeholder form' => array(
    '#type' => 'fieldset',
    'content' => array(
      '#title' => t('Commerce checkout page'),
      '#type' => 'textarea',
      '#default_value' => '<p>Order</p>',
    ),
  ),
  'no ui' => FALSE,
);

/**
 * Discover if this argument gives us the order we crave.
 */
function commerce_checkout_panels_argument_commerce_checkout_page($arg = NULL, $conf = NULL, $empty = FALSE) {
  // If unset it wants a generic, unfilled context.
  if ($empty || empty($arg)) {
    return ctools_context_create_empty('commerce_checkout_page');
  }

  $context = ctools_context_create('commerce_checkout_page', $arg);
  $context->original_argument = $arg;

  return $context;
}
