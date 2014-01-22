<?php

//drush -d scr --uri=kms.dev transfer_script.php

$settings = array(
  'kms_oci_conn_user' => variable_get('kms_permissions_conn_user', ''),
  'kms_oci_conn_pass' => variable_get('kms_permissions_conn_pass', ''),
  'kms_oci_conn_host' => variable_get('kms_permissions_conn_host', ''),
  'kms_oci_conn_db' => variable_get('kms_permissions_conn_db', ''),
  );

$counter = 0;

if (kms_oci_get_conn('kms_permissions', $settings)) {

  $query = "SELECT * from (
  	SELECT US2.USERID, S2.SERVICEID, S2.SERVICENAME, ST.TYPENAME 
  	From USERRESTRICTIONS2 US2
  	LEFT JOIN SERVICES2 S2 
  	ON US2.SERVICEID = S2.SERVICEID
    LEFT JOIN SERVICETYPES2 ST
    ON S2.TYPEID = ST.TYPEID
    ) 
where ROWNUM <=200000";  

$rows = kms_oci_select($query, array(), 'kms_permissions');

if (!empty($rows)) {
  foreach ($rows as $row) {
    $userid = get_drupal_uid($row['USERID']);
    $type = strtolower($row['TYPENAME']);

    if(!is_null($userid) && $type != "tms"){

        // Remove all associated service records with this user in this type of table, we gonna rewrite them with Oracle
      remove_duplicate($userid,$type,$row['SERVICEID']);

      $fields = array(
       'entity_type' => 'user',
       'bundle' => 'user',
       'deleted' => 0,
       'entity_id' => $userid,
       'revision_id' => $userid,
       'language' => LANGUAGE_NONE,
       'delta' => get_next_delta($userid, $type),
       'field_bundle_webservices_'.$type.'_value' => $row['SERVICEID']
       );    

      db_insert('field_data_field_bundle_webservices_'.$type)
      ->fields($fields)
      ->execute();

      db_insert('field_revision_field_bundle_webservices_'.$type)
      ->fields($fields)
      ->execute();

      $counter++;

    }

  }

}

kms_oci_close_conn('kms_permissions');
}

print('Script successfully inserted/updated '.$counter.' rows ');


function get_drupal_uid($kms_user_id){

  if(is_numeric($kms_user_id) && strlen($kms_user_id) < 7) {
    return $kms_user_id;
  } else {

    $query = db_select('field_data_field_kms_user_id', 'kms')
    ->condition('field_kms_user_id_value', $kms_user_id, '=')
    ->fields('kms', array('entity_id'));
    
    $result = $query->execute();
    
    while($record = $result->fetchAssoc()) {
      if(!empty($record['entity_id'])) {
       return $record['entity_id'];
      } else {
       return null;
      }
   }
  }
}

function get_next_delta($userid, $type){
  $last_delta = db_query('SELECT MAX(delta) FROM {field_data_field_bundle_webservices_'.$type.'} WHERE entity_id = '.$userid.'')
  ->fetchField();
  
  return $last_delta != "" ? $last_delta+1:0;
}

function remove_duplicate($userid, $type, $serviceid){
  db_query('DELETE FROM {field_data_field_bundle_webservices_'.$type.'} 
    WHERE entity_id = :entity_id AND field_bundle_webservices_'.$type.'_value = :webservice_id', array(':entity_id' => $userid, ':webservice_id' => $serviceid));
  db_query('DELETE FROM {field_revision_field_bundle_webservices_'.$type.'} 
    WHERE entity_id = :entity_id AND field_bundle_webservices_'.$type.'_value = :webservice_id', array(':entity_id' => $userid, ':webservice_id' => $serviceid));
}