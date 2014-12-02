<?php

class kms_user_handler_filter_exposed_services extends views_handler_filter {
  /**
   * Options form subform for setting exposed filter options.
   */
  function value_form(&$form, &$form_state) {
    parent::value_form($form, $form_state);

    $service_types = kms_permissions_widget_type_options();
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
    //*TODO if filter already has value, add array with webservice list
    $webServiceList = return_websevice_list_all();
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
   * Alters Views query when filter is used.
   */
  function query() {

    //Get webservice and webservice type array
    $data = $this->view;

    if(isset($this->value['0']) && $this->value['0'] != '0' && !empty($data->exposed_data['exposed_services_list'])){
      // make sure base table is included in the query
      $this->ensure_my_table();
            
      //Get webservice name in lower cases
      $webservice = strtolower($this->value['0']);

      //GetService list array
      $webserviceType = $data->exposed_data['exposed_services_list'];
      $service = array('field_bundle_webservices_'.$webservice => array('und' => $webserviceType));

      //defind empty users array
      $users = array();

      if($data->exposed_data['seperate_permissions'] == "1"){
        //Seperate permissions only
        $usersAll = _kms_permissions_get_uids_by_separate_services($service);
        foreach($usersAll as $uid => $sids) {
            $users[] = $uid;
        }
      }else{
        //Show seperate permissions and bundles        
        //Get all users which are in has permission for that webservice
        $users = _kms_user_get_users_from_services($service);
      }

      //Add where expresion to view query
      $usersIn = join($users, ', ');
      $operator = "IN (".$usersIn.")";
      $this->query->add_where_expression($this->options['group'], "users.uid $operator");
    }
  }

}