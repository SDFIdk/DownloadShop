<?php

$plugin = array(
  'title' => t('KMS map widget'),
  'description' => t('Show the map widget'),
  'category' => t('KMS'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'defaults' => array(),
  'render callback' => 'kms_mapwidget_pane_render',
);

/**
 * Render the custom content type.
 */

function kms_mapwidget_pane_render($subtype, $conf, $panel_args, $context) {

  $modulename = 'kms_mapwidget';

  if (empty($_COOKIE['downloadticket'])) {
    $domain = $_SERVER['HTTP_HOST'];
    if (preg_match("/^(.+):/", $_SERVER['HTTP_HOST'], $matches))
      $domain = $matches[1];
    @$ticket = file_get_contents("http://kortforsyningen.kms.dk/?request=GetTicket&login=FriDownload&password=FriDownload2013");
    setcookie("downloadticket", $ticket, time()+60*60*24, '/', $domain);
  }

  $nw = entity_metadata_wrapper('node',$context->data);

  drupal_add_js(
    array('kms_mapwidget' => array(
      'name'             => $nw->title->value(),
      'service_name'     => $nw->field_service_name->name->value(),
      'service_layer'    => $nw->field_service_layer->value(),
      'overlay'          => (bool) $nw->field_overlay->value(),
      'center_longitude' => (int) $nw->field_center_longitude->value(),
      'center_latitude'  => (int) $nw->field_center_latitude->value(),
      'zoom_level'       => (int) $nw->field_zoom_level->value(),
      'grid_folder'      => '/sites/default/files/grid/',
      ),
    ),
    array('type' => 'setting')
  );

  drupal_add_library('system', 'ui.autocomplete');
  drupal_add_js('http://openlayers.org/api/2/OpenLayers.js');
  drupal_add_css(drupal_get_path('module', $modulename).'/css/style.css');
  drupal_add_js(drupal_get_path('module', $modulename).'/js/json2.js');
  drupal_add_js(drupal_get_path('module', $modulename).'/js/VisStedet/Utils.js');
  drupal_add_js(drupal_get_path('module', $modulename).'/js/VisStedet/Ticket.js');
  drupal_add_js(drupal_get_path('module', $modulename).'/js/VisStedet/Search.js');
  drupal_add_js(drupal_get_path('module', $modulename).'/js/VisStedet/Search/GeoSearch.js');
  drupal_add_js(drupal_get_path('module', $modulename).'/js/kms-search.js');
  drupal_add_js(drupal_get_path('module', $modulename).'/js/kms-mapwidget.js');

  $form = drupal_get_form('kms_mapwidget_form',$nw);

  $block = new stdClass();

  $content = '<div class="map-info-wrapper">';
  $content .= '<div class="map-wrapper"><div class="ui-widget"><a class="search" title="' . t('Search', array(), array('context' => 'KMS'))  . '"></a><input id="geosearch"/></div>';
  $content .= '<ul class="controlToggle">';
  $content .= '<li class="drag"><a href="" id="drag-button" class="active toggle" title="' . t('Drag map')  . '"></a></li>';
  $content .= '<li class="select"><a href="" id="select-button" class="toggle" title="' . t('Select items')  . '"></a></li>';
  $content .= '<li class="rect"><a href="" id="rect-button" class="toggle" title="' . t('Draw rectangle')  . '"></a></li>';
  $content .= '<li class="csv toggle"><a href="" id="csv-button" class="toggle" title="' . t('Enter comma separated values')  .
    '"></a><div class="title">' . t('Enter list with comma separated values').
    '<span id="csv-desc-button"></span></div><textarea id="csv-data"></textarea><button id="update-from-csv">'.
    t('Update') .'</button></li>';
  $content .= '<li class="reset"><a href="" id="reset-button" title="' . t('Reset selection')  . '"></a></li>';
  $content .= '<li><div id="layer-switcher"></div ></li>';
  $content .= '</ul>';

  $content .= '<div id="mapTag" style="width: 445px; height: 550px"></div></div>';

  $content .= '<div class="product-body">' . $nw->body->value->value() . '</div>';
  $content .= '<div id="selection_message"></div>';
  $content .= '<div id="selection_errors"></div>';
  $content .= '<div class="select-desc" id="csv-description" style="display:none;">' . t('Paste comma-separated list of codes.') . '</div>';

  $content .= '<div class="useful-links">';
  foreach (array('field_kms_dk', 'field_geodata_info_dk', 'field_legend') as $field_name) {
    $field = field_view_field('node', $nw->value(), $field_name, array('label' => 'hidden'));
    $content .= '<span>' . render($field) . '</span>';
  }
  $content .= '</div><div class="clear-fix"></div></div>';

  $block->content = drupal_render($form) . $content;

  return $block;
}
