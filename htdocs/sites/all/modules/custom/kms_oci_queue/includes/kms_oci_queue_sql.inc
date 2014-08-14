<?php
/**
 * @file
 * kms_oci_queue_sql.inc.
 * User: mikkel@adapt.dk
 * Date: 03/20/14 - 13:07 PM
 */

class KmsOciQueueSql {

  private $type = '';
  private $data = array();
  private $sqlClass = '';
  private $conf = array();

  public function __construct($type = NULL, $data = NULL) {
    $this->type = $type;
    $this->data = $data;
    $this->sqlClass = sprintf('%s%s', __CLASS__, ucfirst($type));
    $conf_callback = array($this->sqlClass, 'conf');
    if (is_callable($conf_callback)) {
      $this->conf = call_user_func($conf_callback);
    }
  }

  public function generate($query_type) {
    $callback = array($this->sqlClass, $query_type);
    if (is_callable($callback)) {
      $args = func_get_args();
      $args = array_slice($args, 1);
      $sql = call_user_func_array($callback, $args);
      $sql = $this->replacePlaceholders($sql, $this->data);
      return !empty($sql) ? sprintf("%s\n", $sql) : '';
    }
  }

  public function generateWrapper($wrapper_type) {
    $sql = '';
    if (
      $this->type != __CLASS__
        && is_callable(array($this->sqlClass, $wrapper_type))
    ){
      $args = array_slice(func_get_args(), 1);
      $sql = call_user_func_array(array($this->sqlClass, $wrapper_type), $args);
    }
    else if (is_callable(array($this, $wrapper_type))) {
      $sql = $this->$wrapper_type();
    }

    if ($this->type != __CLASS__ && !empty($sql)) {
      $sql = $this->replacePlaceholders($sql, $this->data);
    }

    return $sql;
  }

  protected function replacePlaceholders($sql, $data) {
    $cb_replace_place_holders = array($this->sqlClass, 'replacePlaceholders');
    if (is_callable($cb_replace_place_holders)) {
      $sql = call_user_func_array(
        $cb_replace_place_holders,
        array($sql, $data)
      );
    }
    return $sql;
  }

  private static function header() {
    return <<<EOD
DECLARE
  v_userid VARCHAR2 (50) := *userid*;
BEGIN

EOD;
  }

  private static function footer() {
    return <<<EOD
EXCEPTION
  WHEN DUP_VAL_ON_INDEX THEN
    RAISE_APPLICATION_ERROR(-20001, 'DUP_VAL_ON_INDEX exception on user: ' || v_userid);
    ROLLBACK;
END;
/

EOD;
  }

}

abstract class KmsOciQueueSqlBase {

  public static function replacePlaceholders($sql, $data) {
    $patterns = $replacements = array();
    array_walk($data, function($v, $k) use(&$patterns, &$replacements){
      $patterns[] = '#\\*' . $k . '\\*#';
      $replacements[] = "'$v'";
    });
    return preg_replace($patterns, $replacements, $sql);
  }

}

class KmsOciQueueSqlServices extends KmsOciQueueSqlBase {

  public static $conf = array(
    'table' => 'USERRESTRICTIONS2',
    'cid' => 'kms_permissions',
    'default_values' => array(
      'SERVICEID' => '',
      'MINX' => '',
      'MINY' => '',
      'MAXX' => '',
      'MAXY' => '',
      'MAXPIXELWIDTH' => '',
      'MAXPIXELHEIGHT' => '',
      'FEATUREINFO' => '0',
    ),
  );

  public static function upsert() {
    $table = self::$conf['table'];
    return <<<EOD
MERGE INTO $table t
USING dual ON (t.userid = v_userid AND t.serviceid = *serviceid*)
WHEN NOT MATCHED THEN
  INSERT (SERVICEID, USERID, MINX, MINY, MAXX, MAXY, MAXPIXELWIDTH, MAXPIXELHEIGHT, FEATUREINFO)
  VALUES (*serviceid*, v_userid, *minx*, *miny*, *maxx*, *maxy*, *maxpixelwidth*, *maxpixelheight*, *featureinfo*)
WHEN MATCHED THEN
  UPDATE SET t.MINX = *minx*, t.MINY = *miny*, t.MAXX = *maxx*, t.MAXY = *maxy*, t.MAXPIXELWIDTH = *maxpixelwidth*, t.MAXPIXELHEIGHT = *maxpixelheight*, t.FEATUREINFO = *featureinfo*
;
EOD;
  }

  public static function insert() {
    $table = self::$conf['table'];
    return <<<EOD
INSERT INTO $table (SERVICEID, USERID, MINX, MINY, MAXX, MAXY, MAXPIXELWIDTH, MAXPIXELHEIGHT, FEATUREINFO)
VALUES (*serviceid*, v_userid, *minx*, *miny*, *maxx*, *maxy*, *maxpixelwidth*, *maxpixelheight*, *featureinfo*)
;
EOD;
  }

  public static function delete() {
    return sprintf(
      'DELETE FROM %s t WHERE t.userid = v_userid AND t.serviceid = *serviceid*;',
      self::$conf['table']
    );
  }

  public static function updateBySid($data) {
    $cols = array_keys(self::$conf['default_values']);
    $sql = array();
    $values = '';
    array_walk($cols, function($col) use(&$values, $data) {
      $col = strtolower($col);
      if ($col != 'serviceid') {
        // If value is empty there is no reason to include it in update statement.
        if (empty($data[$col])) {
          return;
        }
        $values[$col] = "t.$col = *$col*";
      }
    });
    $sql[] = sprintf(
      "UPDATE %s t SET %s WHERE t.serviceid = *serviceid*;\n",
      self::$conf['table'],
      implode(', ', $values)
    );
    $output = implode("\n", $sql);
    return $output ? $output : '';
  }

