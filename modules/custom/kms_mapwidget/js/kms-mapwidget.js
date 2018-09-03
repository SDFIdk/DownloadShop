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
var denmark = true;

jQuery(document).ready(function($) {

  conf = Drupal.settings.kms_mapwidget;
  map = initMap(conf);
  if (denmark) {
    initSearch(map);
  } else {
    $('div.ui-widget').hide();
  }

  $('#rect-button').click(function(e) {
    $('.toggle').removeClass('active');
    $(this).addClass('active');
    if (selectCtrl) selectCtrl.activate();
    return false;
  });

  $('#select-button').click(function(e) {
    $('.toggle').removeClass('active');
    $(this).addClass('active');
    if (highlightCtrl) highlightCtrl.activate();
    if (selectCtrl) selectCtrl.activate();
    return false;
  });

  $('#csv-button').click(function(e) {
    $('.toggle').removeClass('active');
    $(this).parent().addClass('active');
    return false;
  });

  $('#drag-button').click(function(e) {
    $('.toggle').removeClass('active');
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

    $('#selection_errors').empty();
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
  $('li.csv').hide();

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
    $('#selection_errors').empty();

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
          $('li.csv').show();
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

      //insert atom feeds
      jQuery('#selection_message').append('<p>' + conf.selection_atom_feed +' </p>');

      $('#selection_message').show();
    } else {
      $('div.product-body').show();
      $('div.useful-links').show();
      $('#selection_message').hide();
    }

  $('#selection_errors').empty();
  $('li.rect').hide();
  $('li.select').hide();
  $('li.reset').hide();
  $('li.csv').hide();
  $('#drag-button').click();

  if ( selectLayer )
    selectLayer.setVisibility(false);

  if ( bboxLayer )
    bboxLayer.setVisibility(false);
  }
})(jQuery);

