<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */
 
 drupal_add_css(path_to_theme() . '/css/ie.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'IE', '!IE' => FALSE), 'preprocess' => FALSE));
 
function kms_theme($existing, $type, $theme, $path){
  return array(
    'user_login' => array(
      'render element' => 'form',
      'template' => 'templates/user-login',
    ),
    'user_pass_reset' => array(
      'render element' => 'form',
      'template' => 'templates/user-reset',
    ),
  );
}
