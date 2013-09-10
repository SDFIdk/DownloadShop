/* Copyright (c) */

/**
 * @requires VisStedet/Utils.js
 * @requires VisStedet/Search.js
 */

/**
 * Class: VisStedet.Search.SpatialAddress
 */
VisStedet.Search.SpatialAddress = VisStedet.Utils.Class (VisStedet.Search,{
    
    /**
     * APIProperty: apikey
     * {String} REQUIRED Please see http://demo-find.spatialsuite.com for information on how to get an APIKEY.
     */
    apikey: null,
    
    /**
     * APIProperty: crs
     * {String} 
     */
    crs: 'EPSG:25832',

    /**
     * Constructor: VisStedet.Search.SpatialAddress
     * Instances of VisStedet.Search.SpatialAddress gives access to seach in SpatialAddress (read more on http://demo-find.spatialsuite.com)
     *     To use SpaitalAddress you need an APIKEY.
     *
     * Parameters:
     * options - {Object} Optional object with properties to add to the VisStedet.Search instance.
     *
     * Returns:
     * An instance of VisStedet.Search.SpatialAddress
     * 
     * Examples:
     * (code)
     * var spatialAddress = new VisStedet.Search.SpatialAddress ({
     *     apikey: 'INSERT APIKEY HERE!'
     * });
     * spatialAddress.search('TEXT TO SEARCH WITH',function (response) {
     *     var html = '';
     *     for (var i=0;i<object.data.length;i++) {
     *         html += object.data[i].presentationString+'<br/>';
     *     }
     *     document.getElementById('list').innerHTML = html;
     * });
     * (end)
     */    
    initialize: function (options) {
        this.url = 'http://find.spatialsuite.com/service/locations/2/detect/json/';
        VisStedet.Search.prototype.initialize.apply(this, arguments);
    },
    
    /**
     * APIMethod: search
     * Do a search on SpatialAddress
     *
     * Parameters:
     * searchstring - {String} The string to search with
     * callback - {Function} The function to call back with the result {<VisStedet.Search.response>}. 
     * params - {Object} OPTIONAL parameter list of parameters to send to the service
     */
    search: function (searchstring, callback, params) {
        if (this.apikey !== null) {
            if (this.currentRequest !== null) {
                this.destroyRequest (this.currentRequest);
                this.currentRequest = null;
            }
            var url = this.url+searchstring+'?apikey='+this.apikey+'&limit='+this.limit+'&crs='+this.crs+'&'+this.callbackKey+'=';
            this.currentRequest = this.createRequest (url, VisStedet.Utils.bind (function (callback,response) {
                this.destroyRequest (this.currentRequest);
                this.currentRequest = null;
                callback(response);
            },this,callback));
        } else {
            callback ({status: 'ERROR - Apikey missing'});
        }
    },

    CLASS_NAME: 'VisStedet.Search.SpatialAddress'
});