<?php

/**
 * Implements hook_resource().
 */
function kms_service_resources_resource() {
  $definitions = [
    'kms_user' => [
      'operations' => [
        'create' => [
          'help' => 'Create a user',
          'callback' => '_kms_services_resources_user_resource_create',
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments' => ['create'],
          'access arguments append' => FALSE,
          'args' => [
            [
              'name' => 'account',
              'type' => 'array',
              'description' => 'The user object',
              'source' => 'data',
              'optional' => FALSE,
            ],
          ],
        ],
      ],
    ],
    'kms_services' => [
      'operations' => [
        'index' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'callback' => '_kms_services_resources_get_services_list',
          'args' => [
            [
              'name' => 'page',
              'optional' => TRUE,
              'type' => 'int',
              'description' => 'The zero-based index of the page to get, defaults to 0.',
              'default value' => 0,
              'source' => ['param' => 'page'],
            ],
            [
              'name' => 'fields',
              'optional' => TRUE,
              'type' => 'string',
              'description' => 'The fields to get.',
              'default value' => '*',
              'source' => ['param' => 'fields'],
            ],
            [
              'name' => 'parameters',
              'optional' => TRUE,
              'type' => 'array',
              'description' => 'Parameters array',
              'default value' => [],
              'source' => ['param' => 'parameters'],
            ],
            [
              'name' => 'pagesize',
              'optional' => TRUE,
              'type' => 'int',
              'description' => 'Number of records to get per page.',
              'default value' => variable_get('services_node_index_page_size', 20),
              'source' => ['param' => 'pagesize'],
            ],
          ],
          'access arguments' => ['access content'],
        ],
      ],
      'actions' => [
        'getUsersWithSeperateServices' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Get all users that has specified separate services'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments' => ['create'],
          'access arguments append' => TRUE,
          'callback' => '_kms_services_resources_get_uids_by_separate_services',
          'args' => [
            [
              'name' => 'services',
              'type' => 'string',
              'description' => t('Array of services array(\'field_bundle_webservices_geo\' => array(1, 4218, 4458), \'field_bundle_webservices_wms\' => array(1614))'),
              'source' => ['data' => 'services'],
              'optional' => FALSE,
            ],

            [
              'name' => 'column_name',
              'type' => 'string',
              'description' => t('Optional column(s) to be shown. Defaults to value column if the argument is not set.'),
              'source' => ['data' => 'column_name'],
              'optional' => TRUE,
            ],
          ],
        ],
        'alive' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Get all users that has specified separate services'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_services_resources_status_check',
        ],
        'getApplicationList' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Get list of applications from the Oracle server'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_services_resources_get_application_list',
        ],

        'getWebservicesList' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Get list of webservices from the Oracle server'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_services_resources_get_webservices_list',
        ],

        'ftpScanStructure' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Read the structure of the FTP folders.'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_services_resources_ftp_scan_structure',
        ],

        'getAccessBundles' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Find all default and active bundles from a given subtype.'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_services_resources_get_access_bundles',
          'args' => [
            [
              'name' => 'subtype',
              'type' => 'string',
              'description' => t('Subtype'),
              'source' => ['data' => 'subtype'],
              'optional' => FALSE,
            ],
          ],
        ],

        'getPredefinedDataCollections' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Find all default and active bundles from a given subtype.'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_services_resources_get_predefined_data_collections',
          'args' => [
            [
              'name' => 'bundle_nid',
              'type' => 'integer',
              'description' => t('Bundle NID'),
              'source' => ['data' => 'bundle_nid'],
              'optional' => FALSE,
            ],
            [
              'name' => 'key_prefix',
              'type' => 'string',
              'description' => t('Key prefix'),
              'source' => ['data' => 'key_prefix'],
              'optional' => FALSE,
            ],
            [
              'name' => 'flattened',
              'type' => 'boolean',
              'description' => t('Flattened'),
              'source' => ['data' => 'flattened'],
              'optional' => FALSE,
            ],
            [
              'name' => 'permissions',
              'type' => 'array',
              'description' => t('Permissions'),
              'source' => ['data' => 'permissions'],
              'optional' => FALSE,
            ],
            [
              'name' => 'field_access_userdefined_ranges',
              'type' => 'array',
              'description' => t('Field access userdefined ranges'),
              'source' => ['data' => 'field_access_userdefined_ranges'],
              'optional' => FALSE,
            ],
            [
              'name' => 'field_max_download_size',
              'type' => 'array',
              'description' => t('Field max download size'),
              'source' => ['data' => 'field_max_download_size'],
              'optional' => FALSE,
            ],
            [
              'name' => 'bounding_box',
              'type' => 'array',
              'description' => t('Bounding box'),
              'source' => ['data' => 'bounding_box'],
              'optional' => FALSE,
            ],
          ],
        ],

        'getBundle' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Get the bundle and entity metadata'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_services_resources_get_bundle',
          'args' => [
            [
              'name' => 'bundle_nid',
              'type' => 'integer',
              'description' => t('Bundle NID'),
              'source' => ['data' => 'bundle_nid'],
              'optional' => FALSE,
            ],
          ]
        ],

        'getBundlesByItemId' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Get the bundle by item ID'),
          'access callback' => '_kms_services_resources_get_bundles_by_item_id',
          'access arguments append' => TRUE,
          'callback' => '_kms_services_resources_get_bundle',
          'args' => [
            [
              'name' => 'id',
              'type' => 'integer',
              'description' => t('Item ID'),
              'source' => ['data' => 'id'],
              'optional' => FALSE,
            ],
            [
              'name' => 'item_type',
              'type' => 'string',
              'description' => t('Item type'),
              'source' => ['data' => 'item_type'],
              'optional' => FALSE,
            ],
          ],
        ],

        'getPermissionsByBid' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Get the permission by a bundle ID'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_services_resources_get_permissions_by_bid',
          'args' => [
            [
              'name' => 'bundle_nid',
              'type' => 'integer',
              'description' => t('Bundle NID'),
              'source' => ['data' => 'bundle_nid'],
              'optional' => FALSE,
            ],
            [
              'name' => 'permissions',
              'type' => 'array',
              'description' => t('Permissions'),
              'source' => ['data' => 'permissions'],
              'optional' => TRUE,
            ],
            [
              'name' => 'permissions',
              'type' => 'array',
              'description' => t('Permissions'),
              'source' => ['data' => 'permissions'],
              'optional' => TRUE,
            ],
          ],
        ],

        'getUserWithAllFields' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Get the user with all the data'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_services_resources_get_user_with_all_fields',
          'args' => [
            [
              'name' => 'uid',
              'type' => 'integer',
              'description' => t('User ID'),
              'source' => ['data' => 'uid'],
              'optional' => FALSE,
            ],
          ],
        ],

        'getWebserviceFields' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Get the webservice fields'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_services_resources_get_webservice_fields',
        ],

        'getMyPageWithFields' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Get the user with all the data'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_service_resources_get_my_page_with_fields',
          'args' => [
            [
              'name' => 'predefined_datacollections',
              'type' => 'array',
              'description' => t('Array of predefined collections'),
              'source' => ['data' => 'predefined_datacollections'],
              'optional' => FALSE,
            ],
            [
              'name' => 'status',
              'type' => 'integer',
              'description' => t('Status of nodes: Published or unpublished'),
              'source' => ['data' => 'status'],
              'optional' => TRUE,
            ],
          ],
        ],

        'getUserEntityWrapperFieldValues' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Get the webservice fields'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_services_resources_get_user_entity_wrapper_field_values',
          'args' => [
            [
              'name' => 'uid',
              'type' => 'integer',
              'description' => t('User ID'),
              'source' => ['data' => 'uid'],
              'optional' => FALSE,
            ],

            [
              'name' => 'fields',
              'type' => 'integer',
              'description' => t('Array of field names'),
              'source' => ['data' => 'fields'],
              'optional' => FALSE,
            ],
          ],
        ],

        'getWebserviceListAll' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Get the webservice fields'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_service_resources_get_webservice_list_all',
        ],

        'getWebserviceReturnListArray' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Get the webservice fields'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_service_resources_webservice_return_list_array',
          'args' => [
            [
              'name' => 'webservices',
              'type' => 'array',
              'description' => t('Webservice array'),
              'source' => ['data' => 'webservices'],
              'optional' => FALSE,
            ],
          ],
        ],

        'getFreeServices' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Get list of free services'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_service_resources_kms_get_free_services',
          'args' => [
            [
              'name' => 'full',
              'type' => 'boolean',
              'description' => t('Get full list'),
              'source' => ['data' => 'full'],
              'optional' => TRUE,
            ],
          ],
        ],

        'getBundlePermsForUser' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Get list of bundle permissions for a given user'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_service_resources_get_bundle_perms_by_uid',
          'args' => [
            [
              'name' => 'uid',
              'type' => 'integer',
              'description' => t('User ID'),
              'source' => ['data' => 'uid'],
              'optional' => FALSE,
            ],
          ],
        ],
      ],
    ],
  ];

  return $definitions;
}

