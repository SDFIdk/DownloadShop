<?php
/**
 * Legacy service retrieve logic, ungly hacks and almost no drupal found
 */

function kms_services_process_form_radios($element, &$form_state)  {
  // Each renderable radio element.
  foreach (element_children($element) as $nid) {
    // View the package using our custom view mode.
    if($nid=='Gaia') {
      $element[$nid]['#prefix'] = '<div class="open-souce-separator">Open Source GIS programmer<div>';
    }
  }

  // Always return the element to render in after_build callbacks.
  return $element;
}


function kms_services_url_wrapper($service_type, $service_name) {
  $return = drupal_get_form('kms_services_url_form', $service_type, $service_name);
  //return just html of the form
  print render($return);
  exit();
}


function kms_service_option_callback(){
  $lontitude_array;
  $i = 0;
  $file_path = drupal_get_path('module', 'kms_services') . '/data/longtitude.txt';

  $handle = fopen($file_path, "r");
  if ($handle) {
    while (($line = fgets($handle)) !== false) {
      $line_val = explode(';', $line);
      $lontitude_array[$line_val[0]] = $line_val[1];
    }
    fclose($handle);
  } else {
    drupal_set_message(t('KMS services, error reading longtitute file'), 'error');
  }

  return  $lontitude_array;
}

function kms_services_output($service_name, $service_type) {

  // Get Capability.
  $service = getCapability($service_name, $service_type);

  // Error message for each title.
  $errorMessage = "No data available.";

  $restGeoKeys = variable_get('kms_services_restgeokeys_text', '');
  $geoSearch = variable_get('kms_services_geosearch_text', '');

  // Adding services that do not have a capabilities file.
  if ($service_name == "RestGeokeys_v2") {
    if (is_array($restGeoKeys) && isset($restGeoKeys['value'])) {
      print $restGeoKeys['value'];
    }
    else {
      print $restGeoKeys;
    }
    exit();
  }
  if ($service_name == "Geosearch") {
    if (is_array($geoSearch) && isset($geoSearch['value'])) {
      print $geoSearch['value'];
    }
    else {
      print $geoSearch;
    }
    exit();
  }
  if ($service == NULL) {
    print $errorMessage;
    exit();
  }
  if ($service == FALSE) {
    $description = $errorMessage;
    $onlineResource = $errorMessage;
  }
  else {
    if ($service["description"] == NULL || $service["description"] == "") {
      $description = $errorMessage;
    }
    else {
      $description = $service["description"];
    }
    if ($service["onlineResource"] == NULL || $service["onlineResource"] == "") {
      $onlineResource = $errorMessage;
    }
    else {
      $onlineResource = $service["onlineResource"];
    }
  }
  $layer = $service["layer"];
  $spatialReference = $service["spatialReference"];
  $spatialReference = epsg2Description($spatialReference);
  // Aggregated error message.
  if ($description == $errorMessage && $onlineResource == $errorMessage && count($layer) == 0 && count($spatialReference) == 0) {
    print $errorMessage;
    exit();
  }
  // Sets temp cookies when go to hoststring node.
  global $base_url;
  $link = $base_url . "/urltilgis?type=" . $service_type . "&name=" . $service_name;
  // $hostString = '<a onclick="setCookies(\''.$service_name.'\', \''.$service_type.'\');" href="'.$link.'" target="_blank">Klik her</a>';
  $hostString = '<a href="' . $link . '" target="_blank">Klik her</a>';
  // Service Name.
  $markup = "<b>Service Navn</b><p>" . $service_name . "</p>";
  // Build markup.
  $markup = $markup . "<b>Beskrivelse</b><p>" . $description . "</p>";
  // $layer.
  if (count($layer) == 0) {
    $markup = $markup . "<b>Lag</b><p>" . $errorMessage . "</p>";
  }
  else {
    $markup = $markup . "<b>Lag</b><p>";
    foreach ($layer as $l) {
      $markup = $markup . $l . "<br>";
    }
    $markup = $markup . "</p>";
  }
  // $spatialReference.
  if (count($spatialReference) == 0) {
    $markup = $markup . "<b>Spatial Reference</b><p>" . $errorMessage . "</p>";
  }
  else {
    $markup = $markup . "<b>Spatial Reference</b><p>";
    foreach ($spatialReference as $srs) {
      $markup = $markup . $srs . "<br>";
    }
    $markup = $markup . "</p>";
  }
  // $format.
  if ($service["type"] == "WCS") {
    if (count($service["format"]) == 0) {
      $markup = $markup . "<b>Format</b><p>" . $errorMessage . "</p>";
    }
    else {
      $markup = $markup . "<b>Format</b><p>";
      foreach ($service["format"] as $format) {
        $markup = $markup . $format . "<br>";
      }
      $markup = $markup . "</p>";
    }
  }
  // $onlineResource.
  $markup = $markup . '<b>Online Resource</b><p>' . $onlineResource . '</p>';
  // URL for xml file.
  $markup = $markup . '<b>Service-metadata som XML</b><p><a href="' . $service['url'] . '" target="_blank">Se Capability-fil</a></p>';
  // HostString.

  if ($service_type == "WMS" || $service_type == "WFS") {
    //$markup = $markup . "<b class=\"url-generator\">Lav URL til GIS</b><p>" . $hostString . "</p>";

    $markup .= kms_services_theme_button(kms_services_return_button('Lav URL til GIS', $service_type, $service_name));
  }


  // Map Iframe.
  if ($service_type == "WMS" || $service_type == "WMTS") {
    $markup = $markup . '<b>Korteksempel&nbsp;</b><a href="//servicelist.kortforsyningen.dk/show_sample.aspx?maptype=' . $service_type . '&servicename=' . $service_name . '&layerselector=true&screenmode=newwin" target="_blank">&Aring;ben kort i nyt vindue</a><p>
  <iframe id="MyFrame" src="//servicelist.kortforsyningen.dk/show_sample.aspx?maptype=' . $service_type . '&servicename=' . $service_name . '&Screenwidth=580px&Screenheight=330px&&layerselector=true&screenmode=iframe"   style="width:600px;height:350px;border:1px;border-style:solid;" scrolling="no"></iframe></p>';
  }

  print $markup;
  exit();
}

