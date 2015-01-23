<?php

/**
 * Implements hook_rules_action_info().
 */

function kms_mapwidget_rules_action_info() {
  $actions = array();

  $actions['kms_mapwidget__fme_request'] = array(
    'label' => t('Create new request to FME'),
    'parameter' => array(
      'line_item' => array(
        'type' => 'commerce_line_item',
        'label' => t('Commerce line item'),
        'restriction' => 'selector',
      ),
    ),
    'group' => 'KMS',
    'callbacks' => array(
      'execute' => 'kms_mapwidget__fme_request',
    ),
  );

  return $actions;

}

/**
* Implementation of hook_rules_condition_info().
*/
function kms_mapwidget_rules_condition_info() {
  return array(
    'kms_mapwidget_run_once_condition' => array(
      'group' => 'KMS',
      'label' => t('Only run rule once'),
      'module' => 'kms_mapwidget',
      'parameter' => array(
         'run_once_tag' => array(
          'type' => 'text',
          'label' => t('Run once tag'),
         ),
      ),
    ),
  );
}

function kms_mapwidget_run_once_condition($run_once_tag) {

  if ($executed = &drupal_static($run_once_tag)) {
    return FALSE;
  } else {
    $executed = TRUE;
    return TRUE;
  }

}

function kms_mapwidget__fme_request($li) {
  // Check if the line item is of type userdefined

  if ($li->field_li_type[LANGUAGE_NONE][0]['value'] == 1) {

    $selection = unserialize($li->field_selection[LANGUAGE_NONE][0]['value']);
    
    $op = commerce_product_load($selection['product_id']);
    $dataset = $op->field_fme_name[LANGUAGE_NONE][0]['value'];

    $selection_type = taxonomy_term_load($selection['selection_type']);
    $dataformat = taxonomy_term_load($selection['dataformat']);
    $koordinatsystem = taxonomy_term_load($selection['koordinatsystem']);
    $buffer = taxonomy_term_load($selection['buffer']);

    $udtrType = $selection_type->field_type[LANGUAGE_NONE][0]['value'] == 'drawrect' ? 1 : 0;  

    $data['udtrType'] = $udtrType;
    $data['DestFormat'] = $dataformat->field_fme_name[LANGUAGE_NONE][0]['value'];
    $data['DestCoordSys'] = $koordinatsystem->field_fme_name[LANGUAGE_NONE][0]['value'];
    $data['BBOX'] = $buffer->name;
    $data['ctlClip'] = $selection['clipping'] ? 'yes' : 'no';
    $data['OrdreNummer'] = $li->order_id;
    
    $sel = json_decode($selection['selection']);

    if ($udtrType == 0) {
      $data['AdmKode'] = join(',',$sel);
    }

    if ($udtrType == 1) {
      // [selection] => {"left":547417.6,"bottom":6235603.2,"right":575270.4,"top":6268371.2}
      $data['X1'] = $sel->left;
      $data['X2'] = $sel->right;
      $data['Y1'] = $sel->bottom;
      $data['Y2'] = $sel->top;
    }

    $job = kms_mapwidget__fme_api('run',$dataset,$data);

    $li->field_jobid[LANGUAGE_NONE][0]['value'] = $job->serviceResponse->jobID;

    commerce_line_item_save($li);

  }
}