/**
 * Create a new user for KMS.
 *
 * This function creates an user without using the drupal_submit_form (as the
 * usual user resources does). This is done the handle the hierarchical select
 * which is not happy to pass validation from the API.
 *
 * @param $account
 *   A object containing account information. The $account object should
 *   contain, at minimum, the following properties:
 *     - name (user name)
 *     - mail (email address)
 *     - pass (plain text unencrypted password)
 *     - user_type (KMS user type as an integer)
 *     - terms_and_conditions (boolean)
 *
 *   These properties can be passed but are optional
 *     - status (0 for blocked, otherwise will be active by default)
 *     - notify (1 to notify user of new account, will not notify by default)
 *
 *  Roles can be passed in a roles property which is an associative
 *  array formatted with '<role id>' => '<role id>', not including
 *  the authenticated user role, which is given by default.
 *
 * @return
 *   The user object of the newly created user.
 */
function _kms_services_resources_user_resource_create($account) {
  // Validate our data.
  $validation = _kms_services_resources_user_resource_create_validate($account);

  // Handle validation fail.
  if (!empty($validation)) {
    return services_error(t('Data could not be validated.'), 422, ['errors' => $validation]);
  }

  $new_user = [
    'name' => $account['name'],
    'pass' => $account['pass'],
    'mail' => $account['email'],
    'status' => $account['status'],
    'timezone' => NULL,
    'roles' => [
      DRUPAL_AUTHENTICATED_RID => 'authenticated user',
    ],
  ];

  // User type and terms & conditions.
  $new_user['field_terms_and_conditions']['und'][0]['value'] = 1;
  $new_user['field_user_type']['und'][0]['tid'] = $account['user_type'];

  // Encapsulate user save and handle errors.
  try {
    $user = user_save(NULL, $new_user);
  } catch (Exception $exception) {

    switch ($exception->getCode()) {
      case 23505:
        // ERROR:  duplicate key value violates unique constraint.
        $error_message = t("Username and/or email already exists.");
        $http_error_code = 409;
        break;
      default:
        // General error.
        $error_message = t("An error occurred.");
        $http_error_code = 422;
        break;
    }
    return services_error($error_message, $http_error_code);
  }

  return $user;
}

