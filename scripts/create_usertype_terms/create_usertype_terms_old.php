<?php
$script_name = 'Create usertype terms';
$drupalroot      = '/home/drupal/kms.dev/htdocs';
$drupal_base_url = 'http://kms.fe.dev.cd.adapt.dk/';

$stdout = fopen('php://stdout', 'w');
fwrite($stdout, "$script_name\n");
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
$_SERVER['SERVER_SOFTWARE'] = $script_name;

require_once 'includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

// Time and memory limits
set_time_limit(10000);
ini_set('memory_limit', '256M');

// Perform import as admin user
global $user;
$user = user_load(array('uid' => 1));


// Load regions.
$res_regions = drupal_http_request('http://oiorest.dk/danmark/regioner.json');
if ($res_regions->code != '200') {
  fwrite($stdout, "Could not load regions\n");
  die;
}

// Populate regions array.
$regions = array();
foreach (json_decode($res_regions->data) as $region) {
  $res_region = drupal_http_request($region->ref);
  if ($res_region->code != '200') {
    fwrite($stdout, "Could not load data for region: {$region->nr}\n");
    die;
  }

  $region_data = json_decode($res_region->data);
  $reg = new stdClass;
  $reg->region = $region_data;

  // Load municipalities.
  $res_muni = drupal_http_request($region_data->kommuner);
  if ($res_muni->code != '200') {
    fwrite($stdout, "Could not load municipalities for region: {$region_data->nr}\n");
    die;
  }

  // Create municipality array with id's as keys.
  $municipalities = array();
  array_walk(json_decode($res_muni->data), function ($v) use (&$municipalities){
    $municipalities[$v->nr] = $v;
  });
  $reg->municipalities = $municipalities;
  // Add region to regions array. 
  $regions[$region->nr] = $reg;
}

$vocab = taxonomy_vocabulary_machine_name_load('user_type');

foreach ($regions as $id => $region) {
  $term = new stdClass();
  $term->name = $region->region->navn;
  $term->vid = $vocab->vid;
  // $term->parent = $region_tid;
  $term->parent = 107;
  taxonomy_term_save($term);
  $region_tid = $term->tid;
  foreach ($region->municipalities as $id => $muni) {
    $term = new stdClass();
    $term->name = $muni->navn;
    $term->vid = $vocab->vid;
    // $term->parent = $region_tid;
    $term->parent = 108;
    taxonomy_term_save($term);
  }
}
