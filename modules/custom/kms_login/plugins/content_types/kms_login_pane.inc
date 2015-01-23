  <?php

$plugin = array(
  'title' => t('KMS login pane'),
  'description' => t('Show login form'),
  'category' => t('KMS'),
  'defaults' => array(),
  'render callback' => 'kms_login_pane_render',
);

/**
 * Render the custom content type.
 */

function kms_login_pane_render($subtype, $conf, $panel_args, $context) {
  
  $content = '';

  global $user;
    if ($user->uid == 0){
        $content .= l(t('login'), 'user');
    }
    else{
      $content .= l(t('log out'), 'user/logout');
  }

  $block = new stdClass();
  $block->content = $content;
 
  return $block;
}