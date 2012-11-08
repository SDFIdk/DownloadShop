<?php

$drupalroot      = '/home/drupal/kms.dev/htdocs';
$drupal_base_url = 'http://kms.fe.dev.cd.adapt.dk/';

$stdout = fopen('php://stdout', 'w');
fwrite($stdout, "KMS service import\n");

// Set cwd and DRUPAL_ROOT to Drupal root directory
chdir($drupalroot);
define('DRUPAL_ROOT', $drupalroot );

// Set up some server variables that are needed to
// bootstrap the correct drupal site.
$drupal_base_url = parse_url($drupal_base_url);
$_SERVER['HTTP_HOST'] = $drupal_base_url['host'];
$_SERVER['PHP_SELF']  = basename(__file__);
$_SERVER['REMOTE_ADDR'] = '127.0.0.1';
$_SERVER['REQUEST_METHOD'] = NULL;
$_SERVER['SERVER_SOFTWARE'] = 'KMS import users';

require_once 'includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

// Time and memory limits
set_time_limit(10000);
ini_set('memory_limit', '256M');

// Perform import as admin user
global $user;
$user = user_load(array('uid' => 1));


// Absolute path to csv file.
$filename = "/home/drupal/kms.dev/scripts/import_users/SM_Oracle_export.csv";

// Mapping configuration.
// What is being used where...
$mapping = array(
  array('col' => 'USERID', 'field' => 'field_kms_user_id'),
  array('col' => 'NAME', 'init_field' => 'name'),
  array('col' => 'PASSWORD', 'init_field' => 'pass'),
  array('col' => 'LASTNAME', 'field' => array('field_address', 'last_name')),
  array('col' => 'FIRSTNAME', 'field' => array('field_address', 'first_name')),
  array('col' => 'EMAILADDRESS', 'ignore' => TRUE),
  array('col' => 'TELEPHONENUMBER', 'field' => 'field_phone'),
  array('col' => 'DISABLED', 'ignore' => TRUE),
  array('col' => 'PIN', 'ignore' => TRUE),
  array('col' => 'MILEAGE', 'ignore' => TRUE),
  array('col' => 'DEBITORNO', 'field' => 'field_debtor_nr'),
  array('col' => 'PASSWORDDATA', 'ignore' => TRUE),
  array('col' => 'USERID_1', 'ignore' => TRUE),
  array('col' => 'STARTDATO', 'ignore' => TRUE),
  array('col' => 'SLUTDATO', 'ignore' => TRUE),
  array('col' => 'FIRMANAVN', 'field' => array('field_address', 'organisation_name')),
  array('col' => 'FAKTURAADRESSE', 'field' => array('field_address', 'thoroughfare')),
  array('col' => 'POSTNR', 'field' => array('field_address', 'postal_code')),
  array('col' => 'UBY', 'field' => array('field_address', 'locality')),
  array('col' => 'LAND', 'field' => array('field_address', 'country')),
  array('col' => 'USERREMARK', 'ignore' => TRUE),
  array('col' => 'OPRETTET', 'ignore' => TRUE),
  array('col' => 'OPRETTETDATO', 'ignore' => TRUE),
  array('col' => 'REDIGERET', 'ignore' => TRUE),
  array('col' => 'REDIGERETDATO', 'ignore' => TRUE),
);

// Add default values.
array_walk($mapping, function($v, $k) use (&$mapping) {
  $mapping[$k] += array(
    'field' => NULL,
    'ignore' => FALSE,
    'init_field' => NULL,
  );
});


// Import those babes.
import_users($mapping, $filename, 3);


/**
 * Import KMS users.
 *
 * @param array $mapping
 *   Mapping configuration.
 * @param string $filename
 *   The absolute path to the csv file.
 * @param integer $limit
 *   For debug use you can limit the number of users. 0 = unlimited.
 *
 * @return void
 */