/**
 * Validate data that is sent to the user resource creation.
 *
 * @param $account
 *   The account object posted to the API.
 *
 * @return array
 *   Return error array. If empty array validation was without errors.
 */
function _kms_services_resources_user_resource_create_validate($account) {
  // Init. return var.
  $errors = [];

  // Is there any data at all ?
  if (empty($account) || !is_array($account) || (isset($account[0]) && $account[0] == NULL)) {
    return ['No data was submitted'];
  }

  // Required for creation.
  $required_fields = ['name', 'email', 'user_type', 'terms_and_conditions'];
  foreach ($required_fields as $required_field) {
    if (!key_exists($required_field, $account)) {
      $errors[] = t('Field missing @s', ['@s' => $required_field]);
    }
  }

  // Valid email.
  if (!filter_var($account['email'], FILTER_VALIDATE_EMAIL)) {
    $errors[] = t('Email is not valid.');
  }

  // Valid taxonomy.
  $taxonomy = taxonomy_term_load(intval($account['user_type']));
  if (!$taxonomy) {
    $errors[] = t('Taxonomy for user_type is not valid.');

    // Since we will need the taxonomy to be a valid object, return if not.
    return $errors;
  }

  // Check vocabulary ID.
  $user_type_vocabulary = taxonomy_vocabulary_machine_name_load('user_type');
  if (!$user_type_vocabulary) {
    $errors[] = t('User type vocabulary could not be loaded.');

    // Since we will need the vocabulary to be a valid object, return if not.
    return $errors;
  }

  if ($taxonomy->vid != $user_type_vocabulary->vid) {
    $errors[] = t('Taxonomy is not in the correct vocabulary.');
    return $errors;
  }

  return $errors;
}

