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
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "kms_mapwidget", "commerce_checkout", "entity" ],
      "ON" : { "commerce_order_update" : [] },
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
      "OWNER" : "rules",
      "REQUIRES" : [ "kms_mapwidget", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
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
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "kms_mapwidget" ],
      "ON" : { "kms_mapwidget_fme_callback_event" : [] },
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
  $items['rules_fme_failure_callback'] = entity_import('rules_config', '{ "rules_fme_failure_callback" : {
      "LABEL" : "FME failure callback",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "php", "kms_mapwidget" ],
      "ON" : { "kms_mapwidget_fme_callback_event_failure" : [] },
      "DO" : [
        { "mail" : {
            "to" : "[user:mail]",
            "subject" : "Ordre [order:order-number]: Brugerdefineret udtr\\u00e6k fejlede ( admin-besked )",
            "message" : "Der skete en fejl ifm. generering af brugerdefineret udtr\\u00e6k fra Kortforsyningen\\/Download.\\r\\n\\r\\nDetaljer om brugeren :\\r\\nBrugernavn: [user:name]\\r\\nEmail: [user:mail]\\r\\nNavn: [user:field-address:first-name] [user:field-address:last-name]\\r\\n\\r\\nDetaljer om ordre :\\r\\nOrdrenummer : [order:order-number]\\r\\nOrdredato: [order:created]\\r\\n\\r\\nDetaljer om fejlen :\\r\\n\\u003C?php print_r( $statusmessage )?\\u003E\\r\\n",
            "language" : [ "" ]
          }
        },
        { "mail" : {
            "to" : "[user:mail]",
            "subject" : "Ordre [order:order-number]: Et brugerdefineret udtr\\u00e6k fejlede",
            "message" : "Der skete en fejl i forbindelse med generering af brugerdefineret udtr\\u00e6k fra Kortforsyningen\\/Download.\\r\\n\\r\\nDette kan skyldes en midlertidig fejl i udtr\\u00e6kssystemet, s\\u00e5 det er en god ide at fors\\u00f8ge igen. F\\u00f8r du g\\u00f8r det kan du evt. tjekke om der er generelle driftsforstyrrelser p\\u00e5 www.kortforsyningen.dk\\r\\n\\r\\nHvis du oplever at fejlen opst\\u00e5r gentagne gange, s\\u00e5 vil vi gerne h\\u00f8re fra dig. Skriv en mail til info@mim.dk og husk at angive ordre-nummer ([order:order-number]), jobnr. ( \\u003C?php echo $statusmessage-\\u003Eid ?\\u003E ), navn p\\u00e5 geodatas\\u00e6ttet og en beskrivelse af problemet.\\r\\n\\r\\nDu kan se en oversigt over dine ordrer p\\u00e5 denne side: [site:url]mine\\/downloads",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_login_in_checkout'] = entity_import('rules_config', '{ "rules_login_in_checkout" : {
      "LABEL" : "Login in checkout",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-10",
      "OWNER" : "rules",
      "REQUIRES" : [ "kms_mapwidget", "rules" ],
      "ON" : { "user_login" : [] },
      "IF" : [
        { "kms_mapwidget_run_once_condition" : { "run_once_tag" : "CHECKOUT_LOGIN" } }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "Du er nu logget p\\u00e5", "repeat" : 0 } }
      ]
    }
  }');
  return $items;
}
