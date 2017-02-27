// KMS WMS tile Widge

var conf;
var selectLayer;
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
    for (var i=0; i<selectLayer.selectedFeatures.length; i++) {
      var filename = selectLayer.selectedFeatures[i].attributes.filename;
      files[i] = filename;
      $('#selection_message ul').append('<li>' + filename + '</li>');
    }
    $('#edit-line-item-fields-field-selection-und-0-value').val(JSON.stringify(files));
    $('#edit-line-item-fields-field-selection-text-und-0-value').val( i.toString() + ' udvalgte filer');
    
    if (data != 'init' && conf.usefull_links) {
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
  
  var skaermkort_url = ["//a.kortforsyningen.kms.dk/topo_skaermkort",
                        "//b.kortforsyningen.kms.dk/topo_skaermkort",
                        "//c.kortforsyningen.kms.dk/topo_skaermkort",
                        "//d.kortforsyningen.kms.dk/topo_skaermkort"];
 
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
		"//kortforsyningen.kms.dk/" + conf.service_name + '?',
		{ layers: conf.service_layer, 
		  format: 'image/png', 
		  bgcolor: '0xFFFFFF',
		  ticket: kmsticket,
		  transparent: true
		},
		{ singleTile: false, 
		  transitionEffect: 'resize', 
		  buffer: 0, 
		  isBaseLayer : true
		}
	);

    oLayers[2] = new OpenLayers.Layer.Vector('Grid', {
		styleMap:new OpenLayers.StyleMap({
		   "default":new OpenLayers.Style(OpenLayers.Util.applyDefaults({
			'strokeWidth' : 0.2,
			'strokeColor' : '#000000',
			'fillOpacity' : 0
		   }, OpenLayers.Feature.Vector.style["default"])),
		   "select":new OpenLayers.Style({'fillColor' : '#00FF00', 'fillOpacity' : 0.2}),
		   "highlight":new OpenLayers.Style({'fillColor' : '#0000FF', 'fillOpacity' : 0.1})
		})

    });

    jQuery.getJSON(conf.grid_folder + conf.selection_details,
      function(data) {
	    var geojson_format = new OpenLayers.Format.GeoJSON();
	    var features = geojson_format.read(data);
	    oLayers[2].addFeatures(features);
      }
    );

	for (var i=0; i<oLayers.length; i++)
    {
        map.addLayer(oLayers[i]);
    }
  
  selectLayer = oLayers[2];

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

  var selectCtrl = new OpenLayers.Control.SelectFeature(selectLayer,
      { clickout: false,  
	    toggle: true,
	    multiple: true, 
	  	onSelect:selected,
		onUnselect:unselected
	  }
	);
  
  var highlightCtrl = new OpenLayers.Control.SelectFeature(selectLayer, {
       hover: true,
       highlightOnly: true,
       renderIntent: "temporary"
   });

   // This sould be set to make mouse pan work
   selectCtrl.handlers.feature.stopDown = false;  
   highlightCtrl.handlers.feature.stopDown = false;

   map.addControl(selectCtrl);
   map.addControl(highlightCtrl);
   
   highlightCtrl.activate();
   selectCtrl.activate();

   initSearch(map);

   function selected(feature) {
	   jQuery.fn.updateForm();
   }

   function unselected(feature) {
	   jQuery.fn.updateForm();
   }
   
}


