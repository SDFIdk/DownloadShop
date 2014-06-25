<?php
/**
 * kms_oci_queue.consistency.inc.
 * User: mikkel@adapt.dk
 * Date: 6/20/14 - 1:30 PM
 */


abstract class cData {

  protected $rows = array();

  public function __construct() {
    // Atodo: Put data in chunks and remove this.
    ini_set('memory_limit', '2048M');
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
  public function __construct() {
    parent::__construct();
  }

  public function defineRows() {
    $sql = new KmsOciQueueSql('services', array());
    $sql_str = $sql->generate('consistency');
    $result = db_query($sql_str);
    while ($record = $result->fetchObject()) {
      $this->rows[$record->userid][] = $record->serviceid;
    }
  }

}

class cDataServicesOracle extends cData {

  public function __construct() {
    parent::__construct();
  }

  public function defineRows() {
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
  public function __construct() {
    parent::__construct();
  }

  public function defineRows() {
    return array();
  }

}

class cDataApplicationsOracle extends cData {
  public function __construct() {
    parent::__construct();
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
          $data[$id][$name_b] = array_diff($row_b, $row_a);
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

  protected function testRowsA() {
return array (
  '001FA1F410637ED3C1256E1A0034EA2B' => 
  array (
    0 => '1',
    1 => '2',
    2 => '4',
    3 => '5',
    4 => '6',
    5 => '7',
    6 => '8',
    7 => '9',
    8 => '10',
    9 => '11',
    10 => '12',
    11 => '13',
    12 => '14',
    13 => '221',
    14 => '452',
    15 => '633',
    16 => '775',
    17 => '894',
    18 => '1013',
    19 => '1133',
    20 => '1134',
    21 => '1135',
    22 => '1136',
    23 => '1137',
    24 => '1138',
    25 => '1493',
    26 => '1695',
    27 => '1795',
    28 => '1855',
    29 => '1898',
    30 => '1899',
    31 => '1901',
    32 => '1916',
    33 => '1917',
    34 => '2117',
    35 => '2124',
    36 => '2795',
    37 => '2895',
    38 => '2935',
    39 => '2997',
    40 => '3018',
    41 => '3118',
    42 => '3137',
    43 => '3157',
    44 => '3458',
    45 => '4038',
    46 => '4218',
    47 => '4238',
    48 => '4278',
    49 => '4398',
    50 => '4418',
    51 => '4498',
    52 => '4578',
    53 => '4580',
    54 => '4598',
    55 => '4618',
    56 => '4778',
    57 => '4818',
    58 => '4938',
    59 => '5138',
    60 => '5338',
  ),
  '01D35F9B48A0B6A6C12577030034F628' => 
  array (
    0 => '1',
    1 => '2',
    2 => '4',
    3 => '5',
    4 => '6',
    5 => '7',
    6 => '8',
    7 => '9',
    8 => '10',
    9 => '11',
    10 => '12',
    11 => '13',
    12 => '14',
    13 => '221',
    14 => '452',
    15 => '633',
    16 => '775',
    17 => '894',
    18 => '1013',
    19 => '1113',
    20 => '1133',
    21 => '1134',
    22 => '1135',
    23 => '1136',
    24 => '1137',
    25 => '1138',
    26 => '1333',
    27 => '1493',
    28 => '1614',
    29 => '1655',
    30 => '1695',
    31 => '1715',
    32 => '1795',
    33 => '1855',
    34 => '1895',
    35 => '1896',
    36 => '1898',
    37 => '1899',
    38 => '1901',
    39 => '1916',
    40 => '1917',
    41 => '1919',
    42 => '1935',
    43 => '1937',
    44 => '1938',
    45 => '1939',
    46 => '1940',
    47 => '2055',
    48 => '2117',
    49 => '2124',
    50 => '2257',
    51 => '2276',
    52 => '2295',
    53 => '2315',
    54 => '2335',
    55 => '2415',
    56 => '2495',
    57 => '2496',
    58 => '2535',
    59 => '2536',
    60 => '2555',
    61 => '2696',
    62 => '2795',
    63 => '2895',
    64 => '2935',
    65 => '2997',
    66 => '3018',
    67 => '3118',
    68 => '3137',
    69 => '3157',
    70 => '3238',
    71 => '3358',
    72 => '3378',
    73 => '3458',
    74 => '3638',
    75 => '3898',
    76 => '4038',
    77 => '4218',
    78 => '4238',
    79 => '4238',
    80 => '4278',
    81 => '4338',
    82 => '4358',
    83 => '4359',
    84 => '4398',
    85 => '4418',
    86 => '4498',
    87 => '4578',
    88 => '4580',
    89 => '4598',
    90 => '4618',
    91 => '4719',
    92 => '4778',
    93 => '4798',
    94 => '4818',
    95 => '4918',
    96 => '4938',
    97 => '5138',
    98 => '5178',
    99 => '5338',
  ),
);

  }

protected function testRowsB() {
return array (
  '001FA1F410637ED3C1256E1A0034EA2B' => 
  array (
    0 => '1',
    1 => '2',
    2 => '4',
    3 => '5',
    4 => '6',
    5 => '7',
    6 => '8',
    7 => '9',
    8 => '10',
    9 => '11',
    10 => '12',
    11 => '13',
    12 => '14',
    13 => '221',
    14 => '452',
    15 => '633',
    16 => '775',
    17 => '894',
    18 => '1013',
    19 => '1133',
    20 => '1134',
    21 => '1135',
    22 => '1136',
    23 => '1137',
    24 => '1138',
    25 => '1493',
    26 => '1695',
    27 => '1795',
    28 => '1855',
    29 => '1898',
    30 => '1899',
    31 => '1901',
    32 => '1916',
    33 => '1917',
    34 => '2117',
    35 => '2124',
    36 => '2795',
    37 => '2895',
    38 => '2935',
    39 => '2997',
    40 => '3018',
    41 => '3118',
    42 => '3137',
    43 => '3157',
    44 => '3458',
    45 => '4038',
    46 => '4218',
    47 => '4238',
    48 => '4278',
    49 => '4398',
    50 => '4418',
    51 => '4498',
    52 => '4578',
    53 => '4580',
    54 => '4598',
    55 => '4618',
    56 => '4778',
    57 => '4818',
    58 => '4938',
    59 => '5138',
    60 => '5338',
    61 => 99999999999999,
  ),
  '003C69D5CA9A73A0C12572330028929C' => 
  array (
    0 => '9',
    1 => '1795',
    2 => '1855',
    3 => '2117',
    4 => '2257',
    5 => '2315',
    6 => '2355',
    7 => '2795',
  ),
);
}

}
