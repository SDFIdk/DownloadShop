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
  'title' => t("Commerce checkout page"),
  'description' => t('A commerce checkout page object.'),
  'context' => 'commerce_checkout_panels_context_create_commerce_checkout_page',
  'keyword' => 'commerce_checkout_page',
  'context name' => 'commerce_checkout_page',
  'no ui' => TRUE,
);

/**
 * It's important to remember that $conf is optional here, because contexts
 * are not always created from the UI.
 */
function commerce_checkout_panels_context_create_commerce_checkout_page($empty, $data = NULL, $conf = FALSE) {
  $context = new ctools_context('commerce_checkout_page');
  $context->plugin = 'commerce_checkout_page';
  if ($empty) {
    return $context;
  }

  // Allow context to be created from the UI config.
  if ($conf) {
    $page_id = is_array($data) && isset($data['page_id'])
      ? $data['page_id']
      : (is_object($data) ? $data->page_id : 0);

    if (is_array($data) || !empty($reload)) {
      $data = commerce_checkout_page_load($page_id);
    }
  }


  if (!empty($data)) {
    $context->data     = $data;
    $context->title    = $data['title'];
    $context->argument = $data['page_id'];

    return $context;
  }
}
