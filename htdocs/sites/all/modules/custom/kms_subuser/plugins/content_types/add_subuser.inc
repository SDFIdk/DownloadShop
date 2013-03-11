  <?php

$plugin = array(
  'title' => t('KMS add subuser'),
  'description' => t('Add subuser and show subuser list'),
  'category' => t('KMS'),
  'defaults' => array(),
  'edit form' => 'add_subuser_plugin_edit_form',
  'render callback' => 'add_subuser_plugin_render',
);

/**
 * Render the custom content type.
 */

function add_subuser_plugin_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  // $form = array();
  return $form;
}

/**
 * Submit handler for search form.
 */
function add_subuser_plugin_edit_form_submit($form, &$form_state) {
  // Copy everything from our defaults.
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

function add_subuser_plugin_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = $block->subject = '';
  $popup = theme('subuser_add_user_popup', array('master_uid' => 15));
  // $view = kms_subuser_render_view(1, FALSE);
  $block->content = $popup . '<div id="subuser-view-wrapper"></div>';
  return $block;
}

// function add_subuser_plugin_content_type_admin_title($subtype, $conf, $context) {
//   $content = !empty($conf['override_title'])
//   ? t('Title') . ': ' . $conf['override_title_text'] . ' - ' : '';
//   $content .= t('Content type form') . ': ' . $conf['content_type'];

//   return $content;
// }
