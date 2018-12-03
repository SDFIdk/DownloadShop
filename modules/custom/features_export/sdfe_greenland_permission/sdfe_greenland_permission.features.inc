<?php
/**
 * @file
 * sdfe_greenland_permission.features.inc
 */

/**
 * Implements hook_default_config_pages_type().
 */
function sdfe_greenland_permission_default_config_pages_type() {
  $items = array();
  $items['greenland_permissions'] = entity_import('config_pages_type', '{
    "type" : "greenland_permissions",
    "label" : "Greenland permissions",
    "weight" : "0",
    "data" : {
      "menu" : { "path" : "admin\\/config\\/greenland", "type" : "6" },
      "context" : { "group" : {
          "config_pages:language" : 0,
          "config_pages:host" : 0,
          "config_pages:domain" : 0
        }
      }
    },
    "rdf_mapping" : []
  }');
  return $items;
}
