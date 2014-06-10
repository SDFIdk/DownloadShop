<?php
/**
 * @file
 * kms_oci_queue_sql.inc.
 * User: mikkel@adapt.dk
 * Date: 06/06/14 - 10:52 AM
 */

class KmsPermsBoundingBoxData {

  protected function setup() {
    return array(
      'minx' => array(
        'def_val' => 0,
        'boundary_rule' => 'min',
      ),
      'miny' => array(
        'def_val' => 0,
        'boundary_rule' => 'min',
      ),
      'maxx' => array(
        'def_val' => 0,
        'boundary_rule' => 'max',
      ),
      'maxy' => array(
        'def_val' => 0,
        'boundary_rule' => 'max',
      ),
      'maxpixelwidth' => array(
        'def_val' => 0,
        'boundary_rule' => 'max',
      ),
      'maxpixelheight' => array(
        'def_val' => 0,
        'boundary_rule' => 'max',
      ),
      'featureinfo' => array(
        'def_val' => 0,
        'boundary_rule' => 'max',
      ),
    );
  }

  public function __set($name, $value) {
    $cast2int = array('featureinfo');
    $value = in_array($name, $cast2int) ? (int) $value : $value;
    $defaults = $this->getDefaultValues();
    if (isset($defaults[$name])) {
      $this->{$name} = $value;
    }
  }

  protected function getSetupDataSet($type) {
    $data_set = array();
    foreach ($this->setup() as $prop => $conf) {
      if (isset($conf[$type])) {
        $data_set[$prop] = $conf[$type];
      }
    }
    return $data_set;
  }

  public function getProperties() {
    return array_keys($this->setup());
  }

  public function getDefaultValues() {
    return $this->getSetupDataSet('def_val');
  }

  public function getBoundaryRules() {
    return $this->getSetupDataSet('boundary_rule');
  }

}

abstract class KmsPermsBoundingBoxInstance {

  protected $data = array();
  protected $fieldPrefix = '';

  public function __construct(EntityMetadataWrapper $mdw, $field_prefix, $properties = array()) {
    $this->fieldPrefix = $field_prefix;
    $bounding_box_data = new KmsPermsBoundingBoxData();

    if (empty($properties)) {
      $properties = $bounding_box_data->getProperties();
    }
    foreach ($properties as $property) {
      $field = sprintf('%s_%s', $field_prefix, $property);
      $bounding_box_data->{$property} = $mdw->$field->raw();
    }
    $this->data = (array) $bounding_box_data;
  }

  public function getFields() {
    $bounding_box_data = new KmsPermsBoundingBoxData();
    $properties = $bounding_box_data->getProperties();
    $prefix = $this->fieldPrefix;
    array_walk($properties, function(&$p) use ($prefix) {
      $p = $prefix . '_' . $p;
    });
    return $properties;
  }

  public function getData() {
    return $this->data;
  }

}

class KmsPermsBoundingBoxBundle extends KmsPermsBoundingBoxInstance {

  public function __construct($ident) {
    if (is_int($ident)) {
      $node = node_load($ident);
      $mdw = entity_metadata_wrapper('node', $node);
    }
    else {
      $mdw = $ident;
    }
    parent::__construct($mdw, 'field_bundle');
  }

}
