<?php

//drush -d scr --uri=kms.dev cleanup_script.php

/**
 * Removes separate service records from user bundle permissions
 */
$counter = 0;

// Load all webservice types
$service_types = kms_permissions_widget_type_options();
$type = 'geo';
$count1 = db_query('SELECT COUNT(entity_id) FROM field_data_field_bundle_webservices_'.$type.' WHERE bundle =:bundle_type', array(':bundle_type'=> 'user'))->fetchField();
Print(' Total records in separate service table on start '.$count1 . "\xA");

// Webservices by type
foreach ($service_types as $type) {
  $result = db_query('SELECT bundle.entity_id as userid, bundle.field_access_bundles_nid, webservices.entity_id, webservices.field_bundle_webservices_'.$type.'_value as serviceid FROM {field_data_field_access_bundles} as bundle
    RIGHT JOIN field_data_field_bundle_webservices_'.$type.' as webservices
    ON bundle.field_access_bundles_nid = webservices.entity_id
    WHERE webservices.bundle =:bundle_type', array(':bundle_type' => 'access_bundle'));
  foreach ($result as $record) {
    $counter++;
    remove_record($record->userid, $type, $record->serviceid);
  }
}

// Applications
$result_app = db_query('SELECT bundle.entity_id as userid, bundle.field_access_bundles_nid, applications.entity_id, applications.field_applications_value as serviceid FROM {field_data_field_access_bundles} as bundle
  RIGHT JOIN field_data_field_applications as applications
  ON bundle.field_access_bundles_nid = applications.entity_id
  WHERE applications.bundle =:bundle_type', array(':bundle_type' => 'access_bundle'));

foreach ($result_app as $record) {
  $counter++;
  remove_record_application($record->userid, $record->serviceid);
}

// Some output information after script run finalized
print(' Found '.$counter.' rows in Bundle sets '. "\xA");

$count2 = db_query('SELECT COUNT(entity_id) FROM field_data_field_bundle_webservices_'.$type.' WHERE bundle =:bundle_type', array(':bundle_type'=> 'user'))->fetchField();
Print(' Total records in separate service table after '.$count2 .' removed '. ($count1 - $count2) . "\xA");

/**
* Remove overlapping permissions from separate permission table
* @param $userid
*   User identifier who's permissions will be removed.
* @param $type
*   Type of the webservice
* @param $serviceid
*   Service identifier
*/
function remove_record($userid, $type, $serviceid){
  db_query('DELETE FROM {field_data_field_bundle_webservices_'.$type.'}
    WHERE entity_id = :entity_id AND field_bundle_webservices_'.$type.'_value = :webservice_id', array(':entity_id' => $userid, ':webservice_id' => $serviceid));
  db_query('DELETE FROM {field_revision_field_bundle_webservices_'.$type.'}
    WHERE entity_id = :entity_id AND field_bundle_webservices_'.$type.'_value = :webservice_id', array(':entity_id' => $userid, ':webservice_id' => $serviceid));
}

/**
* Remove overlapping permissions from separate permission table
* @param $userid
*   User identifier who's permissions will be removed.
* @param $serviceid
*   Service identifier
*/
function remove_record_application($userid, $serviceid){
  db_query('DELETE FROM {field_data_field_applications}
    WHERE entity_id = :entity_id AND field_applications_value = :webservice_id', array(':entity_id' => $userid, ':webservice_id' => $serviceid));
  db_query('DELETE FROM {field_revision_field_applications}
    WHERE entity_id = :entity_id AND field_applications_value = :webservice_id', array(':entity_id' => $userid, ':webservice_id' => $serviceid));
}
