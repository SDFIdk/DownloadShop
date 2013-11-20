<?php
/**
 * kms_oci_queue_job.inc.
 * User: mikkel@adapt.dk
 * Date: 11/16/13 - 12:16 PM
 */

class KmsOciQueueJob {

  public $jid = 0;
  public $created;
  public $status;
  public $info;
  private $queueItem;
  private $log;
  private $type;

  static public $types = array(
    'single' => 'kms_oci_queue_query',
    'multi' => 'kms_oci_queue_multi_query_creator',
  );

  public function __construct($jid) {
    $this->setJid($jid);
    $this->setQueueItem($this->loadQueueItem());
    $this->setType();
    $this->setCreated();
    $this->setInfo();
    $this->setStatus();
    $this->setLog($this->loadLog());
  }

  private function setJid($jid){
    $this->jid = $jid;
  }

  private function setCreated(){
    $this->created = $this->queueItem->created;
  }

  private function setQueueItem($item){
    $this->queueItem = $item;
  }

  private function setLog($log){
    $this->log = $log;
  }

  private function setType(){
    $this->type = self::typeFromQueueName($this->queueItem->name);
  }

  private function setInfo(){
    $this->info = '';
    switch($this->type) {
      case 'single':
        $this->info = 'jeg er single';
        break;
      case 'multi':
        if(property_exists($this->queueItem, 'data') && !empty($this->queueItem->data['action'])) {
          $this->info = $this->queueItem->data['action'];
        }
        break;
    }
  }

  private function setStatus() {
    $status = KmsOciQueueJobStatus::load($this->jid);
    $this->status = $status;
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
    $result = $query->execute()->fetchAllAssoc('oqid');
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

  public static function create($type, $params) {
    $queue_name = self::queueNameFromType($type);
    if(empty($queue_name)) {
      return FALSE;
    }
    $queue = DrupalQueue::get($queue_name);
    $jid = $queue->createItem($params);
    KmsOciQueueJobStatus::save($jid, self::STATUS_READY);
    self::log($jid, t('Job created'));
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

  public static function typeFromQueueName($queue_name){
    $queues = array_flip(self::$types);
    return !empty($queues[$queue_name]) ? $queues[$queue_name] : '';
  }

  public static function queueNameFromType($type){
    return !empty(self::$types[$type]) ? self::$types[$type] : '';
  }

}


class KmsOciQueueJobStatus {
  const STATUS_READY = 0;
  const STATUS_PROCESSING = 1;
  const STATUS_FAILED = -1;

  public static function save($jid, $status){
    $record = new stdClass();
    $record->jid = $jid;
    $record->status = $status;
    $record->timestamp = time();
    drupal_write_record('kms_oci_queue_job_status', $record);
  }

  public static function load($jid){
    $query = db_select('kms_oci_queue_job_status', 'js');
    $query->fields('js');
    $query->condition('js.jid', $jid, '=');
    $result = $query->execute()->fetchObject();
    if($result) {
      $result->message = self::status2human($result->status);
    }
    return $result;
  }

  private static function status2human($status) {
    $statuses = self::statuses();
    return $statuses[$status];
  }

  private static function statuses() {
    return array(
      self::STATUS_READY => t('Ready'),
      self::STATUS_PROCESSING => t('Processing'),
      self::STATUS_FAILED => t('Failed'),
    );
  }

}



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