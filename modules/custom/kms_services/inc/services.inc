<?php

/**
 * @file
 */

function getServiceList($username) {

  $url = serviceListURLBuilder($username, $password);

  $xml = simplexml_load_file($url);
  if ($xml == FALSE) {
    return FALSE;
  }
  $serviceList = array();
  $serviceType = array();

  // Creates array with each service type.
  foreach ($xml->children() as $child) {
    $temp = (string) $child->getName();
    $serviceType[] = $temp;
  }
  // Get Free Service list.
  //$freeServiceList = getFreeServiceList();
  $freeServiceList = kms_services_get_free_services();
  // Loop each servicetype for name and title. Each service get's added to array with $name as key.
  foreach ($serviceType as $sType) {
    // Check if type have getCapability.
    $capability;
    switch ($sType) {
      case "WMS_vector": $capability = TRUE;
        break;

      case "WMTS": $capability = TRUE;
        break;

      case "WFS": $capability = TRUE;
        break;

      case "WCS": $capability = TRUE;
        break;

      case "GEO": $capability = TRUE;
        break;

      default: $capability = FALSE;
    }
    // Check if type has hoststring.
    $hoststring;
    switch ($sType) {
      case "WMS_vector": $hoststring = TRUE;
        break;

      case "WFS": $hoststring = TRUE;
        break;

      default: $hoststring = FALSE;
    }
    foreach ($xml->$sType->children() as $child) {
      $name = (string) $child->getName();
      $title = (string) $xml->$sType->$name->title;
      $type = (string) $sType;
      if ($type == "WMS_vector") {
        $type = "WMS";
      }
      $key = strtolower($type . "-" . $name);
      $free = FALSE;
      if (isset($freeServiceList[$key])) {
        $free = TRUE;
      }
      $service = array(
        "key" => $key,
        "type" => $type,
        "title" => $title,
        "name" => $name,
        "capability" => $capability,
        "hostString" => $hoststring,
        "version" => "",
        "free" => $free,
      );
      $serviceList[$key] = $service;
    }
  }
  // return null if list is empty.
  if (count($serviceList) == 0) {
    return NULL;
  }
  // Sort list.
  asort($serviceList);
  return $serviceList;
}

function serviceListURLBuilder($username, $password) {
  $url = "http://kortforsyningen.kms.dk/service?request=GetServices&login=" . $username . "&password=" . $password;
  return $url;
}

function getFreeServiceList() {
  $freeServiceList = array();
  $path = drupal_get_path('module', 'kms_services');
  // Read freeServiceList info into map.
  $file     = file_get_contents($path . "/data/FreeServiceList.csv");
  $rows     = explode("\n", $file);
  foreach ($rows as $key => $value) {
    if ($value != NULL) {
      $temp = explode(":", $value);
      $freeServiceList[strtolower(trim($temp[0] . "-" . $temp[1]))] = TRUE;
    }
  }

  return $freeServiceList;
}

/**
 * Page callback for admin/config/kms_services/.
 */
function kms_services_free_service_list() {
  $list = kms_services_get_free_services(TRUE);
  $add_new = drupal_get_form('kms_service_update_free_service_add_new');
  $table = array(
    '#theme' => 'table',
    '#header' => array('ID', 'Service'),
    '#rows' => array(),
    '#prefix' => drupal_render($add_new),
  );

  foreach($list as $value) {
    $form = drupal_get_form('kms_service_update_free_service', $value);
    $table['#rows'][] = array($value->id, drupal_render($form));
  }

  return drupal_render($table);
}

function kms_service_update_free_service_add_new($form, &$form_state) {
  $form['#attributes']['id'] = 'add_new_service';
  $form['name'] = array(
    '#type' => 'textfield',
    '#maxlength' => 30,
    '#required' => TRUE,
    '#attributes' => array(
      'placeholder' => t('Service name'),
    ),
    '#prefix' => t('Create new'),
  );

  $form['add_new_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Submit handler for kms_service_update_free_service_add_new form.
 */
function kms_service_update_free_service_add_new_submit(&$form, &$form_state) {
  db_insert('kms_services')
  ->fields(array(
    'free_service' => $form_state['values']['name'],
  ))
  ->execute();

  drupal_set_message(t('Successfully saved.'));
}

/**
 * Free service list update form.
 */
function kms_service_update_free_service($form, &$form_state, $service) {

  $form['#attributes']['id'] = 'update_free_service_' . $service->id;
  $form['name'] = array(
    '#type' => 'textfield',
    '#size' => 30,
    '#default_value' => $service->free_service,
    '#required' => TRUE,
  );
  $form['value'] = array(
    '#type' => 'hidden',
    '#value' => $service->id,
  );
  $form['update'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
    '#ajax' => array(
      'callback' => 'kms_service_update_free_service_update',
      'wrapper' => $form['#attributes']['id'],
    ),
  );
  $form['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
    '#submit' => array(
      'kms_service_update_free_service_delete',
    )
  );

  return $form;
}

/**
 * Ajax callback to update service value.
 */
function kms_service_update_free_service_update(&$form, &$form_state) {
  db_update('kms_services')
  ->fields(array(
    'free_service' => $form_state['values']['name'],
  ))
  ->condition('id', $form_state['values']['value'], '=')
  ->execute();

  $form['name']['#suffix'] = '<span class="form_message">' . t('Successfully updated.') . '</span>';

  $commands = array();
  $commands[] = ajax_command_replace($form['id'], render($form));
  $commands[] = ajax_command_invoke('.form_message', 'fadeOut', array(2000));
  return array('#type' => 'ajax','#commands' => $commands);
}

/**
 * Form callback to delete service.
 */
function kms_service_update_free_service_delete(&$form, &$form_state) {
  db_delete('kms_services')
    ->condition('id', $form_state['values']['value'], '=')
    ->execute();
}

function kms_services_get_free_services($full = FALSE) {
  $list = db_select('kms_services', 'c')
    ->fields('c')
    ->execute()
    ->fetchAll();

  if(empty($list)) {
    return FALSE;
  }

  if($full != FALSE) {
    return $list;
  }

  $new_list = array();
  foreach($list as $value) {
    $new_list[$value->free_service] = TRUE;
  }

  return $new_list;
}

/**
 * Start free service import.
 */
function kms_services_free_service_list_import() {
  $list = getFreeServiceList();
  $result = db_select('kms_services', 'c')
    ->fields('c')
    ->execute()
    ->fetchAssoc();

  if(!empty($result)) {
    return 'Free list was already imported';
  } else {
    foreach ($list as $key => $value) {
      db_insert('kms_services')
      ->fields(array(
        'free_service' => $key,
      ))
      ->execute();
    }
  }

  return "Imported successfully.";
}