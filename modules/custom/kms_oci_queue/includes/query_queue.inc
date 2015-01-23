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
    return $item_id;
  }

  public function numberOfItems() {
    return parent::numberOfItems();
  }

  public function claimItem($lease_time = 30) {
    // Claim an item by updating its expire fields. If claim is not successful
    // another thread may have claimed the item in the meantime. Therefore loop
    // until an item is successfully claimed or we are reasonably sure there
    // are no unclaimed items left.
    while (TRUE) {
      $item = db_query_range('SELECT data, item_id FROM {queue} q WHERE expire = 0 AND name = :name ORDER BY created, item_id ASC', 0, 1, array(':name' => $this->name))->fetchObject();
      if ($item) {
        // Try to update the item. Only one thread can succeed in UPDATEing the
        // same row. We cannot rely on REQUEST_TIME because items might be
        // claimed by a single consumer which runs longer than 1 second. If we
        // continue to use REQUEST_TIME instead of the current time(), we steal
        // time from the lease, and will tend to reset items before the lease
        // should really expire.
        $update = db_update('queue')
          ->fields(array(
            'expire' => time() + $lease_time,
          ))
          ->condition('item_id', $item->item_id)
          ->condition('expire', 0);
        // If there are affected rows, this update succeeded.
        if ($update->execute()) {
          $item->data = unserialize($item->data);
          return $item;
        }
      }
      else {
        // No items currently available to claim.
        return FALSE;
      }
    }
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