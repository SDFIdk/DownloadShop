<?php

/**
 * @file
 * Views hooks implementations.
 */

/**
 * Implements hook_views_data_alter().
 */
function kms_permissions_views_data_alter(&$data) {
  $data['views']['has_separate_services'] = array(
    'title' => t('Separate services'),
    'help' => t('Show if user has separate services.'),
    'field' => array(
      'handler' => 'kms_permissions_handler_has_separate_services',
      'click sortable' => TRUE,
    ),
  );
}
