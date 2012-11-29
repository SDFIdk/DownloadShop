// KMS WMS Widget JS

jQuery(function() { 
  var conf = Drupal.settings.kms_widget;
  conf.center_longitude = parseInt(conf.center_longitude);
  conf.center_latitude = parseInt(conf.center_latitude);
  conf.zoom_level = parseInt(conf.zoom_level);
  conf.selection_type = parseInt(conf.selection_type);
  initService(conf);   
});

function initService(conf) {

  kmsticket: '',  
  kmsticket = new VisStedet.Ticket();

  var overlay = false;
  var feature = '';
  var eventListeners = {};
  var selectedFeatures = {};

  switch (conf.selection_type) {
    case 3524 : // En samlet fil
      break;  
    case 3525 : // Regioner
      overlay = true;
      feature = 'REGION2000';
      break; 
    case 3526 : // Tiles 10km
      break; 
    case 3527 : // Kommuner
      overlay = true;
      feature = 'KOMMUNE500';
      eventListeners = { "zoomend" : zoomHandler } ;
  }

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
	
    var map = new OpenLayers.Map(
        'mapTag',
        {
            projection: 'EPSG:25832',
            units: 'm',
            maxExtent: olMaxExtent,
            maxResolution: 1638.4,
		    numZoomLevels: 12,
		    resolutions: olResolutions,
		    controls : [],
		    eventListeners : eventListeners
        }
    );

	var base_layer;
	var overlay_layer;
    
    base_layer = new OpenLayers.Layer.WMS (
		"BASE",
		"http://kortforsyningen.kms.dk/" + conf.service_name + '?',
		{ layers: conf.service_layer, 
		  format: 'image/jpeg', 
		  bgcolor: '0xFFFFFF',
		  ticket: kmsticket,  
		},
		{ singleTile: true, 
		  resolutions : new Array(0.8,1.6,3.2),
		  transitionEffect: 'resize', 
		  buffer: 0, 
		  isBaseLayer : true,
		}
	);

   map.addLayer(base_layer);

   if (overlay) {	
	 overlay_layer = new OpenLayers.Layer.Vector(
		"OVERLAY", {
		strategies : [new OpenLayers.Strategy.BBOX()],
		displayInLayerSwitcher:false,
		styleMap:new OpenLayers.StyleMap({
		   "default":new OpenLayers.Style(OpenLayers.Util.applyDefaults({
			'strokeWidth' : 0,
			'fillOpacity' : 0
		   }, OpenLayers.Feature.Vector.style["default"])),
		   "select":new OpenLayers.Style({'fillColor' : '#00FF00', 'fillOpacity' : 0.2}),
		   "highlight":new OpenLayers.Style({'fillColor' : '#0000FF', 'fillOpacity' : 0.2})
		}),
    		protocol : new OpenLayers.Protocol.WFS({
			url : "/dagi_gml2?" , // + overlay_name,
			version : "1.0.0",
			featurePrefix : "kms",
		    featureType : feature,
	   	    geometryName : "geometri",
			params : { ticket: kmsticket },
		}),
	  });
	  
	  map.addLayer(overlay_layer);
	
    }
	
    var kommune_layer = new OpenLayers.Layer.WMS (
		"KOMMUNE",
		"http://kortforsyningen.kms.dk/dagi?",
		{ layers: "kommune", 
		  format: 'image/jpeg', 
		  bgcolor: '0xFFFFFF',
		  ticket: kmsticket,
		},
		{singleTile: true, 
		  transitionEffect: 'resize', 
		  buffer: 0, 
		  isBaseLayer : true,
		  resolutions : new Array(51.2,102.4,204.8,409.6),
		}
	);

   map.addLayer(kommune_layer);    
		
	// The buttons and bar in upper left corner:
	map.addControl(new OpenLayers.Control.PanZoomBar());

	// All mouse controls (drag, zoom with mouse wheel. etc)
	map.addControl(new OpenLayers.Control.Navigation());

	// Layer selector in upper right corner. (Base layers show as choices between
	// radio buttons, other layers as selectable checkboxes):
	map.addControl(new OpenLayers.Control.LayerSwitcher({'div':OpenLayers.Util.getElement('layerswitcher')}));
	
	// Set center and zoom 
	map.setCenter(new OpenLayers.LonLat(conf.center_longitude, conf.center_latitude),conf.zoom_level);

    var selectCtrl = new OpenLayers.Control.SelectFeature(overlay_layer,
      { clickout: true,  
	    toggle: true,
	    multiple: true, 
	  	onSelect:selected,
		onUnselect:unselected
	  }
	);
    map.addControl(selectCtrl);
   
    var highlightCtrl = new OpenLayers.Control.SelectFeature(overlay_layer, {
       hover: true,
       highlightOnly: true,
       renderIntent: "temporary",
       /*eventListeners: {
          featurehighlighted: highlighted,
          featureunhighlighted: unhighlighted
       }*/
   });
   map.addControl(highlightCtrl);
   
   highlightCtrl.activate();
   selectCtrl.activate();

    /*
	function highlighted(e) {
	  console.log("highlighted:" + e.type +":"+ e.feature.id);	
	}

	function unhighlighted(e) {
	  console.log("unhighlighted:"+ + e.type +":"+ e.feature.id);	
	}
    */

	function selected(feature) {
	  console.log(overlay_layer);
	  var data = { 'id' : feature.data.CPR_noegle ,
	               'navn' :  feature.data.Navn
	             };
	  selectedFeatures[feature.fid] = data ;	
	  showStatus();
	}

	function unselected(feature) {
	  delete selectedFeatures[feature.fid];	
	  showStatus();
    }
    
    function showStatus() {
	  var selectedValues = [];
	  for (var i in selectedFeatures) {
	    selectedValues.push(selectedFeatures[i]['navn']);
	  }
	  jQuery('#edit-line-item-fields-field-selection-und-0-value').val(JSON.stringify(selectedFeatures));
	  jQuery('#edit-line-item-fields-field-selection-text-und-0-value').val(selectedValues.join(', '));
    }

    function zoomHandler(event) {
    selectCtrl.select(overlay_layer.getFeatureByFid('KOMMUNE500.3732')); 
      for (var i in selectedFeatures) {
        console.log('select : ' + i);
	    selectCtrl.select(overlay_layer.getFeatureByFid(i));
	  }
    }


}


