<?php

/**
 * Request a new password given a user name or e-mail address.
 *
 * @param $name
 *   The username or e-mail address of the requesting account.
 *
 * @see https://api.drupal.org/api/drupal/modules!user!user.pages.inc/function/user_pass_validate/7
 * @see https://api.drupal.org/api/drupal/modules!user!user.pages.inc/function/user_pass_submit/7
 */
function _kms_services_resources_password_request_new_password($name) {

  $name = trim($name);
  // Try to load by email.
  $users = user_load_multiple([], ['mail' => $name, 'status' => '1']);
  $account = reset($users);
  if (!$account) {
    // No success, try to load by name.
    $users = user_load_multiple([], ['name' => $name, 'status' => '1']);
    $account = reset($users);
  }

  if (!isset($account->uid)) {
    return services_error(t('Sorry, %name is not recognized as a user name or an e-mail address.', ['%name' => $name]), 406);
  }

  // Mail one time login URL and instructions using current language.
  global $language;

  // Lets just make sure that we do not have any checksums for this user.
  db_delete('user_password_reset_checksum')
    ->condition('uid', $account->uid)
    ->execute();

  // Insert into password reset checksum and make valid for the next day.
  $checksum = drupal_random_key(28);
  db_insert('user_password_reset_checksum')
    ->fields([
      'uid' => $account->uid,
      'checksum' => $checksum,
      'expires' => time() + 86400,
    ])
    ->execute();

  $mail = _kms_services_resources_password_user_mail_notify('password_reset', $account, $language, $checksum);

  drupal_debug('Mailed: ');
  drupal_debug($mail);

  if (!empty($mail)) {
    watchdog('user', 'Password reset instructions mailed to %name at %email.', array('%name' => $account->name, '%email' => $account->mail));
    return TRUE;
  }
  else {
    return FALSE;
  }

}

function _kms_services_resources_password_user_mail_notify($op, $account, $language = NULL, $hash_value = NULL) {
  // By default, we always notify except for canceled and blocked.
  $default_notify = ($op != 'status_canceled' && $op != 'status_blocked');
  $notify = variable_get('user_mail_' . $op . '_notify', $default_notify);

  if ($notify) {
    $params['account'] = $account;
    $params['hash_value'] = $hash_value;
    $language = $language ? $language : user_preferred_language($account);

    $mail = drupal_mail('kms_services_resources', $op, $account->mail, $language, $params);

    if ($op == 'register_pending_approval') {
      // If a user registered requiring admin approval, notify the admin, too.
      // We use the site default language for this.
      drupal_mail('user', 'register_pending_approval_admin', variable_get('site_mail', ini_get('sendmail_from')), language_default(), $params);
    }
  }
  return empty($mail) ? NULL : $mail['result'];
}
