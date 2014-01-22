<?php

//drush -d scr --uri=kms.dev cleanup_script.php

/**
 * Removes separate service records from user bundle permissions
 */
$counter = 0;

$service_types = kms_permissions_widget_type_options(); 
$type = 'geo';
$count1 = db_query('SELECT COUNT(entity_id) FROM field_data_field_bundle_webservices_'.$type.' WHERE bundle =:bundle_type', array(':bundle_type'=> 'user'))->fetchField();
Print(' Total records in separate service table on start '.$count1 . "\xA");


foreach ($service_types as $type) {

  $result = db_query('SELECT bundle.entity_id as userid, bundle.field_access_bundles_nid, webservices.entity_id, webservices.field_bundle_webservices_'.$type.'_value as serviceid FROM {field_data_field_access_bundles} as bundle
    RIGHT JOIN field_data_field_bundle_webservices_'.$type.' as webservices 
    ON bundle.field_access_bundles_nid = webservices.entity_id
    WHERE webservices.bundle =:bundle_type
    AND bundle.entity_id = :entity_id', array(':bundle_type' => 'access_bundle', ':entity_id' => '4715'));
  
  foreach ($result as $record) {   
    
   // print_r($record);
    $counter++;
    remove_record($record->userid, $type, $record->serviceid);
  }


}

/* Test particular user by uid
print(' User 4715 has these separatate permissions in permissions table ' . "\xA");

$type = 'geo';

$result = db_query('SELECT field_bundle_webservices_'.$type.'_value
    FROM field_data_field_bundle_webservices_'.$type.' 
    WHERE bundle =:bundle_type
    AND entity_id = :entity_id', array(':bundle_type' => 'user', ':entity_id' => '4715'));

  foreach ($result as $record) {   
    print_r($record);
  }

*/

print(' Found '.$counter.' rows in Bundle sets '. "\xA");

$count2 = db_query('SELECT COUNT(entity_id) FROM field_data_field_bundle_webservices_'.$type.' WHERE bundle =:bundle_type', array(':bundle_type'=> 'user'))->fetchField();
Print(' Total records in separate service table after '.$count2 .' removed '. ($count1 - $count2) . "\xA");



function remove_record($userid, $type, $serviceid){
  //print('Removed '.$userid. ' with service_id '.$serviceid.  "\xA");
  db_query('DELETE FROM {field_data_field_bundle_webservices_'.$type.'} 
    WHERE entity_id = :entity_id AND field_bundle_webservices_'.$type.'_value = :webservice_id', array(':entity_id' => $userid, ':webservice_id' => $serviceid));
  db_query('DELETE FROM {field_revision_field_bundle_webservices_'.$type.'} 
    WHERE entity_id = :entity_id AND field_bundle_webservices_'.$type.'_value = :webservice_id', array(':entity_id' => $userid, ':webservice_id' => $serviceid));
}