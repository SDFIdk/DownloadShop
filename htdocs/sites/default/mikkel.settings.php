<?php
$databases = array (
  'default' => 
  array (
    'default' => 
    array (
      'database' => 'kms_live',
      'username' => 'kms_live',
      'password' => 'kms_live',
      'host' => 'localhost',
      'port' => '',
      'driver' => 'pgsql',
      'prefix' => '',
    ),
  ),
  'oracle' =>
  array (
    'default' => 
    array (
      'database' => 'kmsoracle_dev',
      'username' => 'root',
      'password' => 'foxyl',
      'host' => 'kms.mysql.dev.cd.adapt.dk',
      'port' => '',
      'driver' => 'mysql',
    ),
  ),
);
$update_free_access = FALSE;
$drupal_hash_salt = 'FZ7cjE7VPpcUCIhLC7-Q0TMzv6WpbQV-9oakjFxFK_M';
$base_url = 'http://loc.kms.dk';  // NO trailing slash!

ini_set('session.gc_probability', 1);
ini_set('session.gc_divisor', 100);
ini_set('session.gc_maxlifetime', 200000);
ini_set('session.cookie_lifetime', 0);

$conf['404_fast_paths_exclude'] = '/\/(?:styles)\//';
$conf['404_fast_paths'] = '/\.(?:txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp)$/i';
$conf['404_fast_html'] = '<html xmlns="http://www.w3.org/1999/xhtml"><head><title>404 Not Found</title></head><body><h1>Not Found</h1><p>The requested URL "@path" was not found on this server.</p></body></html>';

// Oracle db 
$conf['kms_oci_conn_user'] = 'kf_download_test';
$conf['kms_oci_conn_pass'] = 'kf_download_test';
$conf['kms_oci_conn_host'] = '192.168.50.5:1521';
$conf['kms_oci_conn_db'] = 'XE';
$conf['kms_oci_mail_default_from'] = 'download@kortforsyningen.dk';
$conf['kms_oci_mail_default_to'] = 'mikkel@adapt.dk';
$conf['kms_permissions_conn_user'] = 'weblog_test';
$conf['kms_permissions_conn_pass'] = 'weblog_test';
$conf['kms_permissions_conn_host'] = '192.168.50.5:1521';
$conf['kms_permissions_conn_db'] = 'XE';


// Preproccesing of js/css OFF
$conf['preprocess_css'] = 0;
$conf['preprocess_js'] = 0;

$conf['ultimate_cron_poorman'] = 0;