/**
 * Access check callback for user resource.
 */
function _kms_services_resources_user_resource_access($op = 'view', $args = []) {

  return TRUE;

  // Adds backwards compatability with regression fixed in #1083242
  if (isset($args[0])) {
    $args[0] = _services_access_value($args[0], ['account', 'data']);
  }

  // Check if the user exists if appropriate.
  if ($op != 'create' && $op != 'register') {
    $account = user_load($args[0]);
    if (!$account) {
      return services_error(t('There is no user with ID @uid.', ['@uid' => $args[0]]), 404);
    }
  }

  global $user;
  switch ($op) {
    case 'view':
      return user_view_access($account);
    case 'update':
      return ($user->uid == $account->uid || user_access('administer users'));
    case 'create':
    case 'register':
      if (!$user->uid && variable_get('user_register', USER_REGISTER_VISITORS_ADMINISTRATIVE_APPROVAL) != USER_REGISTER_ADMINISTRATORS_ONLY) {
        return TRUE;
      }
      else {
        return user_access('administer users');
      }
    case 'password_reset':
      return TRUE;
    case 'delete':
    case 'cancel':
    case 'resend_welcome_email':
      return user_access('administer users');
  }
}

/**
 * Get a list of KSM permissions services.
 *
 * @return array|mixed
 */
function _kms_services_resources_get_services_list() {

  return [
    'array',
  ];

  $services = kms_permissions_get_service_list();

  // If nothing, return empty array.
  if (!$services) {
    return [];
  }

  return $services;
}

/**
 * Get a list of uids from a given array of services.
 *
 * @param $services
 *   An array of the services we want to get users from.
 * @param null $column_name
 *   An array of columns name to output.
 *
 * @return array
 */
function _kms_services_resources_get_uids_by_separate_services($services, $column_name = NULL) {

  /**
   * Example JSON.
   *
   * { "services":  {
   *    "field_bundle_webservices_geo": {
   *      "und" : [1, 4218, 4458]
   *      }
   *    }
   *  }
   */

  $uids = _kms_permissions_get_uids_by_separate_services($services, $column_name);
  return [$uids];

}

/**
 * A test to see if the API is alive.
 *
 * Return an array with active = true.
 *
 * @return array
 */
function _kms_services_resources_status_check() {
  return ['active' => TRUE];
}

/**
 * Get a list of webservices from Oracle.
 *
 * @return array
 */
function _kms_services_resources_get_webservices_list() {
  return kms_permissions_widget_type_options();
}

