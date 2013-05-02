<?php

$drupalroot      = '/home/drupal/kms.dev/htdocs';
$drupal_base_url = 'http://kms.fe.dev.cd.adapt.dk/';

$stdout = fopen('php://stdout', 'w');
fwrite($stdout, "KMS service import\n");
fwrite($stdout, str_repeat('-', 30) . "\n");

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
$settings = array(
  // 'filename' => "/home/drupal/kms.dev/scripts/import_users/SM_Oracle_export.csv",
  'filename' => "/home/drupal/kms.dev/scripts/import_users/Siteminder_users_incl_TermID_abt_13122012_latin_min1.csv",
  'roles' => array(6 => TRUE),
  'nonmail' => 'userneeds@tochange.this'
);

// Mapping configuration.
// What is being used where...
$mapping_1 = array(
  array('col' => 'USERID', 'field' => 'field_kms_user_id'),
  array('col' => 'NAME', 'init_field' => 'name'),
  array('col' => 'PASSWORD', 'init_field' => 'pass'),
  array('col' => 'LASTNAME', 'field' => array('field_address', 'last_name')),
  array('col' => 'FIRSTNAME', 'field' => array('field_address', 'first_name')),
  array('col' => 'EMAILADDRESS', 'init_field' => 'mail', 'value_callback' => 'import_users_process_empty_email'),
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
  array('col' => 'USERREMARK', 'field' => 'field_user_remark'),
  array('col' => 'OPRETTET', 'ignore' => TRUE),
  array('col' => 'OPRETTETDATO', 'init_field' => 'created', 'value_callback' => 'strtotime'),
  array('col' => 'REDIGERET', 'ignore' => TRUE),
  array('col' => 'REDIGERETDATO', 'field' => 'field_updated', 'value_callback' => 'strtotime'),
  array('col' => 'SYSTEMACCOUNT', 'role' => 7),
);
$mapping_2 = array(
  array('col' => 'SYSTEMACCOUNT', 'role' => 7),
  array('col' => 'TERMID', 'field' => 'field_user_type', 'field_type' => 'term_ref_hierarical'),
  array('col' => 'DEBITORNO', 'field' => 'field_debtor_nr'),
  array('col' => 'FIRMANAVN', 'field' => array('field_address', 'organisation_name')),
  array('col' => 'FIRSTNAME', 'field' => array('field_address', 'first_name')),
  array('col' => 'LASTNAME', 'field' => array('field_address', 'last_name')),
  array('col' => 'NAME', 'init_field' => 'name'),
  array('col' => 'OPRETTETDATO', 'init_field' => 'created', 'value_callback' => 'import_users_fuckedup_kms_time2unix'),
  array('col' => 'SLUTDATO', 'ignore' => TRUE),
  array('col' => 'REDIGERETDATO', 'field' => 'field_updated', 'value_callback' => 'import_users_fuckedup_kms_time2unix'),
  array('col' => 'USERREMARK', 'field' => 'field_user_remark'),
  array('col' => 'TELEPHONENUMBER', 'field' => 'field_phone'),
  array('col' => 'USERID', 'field' => 'field_kms_user_id'),
  array('col' => 'DISABLED', 'ignore' => TRUE),
  array('col' => 'PIN', 'ignore' => TRUE),
  array('col' => 'PASSWORD', 'init_field' => 'pass'),
  array('col' => 'MILEAGE', 'ignore' => TRUE),
  array('col' => 'PASSWORDDATA', 'ignore' => TRUE),
  array('col' => 'STARTDATO', 'ignore' => TRUE),
  array('col' => 'FAKTURAADRESSE', 'field' => array('field_address', 'thoroughfare')),
  array('col' => 'POSTNR', 'field' => array('field_address', 'postal_code')),
  array('col' => 'UBY', 'field' => array('field_address', 'locality')),
  array('col' => 'LAND', 'field' => array('field_address', 'country')),
  array('col' => 'OPRETTET', 'ignore' => TRUE),
  array('col' => 'REDIGERET', 'ignore' => TRUE),
  array('col' => 'EMAILADDRESS', 'init_field' => 'mail', 'value_callback' => 'import_users_process_empty_email'),
  // array('col' => 'USERID_1', 'ignore' => TRUE),
);

// Add default values.
array_walk($mapping_2, function($v, $k) use (&$mapping_2) {
  $mapping_2[$k] += array(
    'field' => NULL,
    'ignore' => FALSE,
    'init_field' => NULL,
    'value_callback' => NULL,
  );
});


// Import those babes.
// TODO: remove limit when it is for real.
$users = import_users($mapping_2);

// Remove duplicate emails.
if (!empty($users)) {
  $mails = $dupes = array();
  foreach($users as $user) {
    $mails[$user->mail]++;
    if ($mails[$user->mail] > 1) {
      $dupes[] = $user->mail;
    }
  }
  if (!empty($dupes)) {
    $query = "UPDATE {users} set mail = :nonmail WHERE mail IN (:dupes)";
    db_query(
      $query,
      array(
        ':nonmail' => $settings['nonmail'],
        ':dupes' => array_unique($dupes),
      )
    );
  } 
}


/**
 * Import KMS users.
 *
 * @todo update desc.
 * @param array $mapping
 *   Mapping configuration.
 * @param string $filename
 *   The absolute path to the csv file.
 * @param mixed $limit
 *   For debug use you can limit the number of users. FALSE = unlimited.
 *
 * @return mixed
 *   $users/FALSE - Either users or false.
 */
