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
  
  $selection_type = $product->field_selection_type['und'][0]['tid'];

  drupal_add_js(
    array('kms_widget' => array(
      'name'             => $product->title,
      'service_name'     => $product->field_service_name['und'][0]['taxonomy_term']->name, 
      'service_layer'    => $product->field_service_layer['und'][0]['value'],
      'selection_type'   => $selection_type,
      'dataformat'       => $product->field_dataformat['und'][0]['taxonomy_term']->name,
      'koordinatsystem'  => $product->field_koordinatsystem['und'][0]['taxonomy_term']->name,
      'center_longitude' => $product->field_center_longitude['und'][0]['value'],
      'center_latitude'  => $product->field_center_latitude['und'][0]['value'],
      'zoom_level'       => $product->field_zoom_level['und'][0]['value'],
      'selection_details'  => (empty($product->field_selection_details['und'][0]['value']) ?
                              false : $product->field_selection_details['und'][0]['value']),
      'grid_folder'      => '/' . drupal_get_path('module', 'kms_widget').'/grid/'),
    ),
    array('type' => 'setting')
  );

  drupal_add_library('system', 'ui.autocomplete');
  drupal_add_js('http://openlayers.org/api/2/OpenLayers.js');
  drupal_add_css(drupal_get_path('module', 'kms_widget').'/css/style.css');
  drupal_add_js(drupal_get_path('module', 'kms_widget').'/kfticket.php');
  drupal_add_js(drupal_get_path('module', 'kms_widget').'/js/json2.js');
  drupal_add_js(drupal_get_path('module', 'kms_widget').'/js/VisStedet/Utils.js');
  drupal_add_js(drupal_get_path('module', 'kms_widget').'/js/VisStedet/Ticket.js'); 
  drupal_add_js(drupal_get_path('module', 'kms_widget').'/js/VisStedet/Search.js'); 
  drupal_add_js(drupal_get_path('module', 'kms_widget').'/js/VisStedet/Search/GeoSearch.js');
  drupal_add_js(drupal_get_path('module', 'kms_widget').'/js/kms-search.js');  

  switch ($selection_type) {
    case 3524: 
      drupal_add_js(drupal_get_path('module', 'kms_widget').'/js/kms-countrywide.js');
      break;
    case 3525: 
      drupal_add_js(drupal_get_path('module', 'kms_widget').'/js/kms-dagi.js');
      break;    
    case 3526: 
      drupal_add_js(drupal_get_path('module', 'kms_widget').'/js/kms-geojson.js');
      break;    
  }

 
  $content = '<div id="mapTag" style="width: 400px; height: 500px"></div>'
           . '<input id="geosearch" placeholder="Søg her"/>';

  $block = new stdClass();
  $block->content = $content;
 
  return $block;
}
