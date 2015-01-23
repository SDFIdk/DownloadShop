  <?php

$plugin = array(
  'title' => t('KMS password request form'),
  'description' => t('KMS password request form'),
  'category' => t('KMS'),
  'defaults' => array(),
  'render callback' => 'kms_user_request_password_pane_render',
);

/**
 * Render the registration form.
 */

function kms_user_request_password_pane_render($subtype, $conf, $panel_args, $context) {
  
  module_load_include('inc', 'user', 'user.pages');
  
  $block = new stdClass();
  $form = drupal_get_form('user_pass');
  $block->content = drupal_render($form);
  return $block;

}
