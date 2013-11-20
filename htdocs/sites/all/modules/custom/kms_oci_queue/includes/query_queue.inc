<?php
/**
 * query_queue.inc.
 * User: mikkel@adapt.dk
 * Date: 11/15/13 - 9:47 PM
 */

class QueryQueue extends SystemQueue {

  public function __construct($name) {
    parent::__construct($name);
  }

  public function createItem($data) {
    $query = db_insert('queue', array('return' => Database::RETURN_INSERT_ID))
      ->fields(array(
        'name' => $this->name,
        'data' => serialize($data),
        // We cannot rely on REQUEST_TIME because many items might be created
        // by a single request which takes longer than 1 second.
        'created' => time(),
      ));
    $item_id = $query->execute();
    KmsOciQueueJobFactory::get($item_id);
    return $item_id;
  }

  public function numberOfItems() {
    return parent::numberOfItems();
  }

  public function claimItem($lease_time = 3600) {
    return parent::claimItem($lease_time);
  }

  public function deleteItem($item) {
    parent::deleteItem($item);
  }

  public function releaseItem($item) {
    parent::releaseItem($item);
  }

  public function createQueue() {
    parent::createQueue();
  }

  public function deleteQueue() {
    parent::deleteQueue();
  }
}