/**
 * Get a list of Applications from Oracle.
 *
 * @return array|mixed
 */
function _kms_services_resources_get_application_list() {
  return kms_permissions_get_application_list();
}

/**
 * Return the ftp structure.
 *
 * @return \alphabetically
 */
function _kms_services_resources_ftp_scan_structure() {
  return kms_permissions_ftp_scan_structure();
}

/**
 * Find all default and active bundles from a given subtype.
 *
 * @param string $subtype
 *
 * @return array
 */
function _kms_services_resources_get_access_bundles($subtype) {
  if ($subtype == 'default') {
    $field_info = field_info_instance('node', 'field_default_bundle', 'access_bundle');
    // If field does not exist return empty array.
    if (empty($field_info)) {
      return [];
    }
    $default_value = 1;
  }
  else {
    $default_value = 0;
  }

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'access_bundle')
    ->propertyCondition('status', 1)
    ->fieldCondition('field_default_bundle', 'value', $default_value, '=')
    ->addMetaData('account', user_load(1)); // Run the query as user 1.

  $result = $query->execute();
  $bids = [];

  if ($result) {
    foreach ($result['node'] as $bundle) {
      $bids[] = $bundle->nid;
    }
  }

  return $bids;
}

/**
 * Get predefined data collections.
 *
 * @param integer $bundle_nid
 * @param string $key_prefix
 * @param boolean $flattened
 * @param array $permissions
 * @param array $field_access_userdefined_ranges
 * @param array $field_max_download_size
 * @param array $bounding_box
 *
 * @return array
 */
function _kms_services_resources_get_predefined_data_collections(
  $bundle_nid,
  $key_prefix,
  $flattened,
  $permissions,
  $field_access_userdefined_ranges,
  $field_max_download_size,
  $bounding_box
) {
  $bundle = node_load($bundle_nid);

  $field_predefined_datacollections = field_get_items('node',
    $bundle,
    'field_predefined_datacollections');

  if (empty($field_predefined_datacollections)) {
    return [];
  }

  foreach ($field_predefined_datacollections as $predefined) {
    $pd_key = $key_prefix ? 'pd' . $predefined['target_id'] : $predefined['target_id'];

    // If a user has access to userdefined ranges on a product on one bundle,
    // there is always access.
    if (isset($permissions['predefined_datacollections'][$pd_key])) {
      $access_userdefined_ranges = ($permissions['predefined_datacollections'][$pd_key]['access_userdefined_ranges'] + $field_access_userdefined_ranges['value'] > 0 ? 1 : 0);
    }
    else {
      $access_userdefined_ranges = $field_access_userdefined_ranges['value'];
    }

    // Only select min/max value if key exists to avoid notices.
    if (isset($permissions['predefined_datacollections']) && isset($permissions['predefined_datacollections'][$pd_key])) {
      if ($flattened) {
        $permissions['predefined_datacollections'][$pd_key] = $predefined['target_id'];
      }
      else {
        $permissions['predefined_datacollections'][$pd_key] = [
          'access_userdefined_ranges' => $access_userdefined_ranges,
          'max_download_size' => max(
            $permissions['predefined_datacollections'][$pd_key]['max_download_size'],
            $field_max_download_size['value']
          ),
          'id' => $predefined['target_id'],
          'MINX' => min($permissions['predefined_datacollections'][$pd_key]['MINX'], $bounding_box['field_bundle_minx']),
          'MINY' => min($permissions['predefined_datacollections'][$pd_key]['MINY'], $bounding_box['field_bundle_miny']),
          'MAXX' => max($permissions['predefined_datacollections'][$pd_key]['MAXX'], $bounding_box['field_bundle_maxx']),
          'MAXY' => max($permissions['predefined_datacollections'][$pd_key]['MAXY'], $bounding_box['field_bundle_maxy']),
          'MAXPIXELWIDTH' => max(
            $permissions['predefined_datacollections'][$pd_key]['MAXPIXELWIDTH'],
            $bounding_box['field_bundle_maxpixelwidth']
          ),
          'MAXPIXELHEIGHT' => max(
            $permissions['predefined_datacollections'][$pd_key]['MAXPIXELHEIGHT'],
            $bounding_box['field_bundle_maxpixelheight']
          ),
          'FEATUREINFO' => '1',
        ];
      }
    }
    else {
      if ($flattened) {
        $permissions['predefined_datacollections'][$pd_key] = $predefined['target_id'];
      }
      else {
        $permissions['predefined_datacollections'][$pd_key] = [
          'access_userdefined_ranges' => $access_userdefined_ranges,
          'max_download_size' => $field_max_download_size['value'],
          'id' => $predefined['target_id'],
          'MINX' => $bounding_box['field_bundle_minx'],
          'MINY' => $bounding_box['field_bundle_miny'],
          'MAXX' => $bounding_box['field_bundle_maxx'],
          'MAXY' => $bounding_box['field_bundle_maxy'],
          'MAXPIXELWIDTH' => $bounding_box['field_bundle_maxpixelwidth'],
          'MAXPIXELHEIGHT' => $bounding_box['field_bundle_maxpixelheight'],
          'FEATUREINFO' => '1',
        ];
      }
    }
  }

  return [
    'permissions' => $permissions,
    'bounding_box' => $bounding_box,
  ];
}

