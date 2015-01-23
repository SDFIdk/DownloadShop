<?php
/**
 * @file
 * KMS CSV admin pages.
 */


/**
 * KMS CSV admin settings form.
 */

function kms_csv_admin() {
  $form = array();
  $form['kms_csv_ftp_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#default_value' => variable_get('kms_csv_ftp_username', 'username'),
    '#size' => 50,
    '#maxlength' => 256,
    '#description' => t("FTP username"),
    '#required' => TRUE,
  );
  
  $form['kms_csv_ftp_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#default_value' => variable_get('kms_csv_ftp_password', 'password'),
    '#size' => 50,
    '#maxlength' => 256,
    '#description' => t("FTP password"),
    '#required' => TRUE,
  );
  
  $form['kms_csv_ftp_hostname'] = array(
    '#type' => 'textfield',
    '#title' => t('Hostname'),
    '#default_value' => variable_get('kms_csv_ftp_hostname', 'localhost'),
    '#size' => 50,
    '#maxlength' => 256,
    '#description' => t("Hostname to which to connect"),
    '#required' => TRUE,
  );
  $form['kms_csv_ftp_port'] = array(
    '#type' => 'textfield',
    '#title' => t('Port'),
    '#default_value' => variable_get('kms_csv_ftp_port', 21),
    '#size' => 10,
    '#maxlength' => 10,
    '#description' => t("FTP port"),
    '#required' => TRUE,
  );
  
  return system_settings_form($form);
}