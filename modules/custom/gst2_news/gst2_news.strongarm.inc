<?php
/**
 * @file
 * gst2_news.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function gst2_news_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mailchimp_api_key';
  $strongarm->value = 'af9070187f0e6d7508175ed0d7e412b7-us10';
  $export['mailchimp_api_key'] = $strongarm;

  return $export;
}
