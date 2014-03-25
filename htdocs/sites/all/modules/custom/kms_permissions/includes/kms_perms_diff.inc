<?php
/**
 * @file
 * kms_oci_queue_sql.inc.
 * User: mikkel@adapt.dk
 * Date: 03/25/14 - 10:52 AM
 */

class KmsPermsDiff {

  public static function diffSeparatePerms(EntityMetadataWrapper $w_original, EntityMetadataWrapper $w_new) {
    $perms_original = $perms_new = array(
      'services' => array(),
      'applications' => array(),
    );
    foreach (_kms_permissions_webservice_fields() as $field) {
      $value_original = $w_original->$field->raw();
      $value_new = $w_new->$field->raw();

      if (!empty($value_original[0])) {
        $perms_original['services'] = array_merge(
          $value_original,
          $perms_original['services']
        );
      }
      if (!empty($value_new[0])) {
        $perms_new['services'] = array_merge(
          $value_new,
          $perms_new['services']
        );
      }
    }

    $perms_original['applications'] = $w_original->field_applications->raw();
    $perms_new['applications'] = $w_new->field_applications->raw();
    // We do not trust entity meta data wrapper data
    // and add empty arrays if empty first value.
    if (empty($perms_original['applications'][0])) {
      $perms_original['applications'] = array();
    }
    if (empty($perms_new['applications'][0])) {
      $perms_new['applications'] = array();
    }
    return self::diffPermsArray($perms_original, $perms_new);
  }

  public static function diffPermsArray($perms_original, $perms_new) {
    return array(
      'services' => self::diff(
        $perms_original['services'],
        $perms_new['services']
      ),
      'applications' => self::diff(
        $perms_original['applications'],
        $perms_new['applications']
      ),
    );
  }

  public static function diffBundlePerms(EntityMetadataWrapper $w_original, EntityMetadataWrapper $w_new) {
    $bundle_perms = array(
      'services' => array('add' => array(), 'remove' => array()),
      'applications' => array('add' => array(), 'remove' => array()),
    );

    $bundle_diff = self::diff(
      $w_original->field_access_bundles->raw(),
      $w_new->field_access_bundles->raw()
    );

    $perm_options = array('key_prefix' => FALSE, 'flattened' => TRUE);
    foreach ($bundle_diff['add'] as $bid) {
      $perms = array();
      _kms_permissions_get_permissions_by_bid($bid, $perms, $perm_options);
      if (!empty($perms['services'])) {
        $bundle_perms['services']['add'] = $perms['services'];
      }
      if (!empty($perms['applications'])) {
        $bundle_perms['applications']['add'] = $perms['applications'];
      }
    }
    foreach ($bundle_diff['remove'] as $bid) {
      $perms = array();
      _kms_permissions_get_permissions_by_bid($bid, $perms, $perm_options);
      if (!empty($perms['services'])) {
        $bundle_perms['services']['remove'] = $perms['services'];
      }
      if (!empty($perms['applications'])) {
        $bundle_perms['applications']['remove'] = $perms['applications'];
      }
    }

    return $bundle_perms;
  }

  public static function diff($original, $new) {
    // Get the difference between new and old array.
    $add = array_diff($new, $original);
    $remove = array_diff($original, $new);
    // Make sure that the keys are the same as the values.
    if (!empty($add)) {
      $add = array_combine(array_values($add), $add);
    }
    if (!empty($remove)) {
      $remove = array_combine(array_values($remove), $remove);
    }
    // Return diff add/remove array.
    return array(
      'add' => $add ? $add : array(),
      'remove' => $remove ? $remove : array(),
    );
  }

  public static function diffIsEmpty($diff) {
    if (!empty($diff['add']) || !empty($diff['remove'])) {
      return FALSE;
    }
    return TRUE;
  }

  public static function createOciSqlFromPermDiff($perm_diff, $userid) {
    $output = array();
    foreach ($perm_diff as $perm_type => $perm_diff) {
      $data = array('userid' => $userid);
      switch ($perm_type) {
        case 'services':
          $data['featureinfo'] = 0;
          foreach ($perm_diff['add'] as $sid => $service_values) {
            if (!empty($service_values)) {
              $data['serviceid'] = $sid;
              $data += $service_values;
              $sql = new KmsOciQueueSql('services', $data);
              $output[] = $sql->generate('insert');
            }
          }
          foreach ($perm_diff['remove'] as $sid) {
            $data['serviceid'] = $sid;
            $sql = new KmsOciQueueSql('services', $data);
            $output[] = $sql->generate('delete');
          }
          break;

        case 'applications':
          foreach ($perm_diff['add'] as $gid) {
            $data['groupid'] = $gid;
            $sql = new KmsOciQueueSql('applications', $data);
            $output[] = $sql->generate('insert');
          }
          foreach ($perm_diff['remove'] as $gid) {
            $data['groupid'] = $gid;
            $sql = new KmsOciQueueSql('applications', $data);
            $output[] = $sql->generate('delete');
          }
          break;
      }
    }

    if (!empty($output)) {
      array_unshift($output, $sql->generateHeader());
    }

    // Return all created query lines.
    return implode("\n", $output);
  }

}
