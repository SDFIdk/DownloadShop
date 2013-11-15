<?php
/**
 * kms_oci_queue.inc.
 * User: mikkel@adapt.dk
 * Date: 11/15/13 - 9:47 PM
 */


class KmsOciQueue extends SystemQueue {

  public function __construct($name) {
    parent::__construct($name);
  }

  public function createItem($data) {
    watchdog('queue', 'Item created : %data', array('%data' => print_r($data, TRUE)));
    $query = db_insert('queue', array('return' => Database::RETURN_INSERT_ID))
      ->fields(array(
        'name' => $this->name,
        'data' => serialize($data),
        // We cannot rely on REQUEST_TIME because many items might be created
        // by a single request which takes longer than 1 second.
        'created' => time(),
      ));
    $result = $query->execute();
    $success = (bool) $result;
    if($success) {
      kms_oci_queue_log($result, 'Job created');
    }

    return $success;
  }

  public function numberOfItems() {
    $count = parent::numberOfItems();
  }

  public function claimItem($lease_time = 3600) {
    $return_value = parent::claimItem($lease_time);
    watchdog('queue', 'Item claimed %item (lease time = %lease)', array('%item' => print_r($return_value, TRUE), '%lease' => $lease_time));
    return $return_value;
  }

  public function deleteItem($item) {
    watchdog('queue', 'Item deleted : %item', array('%item' => print_r($item, TRUE)));
    parent::deleteItem($item);
  }

  public function releaseItem($item) {
    watchdog('queue', 'Item released : %item', array('%item' => print_r($item, TRUE)));
    parent::releaseItem($item);
  }

  public function createQueue() {
    watchdog('queue', 'Queue created ');
    parent::createQueue();
  }

  public function deleteQueue() {
    watchdog('queue', 'Queue deleted');
    parent::deleteQueue();
  }
}