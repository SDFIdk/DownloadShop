<?php
/**
* Configuration
*/
$drupalroot      = '/home/drupal/kms.dev/htdocs';
$drupal_base_url = 'http://kms.fe.dev.cd.adapt.dk/';

$stdout = fopen('php://stdout', 'w');
fwrite($stdout, "KMS user auth test\n");

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
$_SERVER['SERVER_SOFTWARE'] = 'KMS User auth test';

// Db
$host = "kms.mysql.dev.cd.adapt.dk"; 
$user = "kms_dev"; 
$pass = "rDWnkhZCyTAbxA4N_dev"; 
$db = "kms_dev"; 


/**
* Open db connection.
*/
$con = pg_connect("host=$host dbname=$db user=$user password=$pass")
    or die ("Could not connect to server\n"); 


/**
* The password check happens here.
* Password 1234 is checked against the hash from user wid id= 10 in the db.
*/
$query = "SELECT pass FROM users WHERE uid = 10";
$rs = pg_query($con, $query) or die("Cannot execute query: $query\n");
$row = pg_fetch_row($rs);

$stored_hash = $row[0];
$password_2_check = '1234';
// If stored hash and password matches the hash is returned otherwise FALSE is returned.
$auth = _adapt_password_crypt('sha512', $password_2_check, $stored_hash);




function _adapt_password_crypt($algo, $password, $setting) {
  define('DRUPAL_MIN_HASH_COUNT', 7);
  define('DRUPAL_MAX_HASH_COUNT', 30);
  define('DRUPAL_HASH_LENGTH', 55);

  // The first 12 characters of an existing hash are its setting string.
  $setting = substr($setting, 0, 12);

  if ($setting[0] != '$' || $setting[2] != '$') {
    return FALSE;
  }
  $count_log2 = _adapt_password_get_count_log2($setting);
  // Hashes may be imported from elsewhere, so we allow != DRUPAL_HASH_COUNT
  if ($count_log2 < DRUPAL_MIN_HASH_COUNT || $count_log2 > DRUPAL_MAX_HASH_COUNT) {
    return FALSE;
  }
  $salt = substr($setting, 4, 8);
  // Hashes must have an 8 character salt.
  if (strlen($salt) != 8) {
    return FALSE;
  }

  // Convert the base 2 logarithm into an integer.
  $count = 1 << $count_log2;

  // We rely on the hash() function being available in PHP 5.2+.
  $hash = hash($algo, $salt . $password, TRUE);
  do {
    $hash = hash($algo, $hash . $password, TRUE);
  } while (--$count);

  $len = strlen($hash);
  $output =  $setting . _adapt_password_base64_encode($hash, $len);
  // _password_base64_encode() of a 16 byte MD5 will always be 22 characters.
  // _password_base64_encode() of a 64 byte sha512 will always be 86 characters.
  $expected = 12 + ceil((8 * $len) / 6);
  return (strlen($output) == $expected) ? substr($output, 0, DRUPAL_HASH_LENGTH) : FALSE;
}

function _adapt_password_get_count_log2($setting) {
  $itoa64 = _adapt_password_itoa64();
  return strpos($itoa64, $setting[3]);
}

function _adapt_password_itoa64() {
  return './0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz';
}

function _adapt_password_base64_encode($input, $count) {
  $output = '';
  $i = 0;
  $itoa64 = _adapt_password_itoa64();
  do {
    $value = ord($input[$i++]);
    $output .= $itoa64[$value & 0x3f];
    if ($i < $count) {
      $value |= ord($input[$i]) << 8;
    }
    $output .= $itoa64[($value >> 6) & 0x3f];
    if ($i++ >= $count) {
      break;
    }
    if ($i < $count) {
      $value |= ord($input[$i]) << 16;
    }
    $output .= $itoa64[($value >> 12) & 0x3f];
    if ($i++ >= $count) {
      break;
    }
    $output .= $itoa64[($value >> 18) & 0x3f];
  } while ($i < $count);

  return $output;
}

/**
* Close db connection
*/
pg_close($con); 

