<?php

$drupalroot      = '/home/drupal/kms.dev/htdocs';
$drupal_base_url = 'http://kms.fe.dev.cd.adapt.dk/';
$service_url     = 'http://kortforsyningen.kms.dk/?request=GetServices&login=YdelsesKatalog&password=YdelsesKatalog';

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
$_SERVER['SERVER_SOFTWARE'] = 'KMS import cli';

require_once 'includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

// Time and memory limits
set_time_limit(10000);
ini_set('memory_limit', '256M');

// Perform import as admin user
global $user;
$user = user_load(array('uid' => 1));

/**
 *  MAIN
 */

$qp = qp($service_url)->find('services');

$taxonomy = taxonomy_vocabulary_machine_name_load('webservices');

foreach ($qp->children() as $ele) {
  foreach ($ele->children() as $subele) {
    // echo $subele->tag() . PHP_EOL; next();
    $name        = $subele->tag();
    $description = $subele->find('title')->text();
    $term = taxonomy_get_term_by_name($name, 'webservices');
    if ($term == false) {
      $term = new stdClass();
      $term->name = $name;
      $term->vid = $taxonomy->vid;
      $term->description = $description;
      taxonomy_term_save($term);
    }
  }
}
