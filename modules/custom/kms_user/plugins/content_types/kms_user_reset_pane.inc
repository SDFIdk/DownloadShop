  <?php

$plugin = array(
  'title' => t('KMS user reset password form'),
  'description' => t('KMS user reset password form'),
  'category' => t('KMS'),
  'defaults' => array(),
  'render callback' => 'kms_user_reset_pane_render',
);


/**
 * Render the password reset login form.
 */
function kms_user_reset_pane_render($subtype, $conf, $panel_args, $context) {

  module_load_include('inc', 'user', 'user.pages');

  $block = new stdClass();
  $form = drupal_get_form('user_pass_reset');
  $block->content = drupal_render_children($form);

  return $block;
}
