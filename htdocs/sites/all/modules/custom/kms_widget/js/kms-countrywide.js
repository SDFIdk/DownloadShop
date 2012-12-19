// KMS WMS contrywide Widge
// Allways download 1 file, entire dataset

var conf;
var searchLayer

jQuery(function($) { 
  conf = Drupal.settings.kms_widget;
  conf.center_longitude = parseInt(conf.center_longitude);
  conf.center_latitude = parseInt(conf.center_latitude);
  conf.zoom_level = parseInt(conf.zoom_level);
  conf.selection_type = parseInt(conf.selection_type);
 
  initService();   

  $.fn.updateForm('init');
});

(function($) {
  $.fn.updateForm = function(data) {
    var files = Array();
    $('#selection_message').empty();
    $('#selection_message').append('<ul></ul');
    $('#selection_message ul').append('<li>' + conf.selection_details + '</li>');
    files[0] = conf.selection_details;
    $('#edit-line-item-fields-field-selection-und-0-value').val(JSON.stringify(files));
    $('#edit-line-item-fields-field-selection-text-und-0-value').val( '1 samlet fil');
    if (data != 'init') {
      $('.useful-links').empty();
      $('.useful-links').append(conf.usefull_links);
    }
  };
})(jQuery);

function initService() {

  OpenLayers.ImgPath = "/sites/all/themes/custom/kms/images/";

  kmsticket: '',  
  kmsticket = new VisStedet.Ticket();

  // --------------------------------------------------------------------
  // WMTS matrixId based on OpenLayers zoomlevels
  // --------------------------------------------------------------------
  var kmsWmtsSkaermkortMatrixIds = new Array(12);

  // Populate matrix id array
  for (zli=0; zli<kmsWmtsSkaermkortMatrixIds.length; ++zli) {
	if (zli<10)
		kmsWmtsSkaermkortMatrixIds[zli] = "L0" + zli;
	else
		kmsWmtsSkaermkortMatrixIds[zli] = "L" + zli;
  }

  // The extent - changes should only be done according to the tiling schemas
  var olMaxExtent = new OpenLayers.Bounds(120000,5900000,1000000,6500000); // KMS tiling schema

  // The resolutions - changes should only be done according to the tiling schemas
  var olResolutions = new Array(0.8,1.6,3.2,6.4,12.8,25.6,51.2,102.4,204.8,409.6,819.2,1638.4);
  
  var skaermkort_url = ["http://a.kortforsyningen.kms.dk/topo_skaermkort",
                        "http://b.kortforsyningen.kms.dk/topo_skaermkort",
                        "http://c.kortforsyningen.kms.dk/topo_skaermkort",
                        "http://d.kortforsyningen.kms.dk/topo_skaermkort"];
 
    var map = new OpenLayers.Map(
        'mapTag',
        {
            projection: 'EPSG:25832',
            units: 'm',
            theme : null,
            maxExtent: olMaxExtent,
            maxResolution: 1638.4,
		    numZoomLevels: 12,
		    resolutions: olResolutions,
		    controls : []
        }
    );
   
   var oLayers = Array();

	// WMTS - baselayer
	oLayers[1] = new OpenLayers.Layer.WMTS(
		{
			name: "Danmarkskort 2012",
			url: skaermkort_url,
			layer: "dtk_skaermkort",
			matrixSet: "View1",
			matrixIds: kmsWmtsSkaermkortMatrixIds,
			format: "image/jpeg",
			style: "default",
			opacity: 1.0,
			isBaselayer: true,
			params: { ticket: kmsticket }  
		}
	);

    oLayers[0] = new OpenLayers.Layer.WMS (
		conf.name,
		"http://kortforsyningen.kms.dk/" + conf.service_name + '?',
		{ layers: conf.service_layer, 
		  format: 'image/png',
		  bgcolor: '0xFFFFFF',
		  ticket: kmsticket
		},
		{ singleTile: false, 
		  transitionEffect: 'resize', 
		  buffer: 0, 
		  isBaseLayer : true
		}
	);

	for (var i=0; i<oLayers.length; i++)
    {
        map.addLayer(oLayers[i]);
    }
       		
	// The buttons and bar in upper left corner:
	map.addControl(new OpenLayers.Control.PanZoomBar());
    //map.addControl(new OpenLayers.Control.PanZoomBar({'div':OpenLayers.Util.getElement('panzoombar')}));

	// All mouse controls (drag, zoom with mouse wheel. etc)
	map.addControl(new OpenLayers.Control.Navigation());

	// Layer selector in upper right corner. (Base layers show as choices between
	// radio buttons, other layers as selectable checkboxes):
	map.addControl(new OpenLayers.Control.LayerSwitcher());
	// map.addControl(new OpenLayers.Control.LayerSwitcher({'div':OpenLayers.Util.getElement('layerswitcher')}));
	
	// Set center and zoom 
	map.setCenter(new OpenLayers.LonLat(conf.center_longitude, conf.center_latitude),conf.zoom_level);

  initSearch(map);

}


