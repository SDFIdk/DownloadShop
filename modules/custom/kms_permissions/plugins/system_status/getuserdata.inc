<?php
/**
 * @file
 * KMS System Status plugin.
 */

$plugin = array(
  'get' => array(
    'function' => 'get_status',
  ),
);

/**
 * Get user service list
 *
 * @param string $type
 *   getuserdata
 */
function get_status($type, $mode) {
  $output = array(
    'productTypeId' => NULL,
    'productTypeName' => NULL,
    'ProductID' => NULL,
    'ProductName' => NULL,
    'ProductLink' => NULL,
    'ProductKorttype' => NULL,
  );

  switch($type) {
    case 'permissions':
      $username = $_GET['login'];
      $password = $_GET['password'];
      $userId = user_authenticate($username, $password);
      // Check if username and password match
      if($userId != FALSE){
        $user = user_load($userId);

        // Get all ID's of webservices from user account
        $all_services['bundles'] = $user->field_access_bundles[LANGUAGE_NONE];
        $all_services['predefined_datacollections'] = (isset($user->field_predefined_datacollections[LANGUAGE_NONE]) ? $user->field_predefined_datacollections[LANGUAGE_NONE] : '');
        $all_services['ftp'] = min_side_query();
        $all_services['applications'] = $user->field_applications[LANGUAGE_NONE];
        $all_services['main_services'] = _kms_permissions_get_separate_webservices_by_uid($userId);

        $webservices = _kms_permissions_webservice_return_list_array($all_services);
        drupal_add_http_header('Content-Type', 'application/json');

        if(isset($_GET['callback'])){
          print $_GET['callback']. '(' .json_encode($webservices). ');';
        }else{
          print json_encode($webservices);
        }
      }else{
        // Passworrd incorect
        print t("Authentication failed");
      }

      break;
  }
  die;
}

function min_side_query() {
  $query = db_select('field_data_field_min_side', 'ms');
  $query->leftJoin('field_data_body', 'b', 'ms.entity_id = b.entity_id');
  $query->fields('ms', array('entity_id', 'field_min_side_url', 'field_min_side_title'));
  $query->fields('b', array('body_value', 'body_summary'));
  $result = $query->execute()->fetchAll();

  return $result;
}
