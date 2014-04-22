<?php
/**
 * @file
 * kms_oci_queue_sql.inc.
 * User: mikkel@adapt.dk
 * Date: 03/25/14 - 10:52 AM
 */

class KmsPermsDiff {

  public static function defaultDiff() {
    return array(
      'services' => array(
        'add' => array(),
        'remove' => array(),
      ),
      'applications' => array(
        'add' => array(),
        'remove' => array(),
      ),
    );
  }

  public static function diffSeparatePerms(EntityMetadataWrapper $w_original, EntityMetadataWrapper $w_new) {
    $perms = self::constructSeparatePerms($w_original, $w_new);
    return self::diffPermsArray($perms['original'], $perms['new']);
  }
  
  public static function constructSeparatePerms(EntityMetadataWrapper $w_original, EntityMetadataWrapper $w_new) {
    $perms_template = array(
      'services' => array(),
      'applications' => array(),
    );
    $perms = array(
      'original' => $perms_template,
      'new' => $perms_template,
    );
    foreach (_kms_permissions_webservice_fields() as $field) {
      $value_original = $w_original->$field->raw();
      $value_new = $w_new->$field->raw();

      if (!empty($value_original[0])) {
        $perms['original']['services'] = array_merge(
          $value_original,
          $perms['original']['services']
        );
      }
      if (!empty($value_new[0])) {
        $perms['new']['services'] = array_merge(
          $value_new,
          $perms['new']['services']
        );
      }
    }

    $perms['original']['applications'] = $w_original->field_applications->raw();
    $perms['new']['applications'] = $w_new->field_applications->raw();
    // We do not trust entity meta data wrapper data
    // and add empty arrays if empty first value.
    if (empty($perms['original']['applications'][0])) {
      $perms['original']['applications'] = array();
    }
    if (empty($perms['new']['applications'][0])) {
      $perms['new']['applications'] = array();
    }

    return $perms;
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

  public static function createOciSqlFromPermDiff($perm_diff, $userid, $ignore_header = FALSE) {
    $output = array();
    $wms_ids = kms_permissions_get_service_ids_by_type('wms');
    foreach ($perm_diff as $perm_type => $perm_diff) {
      switch ($perm_type) {
        case 'services':
          foreach ($perm_diff['add'] as $sid => $service_values) {
            if (empty($service_values)) {
              continue;
            }
            $data = array(
              'userid' => $userid,
              'serviceid' => $sid,
              'featureinfo' => 0,
            );

            $data += $service_values;
            // If a service is a wms service then set feature info to 1.
            if (in_array($sid, $wms_ids)) {
              $data['featureinfo'] = 1;
            }

            $sql = new KmsOciQueueSql('services', $data);
            $output[] = $sql->generate('insert');
          }
          foreach ($perm_diff['remove'] as $sid) {
            $data = array('userid' => $userid);
            $data['serviceid'] = $sid;
            $sql = new KmsOciQueueSql('services', $data);
            $output[] = $sql->generate('delete');
          }
          break;

        case 'applications':
          foreach ($perm_diff['add'] as $gid) {
            $data = array(
              'userid' => $userid,
              'groupid' => $gid,
            );
            $sql = new KmsOciQueueSql('applications', $data);
            $output[] = $sql->generate('insert');
          }
          foreach ($perm_diff['remove'] as $gid) {
            $data = array(
              'userid' => $userid,
              'groupid' => $gid,
            );
            $sql = new KmsOciQueueSql('applications', $data);
            $output[] = $sql->generate('delete');
          }
          break;
      }
    }

    if (!empty($output) && !$ignore_header) {
      array_unshift($output, $sql->generateHeader());
    }

    // Return all created query lines.
    return implode("\n", $output);
  }

}

class KmsPermsDiffDb {

  protected static function constructSchemaName($type) {
    return "kms_permissions_diff_$type";
  }

  protected static function constructIdentifier($type) {
    switch ($type) {
      case 'user':
        $id = 'uid';
        break;

      case 'node':
        $id = 'nid';
        break;
    }
    return !empty($id) ? $id : FALSE;
  }

  public static function save($id, $diff_data, $type) {
    $id_field = self::constructIdentifier($type);
    if ($id_field) {
      $diff = array(
        $id_field => $id,
        'diff' => $diff_data,
      );
      if (self::loadDiff($id, $type)) {
        self::update((object) $diff, $type);
      }
      else {
        self::insert((object) $diff, $type);
      }
    }

  }

  public static function insert($diff, $type){
    $diff->timestamp = time();
    $schema = self::constructSchemaName($type);
    if (drupal_get_schema($schema)) {
      return drupal_write_record($schema, $diff);
    }
    return FALSE;
  }

  public static function update($diff, $type){
    $diff->timestamp = time();
    $schema = self::constructSchemaName($type);
    $id_field = self::constructIdentifier($type);
    if (drupal_get_schema($schema)) {
      return drupal_write_record($schema, $diff, $id_field);
    }
    return FALSE;
  }

  public static function loadDiff($id, $type){
    $schema = self::constructSchemaName($type);
    $id_field = self::constructIdentifier($type);
    $query = db_select($schema, 'pd');
    $query->fields('pd');
    $query->condition('pd.' . $id_field, $id, '=');
    $result = $query->execute()->fetchObject();
    if (is_object($result)) {
      return unserialize($result->diff);
    }
    return FALSE;
  }

  public static function deleteDiff($id, $type){
    $schema = self::constructSchemaName($type);
    $id_field = self::constructIdentifier($type);
    $num_deleted = db_delete($schema)
      ->condition($id_field, $id)
      ->execute();
    return (bool) $num_deleted;
  }

}