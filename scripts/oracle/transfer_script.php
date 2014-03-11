<?php

ini_set('memory_limit', '1024M');
//drush -d scr --uri=kms.dev transfer_script.php

$settings = array(
  'kms_oci_conn_user' => variable_get('kms_permissions_conn_user', ''),
  'kms_oci_conn_pass' => variable_get('kms_permissions_conn_pass', ''),
  'kms_oci_conn_host' => variable_get('kms_permissions_conn_host', ''),
  'kms_oci_conn_db' => variable_get('kms_permissions_conn_db', ''),
  );

$counter = 0;

// USERRESTRICTIONS2 - ALL Webservices
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
      remove_webservice_duplicate($userid,$type,$row['SERVICEID']);

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

// SMSUSERGROUP -  Applications
if (kms_oci_get_conn()) {
  //Delete existing permissions for user
  $query = "SELECT * FROM SMUSERGROUP";
  $rows = kms_oci_select($query, array());
  if (!empty($rows)) {
    foreach ($rows as $row) {
      $userid = get_drupal_uid($row['USERID']);
      //print('User id '.$userid.' will be altered with permissions from application '.$row['GROUPID'].' \n');
      if(!is_null($userid)){

        remove_application_duplicate($userid,$row['GROUPID']);

        $fields = array(
       'entity_type' => 'user',
       'bundle' => 'user',
       'deleted' => 0,
       'entity_id' => $userid,
       'revision_id' => $userid,
       'language' => LANGUAGE_NONE,
       'delta' => get_next_delta_applications($userid),
       'field_applications_value' => $row['GROUPID']
       );

      db_insert('field_data_field_applications')
      ->fields($fields)
      ->execute();

      db_insert('field_revision_field_applications')
      ->fields($fields)
      ->execute();

        $counter++;
      }
    }
  }

  // Close connection
  kms_oci_close_conn();
}

print('Script successfully inserted/updated from webservices'.$counter.' rows ');


/**
* Get drupal User idenfier
* @param $kms_user_id
*   ID returned from oracle, might be old or new (drupal) format
* @return $uid
*   UID
*/
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

/**
* Get next delta, so one user can have more than one separate service correctly inserted
* @param $userid
*   User identifier who's permissions will be removed.
* @param $type
*   Type of the service
*/
function get_next_delta($userid, $type){
  $last_delta = db_query('SELECT MAX(delta) FROM {field_data_field_bundle_webservices_'.$type.'} WHERE entity_id = '.$userid.'')
  ->fetchField();

  return $last_delta != "" ? $last_delta+1:0;
}

/**
* Get next delta for applications, so one user can have more than one separate service correctly inserted
* @param $userid
*   User identifier who's permissions will be removed.
*/
function get_next_delta_applications($userid){
  $last_delta = db_query('SELECT MAX(delta) FROM {field_data_field_applications} WHERE entity_id = '.$userid.'')
  ->fetchField();

  return $last_delta != "" ? $last_delta+1:0;
}

/**
* Remove all permissions before inserting from Oracle
* @param $userid
*   User identifier who's permissions will be removed.
* @param $type
*   Type of the service
* @param $serviceid
*   Service identifier
*/
function remove_webservice_duplicate($userid, $type, $serviceid){
  db_query('DELETE FROM {field_data_field_bundle_webservices_'.$type.'}
    WHERE entity_id = :entity_id AND field_bundle_webservices_'.$type.'_value = :webservice_id', array(':entity_id' => $userid, ':webservice_id' => $serviceid));
  db_query('DELETE FROM {field_revision_field_bundle_webservices_'.$type.'}
    WHERE entity_id = :entity_id AND field_bundle_webservices_'.$type.'_value = :webservice_id', array(':entity_id' => $userid, ':webservice_id' => $serviceid));
}

/**
* Remove all permissions before inserting from Oracle for applications
* @param $userid
*   User identifier who's permissions will be removed.
* @param $serviceid
*   Service identifier
*/
function remove_application_duplicate($userid, $serviceid){
  db_query('DELETE FROM {field_data_field_applications}
    WHERE entity_id = :entity_id AND field_applications_value = :webservice_id', array(':entity_id' => $userid, ':webservice_id' => $serviceid));
  db_query('DELETE FROM {field_revision_field_applications}
    WHERE entity_id = :entity_id AND field_applications_value = :webservice_id', array(':entity_id' => $userid, ':webservice_id' => $serviceid));
}