function initMap(conf) {

  OpenLayers.ImgPath = conf.imgPath;

  kmsticket = new VisStedet.Ticket();

  if (!kmsticket.ticket) {
    jQuery.ajax({
      url : "/downloadticket",
      type: "POST",
      async : false,
      success : function( data ) {
        jQuery.cookie('downloadticket', data, { expires: 1, path: '/' });
        kmsticket.ticket = data;
      }
    });
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

  var numZoomLevels = 12;
  var maxResolution = 1638.4;

  // The resolutions - changes should only be done according to the tiling schemas
  var olResolutions = new Array(0.8,1.6,3.2,6.4,12.8,25.6,51.2,102.4,204.8,409.6,819.2,1638.4);

  var baselayer_name = 'Danmarkskort 2012';
  var baselayer_service_name = '';
  var baselayer_service_layer = '';

  // Greenland
  if (conf.projection == 'EPSG:32624') {
    // <BoundingBox miny="6400000" minx="-400000" maxy="9400000" maxx="1320000" SRS="EPSG:32624"/>
    olMaxExtent = new OpenLayers.Bounds(-400000,6400000,1320000,9400000);
    olResolutions = new Array(50,100,200,400,800,1600,2000,3000,4000,5000);
    numZoomLevels = 10;
    maxResolution = 5000;
    denmark = false;
    baselayer_name = 'Basiskort grønland';
    baselayer_service_name = 'gtopo';
    baselayer_service_layer = 'Gtk_g2500';
  }

  // The Faroe Islands
  if (conf.projection == 'EPSG:32629') {
    // <BoundingBox miny="6791524.000000" minx="557587.000000" maxy="6934414.000000" maxx="654409.000000" SRS="EPSG:32629"/>
    olMaxExtent = new OpenLayers.Bounds(557587,6791524,654409,6934414);
    olResolutions = new Array(10,25,50,100,160,200);
    numZoomLevels = 6;
    maxResolution = 200;
    denmark = false;
    baselayer_name = 'Basiskort færøerne';
    baselayer_service_name = 'ftopo';
    baselayer_service_layer = 'Ftk_f200';
  }

  var skaermkort_url = ["//a.services.kortforsyningen.dk/topo_skaermkort",
                        "//b.services.kortforsyningen.dk/topo_skaermkort",
                        "//c.services.kortforsyningen.dk/topo_skaermkort",
                        "//d.services.kortforsyningen.dk/topo_skaermkort"];

    var map = new OpenLayers.Map(
        'mapTag',
        {
          projection: conf.projection,
          units: 'm',
          theme : null,
          maxExtent: olMaxExtent,
          maxResolution: maxResolution,
		      numZoomLevels: numZoomLevels,
		      resolutions: olResolutions,
		      controls : []
        }
    );

  var baselayer_generic;

  if (denmark) {
  	// generic WMTS baselayer used for all maps
  	baselayer_generic = new OpenLayers.Layer.WMTS(
  		{
  			name: baselayer_name,
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
  } else {
    baselayer_generic = new OpenLayers.Layer.WMS (
      baselayer_name,
      "//services.kortforsyningen.dk/" + baselayer_service_name + '?',
      { layers: baselayer_service_layer,
        format: 'image/png',
        bgcolor: '0xFFFFFF',
        ticket: kmsticket,
        projection: conf.projection,
        transparent: true
      },
      { singleTile: false,
        transitionEffect: 'resize',
        buffer: 0,
        isBaseLayer : true
      }
    );
  }

  if (conf.overlay) {
    var layers = conf.service_layer.split(',');
    for (var i = 0; i < layers.length; i++) {
      var layername = jQuery.trim(layers[i]);
      overlay = new OpenLayers.Layer.WMS (
        layername,
        "//services.kortforsyningen.dk/" + conf.service_name + '?',
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
    if (conf.service_name != false) {
      // specific WMS baselayer
      baselayer_specific = new OpenLayers.Layer.WMS (
    		conf.name,
    		"//services.kortforsyningen.dk/" + conf.service_name + '?',
    		{ layers: conf.service_layer,
    		  format: 'image/png',
    		  bgcolor: '0xFFFFFF',
    		  ticket: kmsticket,
          projection: conf.projection,
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
    $('#selection_message').append('<h3>' + Drupal.t('Selected items') + '<p>' + selectLayer.selectedFeatures.length + Drupal.t(' of 100 allowed items') +'</p></h3>');
    if (selectLayer.selectedFeatures.length > 100) {
      $('#selection_message').append('<div class="messages error"><p>' + Drupal.t('Whoops you have selected too many items') + '</p></div>');
    }
    jQuery('#selection_message').append('<ul></ul>');

    for (var i=0; i<selectLayer.selectedFeatures.length; i++) {

      var filename;

      if (conf.product_type == 'predefined')
        filename = selectLayer.selectedFeatures[i].attributes.filename;
      else
        filename = selectLayer.selectedFeatures[i].attributes.fileid;

      files[i] = filename;

      jQuery('#selection_message ul').append('<li>' + filename + '</li>');
    }

    if (selectLayer.selectedFeatures.length > 0 && selectLayer.selectedFeatures.length <= 100) {
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
        return feature.attributes.name;
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
        return feature.attributes.name;
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
        return feature.attributes.name;
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
      codeVarName = getCodeVarName(conf);
      nameVarName = getNameVarName(conf);
      for(var f=0; f<data.features.length; f++) {
        data.features[f].properties.code = parseInt(data.features[f].properties[codeVarName]);
        data.features[f].properties.name = data.features[f].properties[nameVarName];
        delete data.features[f].properties[nameVarName];
        delete data.features[f].properties[codeVarName];
      }
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

  /* CSV selection handler */
  (function($) {
    $("#update-from-csv").click(function(e) {
      $('#selection_errors').empty();
      selectCtrl.unselectAll();
      var codes = $('textarea#csv-data').val().split(',');
      for(var f=0; f<codes.length; f++) { codes[f] = codes[f].trim(); }
      codes = sort_unique(codes);
      for(var f=0; f<codes.length; f++) {
        code = parseInt(codes[f]);
        if (code) {
          feature = selectLayer.getFeaturesByAttribute('code', code);
          if (feature.length == 1) {
            selectCtrl.select(feature[0]);
          } else {
            $('#selection_errors').append('<p style="color:red">"' + code + '" ' + Drupal.t('is not a valid code') + '</p>');
          }
        }
      }
      e.preventDefault();

      // Zoom to selected features
      var fts = selectLayer.selectedFeatures;
      if (fts.length > 0) {
        var bounds = fts[0].geometry.getBounds().clone();
        for(var i=1;i<fts.length;i++)
          bounds.extend(fts[i].geometry.getBounds());
        map.zoomToExtent(bounds,false);
      }
      
      // Click the select tool, so CSV dialog is hidden.
      $('#select-button').click();
    });

    $("#csv-description").easyModal({overlayOpacity: 0.5});
    $("#csv-desc-button").click(function(e) {
       $("#csv-description").trigger("openModal");
      e.preventDefault();
    });

  })(jQuery);

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

      if ( conf.product_type == 'predefined') {
        files[i] = feature.attributes.code + '_' + conf.dataformat + '_' + conf.koordinatsystem + '.zip';
      } else {
        files[i] = feature.attributes.code;
      }

      $('#selection_message ul').append('<li>' + feature.attributes.name + ' (' + files[i] + ')</li>');
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

function sort_unique(arr) {
    arr = arr.sort(function (a, b) { return a*1 - b*1; });
    var ret = [arr[0]];
    for (var i = 1; i < arr.length; i++) { // start loop at 1 as element 0 can never be a duplicate
        if (arr[i-1] !== arr[i]) {
            ret.push(arr[i]);
        }
    }
    return ret;
}

function getCodeVarName(conf) {
  codenames= {
    'region.json': 'REGIONKODE',
    'kommune.json': 'KOMKODE',
    'ejerlav.json': 'ELAVSKODE',
    'sogn.json': 'SOGNEKODE',
    'ejerlav_1081.json' : 'ELAVSKODE',
    'ejerlav_1082.json' : 'ELAVSKODE',
    'ejerlav_1083.json' : 'ELAVSKODE',
    'ejerlav_1084.json' : 'ELAVSKODE',
    'ejerlav_1085.json' : 'ELAVSKODE'

  };
  return codenames[conf.details];
}

function getNameVarName(conf) {
  codenames= {
    'region.json': 'REGIONNAVN',
    'kommune.json': 'KOMNAVN',
    'ejerlav.json': 'ELAVSNAVN',
    'sogn.json': 'SOGNENAVN',
    'ejerlav_1081.json' : 'ELAVSNAVN',
    'ejerlav_1082.json' : 'ELAVSNAVN',
    'ejerlav_1083.json' : 'ELAVSNAVN',
    'ejerlav_1084.json' : 'ELAVSNAVN',
    'ejerlav_1085.json' : 'ELAVSNAVN'

  };
  return codenames[conf.details];
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
