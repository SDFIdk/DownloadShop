<?php
/**
 * @file
 * panel_edit_user_profile.features.inc
 */

/**
 * Implements hook_default_config_pages_type().
 */
function panel_edit_user_profile_default_config_pages_type() {
  $items = array();
  $items['my_products_info'] = entity_import('config_pages_type', '{
    "type" : "my_products_info",
    "label" : "My products info",
    "weight" : "0",
    "data" : {
      "menu" : { "path" : "admin\\/config\\/people\\/my-products-info", "type" : "6" },
      "context" : { "group" : {
          "config_pages:language" : 0,
          "config_pages:host" : 0,
          "config_pages:domain" : 0
        }
      }
    },
    "metatags" : [],
    "rdf_mapping" : []
  }');
  $items['my_profile_info'] = entity_import('config_pages_type', '{
    "type" : "my_profile_info",
    "label" : "My profile info",
    "weight" : "0",
    "data" : {
      "menu" : { "path" : "admin\\/config\\/people\\/my-profile-info", "type" : "6" },
      "context" : { "group" : {
          "config_pages:language" : 0,
          "config_pages:host" : 0,
          "config_pages:domain" : 0
        }
      }
    },
    "metatags" : [],
    "rdf_mapping" : []
  }');
  $items['my_profile_info_subuser'] = entity_import('config_pages_type', '{
    "type" : "my_profile_info_subuser",
    "label" : "My profile info (subuser)",
    "weight" : "0",
    "data" : {
      "menu" : {
        "path" : "admin\\/config\\/people\\/my-profile-info-subuser",
        "type" : "6"
      },
      "context" : { "group" : {
          "config_pages:language" : 0,
          "config_pages:host" : 0,
          "config_pages:domain" : 0
        }
      }
    },
    "metatags" : [],
    "rdf_mapping" : []
  }');
  $items['my_subscriptions_info'] = entity_import('config_pages_type', '{
    "type" : "my_subscriptions_info",
    "label" : "My subscriptions info",
    "weight" : "0",
    "data" : {
      "menu" : { "path" : "admin\\/config\\/people\\/my-subscriptions-info", "type" : "6" },
      "context" : { "group" : {
          "config_pages:language" : 0,
          "config_pages:host" : 0,
          "config_pages:domain" : 0
        }
      }
    },
    "metatags" : [],
    "rdf_mapping" : []
  }');
  $items['my_subscriptions_rss'] = entity_import('config_pages_type', '{
    "type" : "my_subscriptions_rss",
    "label" : "My subscriptions RSS",
    "weight" : "0",
    "data" : {
      "menu" : { "path" : "admin\\/config\\/people\\/my-subscriptions-rss", "type" : "6" },
      "context" : { "group" : {
          "config_pages:language" : 0,
          "config_pages:host" : 0,
          "config_pages:domain" : 0
        }
      }
    },
    "metatags" : [],
    "rdf_mapping" : []
  }');
  $items['my_subusers_info'] = entity_import('config_pages_type', '{
    "type" : "my_subusers_info",
    "label" : "My subusers info",
    "weight" : "0",
    "data" : {
      "menu" : { "path" : "admin\\/config\\/people\\/my-subusers-info", "type" : "6" },
      "context" : { "group" : {
          "config_pages:language" : 0,
          "config_pages:host" : 0,
          "config_pages:domain" : 0
        }
      }
    },
    "metatags" : [],
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function panel_edit_user_profile_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
