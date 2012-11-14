  <?php

$plugin = array(
  'title' => t('KMS user profile form'),
  'description' => t('KMS user profile form'),
  'category' => t('KMS'),
  'defaults' => array(),
  'render callback' => 'kms_user_profile_form_pane_render',
);

/**
 * Render the registration form.
 */

function kms_user_profile_form_pane_render($subtype, $conf, $panel_args, $context) {
  global $user;

  module_load_include('inc', 'user', 'user.pages');
  
  $block = new stdClass();
  $form = drupal_get_form('user_profile_form', $user);
  $block->content = drupal_render($form);
  return $block;

}
