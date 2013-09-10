<?php
/**
 * @file
 * map_download_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function map_download_rules_default_rules_configuration() {
  $items = array();
  $items['rules_checkout_complete'] = entity_import('rules_config', '{ "rules_checkout_complete" : {
      "LABEL" : "Checkout complete",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-5",
      "REQUIRES" : [ "rules", "kms_mapwidget", "commerce_checkout", "entity" ],
      "ON" : [ "commerce_order_update" ],
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "2" : "2" } }
          }
        },
        { "data_is" : { "data" : [ "commerce-order:status" ], "value" : "checkout_complete" } },
        { "kms_mapwidget_run_once_condition" : { "run_once_tag" : "CHECKOUT_LOGIN" } }
      ],
      "DO" : [
        { "commerce_checkout_complete" : { "commerce_order" : [ "commerce_order" ] } }
      ]
    }
  }');
  $items['rules_create_fme_request'] = entity_import('rules_config', '{ "rules_create_fme_request" : {
      "LABEL" : "Create FME requests",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "kms_mapwidget", "commerce_checkout" ],
      "ON" : [ "commerce_checkout_complete" ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "commerce-order:commerce-line-items" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [ { "kms_mapwidget__fme_request" : { "line_item" : [ "list-item" ] } } ]
          }
        }
      ]
    }
  }');
  $items['rules_fme_callback'] = entity_import('rules_config', '{ "rules_fme_callback" : {
      "LABEL" : "FME callback",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "kms_mapwidget" ],
      "ON" : [ "kms_mapwidget_fme_callback_event" ],
      "DO" : [
        { "mail" : {
            "to" : "[user:mail]",
            "subject" : "Ordre [order:order-number]: Et brugerdefineret udtr\\u00e6k er klar til download",
            "message" : "Et brugerdefineret udtr\\u00e6k er klar til download fra Kortforsyningen\\/Download.\\r\\n\\r\\nDu kan se en oversigt over de bestilte filer og downloade dem p\\u00e5 denne side:\\r\\n\\r\\n[site:url]mine\\/downloads\\r\\n\\r\\n",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
