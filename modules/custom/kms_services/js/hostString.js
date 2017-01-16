/**
 * @file
 */
function setCookies(name, type){
  // alert(name + "  " + type);
  document.cookie = 'kms_hoststring_name=' + name + ';expires="";path=/';
  document.cookie = 'kms_hoststring_type=' + type + ';expires="";path=/';
}

function addString() {
  // Get variables from form.
  var type = document.getElementById('edit-servicetype').value.toUpperCase();
  var name = document.getElementById('edit-servicename').value;
  // Generate hoststring from busines logic.
  var status;
  var url = "";
  switch (type) {
    case 'WMS': url = "http://kortforsyningen.kms.dk/?"; break;

    case 'WFS': url = "http://kortforsyningen.kms.dk/service?"; break;

    case 'WMTS': url = "http://kortforsyningen.kms.dk/?"; break;

    default: status = false;
  }
  // Add GIS service.
  var gis;
  for (i = 0; i < document.getElementsByName('GIS').length; i++) {
    if (document.getElementsByName('GIS')[i].checked) {
      gis = document.getElementsByName('GIS')[i].value;
    }
  }
  url = url + "servicename=" + name;
  switch (gis) {
    case '0': url = url + "&client=arcGIS"; break;

    case '1': url = url + "&client=AutoCad"; break;

    case '2': url = url + "&client=Gaia"; break;

    case '3': url = url + "&client=Geomedia"; break;

    case '4': url = url + "&client=MapInfo"; break;

    case '5': url = url + "&client=QGIS"; break;

    case '6': url = url + "&client=Udig"; break;
  }
  // Add servicetype.
  var arcgis;

  /*if(gis=='0'){
		var dd = document.getElementById("edit-arcgis");
		arcgis = dd.options[dd.selectedIndex].value;
		url = url + "&request=GetCapabilities&bbox="+ city_list[arcgis][0] + ","+ city_list[arcgis][1] + ","+ city_list[arcgis][2] + ","+ city_list[arcgis][3] + "&";
  }else{*/
  switch (type) {
    case "WMS": url = url + "&request=GetCapabilities&service=WMS&"; break;

    case "WFS": url = url + "&request=GetCapabilities&service=WFS&"; break;

    case "WMTS": url = url + "&request=GetCapabilities&service=WMTS&"; break;

    case "WCS": url = url + "&request=GetCapabilities&service=WCS&"; break;

    default: status = false;
      /*}*/
  }
  // Add version number
  // if(gis!=0){
  if (type == "WMS") {
    url = url + "version=1.1.1&";
  }
  else {
    if (type == "WMTS") {
      url = url + "acceptversions=1.0.0&";
    }
    else {
      // WFS.
      if (type == "WCS") {
        url = url + "version=1.1.1&";
      }
      else {
        var nameUpperCase = name.toUpperCase();
        var ma = nameUpperCase.match("GMLSFP");
        if (ma != null) {
          url = url + "version=1.1.0&";
        }
        else {
          url = url + "version=1.0.0&";
        }
      }
    }
  }
  /*}*/
  // If username and password is selected:
  var identity;
  for (i = 0; i < document.getElementsByName('identity').length; i++) {
    if (document.getElementsByName('identity')[i].checked) {
      identity = document.getElementsByName('identity')[i].value;
    }
  }
  if (identity == 1) {
    var username = document.getElementById('edit-servicesusername').value;
    var password = document.getElementById('edit-servicespassword').value;;
    url = url + "login=" + username + "&password=" + password;
  }
  // If an error occured:
  if (status == false) {
    document.getElementById('edit-servicesoutput').value = "Input Error.";
  }
  else {
    document.getElementById('edit-servicesoutput').value = url;
  }
}