function import_users($mapping, $limit = FALSE) {
  global $stdout, $settings;

  $users = array();
  $row_count = 0;
  if (($handle = fopen($settings['filename'], "r")) !== FALSE) {
    
    while (($row = fgetcsv($handle, 1000, ",")) !== FALSE) {
      // Don't do anything at header row.
      if (!$row_count) {
        $row_count++;
        continue;
      }

      if ($limit === FALSE || $row_count <= $limit) {
        // Save user intially.
        $account = import_users_save_user($mapping, $row, $settings['roles']);
        import_users_save_pass_cleartext($account);

        $users[$account->uid] = $account;
        // Save fields on user.
        $user_wrapper = import_users_save_fields($mapping, $row, $account);

        fwrite($stdout, "[$row_count] Imported: {$account->name}\n");
        $row_count++;
      }

    }

    fclose($handle);
    fwrite($stdout, str_repeat('-', 30) . "\n");
    fwrite($stdout, ($row_count - 1) . " users were imported\n");
    return $users;
  }

  return FALSE;

}

/**
 * Save user without additional fields.
 *
 * @todo Change description.
 * 
 * @param array $mapping
 *   Mapping configuration.
 * @param array $row
 *   Current csv row.
 *
 * @return object
 *   Drupal user object.
 */
function import_users_save_user($mapping, $row, $roles) {
  $col = 0;
  $user = new stdClass;

  foreach($mapping as $conf) {
    if (empty($conf['init_field']) && empty($conf['role'])) {
      $col++;
      continue;
    }

    $value = $row[$col];

    if (!empty($conf['init_field'])) {
      if (!empty($conf['value_callback'])) {
        $value = call_user_func($conf['value_callback'], $value);
      }
      // Convert value to UTF-8.
      import_users_convert_2_utf8($value);
      $user->{$conf['init_field']} = $value;
    }
    
    if (!empty($conf['role']) && !empty($value)) {
      $roles += array((int)$conf['role'] => TRUE);
    }

    $col++;
  }

  $pass_clear = $user->pass;
  $account = import_users_save_user_init($user, $roles);
  $account->pass_clear = $pass_clear;
  return $account;
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
function import_users_save_user_init($user, $roles) {
  if (empty($user->name) || empty($user->pass)) {
    return FALSE;
  }
  $account = new stdClass;
  $account->is_new = TRUE;
  $account->name = $user->name;
  $account->mail = $account->init = $user->mail;
  $account->status = TRUE;
  $account->roles = $roles;
  if (!empty($user->created)) {
    $account->created = $user->created;
  }
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
    if (empty($row[$col])) {
      $col++;
      continue;
    }
    if (!empty($conf['field'])) {
      $field = $conf['field'];
      $user_wrapper = entity_metadata_wrapper('user', $account);
      $value = $row[$col];
      if (!empty($conf['value_callback'])) {
        $value = call_user_func($conf['value_callback'], $value);
      }
      // Convert value to UTF-8.
      import_users_convert_2_utf8($value);
      // Translate country code.
      if ($conf['col'] == 'LAND') {
        import_users_translate_country($value);
      }

      // If hierarical term ref is used.
      if (
        !empty($conf['field_type'])
        && $conf['field_type'] == 'term_ref_hierarical'
      ) {
        $term_lineage = taxonomy_get_parents_all($value);
        $value = !empty($term_lineage) ? $term_lineage : $value;
      }

      // If the field value is available at root level.
      if (!is_array($field)){
        $user_wrapper->$field->set($value);
      }
      // Otherwise if the field value is at the second level.
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
    case 'Norge':
      $value = 'NO';
      break;
    case 'Sverige':
      $value = 'SE';
      break;
    case 'USA':
      $value = 'US';
      break;
    default:
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

/**
 * Simple function. Replaces empty string with predefined mail address.
 *
 * @param string $value
 *   Email value.
 *
 * @return string
 *   Non-empty string (email).
 */
function import_users_process_empty_email($value) {
 return !empty($value) ? $value :'userneeds@tochange.this';
}

/**
 * Handles changed kms timestamp.
 *
 * @param string $kms_time
 *   Kms timestamp that needs to be converted.
 *
 * @return string
 *   UNIX time stamp.
 */
function import_users_fuckedup_kms_time2unix($kms_time) {
  $t = explode('/', $kms_time);
  return strtotime(
    implode('/', array($t[1], $t[0], $t[2]))
  );
}

function import_users_save_pass_cleartext($user) {
  $user_wrapper = entity_metadata_wrapper('user', $user);
  $user_wrapper->field_pass_clear->set($user->pass_clear);
  $user_wrapper->save();
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


/*
Nye felter:
SYSTEMACCOUNT
TERMID
DEBITORNO
FIRMANAVN
FIRSTNAME
LASTNAME
NAME
OPRETTETDATO
SLUTDATO
REDIGERETDATO
USERREMARK
TELEPHONENUMBER
USERID
DISABLED
PIN
PASSWORD
MILEAGE
PASSWORDDATA
STARTDATO
FAKTURAADRESSE
POSTNR
UBY
LAND
OPRETTET
REDIGERET
EMAILADDRESS
 */
