<?php
/**
 * kms_oci_queue_job.inc.
 * User: mikkel@adapt.dk
 * Date: 11/16/13 - 12:16 PM
 */

class KmsOciQueueJob {

  const STATUS_WAITING = 0;
  const STATUS_PROCESSING = 1;
  const STATUS_FAILED = 2;
  const STATUS_DONE = 3;

  public static $queues = array(
    'creator' => array(
      'name' => 'kms_oci_queue_query_creator',
      'class' => 'QueryQueue',
    ),
    'executor' => array(
      'name' => 'kms_oci_queue_query',
      'class' => 'SystemQueue',
    ),
  );

  public $jid = 0;
  public $created;
  public $status;
  public $info;
  public $queryNum;
  private $queueItem;
  private $job;



  public function __construct($jid) {
    $this->setJid($jid);
    $this->setJob();
    $this->setQueueItem($this->loadQueueItem());
    $this->setCreated();
    $this->setInfo();
    $this->setStatus();
    $this->setQueryNum();
  }

  private function setJid($jid){
    $this->jid = $jid;
  }

  private function setJob(){
    $this->job = KmsOciQueueJobDb::loadJob($this->jid);
  }

  private function setCreated(){
    $this->created = $this->job->created;
  }

  private function setQueueItem($item){
    $this->queueItem = $item;
  }

  private function setInfo(){
    $this->info = '';
    if(property_exists($this->queueItem, 'data') && !empty($this->queueItem->data['action'])) {
      $this->info = $this->queueItem->data['action'];
    }
  }

  public function getLog($mode = 'all') {
    return $this->loadLog($mode);
  }

  private function setStatus() {
    $this->status = (object)array(
      'status' => $this->job->status,
      'message' => $this->job->message,
    );
  }

  private function setQueryNum() {
    $this->queryNum = $this->job->query_num;
  }

  private function loadLog($mode = 'all') {
    $query = db_select('kms_oci_queue_log', 'ql');
    $query->fields('ql');
    $query->condition('ql.jid', $this->jid, '=');
    $query->orderBy('timestamp', 'DESC');
    switch($mode) {
      case 'latest':
        $query->range(0,1);
        break;
      case 'all':
        break;
    }
    $result = $query->execute()->fetchAllAssoc('lid');
    return $result ? $result : array();
  }

  private function loadQueueItem() {
    $query = db_select('queue', 'q');
    $query->fields('q');
    $query->condition('q.item_id', $this->jid, '=');
    $result = $query->execute()->fetchObject();

    if(is_object($result) && !empty($result->data)){
      $result->data = unserialize($result->data);
    }
    return $result;
  }

  public static function create($params) {
    $queue = DrupalQueue::get(self::$queues['creator']['name']);
    $job = new stdClass();
    $job->jid = $queue->createItem($params);
    $job->status = KmsOciQueueJob::STATUS_WAITING;
    $job->created = time();
    $job_saved = KmsOciQueueJobDb::insertJob($job);
    if ($job_saved) {
      self::log($job->jid, t('Job %jid created'), array('%jid' => $job->jid));
    }
  }

  public function setState($state){

  }

  public function delete() {
    // Delete queue item;
    $queue = DrupalQueue::get($this->queueItem->name);
    $queue->deleteItem((object)array('item_id' => $this->jid));
    // Delete job from job table.
    KmsOciQueueJobDb::deleteJob($this->jid);
    // Delete related log entries.
    db_delete('kms_oci_queue_log')
      ->condition('jid', $this->jid)
      ->execute();
  }

  public static function log($jid, $message, $variables = array(), $severity = WATCHDOG_INFO) {
    global $user;

    $record = new stdClass();
    $record->jid = $jid;
    $record->uid = $user->uid;
    $record->message = $message;
    $record->variables = $variables;
    $record->severity = $severity;
    $record->timestamp = time();
    drupal_write_record('kms_oci_queue_log', $record);
    watchdog(implode(':', array(KMS_OCI_QUEUE_PREFIX, $jid)), $message, $variables, $severity);
  }

  public static function status2human($status) {
    $statuses = self::statuses();
    return $statuses[$status];
  }

  private static function statuses() {
    return array(
      self::STATUS_WAITING => t('Waiting'),
      self::STATUS_PROCESSING => t('Processing'),
      self::STATUS_FAILED => t('Failed'),
    );
  }
}

class KmsOciQueueJobDb {

  public static function insertJob($job){
    $job->timestamp = time();
    return drupal_write_record('kms_oci_queue_job', $job);
  }

  public static function updateJob($job){
    return drupal_write_record('kms_oci_queue_job', $job, 'jid');
  }

  public static function loadJob($jid){
    $query = db_select('kms_oci_queue_job', 'j');
    $query->fields('j');
    $query->condition('j.jid', $jid, '=');
    $result = $query->execute()->fetchObject();
    if($result) {
      $result->message = KmsOciQueueJob::status2human($result->status);
    }
    return $result;
  }

  public static function deleteJob($jid){
    db_delete('kms_oci_queue_job')
      ->condition('jid', $jid)
      ->execute();
  }

}

//class KmsOciQueueJobStatus {
//  const STATUS_READY = 0;
//  const STATUS_PROCESSING = 1;
//  const STATUS_FAILED = 2;
//
//  public static function save($jid, $status){
//    $record = new stdClass();
//    $record->jid = $jid;
//    $record->status = $status;
//    $record->timestamp = time();
//    drupal_write_record('kms_oci_queue_job', $record);
//  }
//
//  public static function load($jid){
//    $query = db_select('kms_oci_queue_job', 'j');
//    $query->fields('js');
//    $query->condition('js.jid', $jid, '=');
//    $result = $query->execute()->fetchObject();
//    if($result) {
//      $result->message = self::status2human($result->status);
//    }
//    return $result;
//  }
//
//  public static function delete($jid){
//    db_delete('kms_oci_queue_job')
//      ->condition('jid', $jid)
//      ->execute();
//  }
//
//  private static function status2human($status) {
//    $statuses = self::statuses();
//    return $statuses[$status];
//  }
//
//  private static function statuses() {
//    return array(
//      self::STATUS_READY => t('Ready'),
//      self::STATUS_PROCESSING => t('Processing'),
//      self::STATUS_FAILED => t('Failed'),
//    );
//  }
//
//}


class KmsOciQueueJobFactory {
  private static $jobs;

  public static function get($jid) {
    if (!isset($jobs[$jid])) {
      $job = new KmsOciQueueJob($jid);
      self::$jobs[$job->jid] = $job;
    }
    return self::$jobs[$jid];
  }

}