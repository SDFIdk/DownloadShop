<?php

/**
 * Specialized implementation of hook_page_manager_task_tasks(). See api-task.html for
 * more information.
 */
function commerce_cart_panels_cart_page_manager_tasks() {
  if (!module_exists('commerce_cart')) {
    return;
  }

  return array(
    // This is a 'page' task and will fall under the page admin UI
    'task type' => 'page',

    'title' => t('Cart'),
    'admin title' => t('Commerce cart'),
    'admin description' => t('When enabled, this overrides the default Drupal behavior for the cart at <em>/cart</em>.'),
    'admin path' => 'cart',

    // Menu hooks so that we can alter the node/%node menu entry to point to us.
    'hook menu alter' => 'commerce_cart_panels_cart_menu_alter',

    // This is task uses 'context' handlers and must implement these to give the
    // handler data it needs.
    'handler type' => 'context',

    // Allow this to be enabled or disabled:
    'disabled' => variable_get('commerce_cart_panels_cart_disabled', TRUE),
    'enable callback' => 'commerce_cart_panels_cart_enable',
  );
}

/**
 * Callback defined by commerce_cart_panels_cart_commerce_cart_panels_tasks().
 *
 * Alter the node edit input so that node edit comes to us rather than the
 * normal node edit process.
 */
function commerce_cart_panels_cart_menu_alter(&$items, $task) {
  if (variable_get('commerce_cart_panels_cart_disabled', TRUE)) {
    return;
  }

  $callback = $items['cart']['page callback'];

  // Override the node edit handler for our purpose.
  if ($callback == 'commerce_cart_view' || variable_get('commerce_cart_panels_override_anyway', FALSE)) {
    $items['cart']['page callback'] = 'commerce_cart_panels__commerce_cart_view';
    $items['cart']['file path'] = $task['path'];
    $items['cart']['file'] = $task['file'];
  }
  else {
    variable_set('commerce_cart_panels_cart_disabled', TRUE);
    if (!empty($GLOBALS['commerce_cart_panels_enabling_cart'])) {
      drupal_set_message(t('Page manager module is unable to enable cart because some other module already has overridden with %callback.', array('%callback' => $callback)), 'warning');
    }
    return;
  }
}

/**
 * Entry point for our overridden cart page.
 *
 * This function asks its assigned handlers who, if anyone, would like
 * to run with it. If no one does, it passes through to Drupal core's
 * node edit, which is node_page_edit().
 */
function commerce_cart_panels__commerce_cart_view() {
  // Load my task plugin
  $task = page_manager_get_task('cart');

  ctools_include('context');
  ctools_include('context-task-handler');
  $output = ctools_context_handler_render($task, '', array(), array());
  if ($output !== FALSE) {
    return $output;
  }


  // Fallback: Load the base implementation of commerce cart.
  module_load_include('inc', 'commerce_cart', 'includes/commerce_cart.pages');
  $function = 'commerce_cart_view';

  foreach (module_implements('commerce_cart_panels_override') as $module) {
    $call = $module . '_commerce_cart_panels_override';
    if (($rc = $call('cart')) && function_exists($rc)) {
      $function = $rc;
      break;
    }
  }

  // Otherwise, fall back.
  return $function();
}

/**
 * Callback to enable/disable the page from the UI.
 */
function commerce_cart_panels_cart_enable($cache, $status) {
  variable_set('commerce_cart_panels_cart_disabled', $status);
  // Set a global flag so that the menu routine knows it needs
  // to set a message if enabling cannot be done.
  if (!$status) {
    $GLOBALS['commerce_cart_panels_enabling_cart'] = TRUE;
  }
}