function getCapability($service_name, $service_type) {

  // Get xml document.
  $url = getCapabilityURL($service_name, $service_type);

  if (!empty($url)){
    $xml = simplexml_load_file($url);
  } else {
    $xml = NULL;
  }

  if (isset($xml) && $xml == FALSE) {
    return FALSE;
  }

  // build default $service.
  $service["xml"] = $xml;
  $service["name"] = $service_name;
  $service["type"] = $service_type;
  $service["description"] = "";
  $service["layer"] = array();
  $service["spatialReference"] = array();
  $service["onlineResource"] = "//kortforsyningen.kms.dk/" . $service_name . "?";
  $service["url"] = $url;
  $service["format"] = array();
  // determine which way to parse xml to $service.
  switch ($service_type) {
    case "WMS": $service = getWMS($service);
      break;

    case "WFS": $service = getWFS($service);
      break;

    case "WMTS": $service = getWMTS($service);
      break;

    case "WCS": $service = getWCS($service);
      break;

    default:
      return NULL;
  }
  // build onlineResource.
  return $service;
}

function getWCS($service) {
  $service["description"] = $service["xml"]->children('ows', TRUE)->ServiceIdentification->Abstract;
  foreach ($service["xml"]->Contents->CoverageSummary as $l) {
    $service["layer"][] = $l->Identifier;
  }
  foreach ($service["xml"]->Contents->CoverageSummary->SupportedCRS as $SRS) {
    $service["spatialReference"][] = $SRS;
  }
  foreach ($service["xml"]->children('ows', TRUE)->OperationsMetadata->Operation as $operation) {
    if ($operation->attributes()->name == "GetCoverage") {
      foreach ($operation->Parameter as $parameter) {
        $attr = $parameter->attributes();
        (String) $name = $attr["name"];
        if ($name == "format") {
          $service["format"][]  = $parameter->AllowedValues->Value;
        }
      }
    }
  }
  // WCS has different onlineResourceURL.
  $service["onlineResource"] = "//kortforsyningen.kms.dk/" . $service["name"] . "?service=" . $service["type"];
  return $service;
}

