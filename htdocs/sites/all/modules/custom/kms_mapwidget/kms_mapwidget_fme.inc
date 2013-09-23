<?php

function kms_mapwidget__fme_api($action, $id = false, $data = array()) {
  
  $fmeurl = 'http://fmeserver.kmsext.dk/fmerest';

  $curl = curl_init();
  
  switch (gethostname()) {
    case 'w3test1.kmsext.dk' :
      $nm_jobsuccess_topic = 'KFDOWNLOAD_TEST';
      $nm_jobfailure_topic = 'KFDOWNLOAD_TEST';
      break;
    case 'w3udv2.kmsext.dk' :
      $nm_jobsuccess_topic = 'KFDOWNLOAD_DEV';
      $nm_jobfailure_topic = 'KFDOWNLOAD_DEV';
      break;  
    default:
      $nm_jobsuccess_topic = 'KFDOWNLOAD_PROD';
      $nm_jobfailure_topic = 'KFDOWNLOAD_PROD';
  }

  switch ($action) {
    case "run":
      $id = strtoupper($id);
      $data += array(
        'opt_servicemode' => 'async',
        'tm_tag' => 'kfdownload',
        'tm_priority' => 20,
        'nm_jobsuccess_topic' => $nm_jobsuccess_topic,
        'nm_jobfailure_topic' => $nm_jobfailure_topic,
        'subsection' => kms_mapwidget__subsection($id),
      );
      $params = http_build_query($data);
      curl_setopt($curl, CURLOPT_URL, $fmeurl . '/repositories/LDS/' . $id . '/run.json?' . $params);
      break;
    case "status":
      curl_setopt($curl, CURLOPT_URL, $fmeurl . '/jobs/' . $id . '.json');
      break;
    case "result":
      curl_setopt($curl, CURLOPT_URL, $fmeurl . '/jobs/' . $id . '/result.json');
      break;
    case "queued":
      curl_setopt($curl, CURLOPT_URL, $fmeurl . '/jobs/queued');
      break;
    }

  //curl_setopt($curl, CURLOPT_VERBOSE, true);

  curl_setopt($curl, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
  curl_setopt($curl, CURLOPT_USERPWD, "kfdownload:secret");

  curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);

  $response = curl_exec($curl);
  
  curl_close($curl);
    
  if ($response) {
    $response = json_decode($response);
    if ( $action == 'run' ) { 
      kms_mapwidget_fme_log(
        FME_TYPE_REQUEST,
        $data['OrdreNummer'],
        $response->serviceResponse->jobID,
        array('params' => $data, 'url' => $fmeurl . '/repositories/LDS/' . $id . '/run.json')
      );
    }
    return $response;
  }
  else
    return FALSE;
}

/**
 * DataSet   subsection
 * ----------------------------------
 * MINIMAKS  GST_KFDOWNLOAD
 * KORT10    GST_KFDOWNLOAD
 * FOT       GST_KFDOWNLOAD
 * ADRESSER  GST_KFDOWNLOAD
 * DAGI      GST_KFDOWNLOAD
 * DHM       GST_KFDOWNLOAD_RASTER
 * ORTOFOTO  GST_KFDOWNLOAD_RASTER
 */

function kms_mapwidget__subsection($dataset) {
  if ($dataset == 'DHM' || $dataset == 'ORTOFOTO')
    return 'GST_KFDOWNLOAD_RASTER';
  else
    return 'GST_KFDOWNLOAD';
}
