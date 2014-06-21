<?php
/**
 * kms_oci_queue.consistency.inc.
 * User: mikkel@adapt.dk
 * Date: 6/20/14 - 1:30 PM
 */


abstract class cData {

  protected $name = '';
  protected $rows = array();

  public function __construct($name) {
    $this->name = $name;
    $this->defineRows();
  }

  public function getName() {
    return $this->name;
  }

  public function getRows() {
    return $this->rows;
  }

  protected abstract function defineRows();

}

class cDataServicesPostgres extends cData {
  public function __construct($name) {
    parent::__construct($name);
  }

  protected function defineRows() {
    $sql = new KmsOciQueueSql('services', array());
    $sql_str = $sql->generate('consitency');
    $result = db_query($sql_str);
    while ($record = $result->fetchObject()) {
      $this->rows[$record->userid][] = $record->serviceid;
    }
  }

}

class cDataServicesOracle extends cData {

  public function __construct($name) {
    parent::__construct($name);
  }

  protected function defineRows() {
    $settings = array(
      'kms_oci_conn_user' => variable_get('kms_permissions_conn_user', ''),
      'kms_oci_conn_pass' => variable_get('kms_permissions_conn_pass', ''),
      'kms_oci_conn_host' => variable_get('kms_permissions_conn_host', ''),
      'kms_oci_conn_db' => variable_get('kms_permissions_conn_db', ''),
    );

    if (kms_oci_get_conn('kms_permissions', $settings)) {
      $sql = new KmsOciQueueSql('services', array());
      $records = kms_oci_select(
        $sql->generate('consistency'),
        array(),
        'kms_permissions'
      );
      foreach ($records as $record) {
        $this->rows[$record['USERID']][] = $record['SERVICEID'];
      }
    }
  }

}

class cDataApplicationsPostgres extends cData {
  public function __construct($name) {
    parent::__construct($name);
  }

  protected function defineRows() {
    return array();
  }

}

class cDataApplicationsOracle extends cData {
  public function __construct($name) {
    parent::__construct($name);
  }

  protected function defineRows() {
    return array();
  }

}

class cDataCheck {

  public function __construct($data_a, $data_b){
    $this->dataA = $data_a;
    $this->dataB = $data_b;
  }

  public function diff() {
    $rows_a = $this->dataA->getRows();
    $rows_b = $this->dataB->getRows();
    $name_a = 'Unique ids:' . $this->dataA->getName();
    $name_b = 'Unique ids: ' . $this->dataB->getName();
    $data = array();
    foreach ($rows_a as $id => $a_data) {
      $a_data = !empty($a_data) ? $a_data : array();
      $b_data = !empty($rows_b[$id]) ? $rows_b[$id] : array();
      if (count($a_data) != count($b_data)) {
        $data[$id][$name_a] = array_diff($a_data, $b_data);
        $data[$id][$name_b] = array_diff($b_data, $a_data);
      }
    }
    return $data;
  }

  public function diffCount() {
    return count($this->diff());
  }

  public function emptyEntries() {
    $rows_a = $this->dataA->getRows();
    $rows_b = $this->dataB->getRows();
    $name_a = $this->dataA->getName();
    $name_b = $this->dataB->getName();
    $data = array();
    $data[$name_a] = array_filter($rows_a, function($v) { return empty($v); });
    $data[$name_b] = array_filter($rows_b, function($v) { return empty($v); });
    return $data;
  }

}
