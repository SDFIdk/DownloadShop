// KMS WMS MAP WIDGET

var conf;
var selectLayer;
var searchLayer;
var bboxLayer = false;
var selectCtrl = false;
var highlightCtrl = false;
var polygonLayer = false;
var map;
var currentType = '';

jQuery(document).ready(function($) {

  conf = Drupal.settings.kms_mapwidget;
  map = initMap();
  initSearch(map);


  $('#rect-button').click(function(e) {
    $('a.toggle').removeClass('active');
    $(this).addClass('active');
    if (selectCtrl) selectCtrl.activate();
    return false;
  });

  $('#select-button').click(function(e) {
    $('a.toggle').removeClass('active');
    $(this).addClass('active');
    if (highlightCtrl) highlightCtrl.activate();
    if (selectCtrl) selectCtrl.activate();
    return false;
  });

  $('#drag-button').click(function(e) {
    $('a.toggle').removeClass('active');
    $(this).addClass('active');
    if (highlightCtrl) highlightCtrl.deactivate();
    if (selectCtrl) selectCtrl.deactivate();
    return false;
  });

  $('#reset-button').click(function(event) {
    
    if (conf.type == 'drawrect') {
      if (selectLayer.features.length > 0) {
        selectLayer.removeFeatures(selectLayer.features[0]);
      }
    } else {
      if (selectCtrl)
        selectCtrl.unselectAll();
    }

    jQuery.fn.updateForm();
    return false;
  });

  $('#OpenLayers_Control_MaximizeDiv').attr('style','position:absolute; width:24px; heigth:24px;');
  $('#OpenLayers_Control_MaximizeDiv_innerImage').attr('style','position:relative; width:24px; heigth:24px;');

  $('#OpenLayers_Control_MinimizeDiv').attr('style','position:absolute; width:24px; heigth:24px; display:none;');
  $('#OpenLayers_Control_MinimizeDiv_innerImage').attr('style','position:relative;width:24px; heigth:24px;');

  $('li.rect').hide();
  $('li.select').hide();
  $('li.reset').hide();

  $.fn.updateForm = function(data) {};

});

(function($) {
  $.fn.initSelection = function(data) {

    if (conf.product_type == 'userdefined') {
	    $("#buffer_description").easyModal({overlayOpacity: 0.5});
	    $("#buffer_button").click(function(e) {
	       $("#buffer_description").trigger("openModal");
	       e.preventDefault();
	    });

	    $("#clipping_description").easyModal({overlayOpacity: 0.5});
	    $("#clipping_button").click(function(e) {
	       $("#clipping_description").trigger("openModal");
	       e.preventDefault();
	    });
    }
    
    $('div.product-body').hide();
    $('div.useful-links').hide();
    $('#selection_message').show();

    if (currentType != conf.type + conf.details ) {

      if (selectCtrl) {
        map.removeControl(selectCtrl);
        selectCtrl = false;
      }

      if (highlightCtrl) {
        map.removeControl(highlightCtrl);
        highlightCtrl = false;
      }
      
      if (selectLayer) {
        map.removeLayer(selectLayer);
        selectLayer = false;
      }

      if (bboxLayer) {
        map.removeLayer(bboxLayer);
        bboxLayer = false;
      }

      switch (conf.type) {
        case '10kmgrid' : 
          addGrid(map,conf);
          break;
        case 'dagi' :
          addDagi(map,conf);
          break;  
        case 'onefile' : 
          addFile(map,conf);
          break;
        case 'drawrect' : 
          addDrawRect(map,conf);
          break;
      }
      currentType=conf.type + conf.details;
    }

    if (selectLayer) {
      selectLayer.setVisibility(true);
    }

    if (selectLayer && conf.details == 'ejerlav.json' && map.getZoom() < 4 ) {
      selectLayer.setVisibility(false);
    }

    if (bboxLayer) 
      bboxLayer.setVisibility(true);

    if ( polygonLayer ) {
      polygonLayer.setVisibility(true);
    }
    
    switch (conf.type) {
        case '10kmgrid' : 
          $('li.select').show();
          $('li.reset').show();
          $('#select-button').click();
          $('.button-submit').attr('disabled', 'disabled');
          $('.button-submit').css('background-color','#EEEEEE');
          break;
        case 'dagi' :
          $('li.select').show();
          $('li.reset').show();
          $('#select-button').click();
          $('.button-submit').attr('disabled', 'disabled');
          $('.button-submit').css('background-color','#EEEEEE');
          break;  
        case 'onefile' :
          break;
        case 'drawrect' : 
          $('li.rect').show();
          $('li.reset').show();
          $('#rect-button').click();
          $('.button-submit').attr('disabled', 'disabled');
          $('.button-submit').css('background-color','#EEEEEE');
          break;
      }

    map.updateSize();

    jQuery.fn.updateForm();

  }
})(jQuery);  

