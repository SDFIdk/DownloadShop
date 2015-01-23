<?php
/**
 * @file
 * kms_oci_queue_job_blocker.inc.
 * User: mikkel@adapt.dk
 * Date: 09/30/14 - 16:19 PM
 */

/**
 * Class KmsOciQueueJobUserRelations
 *
 * Handles relations between users and jobs.
 * A tool to get affected users by jobs.
 */
class KmsOciQueueJobUserRelations {
  /**
   * Schema name for storing relations.
   */
  const SCHEMA = "kms_oci_queue_job_user_relations";

  /**
   * Save job user relations.
   *
   * @param KmsOciQueueJob $job
   *   Kms oci queue job object.
   * @param array $uids
   *   Drupal user ids.
   */
  public static function save(KmsOciQueueJob $job, array $uids) {
    foreach ($uids as $uid) {
      $job_user_rel = new stdClass();
      $job_user_rel->jid = $job->jid;
      $job_user_rel->uid = $uid;
      drupal_write_record(self::SCHEMA, $job_user_rel);
    }
    watchdog(self::SCHEMA, 'Relations saved for job id: @jid', array('@jid' => $job->jid));
  }

  /**
   * Update job user relations.
   *
   * @param KmsOciQueueJob $job
   *   Kms oci queue job object.
   * @param array $uids
   *   Drupal user ids.
   */
  public static function update(KmsOciQueueJob $job, array $uids) {
    foreach ($uids as $uid) {
      $job_user_rel = new stdClass();
      $job_user_rel->jid = $job->jid;
      $job_user_rel->uid = $uid;
      drupal_write_record(self::SCHEMA, $job_user_rel, 'jid');
    }
    watchdog(self::SCHEMA, 'Relations updated for job id: @jid', array('@jid' => $job->jid));
  }

  /**
   * Get all relations by user id.
   *
   * @param int $uid
   *   Drupal user id.
   *
   * @return mixed
   *   Array (relation rows).
   */
  public static function getByUid(int $uid) {
    return self::getByUids(array($uid));
  }

  /**
   * Get all relations by user id.
   *
   * @param array $uids
   *   Drupal user ids.
   *
   * @return mixed
   *   Array (relation rows).
   */
  public static function getByUids(array $uids) {
    // If no uids are present show empty relations.
    if (empty($uids)) {
      return array();
    }
    $query = db_select(self::SCHEMA, 'r')
      ->fields('r', array('jid'))
      ->groupBy('r.jid')
      ->condition('uid', $uids, 'IN');
    $result = $query->execute()->fetchCol();
    return !empty($result) ? $result : array();
  }

  /**
   * Delete job user relations.
   *
   * @param KmsOciQueueJob $job
   *   Kms oci queue job object.
   */
  public static function delete(KmsOciQueueJob $job) {
    db_delete(self::SCHEMA)
      ->condition('jid', $job->jid)
      ->execute();
    watchdog(self::SCHEMA, 'Relations erased for job id: @jid', array('@jid' => $job->jid));
  }

  /**
   * Delete all relations.
   */
  public static function deleteAll() {
    db_delete(self::SCHEMA)
      ->execute();
    watchdog(self::SCHEMA, 'All relations erased.');
  }

}

/**
 * Class KmsOciQueueJobBlocker
 *
 * Handles blocking of user actions depennding on job/user relations.
 * @see KmsOciQueueJobUserRelations
 */
class KmsOciQueueJobBlocker {

  /**
   * Determine if the users are blocked.
   *
   * @param array $uids
   *   Druapl user ids.
   *
   * @return bool
   *   Are the users blocked?
   */
  public static function usersAreBlocked(array $uids) {
    $relations = KmsOciQueueJobUserRelations::getByUids($uids);
    return !empty($relations);
  }

  /**
   * Determine if user is blocked.
   *
   * @param int $uid
   *   Drupal user id.
   *
   * @return bool
   *   Is the user blocked?
   */
  public static function userIsBlocked($uid) {
    return self::usersAreBlocked(array($uid));
  }
}
