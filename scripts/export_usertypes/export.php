<?php

$drupalroot      = '/home/drupal/kms.dev/htdocs';
$drupal_base_url = 'http://kms.fe.dev.cd.adapt.dk/';

$output = '"User-term name", "ID"' . "\n";

$stdout = fopen('php://stdout', 'w');

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
$_SERVER['SERVER_SOFTWARE'] = 'KMS user-term export cli';

error_reporting(E_ERROR | E_PARSE);

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

// Find the correct term-id from the vocabulary name
$taxonomy_vid  = taxonomy_vocabulary_machine_name_load('user_type');

// Get the taxonomy tree for the user term vocabulary
$taxonomy_tree = taxonomy_get_tree($taxonomy_vid->vid);

// Step through each tree element, and find leaf-children plus their parents
foreach ($taxonomy_tree as $id => $item) {
	$tid = $item->tid;
	$children = taxonomy_get_children($tid, $taxonomy->vid);
	if (empty($children)) {
		// This must be a leaf since it has no children
		$parents = taxonomy_get_parents_all($tid);
		$txt = '"';
		$first = TRUE;
		while (!empty($parents)) {
			$litem = array_pop($parents);
			$txt .= ($first ? '' : '-->') . $litem->name;
			$first = FALSE;
		}
		$txt .= '", "' . $item->tid .'"'."\n";
		$output .= $txt;
	}
}

$iso_output = utf8_decode($output);

fwrite($stdout, $iso_output);

?>
