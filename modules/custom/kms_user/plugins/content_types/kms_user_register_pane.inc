  <?php

$plugin = array(
  'title' => t('KMS user regitration form'),
  'description' => t('KMS user regitration form'),
  'category' => t('KMS'),
  'defaults' => array(),
  'render callback' => 'kms_user_registration_pane_render',
);

/**
 * Render the registration form.
 */

function kms_user_registration_pane_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $form = drupal_get_form('user_register_form');
  $block->content = drupal_render($form);
  return $block;

}
