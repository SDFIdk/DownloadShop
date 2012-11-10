  <?php

$plugin = array(
  'title' => t('KMS map widget'),
  'description' => t('Show the map widget'),
  'category' => t('KMS'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'defaults' => array(),
  'render callback' => 'kms_widget_pane_render',
);

/**
 * Render the custom content type.
 */

function kms_widget_pane_render($subtype, $conf, $panel_args, $context) {
  
  $product = commerce_product_load($context->data->field_product['und'][0]['product_id']);
  $service_name = $product->field_service_name['und'][0]['taxonomy_term']->name;
  $service_layer = $product->field_service_layer['und'][0]['value']; 

  drupal_add_js(
    array('kms_widget' => array(
      'service_name' => $service_name, 
      'service_layer' => $service_layer)
    ),
    array('type' => 'setting')
  );

  drupal_add_js('http://openlayers.org/api/2/OpenLayers.js');
  drupal_add_js(drupal_get_path('module', 'kms_widget').'/kfticket.php');
  drupal_add_js(drupal_get_path('module', 'kms_widget').'/js/VisStedet/Utils.js');
  drupal_add_js(drupal_get_path('module', 'kms_widget').'/js/VisStedet/Ticket.js'); 

  drupal_add_js(drupal_get_path('module', 'kms_widget').'/js/kms-wms.js');

  $content = '<div id="mapTag" style="width: 400px; height: 400px"></div>';

  $block = new stdClass();
  $block->content = $content;
 
  return $block;
}