/**
 * Get a bundle node and the entity metadata.
 *
 * @param int $nid
 *
 * @return array
 */
function _kms_services_resources_get_bundle($bundle_nid) {
  $bundle_node = node_load($bundle_nid);
  if (!$bundle_node) {
    return services_error("Bundle node could not be loaded.");
  }

  $wrapper = entity_metadata_wrapper('node', $bundle_node);

  return [
    'bundle' => $bundle_node,
    'wrapper' => $wrapper,
  ];
}

/**
 * Find what bundle(s) a given item is included in.
 *
 * @param integer $id
 * @param string $item_type
 *
 * @return array
 *   Bundles.
 */
function _kms_services_resources_get_bundles_by_item_id($id, $item_type) {
  module_load_include('module', 'kms_permissions', 'kms_permissions');
  return _kms_permissions_get_bundles_by_item_id($id, $item_type);
}

/**
 * Get bundles by bundle ID and return nicely formatted array.
 *
 * @param integer $bid
 * @param array $permissions
 * @param array $options
 *
 * @return array
 */
function _kms_services_resources_get_permissions_by_bid($bid, $permissions = array(), $options = array()) {
  // When they come from API call they will be null instead of an empty array.
  if (!$permissions) {
    $permissions = array();
  }

  // When they come from API call they will be null instead of an empty array.
  if (!$options) {
    $options = array();
  }

  return _kms_permissions_get_permissions_by_bid($bid, $permissions, $options);
}

/**
 * Get the user with all the fields.
 *
 * @param $uid
 *
 * @return mixed
 */
function _kms_services_resources_get_user_with_all_fields($uid) {
  $user = user_load(intval($uid));

  if (!$user) {
    return services_error(t('Could not load user.'), 404);
  }

  return $user;
}

function _kms_services_resources_get_user_entity_wrapper_field_values($uid, $fields = array()) {
  // Init vars.
  $services = array();

  // If empty fields sent from the API args.
  if (!$fields) {
    $fields = array();
  }

  $userObj = user_load(intval($uid));
  if (!$userObj) {
    return services_error(t('Could not load user.'), 404);
  }

  // Get the wrapper to get easier access to field values.
  $userWrapper = entity_metadata_wrapper('user', $userObj->uid);

  if (!empty($fields)) {
    foreach($fields as $field) {

      $sids = $userWrapper->$field->value();
      if (!empty($sids)) {
        array_walk($sids, function($sid) use (&$services) {
          $services[$sid] = $sid;
        });
      }
    }
  }

  return $services;
}

