<?php

/**
 * @file
 * Generates a first name + last name format.
 */

$plugin = array(
  'title' => t('Phone'),
  'format callback' => 'kms_user_format_phone_generate',
  'type' => 'phone',
  'weight' => 0,
);


