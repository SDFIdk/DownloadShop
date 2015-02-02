<?php

class kms_user_handler_filter_exposed_services extends views_handler_filter {
  /**
   * Options form subform for setting exposed filter options.
   */
  function value_form(&$form, &$form_state) {
    parent::value_form($form, $form_state);

    $service_types = kms_permissions_widget_type_options();
    $service_types_diferent = $this->diferent_service_types();
    $service_types = array_merge($service_types, $service_types_diferent);
    $service_types['0'] = t('- Alle -');

    //Multiple select field for webservice type list
  	$form['value']['exposed_services'] = array(
  	  '#type' => 'select',
  	  '#description' => t('Select the webservice type'),
      '#default_value' => '0',
  	  '#options' => $service_types,
      '#required' => FALSE,
  	);

    //Fake multiple select field list for webservice with all available web services
    $webServiceList = _kms_user_return_websevice_list_all();
    $form['value']['exposed_services_list'] = array(
      '#type' => 'select',
      '#multiple' => 'true',
      '#size' => '8',
      '#required' => FALSE,
      '#description' => t('Select the webservice type'),
      '#options' => $webServiceList,
    );

    //Checkbox for seperate permissions
    $form['value']['seperate_permissions'] = array(
      '#type' => 'checkbox', 
      '#title' => t('separate permissions'),
      '#return_value' => 1, 
      '#default_value' => 0,
    );

    drupal_add_css('#edit-exposed-services-list { display:none; } .form-item-seperate-permissions { display:none; } ' , 'inline');
  }

  /**
  * Return diferent service types
  */
  function diferent_service_types(){
    $service_types['predefined_datacollections'] = "Predefined datacollections";
    $service_types['applications'] = "Applications";
    $service_types['ftp'] = "FTP";

    return $service_types;
  }

  /**
  * remowes prefix from key
  */
  function remove_prefix_from_key($array, $prefix){
    $narray = array();
    foreach ($array as $key => $value) {
      $new_key = str_replace($prefix, "", $key);
      $narray[$new_key] = $new_key;
    }
    return $narray;
  }

  /**
   * Alters Views query when filter is used.
   */
  function query() {

    //Get webservice and webservice type array
    $data = $this->view;

    if(isset($this->value['0']) && $this->value['0'] != '0' && !empty($data->exposed_data['exposed_services_list'])){
      // make sure base table is included in the query
      $this->ensure_my_table();
            
      //Get webservice table name
      $other_services = $this->diferent_service_types();
      $col_name = 'value';
      switch ($this->value['0']) {
        case 'predefined_datacollections':
          $webservice = 'field_predefined_datacollections';
          //Remove prefix from key
          $prefix = 'predefined_datacollections_';
          $webserviceType = $this->remove_prefix_from_key($data->exposed_data['exposed_services_list'], $prefix);
          $col_name = 'target_id';
          break;
        case 'applications':
          $webservice = 'field_applications';
          //Remove prefix from key
          $prefix = 'applications_';
          $webserviceType = $this->remove_prefix_from_key($data->exposed_data['exposed_services_list'], $prefix);
          break;
        case 'ftp':
          $webservice = 'field_ftp_permissions';
          //Remove prefix from key
          $prefix = 'ftp_';
          $webserviceType = $this->remove_prefix_from_key($data->exposed_data['exposed_services_list'], $prefix);
          break;

        default:
          $webservice = 'field_bundle_webservices_'.strtolower($this->value['0']);
          //GetService list array
          $webserviceType = $data->exposed_data['exposed_services_list'];
          break;
      }

      $service = array($webservice => array('und' => $webserviceType));

      //defind empty users array
      $users = array();
      if($data->exposed_data['seperate_permissions'] == "1"){
        //Seperate permissions only
        $usersAll = _kms_permissions_get_uids_by_separate_services($service, $col_name);
        foreach($usersAll as $uid => $sids) {
            $users[] = $uid;
        }
      }else{
        //Show seperate permissions and bundles        
        //Get all users which are in has permission for that webservice
        $users = _kms_user_get_users_from_services($service, $col_name);
      }
      
      if(empty($users)){ $users['0'] = '0'; }
      //Add where expresion to view query
      $usersIn = join($users, ', ');
      $operator = "IN (".$usersIn.")";
      $this->query->add_where_expression($this->options['group'], "users.uid $operator");
    }
  }

}