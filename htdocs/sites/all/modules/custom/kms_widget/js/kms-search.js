function initSearch(map) {
    searchLayer = new OpenLayers.Layer.Vector('searchlayer',{
        displayInLayerSwitcher:false,
        styleMap: new OpenLayers.StyleMap({
            "default": {
                fillOpacity: 0,
                strokeColor: '#f00',
                strokeWidth: 0,
                pointRadius: 4,
                graphicName: 'circle'
            }
        })
    });
   
    map.addLayer(searchLayer);

   geosearch = new VisStedet.Search.GeoSearch ({
    ticket: kmsticket,
      resources: ['Stednavne','Kommuner','Regioner','Adresser','Matrikelnumre'],
    });
 
  jQuery('#geosearch').autocomplete({
        autoFocus: true,
        source: function(request, response) {
        	geosearch.search(request.term, function(result) {
                if (result.data) {
                    response(jQuery.map(result.data, function(item) {
                        displayLabel = item.presentationString;
                        displayValue = item.presentationString;
                        return {
                            label: displayLabel,
                            value: displayValue,
                            data: item
                        };
                    }));
                }
            });
        },
        delay: 200,
        minLength: 2,
        select: function (event, ui) {
          
          var wkt = ui.item.data.geometryWkt;
          searchLayer.removeAllFeatures ();
          if (wkt) {
                var in_options = {
                    'internalProjection': new OpenLayers.Projection('EPSG:25832'),
                    'externalProjection': new OpenLayers.Projection('EPSG:25832')
                };
                if (wkt.match(/BOX/i)) {
                    wkt = wkt.split(',')[0].replace (/BOX/,'POINT')+')';
                }
                var format = new OpenLayers.Format.WKT(in_options);
                var feature = format.read(wkt);
                if(feature) {
                    if(feature.constructor != Array) {
                        feature = [feature];
                    }
                    searchLayer.addFeatures (feature);
                    map.zoomToExtent(searchLayer.getDataExtent()); 
      }
    }
  }
}).val('');
}