function getWMS($service) {
  $service["description"] = $service["xml"]->Service->Abstract;
  foreach ($service["xml"]->Capability->Layer->Layer as $l) {
    $service["layer"][] = $l->Name;
  }
  foreach ($service["xml"]->Capability->Layer[0]->SRS as $SRS) {
    $service["spatialReference"][] = $SRS;
  }
  return $service;
}

function getWMTS($service) {
  $service["description"] = $service["xml"]->children('ows', TRUE)->ServiceIdentification->Abstract;
  foreach ($service["xml"]->Contents->Layer as $l) {
    $service["layer"][] = $l->children('ows', TRUE)->Identifier;
  }
  foreach ($service["xml"]->Contents->TileMatrixSet as $SRS) {
    $service["spatialReference"][] = $SRS->children('ows', TRUE)->SupportedCRS;
  }
  return $service;
}

function getWFS_v110($service) {
  // No description.
  foreach ($service["xml"]->FeatureTypeList->FeatureType as $l) {
    $service["layer"][] = $l->Title;
  }
  foreach ($service["xml"]->FeatureTypeList->FeatureType as $featureType) {
    foreach ($featureType->DefaultSRS as $def) {
      $temp = (string) $def;
      $service["spatialReference"][$temp] = $temp;
    }
    foreach ($featureType->OtherSRS as $other) {
      $temp = (string) $other;
      $service["spatialReference"][$temp] = $temp;
    }
  }
  return $service;
}

function getWFS_gmlsfp($service) {
  $service["description"] = $service["xml"]->children('ows', TRUE)->ServiceIdentification->Abstract;
  foreach ($service["xml"]->children('wfs', TRUE)->FeatureTypeList->FeatureType as $l) {
    $service["layer"][] = $l->children('ows', TRUE)->Keywords->Keyword;
  }
  foreach ($service["xml"]->children('wfs', TRUE)->FeatureTypeList->FeatureType as $featureType) {
    foreach ($featureType->children('wfs', TRUE)->DefaultSRS as $SRS) {
      $temp = (string) $SRS;
      $service["spatialReference"][$temp] = $temp;
    }
    foreach ($featureType->children('wfs', TRUE)->OtherSRS as $SRS) {
      $temp = (string) $SRS;
      $service["spatialReference"][$temp] = $temp;
    }
  }
  return $service;
}

function getWFS_std($service) {
  $service["description"] = $service["xml"]->children('wfs', TRUE)->Service->Abstract;
  foreach ($service["xml"]->children('wfs', TRUE)->FeatureTypeList->FeatureType as $l) {
    $service["layer"][] = $l->Title;
  }
  foreach ($service["xml"]->children('wfs', TRUE)->FeatureTypeList->FeatureType as $SRS) {
    $temp = (string) ($SRS->SRS);
    $service["spatialReference"][$temp] = $temp;
  }
  return $service;
}

function getWFS_old($service) {
  $service["description"] = $service["xml"]->Service->Abstract;
  foreach ($service["xml"]->FeatureTypeList->FeatureType as $l) {
    $service["layer"][] = $l->Name;
  }
  foreach ($service["xml"]->FeatureTypeList->FeatureType as $SRS) {
    $temp = (string) ($SRS->SRS);
    $service["spatialReference"][$temp] = $temp;
  }
  return $service;
}

function getWFS_v200($service) {
  $service["description"] = $service["xml"]->children('ows', TRUE)->ServiceIdentification->Abstract;
  foreach ($service["xml"]->children('wfs', TRUE)->FeatureTypeList->FeatureType as $l) {
    $service["layer"][] = $l->Title;
  }
  foreach ($service["xml"]->children('wfs', TRUE)->FeatureTypeList->FeatureType as $featureType) {
    foreach ($featureType->DefaultCRS as $def) {
      $temp = (string) $def;
      $service["spatialReference"][$temp] = $temp;
    }
    foreach ($featureType->OtherCRS as $other) {
      $temp = (string) $other;
      $service["spatialReference"][$temp] = $temp;
    }
  }
  return $service;
}

