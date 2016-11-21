<?php

/**
 * @file
 */

function readArcGISData() {
  $p = drupal_get_path('module', 'services_kms_v2') . '/data/kommuner_bbox_2007.txt';
  $txt_file    = file_get_contents($p);
  $rows        = explode("\n", $txt_file);
  // array_shift is used 2 times. One to remove the header. One to remove separation line below the header.
  array_shift($rows); array_shift($rows);
  $info["Hele Landet"] = array(120000, 1000000, 59000000, 6500000);
  foreach ($rows as $row => $data) {
    // Finds city name.
    $city = explode("  ", $data);
    trim($city[0]);
    if ($city[0] != "") {
      // Finds every coordinate for city and stores it in $coords[1]
      $coords = explode($city[0], $data);
      // split up coords.
      $coordsSorted = preg_split('/\s+/', $coords[1]);
      // Only take x coordinate.
      $xCoordsSorted = array();
      foreach ($coordsSorted as $value) {
        $xCoordsSorted[] = preg_split('/,/', $value);
      }

      // Collects all info to ONE array.
      $info[$city[0]] = array(
        $xCoordsSorted[1][0],
        $xCoordsSorted[2][0],
        $xCoordsSorted[3][0],
        $xCoordsSorted[4][0],
      );
    }
  }
  printArcGISDataToJs($info);
  return $info;
}

function printArcGISDataToJs($arr) {
  echo "<script type='text/javascript'>";
  $js_array = json_encode($arr);
  echo "var city_list = " . $js_array . ";\n";
  echo "</script>";
}
