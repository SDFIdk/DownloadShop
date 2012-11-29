<?php
/**
 * @file
 *
 * Plugin to provide a commerce order context. A commerce order context is an
 * order wrapped in a context object that can be utilized by anything that
 * accepts contexts.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Commerce order"),
  'description' => t('A commerce order object.'),
  'context' => 'commerce_checkout_panels_context_create_commerce_order',
  'keyword' => 'commerce_order',
  'context name' => 'commerce_order',
  'no ui' => TRUE,
);

/**
 * It's important to remember that $conf is optional here, because contexts
 * are not always created from the UI.
 */
function commerce_checkout_panels_context_create_commerce_order($empty, $data = NULL, $conf = FALSE) {
  $context = new ctools_context('commerce_order');
  $context->plugin = 'commerce_order';

  if ($empty) {
    return $context;
  }

  if ($conf) {
    $order_id = is_array($data) && isset($data['order_id'])
      ? $data['order_id']
      : (is_object($data) ? $data->order_id : 0);

    if (is_array($data) || !empty($reload)) {
      $data = commerce_order_load($order_id);
    }
  }

  if (!empty($data)) {
    $context->data     = $data;
    $context->argument = $data->order_id;

    return $context;
  }
}
