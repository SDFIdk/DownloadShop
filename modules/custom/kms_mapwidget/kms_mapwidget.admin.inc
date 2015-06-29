<?php

/**
 * Admin form for setting the Maxumim area.
 */
function kms_mapwidget__max_area_form() {
  $form['kms_mapwidget_max_area'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum area'),
    '#default_value' => variable_get('kms_mapwidget_max_area', 0),
    '#description' => t('Maximum allowed area when making FME requests.'),
  );
  return system_settings_form($form);
}

/**
 * Admin form for setting the FME URL.
 */
function kms_mapwidget__fmeurl_form() {
  $form['fmeurl'] = array(
    '#type' => 'textfield',
    '#title' => t('FME URL'),
    '#default_value' => variable_get('fmeurl', 'http://fmeserver.kmsext.dk/fmerest'),
    '#description' => t('URL used when making FME requests.'),
  );
  return system_settings_form($form);
}