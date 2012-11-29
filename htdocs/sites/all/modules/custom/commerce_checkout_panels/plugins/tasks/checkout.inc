<?php
/**
 * Specialized implementation of hook_page_manager_task_tasks(). See api-task.html for
 * more information.
 */
function commerce_checkout_panels_checkout_page_manager_tasks() {
  if (!module_exists('commerce_checkout')) {
    return;
  }

  return array(
    // This is a 'page' task and will fall under the page admin UI
    'task type' => 'page',

    'title' => t('Checkout'),
    'admin title' => t('Commerce checkout'),
    'admin description' => t('When enabled, this overrides the default Drupal behavior for the checkout at <em>/checkout</em>.'),
    'admin path' => 'checkout',

    // Menu hooks so that we can alter the node/%node menu entry to point to us.
    'hook menu alter' => 'commerce_checkout_panels_checkout_menu_alter',

    // This is task uses 'context' handlers and must implement these to give the
    // handler data it needs.
    'handler type' => 'context',
    'get arguments' => 'commerce_checkout_panels_checkout_get_arguments',
    'get context placeholders' => 'commerce_checkout_panels_checkout_get_contexts',


    // Allow this to be enabled or disabled:
    'disabled' => variable_get('commerce_checkout_panels_checkout_disabled', TRUE),
    'enable callback' => 'commerce_checkout_panels_checkout_enable',
  );
}

/**
 * Callback defined by commerce_cart_panels_cart_commerce_cart_panels_tasks().
 *
 * Alter the node edit input so that node edit comes to us rather than the
 * normal node edit process.
 */
function commerce_checkout_panels_checkout_menu_alter(&$items, $task) {
  if (variable_get('commerce_checkout_panels_checkout_disabled', TRUE)) {
    return;
  }

  // Get the current callback for checkout/%commerce_order.
  $callback1 = $items['checkout/%commerce_order']['page callback'];
  $callback2 = $items['checkout/%commerce_order/%commerce_checkout_page']['page callback'];

  // Check if the URLs are using the default route (or if 'override anyway' is
  // chosen).
  if (($callback1 == 'commerce_checkout_router' && $callback2 == $callback1) || variable_get('commerce_checkout_panels_override_anyway', FALSE)) {

    $items['checkout/%commerce_order']['page callback'] = 'commerce_checkout_panels__commerce_checkout_view';
    $items['checkout/%commerce_order']['file path'] = $task['path'];
    $items['checkout/%commerce_order']['file'] = $task['file'];

    $items['checkout/%commerce_order/%commerce_checkout_page']['page callback'] = 'commerce_checkout_panels__commerce_checkout_view';
    $items['checkout/%commerce_order/%commerce_checkout_page']['file path'] = $task['path'];
    $items['checkout/%commerce_order/%commerce_checkout_page']['file'] = $task['file'];

  }
  else {
    variable_set('commerce_checkout_panels_checkout_disabled', TRUE);
    if (!empty($GLOBALS['commerce_checkout_panels_enabling_checkout'])) {
      drupal_set_message(t('Page manager module is unable to enable checkout because some other module already has overridden with %callback.', array('%callback' => $callback)), 'warning');
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
function commerce_checkout_panels__commerce_checkout_view($order, $checkout_page = NULL) {
  // Load my task plugin
  $task = page_manager_get_task('checkout');

  ctools_include('context');
  ctools_include('context-task-handler');

  // Load contexts.
  $args = array($order, $checkout_page);
  $contexts = ctools_context_handler_get_task_contexts($task, '', $args);

  $output = ctools_context_handler_render($task, '', $contexts, $args);

  if ($output !== FALSE) {
    return $output;
  }

  // Fallback: Load the base implementation of commerce cart.
  module_load_include('inc', 'commerce_checkout', 'includes/commerce_checkout.pages');
  $function = 'commerce_checkout_router';

  foreach (module_implements('commerce_checkout_panels_override') as $module) {
    $call = $module . '_commerce_checkout_panels_override';
    if (($rc = $call('checkout')) && function_exists($rc)) {
      $function = $rc;
      break;
    }
  }

  // Otherwise, fall back.
  return $function($order, $checkout_page);
}

/**
 * Callback to get arguments provided by this task handler.
 */
function commerce_checkout_panels_checkout_get_arguments($task, $subtask_id) {
  return array(
    array(
      // 'name' is used to choose which context-handler to invoke.
      'name' => 'commerce_order',

      // 'settings' is passed to the context-handler constructor.
      'settings' => array(),

      // The human readable identifier for this argument, usually defined by the UI.
      'identifier' => t('Commerce order'),

      // The keyword used for this argument for substitutions.
      'keyword' => 'commerce_order',

      'id' => 1,
    ),
    array(
      'name' => 'commerce_checkout_page',
      'settings' => array(),
      'identifier' => t('Commerce checkout page'),
      'keyword' => 'commerce_checkout_page',
      'id' => 1,
    ),
  );
}

/**
 * Callback to get context placeholders provided by this handler.
 */
function commerce_checkout_panels_checkout_get_contexts($task, $subtask_id) {
  return ctools_context_get_placeholders_from_argument(commerce_checkout_panels_checkout_get_arguments($task, $subtask_id));
}

/**
 * Callback to enable/disable the page from the UI.
 */
function commerce_checkout_panels_checkout_enable($cache, $status) {
  variable_set('commerce_checkout_panels_checkout_disabled', $status);
  // Set a global flag so that the menu routine knows it needs
  // to set a message if enabling cannot be done.
  if (!$status) {
    $GLOBALS['commerce_checkout_panels_enabling_checkout'] = TRUE;
  }
}

