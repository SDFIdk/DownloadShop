<?php
/**
 * @file
 * kms_perms_extract.inc.
 * User: mikkel@adapt.dk
 * Date: 04/09/14 - 14:01 PM
 */

/**
 * Class KmsPermsExtract
 */
abstract class KmsPermsExtract {

  protected $table = '';
  protected $ignoreCols = array();
  protected $tmpFilename = '';
  protected $dbResult = FALSE;

  /**
   * Extracts postgres data to be imported in Oracle via Oracle Bulk Loader.
   *
   * @param string $table
   *   Table (postgres view) name.
   * @param array $ignore_cols
   *   Columns to ignore in extraction.
   */
  public function __construct($table, $ignore_cols = array('uid')) {
    $this->table = $table;
    $this->ignoreCols = $ignore_cols;
    $this->tmpFilename = $this->constructTmpFilename($table);
    $this->dbResult = $this->dbResult($table);
  }

  /**
   * Extract data and write an Oracle PL/SQL script file.
   */
  public function writeFile() {
    $header = $this->constructHeader();
    $this->writeLines($header);

    while ($row = $this->dbResult->fetchAssoc()) {
      $fields = array_diff_key($row, array_combine($this->ignoreCols, $this->ignoreCols));
      array_push($fields, "\n");
      $this->writeLines(implode('|', $fields));
    }

    echo "$this->table: data extracted...\n";
  }

  /**
   * Create database result.
   *
   * @param string $table
   *   Table to extract data from.
   *
   * @return DatabaseStatementInterface
   *   The database result.
   */
  protected function dbResult($table) {
    $sql = db_select($table, 't')
      ->fields('t');
    return $sql->execute();
  }

  /**
   * Construct sql heder lines.
   *
   * @param array $additional_fields
   *   Additional fields to put in header.
   * @param bool $wipe_data
   *   Should data be deleted first?
   *
   * @return string
   *   Sql.
   */
  protected function constructHeader($additional_fields = array(), $wipe_data = TRUE) {
    $record = $this->dbResult->fetchAssoc();
    $columns = array_diff(array_keys($record), $this->ignoreCols);
    $columns += $additional_fields;
    $fields = implode(', ', $columns);
    $wipe = $wipe_data ? sprintf("DELETE FROM %s;", $this->table) : '';
    return <<<EOD
$wipe
LOAD DATA
INFILE *
INTO TABLE $this->table
FIELDS TERMINATED BY '|'
($fields)
BEGINDATA

EOD;
  }

  /**
   * Construct temporary filename.
   *
   * @param string $table
   *   Table to extract data from.
   *
   * @return string
   *   Name of temporary file.
   */
  protected function constructTmpFilename($table) {
    return sprintf('temporary://%s.%s.%s.tmp', 'kms_perms_extract', $table, uniqid());
  }

  /**
   * Write sql lines.
   *
   * @param string $data
   *   Sql lines.
   */
  protected function writeLines($data) {
    if (file_put_contents($this->tmpFilename, $data, FILE_APPEND) === FALSE) {
      die('something went wrong');
    }
  }

}

/**
 * Class KmsPermsExtractSmuser
 */
class KmsPermsExtractSmuser extends KmsPermsExtract {
  /**
   * Extract smuser data.
   */
  public function __construct() {
    parent::__construct('smuser');
  }

}
/**
 * Class KmsPermsExtractSmuserExtra
 */
class KmsPermsExtractSmuserExtra extends KmsPermsExtract {
  /**
   * Extract smuser_extra data.
   */
  public function __construct() {
    parent::__construct('smuser_extra');
  }

}
/**
 * Class KmsPermsExtractApplications
 */
class KmsPermsExtractApplications extends KmsPermsExtract {
  /**
   * Extract smusergroup data.
   */
  public function __construct() {
    parent::__construct('smusergroup');
  }

}
/**
 * Class KmsPermsExtractServices
 */
class KmsPermsExtractServices extends KmsPermsExtract {
  /**
   * Extract userrestrictions2 data.
   */
  public function __construct() {
    parent::__construct('userrestrictions2');
  }

  /**
   * Implements KmsPermsExtract::extractData.
   *
   * We need bounding box data and featureinfo attached.
   */
  public function writeFile() {
    $default_bounding_box = kms_permissions_get_service_bounding_box();
    $additional_fields = array_merge(array_keys($default_bounding_box), array('featureinfo'));
    $wms_ids = kms_permissions_get_service_ids_by_type('wms');

    $header = $this->constructHeader($additional_fields);
    $this->writeLines($header);

    while ($row = $this->dbResult->fetchAssoc()) {
      // If service is of the type: 'wms' then set it to 1 else 0;
      $featureinfo = (int) in_array($row['serviceid'], $wms_ids);
      // Aggregate fields to use.
      // First db result row.
      $fields = array_diff_key($row, array_combine($this->ignoreCols, $this->ignoreCols));
      // Next bounding box data.
      $fields += kms_permissions_get_service_bounding_box($row['serviceid']);
      // Last featureinfo.
      $fields += array('featureinfo' => $featureinfo);
      // And a beautiful new line character.
      array_push($fields, "\n");
      $this->writeLines(implode('|', $fields));
    }

    echo "$this->table: data extracted...\n";
  }

}