function import_users($mapping, $filename, $limit = 0) {
  global $stdout;

  $row_count = 0;
  if (($handle = fopen($filename, "r")) !== FALSE) {
    
    while (($row = fgetcsv($handle, 1000, ",")) !== FALSE) {
      // Don't do anything at header row.
      if (!$row_count) {
        $row_count++;
        continue;
      }

      if ($limit != 0 && $row_count <= $limit) {
        // Save user intially.
        $account = import_users_save_user($mapping, $row);
        // Save fields on user.
        $user_wrapper = import_users_save_fields($mapping, $row, $account);
      }

      $row_count++;
    }

    fclose($handle);
    fwrite($stdout, $row_count . " users were imported\n");

  }

}

/**
 * Save user without additional fields.
 *
 * @param array $mapping
 *   Mapping configuration.
 * @param array $row
 *   Current csv row.
 *
 * @return object
 *   Drupal user object.
 */
function import_users_save_user($mapping, $row) {
  $col = 0;
  $user = new stdClass;
  foreach($mapping as $conf) {
    if (empty($conf['init_field'])) {
      $col++;
      continue;
    }

    if(!empty($conf['init_field'])) {
      $value = $row[$col];
      // Convert value to UTF-8.
      import_users_convert_2_utf8($value);
      $user->{$conf['init_field']} = $value;
    }
    $col++;
  }

  return import_users_save_user_init($user);
}

/**
 * Save the user initially.
 *
 * @param object $user
 *   Values to store in user object.
 * @param array $role
 *   Role given to all imported users.
 *
 * @return object $account
 *   Drupal user object.
 */
function import_users_save_user_init($user, $role = array(6 => TRUE)) {
  if (empty($user->name) || empty($user->pass)) {
    return FALSE;
  }
  $account = new stdClass;
  $account->is_new = TRUE;
  $account->name = $user->name;
  $account->mail = $account->init = 'userneeds@tochange.this';
  $account->status = TRUE;
  $account->roles = $role;
  $account->timezone = variable_get('date_default_timezone', '');
  return user_save($account, array('pass' => $user->pass));

}

/**
 * Save additonal fields to user object via the entity_metadata_wrapper.
 *
 * @param array $mapping
 *   Mapping configuration.
 * @param array $row
 *   Csv row.
 * @param object $account
 *   Drupal user object.
 *
 * @return object
 *   Entity meta data object.
 */
function import_users_save_fields($mapping, $row, $account) {
  $col = 0;
  foreach ($mapping as $conf) {
    var_dump(str_repeat('-', 20));
    if (empty($row[$col])) {
      $col++;
      continue;
    }
    if (!empty($conf['field'])) {
      $field = $conf['field'];
      $user_wrapper = entity_metadata_wrapper('user', $account);
      $value = $row[$col];
      // Convert value to UTF-8.
      import_users_convert_2_utf8($value);
      // Translate country code.
      if ($conf['col'] == 'LAND') {
        import_users_translate_country($value);
      }

      if (!is_array($field)){
        $user_wrapper->$field->set($value);
      }
      else {
        $user_wrapper->{$field[0]}->{$field[1]}->set($value);
      }
    }
    $col++;
  }
  $user_wrapper->save();
  return $user_wrapper;
}

/**
 * Translate country code.
 *
 * @param string $value
 *   String to be translated.
 *
 * @return void
 */
function import_users_translate_country(&$value) {
  switch ($value) {
    case 'Danmark':
      $value = 'DK';
      break;
  }
}

/**
 * Convert strings to UTF-8.
 *
 * @param string $value
 *
 * @return void
 */
function import_users_convert_2_utf8(&$value) {
  $value = iconv("ISO-8859-1", "UTF-8", $value);
}

/*
USERID
NAME
PASSWORD
LASTNAME
FIRSTNAME
EMAILADDRESS
TELEPHONENUMBER
DISABLED
PIN
STARTDATO
SLUTDATO
FIRMANAVN
FAKTURAADRESSE
MILEAGE
DEBITORNO
PASSWORDDATA
USERID_1
POSTNR
UBY
LAND
USERREMARK
OPRETTET
OPRETTETDATO
REDIGERET
REDIGERETDATO
*/
