<?php
/**
 * kms_oci_queue.consistency.inc.
 * User: mikkel@adapt.dk
 * Date: 6/20/14 - 1:30 PM
 */


abstract class cData {

  protected $rows = array();
  protected $uids = array();

  public function __construct($uids) {
    $this->uids = $uids;
    $this->defineRows();
  }

  public function getName() {
    return preg_replace(
      '#^cData([A-Z]{1}[a-z]+)([A-Z]{1}[a-z]+)$#',
      "$1:$2",
      get_class($this)
    );
  }

  public function getRows() {
    return $this->rows;
  }

  public abstract function defineRows();

}

class cDataServicesPostgres extends cData {
  public function __construct($uids) {
    parent::__construct($uids);
  }

  public function defineRows() {
    $valid_sids = cHelper::getValidServiceIds();
    $sql = new KmsOciQueueSql('services');
    $result = db_query($sql->generate('consistency', $this->uids));
    while ($record = $result->fetchObject()) {
      $sid = (string) $record->serviceid;
      if (in_array($sid, $valid_sids)) {
        $this->rows[$record->userid][$sid] = $record->serviceid;
      }
    }
  }

}

class cDataServicesOracle extends cData {

  public function __construct($uids) {
    parent::__construct($uids);
  }

  public function defineRows() {
    $valid_sids = cHelper::getValidServiceIds();
    $settings = array(
      'kms_oci_conn_user' => variable_get('kms_permissions_conn_user', ''),
      'kms_oci_conn_pass' => variable_get('kms_permissions_conn_pass', ''),
      'kms_oci_conn_host' => variable_get('kms_permissions_conn_host', ''),
      'kms_oci_conn_db' => variable_get('kms_permissions_conn_db', ''),
    );
    if (kms_oci_get_conn('kms_permissions', $settings)) {
      $sql = new KmsOciQueueSql('services');
      $records = kms_oci_select(
        $sql->generate('consistency', $this->uids),
        array(),
        'kms_permissions'
      );
      foreach ($records as $record) {
        $sid = (string) $record['SERVICEID'];
        if (in_array($sid, $valid_sids)) {
          $this->rows[$record['USERID']][$sid] = $record['SERVICEID'];
        }
      }
    }
  }

}

class cDataApplicationsPostgres extends cData {
  public function __construct($uids) {
    parent::__construct($uids);
  }

  public function defineRows() {
    return array();
  }

}

class cDataApplicationsOracle extends cData {
  public function __construct($uids) {
    parent::__construct($uids);
  }

  public function defineRows() {
    return array();
  }

}

class cDataCheck {

  public function __construct($data_a, $data_b){
    $this->dataA = $data_a;
    $this->dataB = $data_b;
  }

  public function diff($mode = 'both') {
    $rows_a = $this->dataA->getRows();
    $rows_b = $this->dataB->getRows();
    ksort($rows_a);
    ksort($rows_b);
    $name_a = 'diff:' . $this->dataA->getName();
    $name_b = 'diff:' . $this->dataB->getName();
    $data = array();

    // Compare a rows against b rows.
    foreach (array_keys($rows_a) as $id) {
      $row_a = !empty($rows_a[$id]) ? $rows_a[$id] : array();
      $row_b = !empty($rows_b[$id]) ? $rows_b[$id] : array();
      if (count($row_a) != count($row_b)) {
        $data_diff_a = array_diff($row_a, $row_b);
        $data_diff_b = array_diff($row_b, $row_a);
        // If row a has a diff and current mode allows us then put diff in data.
        if ($data_diff_a && in_array($mode, array('both', 'a'))) {
          $data[$id][$name_a] = $data_diff_a;
          // If row b is empty and we didn't choose to only watch a diffs.
          if (empty($data[$id][$name_b]) && $mode != 'a') {
            $data[$id][$name_b] = array();
          }
        }
        // If row b has a diff and current mode allows us then put diff in data.
        if ($data_diff_b && in_array($mode, array('both', 'b'))) {
          $data[$id][$name_b] = $data_diff_b;
          // If row a is empty and we didn't choose to only watch b diffs.
          if (empty($data[$id][$name_a]) && $mode != 'b') {
            $data[$id][$name_a] = array();
          }
        }
      }
    }

    // Add unique ids from b rows.
    foreach (array_diff_assoc($rows_b, $rows_a) as $id => $children) {
      // If current mode allows us the populate data with b row diff.
      if (in_array($mode, array('both', 'b'))) {
        $data[$id][$name_b] = $children;
      }
      // If we are showing both row a and b
      // then make sure a row is empty when b row has a diff.
      if ($mode == 'both') {
        $data[$id][$name_a] = array();
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

class cHelper {
  const uidChunkSize = 1000;
  const dirConsistencyDiff = 'temporary://consistency_diff';

  public static function getUidChunks() {
    $uids = array();
    // Postgres
    $query_str = "SELECT DISTINCT userid FROM smuser ORDER BY userid";
    $result = db_query($query_str);
    foreach ($result as $row) {
      $uids[$row->userid] = $row->userid;
    }
    // Oracle
    if (kms_oci_get_conn()) {
      $records = kms_oci_select("SELECT DISTINCT userid FROM smuser ORDER BY userid");
      foreach ($records as $record) {
        $uid = (string)$record['USERID'];
        if (empty($uids[$uid])) {
          $uids[$uid] = $record['USERID'];
        }
      }
    }

    sort($uids);

    return array_chunk($uids, self::uidChunkSize);
  }


  public static function getValidServiceIds() {
    static $sids;

    if (isset($sids)) {
      return $sids;
    }

    $sids = array();
    $settings = array(
      'kms_oci_conn_user' => variable_get('kms_permissions_conn_user', ''),
      'kms_oci_conn_pass' => variable_get('kms_permissions_conn_pass', ''),
      'kms_oci_conn_host' => variable_get('kms_permissions_conn_host', ''),
      'kms_oci_conn_db' => variable_get('kms_permissions_conn_db', ''),
    );
    if (kms_oci_get_conn('kms_permissions', $settings)) {
      $sql = new KmsOciQueueSql('services');
      $records = kms_oci_select(
        'SELECT serviceid from SERVICES2',
        array(),
        'kms_permissions'
      );
      foreach ($records as $record) {
        $sids[$record['SERVICEID']] = $record['SERVICEID'];
      }
    }
    return $sids;
  }

  public static function getAllServiceIdsPostgres() {
    $query = db_select('userrestrictions2', 'ur')
      ->fields('ur', array('serviceid'))
      ->groupBy('ur.serviceid')
      ->orderBy('ur.serviceid');
    return $query->execute()->fetchCol();
  }

}
