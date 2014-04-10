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
  protected $mode = '';
  protected $ignoreCols = array();
  protected $workingDir = '';
  protected $filePathDatTmp = '';
  protected $filePathDat = '';
  protected $filePathCtl = '';
  protected $dbResult = FALSE;

  /**
   * Extracts postgres data to be imported in Oracle via Oracle Bulk Loader.
   *
   * @param string $table
   *   Table (postgres view) name.
   * @param string $working_dir
   *   Current working directory.
   * @param string $mode
   *   Drush or web.
   * @param array $ignore_cols
   *   Columns to ignore in extraction.
   */
  public function __construct($table, $working_dir = '.', $mode = 'drush', $ignore_cols = array('uid')) {
    $this->table = $table;
    $this->mode = $mode;
    $this->ignoreCols = $ignore_cols;
    $this->workingDir = $working_dir;
    $this->filePathDatTmp = $this->constructTmpFilename($table);
    $this->filePathDat = $this->constructFilePath($table, '.dat');
    $this->filePathCtl = $this->constructFilePath($table, '.ctl');
    $this->dbResult = $this->dbResult($table);
  }

  /**
   * Extract data and write an Oracle PL/SQL script file.
   */
  public function writeFiles() {
    $this->writeFilesInit();
    $this->writeLines($this->constructCtl(), $this->filePathCtl, FILE_EXISTS_REPLACE);
    $row_count = 0;
    while ($row = $this->dbResult->fetchAssoc()) {
      $fields = array_diff_key($row, array_combine($this->ignoreCols, $this->ignoreCols));
      $this->encloseFields($fields);
      array_push($fields, "~\n");
      $this->writeLines(implode('|', $fields), $this->filePathDatTmp);
      $row_count++;
    }

    $this->writeFilesFinalize($row_count);
  }

  protected function writeFilesInit() {
    if ($this->mode == 'drush') {
      drush_print(dt('Extracing data from: @table...', array('@table' => $this->table)));
    }
  }

  protected function writeFilesFinalize($row_count) {
    $move = file_unmanaged_move(
      $this->filePathDatTmp,
      $this->filePathDat,
      FILE_EXISTS_REPLACE
    );

    if ($move) {
      if ($this->mode == 'drush') {
        drush_print(dt('Data extracted. Rows processed: @row_count.', array('@row_count' => $row_count)));
      };
    }
    else {
      if ($this->mode == 'drush') {
        drush_set_error('file_permissions', dt('Could not create sql file'));
      }
    }
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
   *
   * @return string
   *   Sql.
   */
  protected function constructCtl($additional_fields = array()) {
    $record = $this->dbResult->fetchAssoc();
    $columns = array_diff(array_keys($record), $this->ignoreCols);
    $columns += $additional_fields;
    $fields = implode(', ', $columns);
    $dat_file = $this->filePathDat;
    return <<<EOD
LOAD DATA
INFILE '$dat_file' "str X'7E'"
REPLACE
INTO TABLE $this->table
FIELDS TERMINATED BY '|'  ENCLOSED BY '§'
TRAILING NULLCOLS
($fields)

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
   * Construct filename.
   *
   * @param string $table
   *   Table to extract data from.
   *
   * @param string $ext
   *   File extension.
   *
   * @return string
   *   Name of temporary file.
   */
  protected function constructFilePath($table, $ext = '') {
    return sprintf('%s/%s.%s%s', $this->workingDir, 'kms_perms_extract', $table, $ext);
  }

  /**
   * Write sql lines.
   *
   * @param string $data
   *   Sql lines.
   * @param string $filepath
   *   Path to file.
   * @param string $write_method
   *   Append or replace?
   *
   * @throws Exception
   *   Throw exception if problems updating tmp file.
   */
  protected function writeLines($data, $filepath, $write_method = FILE_APPEND) {
    try {
      file_put_contents($filepath, $data, $write_method);
    }
    catch (Exception $e) {
      throw new Exception('Something went wrong saving ' . $this->filePathDatTmp, 0, $e);
    }
  }

  /**
   * Wrap fields with enclosure character.
   *
   * @param array $fields
   *   The fields to wrap.
   */
  protected function encloseFields(&$fields) {
    array_walk($fields, function(&$v){
      $v = sprintf('§%s§', $v);
    });
  }

}

/**
 * Class KmsPermsExtractSmuser
 */
class KmsPermsExtractSmuser extends KmsPermsExtract {
  /**
   * Extract smuser data.
   */
  public function __construct($working_dir = '.', $mode = 'drush', $ignore_cols = array('uid')) {
    parent::__construct('smuser', $working_dir, $mode, $ignore_cols);
  }

}
/**
 * Class KmsPermsExtractSmuserExtra
 */
class KmsPermsExtractSmuserExtra extends KmsPermsExtract {
  /**
   * Extract smuser_extra data.
   */
  public function __construct($working_dir = '.', $mode = 'drush', $ignore_cols = array('uid')) {
    parent::__construct('smuser_extra', $working_dir, $mode, $ignore_cols);
  }

}
/**
 * Class KmsPermsExtractApplications
 */
class KmsPermsExtractApplications extends KmsPermsExtract {
  /**
   * Extract smusergroup data.
   */
  public function __construct($working_dir = '.', $mode = 'drush', $ignore_cols = array('uid')) {
    parent::__construct('smusergroup', $working_dir, $mode, $ignore_cols);
  }

}
/**
 * Class KmsPermsExtractServices
 */
class KmsPermsExtractServices extends KmsPermsExtract {
  /**
   * Extract userrestrictions2 data.
   */
  public function __construct($working_dir = '.', $mode = 'drush', $ignore_cols = array('uid')) {
    parent::__construct('userrestrictions2', $working_dir, $mode, $ignore_cols);
  }

  /**
   * Implements KmsPermsExtract::extractData.
   *
   * We need bounding box data and featureinfo attached.
   */
  public function writeFiles() {
    $this->writeFilesInit();
    $default_bounding_box = kms_permissions_get_service_bounding_box();
    $additional_fields = array_merge(array_keys($default_bounding_box), array('featureinfo'));
    $wms_ids = kms_permissions_get_service_ids_by_type('wms');

    $this->writeLines($this->constructCtl(), $this->filePathCtl, FILE_EXISTS_REPLACE);

    $row_count = 0;
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
      $this->encloseFields($fields);
      // And a beautiful new line character plus row delimiter.
      array_push($fields, "~\n");
      $this->writeLines(implode('|', $fields), $this->filePathDatTmp);
      $row_count++;
    }

    $this->writeFilesFinalize($row_count);
  }

}