(function($) {
  $.fn.resetSelection = function(data) {

    if (conf.step == 2) {
      $('div.product-body').hide();
      $('div.useful-links').hide();
      jQuery('#selection_message').empty();
      jQuery('#selection_message').append('<p>' + Drupal.t('Selection method') + ' : <span class="value">' + conf.product_type_title + ' - ' + conf.selection_type_title + '</span></p>');
      $('#selection_message').show();
    } else {
      $('div.product-body').show();
      $('div.useful-links').show();
      $('#selection_message').hide();
    }

  $('li.rect').hide();
  $('li.select').hide();
  $('li.reset').hide();
  $('#drag-button').click();

  if ( selectLayer )
    selectLayer.setVisibility(false);

  if ( bboxLayer )
    bboxLayer.setVisibility(false);
  
  }
})(jQuery);  

function initMap() {
  
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
   
	// generic WMTS baselayer used for all maps
	baselayer_generic = new OpenLayers.Layer.WMTS(
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
  
  if (conf.overlay) {
    var layers = conf.service_layer.split(',');
    for (var i = 0; i < layers.length; i++) {
      var layername = jQuery.trim(layers[i]);
      overlay = new OpenLayers.Layer.WMS (
        layername,
        "http://kortforsyningen.kms.dk/" + conf.service_name + '?',
        { layers: layername, 
          format: 'image/png', 
          bgcolor: '0xFFFFFF',
          ticket: kmsticket,
          transparent: true
        },
        { singleTile: false, 
          transitionEffect: 'resize', 
          buffer: 0, 
          isBaseLayer : false,
          visibility: i == 0 ? true : false
        }
      );
      map.addLayer(overlay);
    }

  } else {
    // specific WMS baselayer
    baselayer_specific = new OpenLayers.Layer.WMS (
  		conf.name,
  		"http://kortforsyningen.kms.dk/" + conf.service_name + '?',
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
    map.addLayer(baselayer_specific);
  }

  map.addLayer(baselayer_generic);

  // The buttons and bar in upper left corner:
  map.addControl(new OpenLayers.Control.PanZoomBar());
  //map.addControl(new OpenLayers.Control.PanZoomBar({'div':OpenLayers.Util.getElement('panzoombar')}));

  // All mouse controls (drag, zoom with mouse wheel. etc)
  map.addControl(new OpenLayers.Control.Navigation({zoomWheelEnabled : true}));

  // Layer selector in upper right corner. (Base layers show as choices between
  // radio buttons, other layers as selectable checkboxes):
  map.addControl(new OpenLayers.Control.LayerSwitcher( {title:Drupal.t('Select layer')} ));
	
  // Set center and zoom 
  map.setCenter(new OpenLayers.LonLat(conf.center_longitude, conf.center_latitude),conf.zoom_level);
 
  // Set the layerswitcher baselayer / overlay labels
  layerSwitcher = map.getControlsByClass("OpenLayers.Control.LayerSwitcher")[0];
  layerSwitcher.baseLbl.innerText = "Basiskort";
  layerSwitcher.dataLbl.innerText = "Kortlag";

  return map;

}

function addFile(map,conf) {
    
  (function($) {

    var files = Array();
    $('#selection_message').empty();
    $('#selection_message').append('<p>' + Drupal.t('Selection method') + ' : <span class="value">' + conf.product_type_title + ' - ' + conf.selection_type_title + '</span></p>');
    $('#selection_message').append('<p>' + Drupal.t('Dataformat') + ' :<span class="value"> ' + conf.dataformat_title + '</span></p>');
    $('#selection_message').append('<p>' + Drupal.t('Reference system') + ' : <span class="value">' + conf.koordinatsystem_title + '</span></p>');
    $('#selection_message').append('<h3>' + Drupal.t('Selected items') + '</h3>'); 
    $('#selection_message').append('<ul></ul');
    
    if (conf.product_type == 'predefined') 
      file = conf.details;
    else
      file = Drupal.t('Country-wide file');

    $('#selection_message ul').append('<li>' + file + '</li>');
    $('input[name=selection]').val(JSON.stringify(Array(file)));

  })(jQuery);

  (function($) {
    $.fn.updateForm = function(data) {};
  })(jQuery);

}

function addGrid(map,conf) {

  selectLayer = new OpenLayers.Layer.Vector('Grid', {
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

  map.addLayer(selectLayer);

  selectCtrl = new OpenLayers.Control.SelectFeature(selectLayer,
    { box: true,
      clickout: false,  
      toggle: true,
      multiple: true, 
      onSelect:selected,
      onUnselect:unselected
    }
  );

  highlightCtrl = new OpenLayers.Control.SelectFeature(selectLayer, {
       hover: true,
       highlightOnly: true,
       renderIntent: "temporary"
   });

   // This sould be set to make mouse pan work
   //selectCtrl.handlers.feature.stopDown = false;  
   //highlightCtrl.handlers.feature.stopDown = false;

  map.addControl(highlightCtrl);
  map.addControl(selectCtrl);

  highlightCtrl.activate();   
  selectCtrl.activate();

  jQuery.getJSON(conf.grid_folder + conf.details,
    function(data) {
      var geojson_format = new OpenLayers.Format.GeoJSON();
      var features = geojson_format.read(data);
      selectLayer.addFeatures(features);
    }
  );

  function selected(feature) {
    jQuery.fn.updateForm();
  }

  function unselected(feature) {
    jQuery.fn.updateForm();
  }

(function($) {
  $.fn.updateForm = function(data) {
    var files = Array();
    var features = Array();
    jQuery('#selection_message').empty();
    $('#selection_message').append('<p>' + Drupal.t('Selection method') + ' :<span class="value"> ' + conf.product_type_title + ' - ' + conf.selection_type_title + '</span></p>');
    $('#selection_message').append('<p>' + Drupal.t('Dataformat') + ' :<span class="value"> ' + conf.dataformat_title + '</span></p>');
    $('#selection_message').append('<p>' + Drupal.t('Reference system') + ' :<span class="value"> ' + conf.koordinatsystem_title + '</span></p>');
    $('#selection_message').append('<h3>' + Drupal.t('Selected items') + '</h3>'); 
    jQuery('#selection_message').append('<ul></ul');
    
    for (var i=0; i<selectLayer.selectedFeatures.length; i++) {
      
      var filename;

      if (conf.product_type == 'predefined') 
        filename = selectLayer.selectedFeatures[i].attributes.filename;
      else
        filename = selectLayer.selectedFeatures[i].attributes.fileid;

      files[i] = filename;

      jQuery('#selection_message ul').append('<li>' + filename + '</li>');
    }

    if (selectLayer.selectedFeatures.length > 0) {
      $('.button-submit').removeAttr('disabled');
      $('.button-submit').css('background-color','#97bc00');
    } else {
      $('.button-submit').css('background','#EEEEEE');
      $('.button-submit').attr('disabled', 'disabled');
    }

    jQuery('input[name=selection]').val(JSON.stringify(files));

  };
})(jQuery);

}

function addDagi(map,conf) {

var template = {
  'strokeWidth' : 0.5,
  'strokeColor' : '#000000',
  'fillOpacity' : 0
};

var context = {};

if (conf.details == 'ejerlav.json' ) {
  context = {
    getLabel: function(feature) {
      if(feature.layer.map.getZoom() > 6)
        return feature.attributes.ELAVSNAVN;
      else
        return '';
    }
  };
  template.label = "${getLabel}";
}

if (conf.details == 'sogn.json' ) {
  context = {
    getLabel: function(feature) {
      if(feature.layer.map.getZoom() > 4)
        return feature.attributes.SOGNENAVN;
      else
        return '';
    }
  };
  template.label = "${getLabel}";
}


if (conf.details == 'kommune.json' ) {
  context = {
    getLabel: function(feature) {
      if(feature.layer.map.getZoom() > 2)
        return feature.attributes.KOMNAVN;
      else
        return '';
    }
  };
  template.label = "${getLabel}";
}

 var styleMap = new OpenLayers.StyleMap({
       'default':new OpenLayers.Style(template, { context : context }),
       "select":new OpenLayers.Style({'fillColor' : '#00FF00', 'fillOpacity' : 0.2}),
       "highlight":new OpenLayers.Style({'fillColor' : '#0000FF', 'fillOpacity' : 0.1})
  });
  
  selectLayer = new OpenLayers.Layer.Vector('DAGI', {
    'displayInLayerSwitcher' : false,
    'styleMap' : styleMap
  });

  map.addLayer(selectLayer);

  selectCtrl = new OpenLayers.Control.SelectFeature(selectLayer,
      { box: true,
        clickout: false,  
      toggle: true,
      multiple: true, 
      onSelect:selected,
      onUnselect:unselected
    }
  );

  highlightCtrl = new OpenLayers.Control.SelectFeature(selectLayer, {
       hover: true,
       highlightOnly: true,
       renderIntent: "temporary"
   });

   map.addControl(highlightCtrl);
   map.addControl(selectCtrl);

   highlightCtrl.activate();
   selectCtrl.activate();   

  if (conf.details == 'ejerlav.json' ) {
     map.events.register('zoomend', this, function(event) {
       if (map.getZoom() > 3) 
         selectLayer.setVisibility(true);
       else 
         selectLayer.setVisibility(false);
    });
  }

  if (conf.details == 'sogn.json' ) {
     map.events.register('zoomend', this, function(event) {
       if (map.getZoom() > 2) 
         selectLayer.setVisibility(true);
       else 
         selectLayer.setVisibility(false);
    });
  }

  jQuery.getJSON(conf.grid_folder + conf.details,
    function(data) {
      var geojson_format = new OpenLayers.Format.GeoJSON();
      var features = geojson_format.read(data);
      selectLayer.addFeatures(features);
      if (conf.details == 'ejerlav.json' || conf.details == 'sogn.json' ) {
        selectLayer.setVisibility(false);
      }
    }
  );

  /* Bounding box layer */

  if (conf.product_type == 'userdefined') {
    var bboxStyleMap = new OpenLayers.StyleMap( { 
      'default':new OpenLayers.Style({ 
        'strokeColor' : '#97bc00', 
        'strokeWidth' : 5,
        'fillOpacity' : 0
    })});

    bboxLayer = new OpenLayers.Layer.Vector('BBOX', {
      'displayInLayerSwitcher' : false,
      'styleMap' : bboxStyleMap
    });
    map.addLayer(bboxLayer);
  }

  function selected(feature) {
    jQuery.fn.updateForm();
  }

  function unselected(feature) {
    jQuery.fn.updateForm();
  }

(function($) {
  $.fn.updateForm = function(data) {

    var bounds = new OpenLayers.Bounds();
    bounds.bottom = bounds.left = 999999999999;
    bounds.top = bounds.right = 0;
    var files = Array();
    var features = Array();
    $('#selection_message').empty();
    $('#selection_message').append('<p>' + Drupal.t('Selection method') + ' :<span class="value"> ' + conf.product_type_title + ' - ' + conf.selection_type_title + '</span></p>');
    $('#selection_message').append('<p>' + Drupal.t('Dataformat') + ' :<span class="value"> ' + conf.dataformat_title + '</span></p>');
    $('#selection_message').append('<p>' + Drupal.t('Reference system') + ' : <span class="value">' + conf.koordinatsystem_title + '</span></p>');
    if ( conf.product_type == 'userdefined' ) {
      $('#selection_message').append('<p>' + Drupal.t('Maximum allowed area') + ' :<span class="value">' + conf.max_area + ' km&sup2;</span></p>');
    }
    $('#selection_message').append('<h3>' + Drupal.t('Selected items') + '</h3>'); 
    $('#selection_message').append('<ul></ul');

    for (var i=0; i<selectLayer.selectedFeatures.length; i++) {
        
        var feature = selectLayer.selectedFeatures[i];
        
        if (feature.geometry.bounds.bottom < bounds.bottom)
          bounds.bottom = feature.geometry.bounds.bottom;

        if (feature.geometry.bounds.left < bounds.left)
          bounds.left = feature.geometry.bounds.left;

        if (feature.geometry.bounds.top >bounds.top)
          bounds.top = feature.geometry.bounds.top;

        if (feature.geometry.bounds.right > bounds.right)
          bounds.right = feature.geometry.bounds.right;

        if (conf.details == 'region.json' ) {
          code = selectLayer.selectedFeatures[i].attributes.REGIONKODE;
          name = selectLayer.selectedFeatures[i].attributes.REGIONNAVN;
        }

        if (conf.details == 'kommune.json' ) {
          code = selectLayer.selectedFeatures[i].attributes.KOMKODE;
          name = selectLayer.selectedFeatures[i].attributes.KOMNAVN;
        }

        if (conf.details == 'ejerlav.json' ) {
          code = selectLayer.selectedFeatures[i].attributes.ELAVSKODE;
          name = selectLayer.selectedFeatures[i].attributes.ELAVSNAVN;
        }

        if (conf.details == 'sogn.json' ) {
          code = selectLayer.selectedFeatures[i].attributes.SOGNEKODE;
          name = selectLayer.selectedFeatures[i].attributes.SOGNENAVN;
        }

      if ( conf.product_type == 'predefined') {
        files[i] = code + '_' + conf.dataformat + '_' + conf.koordinatsystem + '.zip';
      } else {
        files[i] = code;
      }

      $('#selection_message ul').append('<li>' + name + ' (' + files[i] + ')</li>');
    }

    /* Remove existing bounding box rectangle */
    if(conf.product_type == 'userdefined' && bboxLayer.features.length > 0){
      bboxLayer.removeFeatures(bboxLayer.features[0]);
    }

    if (selectLayer.selectedFeatures.length > 0) {

      if ( conf.product_type == 'userdefined' ) {
        var geometry = bounds.toGeometry();
        var area = geometry.getArea() / 1000000;
        $('#selection_message ul').prepend('<p>' + Drupal.t('Area') + ' : <span class="value">' + area.toFixed(2).replace('.',',') + ' km&sup2;</span></p');
        
        /* Draw bounding box rectangle */
        var rectangle = new OpenLayers.Feature.Vector(geometry);
        bboxLayer.addFeatures(rectangle);

        if (area > conf.max_area) {
          $('.button-submit').attr('disabled', 'disabled');
          $('.button-submit').css('background','#EEEEEE');
          $('#selection_message').append('<p style="color:red">' + Drupal.t('Selected area larger than maximum allowed.') + '</p>');
          $('#selection_message').append('<p>' + Drupal.t('Please select a smaller area.') + '</p>');
        } else {
          $('.button-submit').removeAttr('disabled');
          $('.button-submit').css('background-color','#97bc00');
        }
      } else {
        $('.button-submit').removeAttr('disabled');
        $('.button-submit').css('background-color','#97bc00');
      }  
    } else {
      $('.button-submit').css('background','#EEEEEE');
      $('.button-submit').attr('disabled', 'disabled');
    }
    
    $('input[name=selection]').val(JSON.stringify(files));

  };
})(jQuery);

}

function addDrawRect(map,conf) {

  selectLayer = new OpenLayers.Layer.Vector('drawRect',{
    displayInLayerSwitcher:false,
      styleMap: new OpenLayers.StyleMap({
        "default": {
          fillOpacity: 0,
          strokeColor: '#97bc00',
          strokeWidth: 1
        }
    })
  });

  map.addLayer(selectLayer);

  selectCtrl = new OpenLayers.Control.DrawFeature(selectLayer,
    OpenLayers.Handler.RegularPolygon, {
      handlerOptions: {
          sides: 4,
          irregular: true
      },
      displayClass: 'drawRectangle' 
    }
  );

  selectCtrl.events.register("featureadded", this, function (e) { 
    if(selectLayer.features.length > 1){
      selectLayer.removeFeatures(selectLayer.features[0]);
    }
    jQuery.fn.updateForm();
  });

  map.addControl(selectCtrl);
  selectCtrl.activate();

  var polygonlayers = map.getLayersByName('OpenLayers.Handler.RegularPolygon');
  polygonLayer = polygonlayers[0];

(function($) {
  $.fn.updateForm = function(data) {
    $('#selection_message').empty();
    $('#selection_message').append('<p>' + Drupal.t('Selection method') + ' :<span class="value">' + conf.product_type_title + ' - ' + conf.selection_type_title + '</span></p>');
    $('#selection_message').append('<p>' + Drupal.t('Dataformat') + ' :<span class="value">' + conf.dataformat_title + '</span></p>');
    $('#selection_message').append('<p>' + Drupal.t('Reference system') + ' :<span class="value">' + conf.koordinatsystem_title + '</span></p>');
    if ( conf.product_type == 'userdefined' ) {
      $('#selection_message').append('<p>' + Drupal.t('Maximum allowed area') + ' :<span class="value">' + conf.max_area + ' km&sup2;</span></p>');
    }
    $('#selection_message').append('<h3>' + Drupal.t('Selected items') + '</h3>');
    
    if (selectLayer.features[0]) {
      selectLayer.features[0].geometry.bounds.left = Math.round(selectLayer.features[0].geometry.bounds.left);
      selectLayer.features[0].geometry.bounds.right = Math.round(selectLayer.features[0].geometry.bounds.right);
      selectLayer.features[0].geometry.bounds.top = Math.round(selectLayer.features[0].geometry.bounds.top);
      selectLayer.features[0].geometry.bounds.bottom = Math.round(selectLayer.features[0].geometry.bounds.bottom);
      var bounds = selectLayer.features[0].geometry.bounds;
      var area = selectLayer.features[0].geometry.getArea() / 1000000;
      $('#selection_message').append('<p>' + Drupal.t('Area') + ': <span class="value">' + area.toFixed(2).replace('.',',') + ' km&sup2;</span></p>'); 
      $('input[name=selection]').val(JSON.stringify(bounds));
      
      if ( area > conf.max_area) {
        $('.button-submit').attr('disabled', 'disabled');
        $('.button-submit').css('background','#EEEEEE');
        $('#selection_message').append('<p style="color:red">' + Drupal.t('Selected area larger than maximum allowed.') + '</p>');
        $('#selection_message').append('<p>' + Drupal.t('Please select a smaller area.') + '</p>');
      } else {
        $('.button-submit').removeAttr('disabled');
        $('.button-submit').css('background-color','#97bc00');
      }

    }
  };

})(jQuery);

}
