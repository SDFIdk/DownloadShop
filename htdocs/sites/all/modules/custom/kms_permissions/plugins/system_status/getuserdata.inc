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

      if($userId != FALSE){
        $user = user_load($user);
        $bundles = _kms_permissions_webservice_return_list_array($user->field_access_bundles[LANGUAGE_NONE]);

        $predefined_datacollections = $user->field_predefined_datacollections[LANGUAGE_NONE];

        $ftp = $user->field_ftp_permissions[LANGUAGE_NONE];
        $applications = $user->field_applications[LANGUAGE_NONE];

        $main_services = _kms_permissions_get_separate_webservices_by_uid($userId);

        if(isset($_GET['callback'])){
          print 'json with callback';
        }else{
          print 'print json';
        }
      }else{
        print "authentication failed";
      }

      break;
  }

  //drupal_json_outpu
  die;
}