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
        $all_services['predefined_datacollections'] = $user->field_predefined_datacollections[LANGUAGE_NONE];
        $all_services['ftp'] = $user->field_ftp_permissions[LANGUAGE_NONE];
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
        print "authentication failed";
      }

      break;
  }
  die;
}