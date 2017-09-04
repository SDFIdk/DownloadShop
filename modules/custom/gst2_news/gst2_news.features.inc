<?php
/**
 * @file
 * gst2_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function gst2_news_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function gst2_news_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function gst2_news_image_default_styles() {
  $styles = array();

  // Exported image style: news.
  $styles['news'] = array(
    'name' => 'news',
    'label' => 'news',
    'effects' => array(
      3 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 180,
          'height' => 140,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_default_mailchimp_signup().
 */
function gst2_news_default_mailchimp_signup() {
  $items = array();
  $items['newsletter'] = entity_import('mailchimp_signup', '{
    "name" : "newsletter",
    "mc_lists" : {
      "79cf358102" : "79cf358102",
      "fc2b05567b" : "fc2b05567b",
      "9cb71e8040" : "9cb71e8040",
      "8877f51385" : "8877f51385"
    },
    "mode" : "1",
    "title" : "Newsletter",
    "settings" : {
      "path" : "",
      "submit_button" : "Tilmeld",
      "confirmation_message" : "You have been successfully subscribed.",
      "destination" : "",
      "mergefields" : {
        "EMAIL" : {
          "name" : "Email Address",
          "req" : true,
          "field_type" : "email",
          "public" : true,
          "show" : true,
          "order" : "1",
          "default" : "",
          "helptext" : "",
          "size" : "25",
          "tag" : "EMAIL",
          "id" : 0
        },
        "FNAME" : 0,
        "LNAME" : 0,
        "TYPE1" : {
          "name" : "Type 1 (private)",
          "req" : false,
          "field_type" : "text",
          "public" : false,
          "show" : true,
          "order" : "4",
          "default" : "",
          "helptext" : "",
          "size" : "25",
          "tag" : "TYPE1",
          "id" : 3
        },
        "TYPE2" : {
          "name" : "Type 2 (private)",
          "req" : false,
          "field_type" : "text",
          "public" : false,
          "show" : true,
          "order" : "5",
          "default" : "",
          "helptext" : "",
          "size" : "25",
          "tag" : "TYPE2",
          "id" : 4
        },
        "TYPE3" : {
          "name" : "Type 3 (private)",
          "req" : false,
          "field_type" : "text",
          "public" : false,
          "show" : true,
          "order" : "6",
          "default" : "",
          "helptext" : "",
          "size" : "25",
          "tag" : "TYPE3",
          "id" : 5
        },
        "TYPE4" : {
          "name" : "Type 4 (private)",
          "req" : false,
          "field_type" : "text",
          "public" : false,
          "show" : true,
          "order" : "7",
          "default" : "",
          "helptext" : "",
          "size" : "25",
          "tag" : "TYPE4",
          "id" : 6
        }
      },
      "description" : "",
      "doublein" : 0,
      "send_welcome" : 0,
      "include_interest_groups" : 0
    },
    "metatags" : [],
    "rdf_mapping" : []
  }');
  return $items;
}
