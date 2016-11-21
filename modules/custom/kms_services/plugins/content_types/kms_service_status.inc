<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('KMS service list'),
  'description' => t('Shows a list of KMS services.'),
  'category' => t('GST'),
  'edit form' => 'kms_status_edit_form',
  'render callback' => 'kms_status_render',
  'admin info' => 'kms_services_admin_info',
  'defaults' => array(
    'freelist' => FALSE,
  )
);

/**
 * 'admin info' callback for panel pane.
 */
function kms_services_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';
    $block->content = t('Showing <em>@@freelist</em>.', array(
      '@freelist' => $conf['freelist'],
    ));
    return $block;
  }
}

/**
 * 'Edit form' callback for the content type.
 */
function kms_status_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['freelist'] = array(
    '#title' => t('Render Business Catalogue'),
    '#description' => t('Renders business catalogue with user YdelsesKatalog'),
    '#type' => 'checkbox',
    '#default_value' => $conf['freelist'],
    '#required' => TRUE,
  );

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function kms_status_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function kms_status_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();

  // initial content is blank
  $block->title = '';
  $block->content = '';

  $form = drupal_get_form('kms_services_form', $conf['freelist']);

  // Add in the content
  $block->content .= drupal_render($form);

  return $block;
}