/**
 * Get the webservice fields.
 *
 * @return array
 */
function _kms_services_resources_get_webservice_fields() {
  return _kms_permissions_webservice_fields();
}

/**
 * Get the MyPage nodes with fields from predefined datacollections.
 *
 * @param $predefined_datacollections
 * @param int $status
 */
function _kms_service_resources_get_my_page_with_fields($predefined_datacollections, $status = null) {

  // Set the status.
  if (!$status) {
    $status = NODE_NOT_PUBLISHED;
  }
  else {
    $status = NODE_PUBLISHED;
  }

  // Handle if we get an empty
  if (!$predefined_datacollections) {
    $predefined_datacollections = array();
  }

  $query = db_select('field_data_field_min_side', 'ms');
  $query->leftJoin('field_data_body', 'b', 'ms.entity_id = b.entity_id');
  $query->leftJoin('node', 'n', 'ms.entity_id = n.nid');
  $query->fields('ms', array('entity_id', 'field_min_side_url', 'field_min_side_title'));
  $query->fields('b', array('body_value', 'body_summary'));
  $query->condition('ms.entity_id', $predefined_datacollections, 'IN');
  $query->condition('n.status', $status);
  $query->orderBy('ms.field_min_side_title');
  $result = $query->execute()->fetchAll();

  return $result;
}

/**
 * Get a list of webservices.
 *
 * @return array
 */
function _kms_service_resources_get_webservice_list_all() {
  return _kms_user_return_websevice_list_all();
}

/**
 * Get a formatted list of webservices correctly formatted.
 *
 * @param array $webservices
 *
 * @return array
 */
function _kms_service_resources_webservice_return_list_array($webservices) {
  return _kms_permissions_webservice_return_list_array($webservices);
}

/**
 * Get a list of the free webservices.
 *
 * @param bool $full
 *
 * @return array|bool
 */
function _kms_service_resources_kms_get_free_services($full = FALSE) {
  module_load_include('inc', 'kms_services', 'inc/services');

  // Clean up value when it comes from the API.
  if (!$full) {
    $full = FALSE;
  }

  return kms_services_get_free_services($full);
}

/**
 * Get the permissions for a given user ID.
 *
 * @param integer $uid
 * @param array $permissions
 * @param array $options
 *
 * @return array
 *   Return an array with bundles and permissions.
 */
function _kms_service_resources_get_bundle_perms_by_uid($uid, $permissions = array(), $options = array()) {
  // This is a rework of _kms_permissions_get_bundle_perms_by_uid from the
  // kms_permission module as that function does not return anything and
  // we need to get the permissions back.

  // Init. vars.
  $bundles = [];

  $options += array(
    'key_prefix' => TRUE,
    'flattened' => FALSE,
  );

  $rows = kms_permissions_get_service_list();

  return $rows;

  //$all_perms = _kms_permissions_get_all_permissions_by_uid($uid, $options);

  // return $all_perms;

  // Load user.
  $user = user_load($uid);

  // Get default bundles.
  $default = _kms_permissions_get_access_bundles('default');

  // Get users bundles.
  $field_access_bundles = field_get_items('user', $user, 'field_access_bundles');

  // Merge them.
  if (is_array($field_access_bundles)) {
    array_walk($field_access_bundles, function(&$row) {
      $row = $row['nid'];
    });
    $bundles = array_merge($field_access_bundles, $default);
  }
  else {
    $bundles = $default;
  }

  // Collect the permissions. Note that $permissions are passed by reference.
  if (!empty($bundles)) {
    $bundles = array_unique($bundles);
    // Get permissions from all bundles.
    foreach ($bundles as $bid) {
      _kms_permissions_get_permissions_by_bid($bid, $permissions, $options);
    }
  }

  return [
   'bundles' => $bundles,
   'permissions' => $permissions
  ];

}