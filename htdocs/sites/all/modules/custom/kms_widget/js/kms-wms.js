// KMS WMS Widget JS

jQuery(function() { 
  var service_name = Drupal.settings.kms_widget.service_name;
  var service_layer = Drupal.settings.kms_widget.service_layer;
  initService(service_name,service_layer);   
});

function initService(name,layer) {

    kmsticket: '',  
    kmsticket = new VisStedet.Ticket();
	
    var map = new OpenLayers.Map(
        'mapTag',
        {
            projection: 'EPSG:25832',
            units: 'm',
            maxExtent: new OpenLayers.Bounds(120000,5661139.2,1000000,6500000.0),
            maxResolution: 1638.4,
		    numZoomLevels: 12,
		    controls : []
        }
    );
	
	var wms = new OpenLayers.Layer.WMS(
		"WMS",
		"http://kortforsyningen.kms.dk/" + name + '?',
		{ layers: layer, 
		  format: 'image/jpeg', 
		  bgcolor: '0xFFFFFF',
		  ticket: kmsticket,
		},
		{singleTile: true, 
		  transitionEffect: 'resize', 
		  buffer: 0, 
		  isBaseLayer : true , 
		});
	
    map.addLayer(wms);
	
	// The buttons and bar in upper left corner:
	map.addControl(new OpenLayers.Control.PanZoomBar());

	// All mouse controls (drag, zoom with mouse wheel. etc)
	map.addControl(new OpenLayers.Control.Navigation());

	// Layer selector in upper right corner. (Base layers show as choices between
	// radio buttons, other layers as selectable checkboxes):
	//map.addControl(new OpenLayers.Control.LayerSwitcher());
	
	// Default center and zoom on Copenhagen
	map.setCenter(new OpenLayers.LonLat(724500, 6176450), 9);
	map.addControl(new OpenLayers.Control.PanZoomBar());
    map.addControl(new OpenLayers.Control.Navigation());
}
