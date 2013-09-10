<?php

$plugin = array(
  'title' => t('KMS my downloads'),
  'description' => t('Show the users downloads'),
  'category' => t('KMS'),
  'render callback' => 'kms_mydownloads_render',
);


 function _kms_mydownloads_date_format($remaining) {
  $j = gmdate("j",$remaining);
  $G = gmdate("G",$remaining);
  $i = intval(gmdate("i",$remaining));
  return '<div class="time-remaining">' . t('Time remaining : ') 
    . ($j > 0 ? ($j . ($j > 1 ? ' dage ' : ' dag ')) : '') 
    . ($j < 1 && $G > 0 ? ($G . ($G > 1 ? ' timer ' : ' time ')) : '') 
    . ($j < 1 ? ($i . ( $i > 1 ? ' minutter ' : ' minut ')) : '') . '</div>';
 }

/**
 * Render the custom content type.
 */

function kms_mydownloads_render($subtype, $conf, $panel_args, $context) {
  
  global $user;
  $now = time();

  $block = new stdClass();

  $orders = commerce_order_load_multiple(array(), 
  	array('uid' => $user->uid, 'status' => 'completed'));
  
  $rows = array();
  
  asort($orders);
  $orders = array_reverse($orders,true);

  foreach ($orders as $orderid => $order) {
  	$ow = entity_metadata_wrapper('commerce_order', $order);
    $remaining_order = $ow->created->value() - $now + ( 86400 * 7 );
    $visible = $remaining_order > 0;
    $firstline = true;

    foreach ($ow->commerce_line_items as $delta => $liw) {
      $extra = '';
      $li = $liw->value();

      if (empty($li->field_li_type))
        continue;
      
      $data = unserialize($liw->field_selection->value());
      $op = commerce_product_load($data['product_id']);
      $opw = entity_metadata_wrapper('commerce_product', $op);
      
      if ($data['type'] == 'predefined') {
        $extra .= _kms_mydownloads_date_format($remaining_order);
        foreach ($liw->commerce_file_line_item_files->value() as $delta => $file) {
         //_kms_mydownloads_update_file_size($file);
         $extra .= theme_file_link(array('file' => file_load($file['fid']), 
         	'icon_directory' => 'sites/default/files')) . ' <span class="file-size">(' . _kms_mydownloads_format_bytes($file['filesize'],0) . ')</span>';
        }
      }

      if ($data['type'] == 'userdefined') {
        if ($liw->field_jobid->value()) {
          $jobid = $liw->field_jobid->value();
          $jobStatus = $liw->field_fme_status->value();
          
          if ($jobStatus != 'SUCCESS' && $jobStatus != 'ABORTED' && $jobStatus != 'FME_FAILURE') {
            $status = kms_mapwidget__fme_api('status',$jobid);
            $jobStatus = $status->serviceResponse->job->jobStatus;
            $liw->field_fme_status = $jobStatus;
            $liw->field_finished = time() - 10;
            $liw->save();
          }

          if ($jobStatus == 'SUCCESS' || $jobStatus == 'ABORTED' || $jobStatus == 'FME_FAILURE') {
             $remaining = $liw->field_finished->value() - $now + ( 86400 * 7 );
             $visible = $remaining > 0;
           } else {
             $visible = true;
           }

           if ($jobStatus == 'SUCCESS') {            
             $extra .= _kms_mydownloads_date_format($remaining);
             $extra .= theme_file_link(array(
               'file' => (object) array(
                 'filemime' => 'application/zip',
                 'filesize' => 0,
                 'uri' => 'sites/default/files/kfdownload/' . $jobid . '.zip',
                 'filename' => $jobid . '.zip' ), 
              'icon_directory' => 'sites/default/files')
             ) . ' ' . _kms_mydownloads_get_file_size($jobid,0);

           } else {
             $extra .= t($jobStatus);
           }
 
        }
        
      }
      
      if ($visible) {
  	    $rows[] = array(
  	      array( 
            'data'  => $firstline ? $ow->order_number->value() : '',
            'class' => $firstline ? array('order-first-line', 'order-specific') : array('order-nth-line', 'order-specific'),
          ),
          array( 
            'data'  => $firstline ? format_date($ow->created->value(),'short') : '',
            'class' => $firstline ? array('order-first-line', 'order-specific') : array('order-nth-line', 'order-specific'),
          ),
          array( 
            'data'  => $liw->line_item_label->value() . '<div class="product-details">' . $liw->field_selection_text->value() . '</div>',
            'class' => array('line-item-specific'),
          ),
          array( 
            'data'  => $extra,
            'class' => array('line-item-specific'),
          )
  	    );
        $firstline = false;
      }
    }
  }

  $block->content = theme_table( array ( 
  	'header' => array(t('Order#'),t('Order date'),t('Product'),t('Download')), 
  	'rows' => $rows,
    'attributes' => array('class' => 'mydownloads'),
    'sticky' => false,
    'caption' => '',
    'colgroups' => array(),
    'empty' => ''
  ));

  //$block->content .= print_r($orders,true);

  return $block;
  
}

/*
  Update fileinfo ( if files in NFS-share was updated )
*/

function _kms_mydownloads_get_file_size($jobid) {
  
  $filename = DRUPAL_ROOT . '/sites/default/files/kfdownload/' . $jobid . '.zip';
  @$stat = stat($filename);
  
  if ($stat) {
    return '<span class="file-size">(' . _kms_mydownloads_format_bytes($stat['size'],0) . ')</span>';
  } else {
    return '';
  }

}

/*
  Get fileinfo ( for FME products not in files table)
*/

function _kms_mydownloads_update_file_size(&$file) {
  
  $orig = DRUPAL_ROOT."/sites/private/" . str_replace('private://','',$file['uri']);
  $finfo = finfo_open(FILEINFO_MIME_TYPE);

  @$stat = stat($orig);
  
  if ($stat) {

    $values = array( 
      finfo_file($finfo, $orig), // filemime
      $stat['size'],             // filesize
      $file['uri']               // uri
    );  
    
    if ($file['filemime']  != $values[0] || $file['filesize']  != $values[1] ) {
      $sql = 'UPDATE file_managed SET filemime=?,filesize=? WHERE uri=?';
      $dbh = Database::getConnection();
      $stmt = $dbh->prepare($sql);
      $stmt->execute($values);
      $file['filesize'] = $values[1];
    }

  }

}


/*
  Format bytes to k/G/T-bytes
*/

function _kms_mydownloads_format_bytes($size, $precision = 2)
{   
  $base = log($size) / log(1024);
  $suffixes = array('B', 'kB', 'MB', 'GB', 'TB');   
  return round(pow(1024, $base - floor($base)), $precision) . $suffixes[floor($base)];
}