function getWFS($service) {
  // function determines in which way to parse a WFS service.
  // check version number.
  $gmlsfp = preg_match("^gmlsfp^", $service["name"]);
  $gmlsfp_old = preg_match("^gmlsfp_old^", $service["name"]);
  $ver = (string) $service["xml"]->attributes()->version;
  $old = $service["xml"]->Service->Abstract;
  if ($ver == "2.0.0") {
    $service = getWFS_v200($service);
  }
  elseif ($gmlsfp_old == 1) {
    $service = getWFS_v110($service);
  }
  elseif ($ver == "1.1.0") {
    if ($gmlsfp == 1) {
      $service = getWFS_gmlsfp($service);
    }
    else {
      $service = getWFS_v110($service);
    }
  }
  elseif ($gmlsfp == TRUE) {
    $service = getWFS_gmlsfp($service);
  }
  elseif ($old != NULL) {
    $service = getWFS_old($service);
  }
  else {
    $service = getWFS_std($service);
  }
  return $service;
}

function getCapabilityURL($service_name, $service_type) {
  if (isset($_SESSION['my_products_ticket']) && isset($_SESSION['my_products_ticket_valid']) && $_SESSION['my_products_ticket_valid'] > time()) {
    $ticket = $_SESSION["my_products_ticket"];
  }
  else {
    global $user;
    $userObj = entity_metadata_wrapper('user', user_load($user->uid));
    $url = url('https://kortforsyningen.kms.dk/service', array('query' => array(
      'request' => 'GetTicket',
      'login' => $userObj->name->value(),
      'password' => $userObj->field_pass_clear->value()
    )));
    $ticket = file_get_contents($url);
    $_SESSION['my_products_ticket'] = $ticket;
    $_SESSION['my_products_ticket_valid'] = time() + 7200;
  }

  // Get version.
  $version = getVersion($service_type, $service_name);
  if ($version == FALSE) {
    return FALSE;
  }
  $url = "https://kortforsyningen.kms.dk/service?request=GetCapabilities&" 
         . $version . "ticket=" . $ticket 
         . "&servicename=" . $service_name 
         . "&service=" . $service_type;

  return $url;
}

function getVersion($service_type, $service_name) {
  $url;
  if ($service_type == "WMS") {
    return "version=1.1.1&";
  }
  if ($service_type == "WCS") {
    return "version=1.1.1&";
  }
  if ($service_type == "WMTS") {
    return "acceptversions=1.0.0&";
  }
  // WFS.
  if ($service_type == "WFS") {
    if (preg_match("^gmlsfp^", $service_name)) {
      return "version=1.1.0&";
    }
    else {
      return "version=1.0.0&";
    }
  }
  return FALSE;
}

function epsg2Description($arr) {
  try {
    $srs = array();
    $epsg2 = array();
    // Read epsg2 info into map.
    $file     = file_get_contents("../data/epsg2.csv");
    $rows     = explode("\n", $file);
    foreach ($rows as $key => $value) {
      if ($value != NULL) {
        $temp = explode(";", $value);
        $epsg2[$temp[0]] = $temp[1];
      }
    }

    // compare epsg2 to xml info.
    foreach ($arr as $value) {
      // convert xml-string to string without letters.
      $srs[] = preg_replace("[^0-9]", "", $value);
    }

    foreach ($srs as $key => $value) {
      if (isset($epsg2[$value]) && $epsg2[$value] == "") {
        $srs[$key] = $value . ": (Ingen beskrivelse)";
      }
      else {
        if(isset($epsg2[$value])) {
          $srs[$key] = $value . ": " . trim($epsg2[$value]) . "";
        }
      }
    }
    return $srs;
  } catch (Exception $e) {
    return array();
    watchdog('gst_products'. 'Caught exception: ',  $e->getMessage(), "\n");
  }
}

function kms_services_theme_button($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'button';
  element_set_attributes($element, array('id', 'name', 'value'));

  $element['#attributes']['class'][] = 'form-' . $element['#type'];
  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'form-button-disabled';
  }

  return '<span class="url-form"><input' . drupal_attributes($element['#attributes']) . ' /><div class="url-form"></div></span>';
}
