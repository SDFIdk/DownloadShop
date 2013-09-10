<?php
  
  require_once("kms_mapwidget_fme.inc");
  
  //$job = kms_mapwidget__fme_api('status',3915);
  //$job = kms_mapwidget__fme_api('queued');

  $job =  kms_mapwidget__fme_api(
    'run',
    'FOT',
    array(
      'DestFormat'   => 'MAPINFO',
      'DestCoordSys' => '', //UTM32-EUREF89',
      'udtrType'     => 0,
      'AdmKode'      => '710,751',
      'ctlClip'      => 'yes',
      'BBOX'         => 2
    )
  );

print_r($job);

