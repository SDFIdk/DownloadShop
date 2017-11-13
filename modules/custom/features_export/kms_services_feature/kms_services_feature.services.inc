<?php
/**
 * @file
 * kms_services_feature.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function kms_services_feature_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'users';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'api/v1';
  $endpoint->authentication = array(
    'services_api_key_auth' => array(
      'api_key' => '2jdAT3rg2IxbsMPDm1ioUw',
      'api_key_source' => 'header',
      'user' => 'api',
    ),
  );
  $endpoint->server_settings = array(
    'formatters' => array(
      'json' => TRUE,
      'bencode' => FALSE,
      'jsonp' => FALSE,
      'php' => FALSE,
      'xml' => FALSE,
    ),
    'parsers' => array(
      'application/json' => TRUE,
      'application/x-www-form-urlencoded' => FALSE,
      'application/xml' => FALSE,
      'multipart/form-data' => FALSE,
      'text/xml' => FALSE,
    ),
  );
  $endpoint->resources = array(
    'kms_user' => array(
      'alias' => 'kms',
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'kms_services' => array(
      'alias' => 'kms-services',
      'operations' => array(
        'index' => array(
          'enabled' => '1',
        ),
      ),
      'actions' => array(
        'getApplicationList' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'node' => array(
      'alias' => 'nodes',
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
        'create' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
        'index' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'taxonomy_term' => array(
      'alias' => 'taxonomy-terms',
      'operations' => array(
        'index' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'user' => array(
      'alias' => 'users',
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
        'create' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
        'index' => array(
          'enabled' => '1',
        ),
      ),
      'actions' => array(
        'login' => array(
          'enabled' => '1',
          'settings' => array(
            'services' => array(
              'resource_api_version' => '1.0',
            ),
          ),
        ),
        'logout' => array(
          'enabled' => '1',
          'settings' => array(
            'services' => array(
              'resource_api_version' => '1.0',
            ),
          ),
        ),
      ),
    ),
    'taxonomy_vocabulary' => array(
      'alias' => 'vocabularies',
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
        'index' => array(
          'enabled' => '1',
        ),
      ),
      'actions' => array(
        'retrieveByMachineName' => array(
          'enabled' => '1',
        ),
        'getTree' => array(
          'enabled' => '1',
        ),
      ),
    ),
  );
  $endpoint->debug = 1;
  $export['users'] = $endpoint;

  return $export;
}
