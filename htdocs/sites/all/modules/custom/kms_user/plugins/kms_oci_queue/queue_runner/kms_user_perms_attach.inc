<?php
/**
 * @file
 * kms_user_perms_attach.inc
 *
 * Provides callback functions run by the queue handling functions.
 * Attaches specified bundles to a given user.
 */


$plugin = array(
  'type' => KMS_OCI_QUEUE_ACTION_PERMS_ATTACH,
  'query_creator_run' => array(
    'function' => 'kms_user_perms_attach_query_creator_run',
  ),
  'query_run' => array(
    'function' => 'kms_user_perms_attach_query_run',
  ),
);

/**
 * Query creator run function.
 *
 * @param int $jid
 *   Kms oci queue job id.
 * @param object $creator_item
 *   Queue item.
 * @param object $exe_queue
 *   Execute queue that is being populated with items.
 *
 * @return int
 *   Number of query lines to be written.
 */
function kms_user_perms_attach_query_creator_run($jid, $creator_item, $exe_queue) {
  $job = KmsOciQueueJobFactory::get($jid);
  $cid = $job->cid;
  $kms_id = $creator_item->params['kms_id'];
  $user_original = $creator_item->params['user_original'];
  $perms_diff = $creator_item->params['perms_diff'];

  $diff = kms_user_perms_attach_create_queue_item_diff($user_original, $perms_diff, $cid);

  // Queue the item.
  $exe_queue_item = array(
    'jid' => $jid,
    'action' => $creator_item->action,
    'diff' => $diff,
    'kms_id' => $kms_id,
    'is_last_item' => TRUE,
  );
  $exe_queue->createItem((object) $exe_queue_item);

}

/**
 * Query run function.
 *
 * Creates query queue items ready to be written in an job file.
 *
 * @param object $item
 *   Queue item.
 *
 * @return string
 *   Generated oracle queries.
 */
function kms_user_perms_attach_query_run($item) {
  return kmsPermsDiff::createOciSqlFromPermDiff($item->diff, $item->kms_id);
}

/**
 * Compare diff against 'original' permissions of a user.
 *
 * @param array $perms_diff
 *   Add/remove diff.
 * @param array $original_perms
 *   The original set of applications and services permissions.
 * @param string $cid
 *   The connection id that decides which schema to use.
 *
 * @return array
 *   The diff result.
 */
function kms_user_perms_attach_compare_diff_and_perms($perms_diff, $original_perms, $cid) {
  $diff = array(
    'services' => array(
      'add' => array(),
      'remove' => array(),
    ),
    'applications' => array(
      'add' => array(),
      'remove' => array(),
    ),
  );
  $perms_oracle_rel = _kms_permissions_perms_oracle_relations();
  foreach ($perms_diff as $perm_type => $perm_diff) {
    $perm_conf = $perms_oracle_rel[$perm_type];
    // If the connection id of the job does not match the one in $perm_conf
    // do nothing.
    if ($cid != $perm_conf['cid']) {
      continue;
    }
    $type_diff = &$diff[$perm_type];
    if (!empty($perm_diff['add'])) {
      // Only use id's in add array that is not already attached to the user.
      $type_diff['add'] = array_diff($perm_diff['add'], $original_perms[$perm_type]);
      // Add bounding box to services.
      if ($perm_type == 'services') {
        foreach ($type_diff['add'] as &$sid) {
          $sid = kms_permissions_get_service_bounding_box($sid);
        }
      }
    }
    // Only use id's in remove array that exists on user.
    if (!empty($perm_diff['remove'])) {
      $type_diff['remove'] = array_filter($perm_diff['remove'], function($id) use ($original_perms, $perm_type){
        return !in_array($id, $original_perms[$perm_type]);
      });
    }
  }
  return $diff;
}

/**
 * The result diff to be used by the query queue.
 *
 * @param object $user_original
 *   User object before any changes to it.
 * @param array $perms_diff
 *   The diff changes to the user permissions.
 * @param string $cid
 *   The connection id that decides which schema to use.
 *
 * @return array
 *   Diff array.
 */
function kms_user_perms_attach_create_queue_item_diff($user_original, $perms_diff, $cid) {

  $w_original = entity_metadata_wrapper('user', $user_original);
  $perm_options = array('key_prefix' => FALSE, 'flattened' => TRUE);

  // Define users original permissions.
  $original_perms['bundles'] = $original_perms['separate'] = array(
    'services' => array(),
    'applications' => array(),
  );
  // Original permissions from bundles (before changes).
  $bundles = $w_original->field_access_bundles->raw();
  $bundles = array_unique(array_merge($bundles, _kms_permissions_get_default_bundles()));
  foreach ($bundles as $bid) {
    _kms_permissions_get_permissions_by_bid($bid, $original_perms['bundles'], $perm_options);
  }
  // Separate services (before changes).
  foreach (_kms_permissions_webservice_fields() as $field) {
    $service_values = $w_original->$field->raw();
    if (!empty($service_values[0])) {
      $original_perms['separate']['services'] = array_merge(
        $original_perms['separate']['services'],
        $service_values
      );
    }
  }
  // Separate applications (before changes).
  $application_values = $w_original->field_applications->raw();
  if (!empty($application_values[0])) {
    $original_perms['separate']['applications'] = array_merge(
      $original_perms['separate']['applications'],
      $application_values
    );
  }

  // Add permissions from perms diff to original perms
  // in order to use those in our calculations.
  $original_perms['separate']['applications'] += $perms_diff['separate']['applications']['add'];
  $original_perms['separate']['services'] += $perms_diff['separate']['services']['add'];
  $original_perms['bundles']['applications'] += $perms_diff['bundles']['applications']['add'];
  $original_perms['bundles']['services'] += $perms_diff['bundles']['services']['add'];

  $diff = array(
    'services' => array(
      'add' => array(),
      'remove' => array(),
    ),
    'applications' => array(
      'add' => array(),
      'remove' => array(),
    ),
  );

  // Compare bundle perms against original separate perms.
  $diff_bundle = kms_user_perms_attach_compare_diff_and_perms(
    $perms_diff['bundles'],
    $original_perms['separate'],
    $cid
  );
  // Compare separate perms against original bundle perms.
  $diff_sep_perms = kms_user_perms_attach_compare_diff_and_perms(
    $perms_diff['separate'],
    $original_perms['bundles'],
    $cid
  );
  // Merge bundle diff with separate perms diff.
  $perms_oracle_rel = _kms_permissions_perms_oracle_relations();
  foreach (array('services', 'applications') as $perm_type) {
    $perm_conf = $perms_oracle_rel[$perm_type];
    foreach (array('add', 'remove') as $action) {
      $diff[$perm_type][$action] = $diff_bundle[$perm_type][$action] + $diff_sep_perms[$perm_type][$action];
      if ($cid == $perm_conf['cid']) {
        // Also use permissions that has been selected
        // in both bundles and separate permissions.
        $diff[$perm_type][$action] += array_intersect($perms_diff['bundles'][$perm_type][$action], $perms_diff['separate'][$perm_type][$action]);
      }
    }
  }

  return $diff;
}