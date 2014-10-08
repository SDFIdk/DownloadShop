<?php
/**
 * @file
 * kms_oci_queue_job_blocker.inc.
 * User: mikkel@adapt.dk
 * Date: 09/30/14 - 16:19 PM
 */

class KmsOciQueueJobUserRelations {

  protected $ignoredJobTypes = array(
    'permissions_attach',
  );

  public static function save(KmsOciQueueJob $job, array $uids) {

  }

  public static function getByUids($uids) {

  }

  public static function delete($jid) {

  }

}


class KmsOciQueueJobBlocker {
  protected function userIsBlocked($uid) {
    $relations = KmsOciQueueJobUserRelations::getByUids(array($uid));
    return !empty($relations);
  }
}


/**

Architecture:
KmsOciQueueJobUserRelations : id, jid, uid, status
Ignore relations of job/uid if the job is of the type: permissions_attach
 */