  public static function consistency() {
    $table = self::$conf['table'];
    return "SELECT userid, serviceid FROM $table ORDER BY userid, serviceid";
  }

}

class KmsOciQueueSqlApplications extends KmsOciQueueSqlBase {

  public static $conf = array(
    'table' => 'SMUSERGROUP',
    'cid' => 'default',
    'default_values' => array(
      'USERID' => '',
      'GROUPID' => '',
    ),
  );

  public static function upsert() {
    $table = self::$conf['table'];
    return <<<EOD
MERGE INTO $table t
USING dual ON (t.userid = v_userid AND t.groupid = *groupid*)
WHEN NOT MATCHED THEN
  INSERT (GROUPID, USERID)
  VALUES (*groupid*, v_userid)
;
EOD;
  }

  public static function insert() {
    $table = self::$conf['table'];
    return <<<EOD
INSERT INTO $table (ID, GROUPID, USERID) VALUES (v_userid, *groupid*, v_userid);
EOD;
  }

  public static function delete() {
    return sprintf(
      'DELETE FROM %s t WHERE t.userid = v_userid AND t.groupid = *groupid*;',
      self::$conf['table']
    );
  }

  public static function consistency() {
    $table = self::$conf['table'];
    return "SELECT userid, groupid FROM $table ORDER BY userid, groupid";
  }

}

class KmsOciQueueSqlUser extends KmsOciQueueSqlBase {

  public static $conf = array(
    'tables' => array('SMUSER', 'SMUSER_EXTRA'),
    'cid' => 'kms_permissions',
    'default_values' => array(
      'SMUSER' => array(
        'USERID' => '',
        'NAME' => '',
        'EMAILADDRESS' => '',
        'DISABLED' => '',
        'FIRSTNAME' => '',
        'LASTNAME' => '',
        'TELEPHONENUMBER' => '',
        'DEBITORNO' => '',
        'PASSWORD' => '',
      ),
      'SMUSER_EXTRA' => array(
        'USERID' => '',
        'DUID' => '',
        'USERTYPE' => '',
        'USERTYPE_INFO' => '',
        'RECEIVE_NEWSLETTER' => '',
        'ACCEPT_TERMS' => '',
        'CONTACT_ME' => '',
      ),
    ),
  );

  public static function upsert($table = '') {
    $sql = array();
    $tables = self::$conf['default_values'];
    foreach ($tables as $table_name => $conf) {
      if (!empty($table) && strtoupper($table) != $table_name) {
        continue;
      }
      $cols = array_keys($conf);
      $sql_data = self::sqlData($cols);
      $insert_cols = implode(', ', $cols);
      $insert_placeholders = implode(', ', $sql_data['insert']);
      $update_placeholders = implode(', ', $sql_data['update']);
      $sql[] = <<<EOD
MERGE INTO $table t
USING dual ON (t.userid = v_userid)
WHEN NOT MATCHED THEN
  INSERT ($insert_cols)
  VALUES ($insert_placeholders)
WHEN MATCHED THEN
  UPDATE SET $update_placeholders
;
EOD;
    }
    $output = implode("\n", $sql);
    return $output ? $output : '';
  }

  public static function insert($table = '') {
    $sql = array();
    $tables = self::$conf['default_values'];
    foreach ($tables as $table_name => $conf) {
      if (!empty($table) && strtoupper($table) != $table_name) {
        continue;
      }
      $cols = array_keys($conf);
      $sql_data = self::sqlData($cols);
      $insert_cols = implode(', ', $cols);
      $insert_placeholders = implode(', ', $sql_data['insert']);
      $sql[] = <<<EOD
INSERT INTO $table ($insert_cols) VALUES ($insert_placeholders);
EOD;
    }
    $output = implode("\n", $sql);
    return $output ? $output : '';
  }

  public static function update($table = '', $data) {
    $sql = array();
    $tables = self::$conf['default_values'];
    foreach ($tables as $table_name => $conf) {
      if (!empty($table) && strtoupper($table) != $table_name) {
        continue;
      }
      $cols = array_keys($conf);
      $sql_data = self::sqlData($cols, $data);
      $values = implode(', ', $sql_data['update']);
      $sql[] = <<<EOD
UPDATE $table t SET $values WHERE t.userid = v_userid;
EOD;
    }
    $output = implode("\n", $sql);
    return $output ? $output : '';
  }

  protected static function sqlData($cols, $data = array()) {
    $sql_data = array('insert' => array(), 'update' => array());
    array_walk($cols, function($col) use(&$sql_data, $data) {
      $sql_col = strtolower($col);
      $sql_data['insert'][$sql_col] = $sql_col == 'userid' ? 'v_userid' : "*$sql_col*";
      if ($sql_col != 'userid') {
        // If value is empty there is no reason to include it in update statement.
        if (empty($data[$sql_col])) {
          return;
        }
        $sql_data['update'][$sql_col] = "t.$sql_col = *$sql_col*";
      }
    });
    return $sql_data;
  }

  public static function replacePlaceholders($sql, $data) {
    $patterns = $replacements = array();
    array_walk($data, function($v, $k) use(&$patterns, &$replacements){
      $patterns[] = '#\\*' . $k . '\\*#';

      if (is_numeric($v) || strlen($v) == 0) {
        $replacements[] = "'$v'";
      }
      else {
        $replacements[] = preg_replace(
          array('#}#', '#^(.*)$#s'),
          array('}}','q\'{$1}\''),
          $v
        );
      }
    });
    return preg_replace($patterns, $replacements, $sql);
  }

}
