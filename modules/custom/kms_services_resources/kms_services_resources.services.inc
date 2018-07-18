<?php

/**
 * Implements hook_resource().
 */
function kms_service_resources_resource() {
  $definitions = [
    'kms_password' => [
      'actions' => [
        'request_new_password' => [
          'help' => 'Request a new password, given a user name or e-mail address',
          'callback' => '_kms_services_resources_password_request_new_password',
          'args' => [
            [
              'name' => 'name',
              'type' => 'string',
              'description' => 'A valid user name or e-mail address',
              'source' => ['data' => 'name'],
              'optional' => FALSE,
            ],
          ],
          'access callback' => 'services_access_menu',
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources_password.services',
          ],
        ],
      ],
    ],
    'kms_user' => [
      'operations' => [
        'retrieve' => [
          'help' => 'Retrieve a user',
          'callback' => '_kms_services_resources_user_resource_retrieve',
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments' => ['view'],
          'access arguments append' => TRUE,
          'args' => [
            [
              'name' => 'uid',
              'type' => 'int',
              'description' => 'The uid of the user to retrieve.',
              'source' => ['path' => 0],
              'optional' => FALSE,
            ],
          ],
        ],
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
          ],
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

        'isSubuser' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Is a given user ID a sub user'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_service_resources_is_subuser',
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

        'isSuperAdmin' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Is a given user ID a sub user'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_service_resources_is_superadmin',
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

        'loadAllSubusers' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Load all related accounts'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_service_resources_subuser_load_all',
          'args' => [
            [
              'name' => 'uid',
              'type' => 'integer',
              'description' => t('The user ID to which all other accounts will be related.'),
              'source' => ['data' => 'uid'],
              'optional' => FALSE,
            ],
            [
              'name' => 'children',
              'type' => 'boolean',
              'description' => t('(Optional) Boolean TRUE to load children of account, otherwise FALSE to load parent(s) of account'),
              'source' => ['data' => 'children'],
              'optional' => TRUE,
            ],
          ],
        ],

        'getSubuserRoles' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Load all related accounts'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_service_resources_get_subuser_roles',
        ],

        'subuserInsert' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Insert a subuser '),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_service_resources_subuser_insert',
          'args' => [
            [
              'name' => 'uid',
              'type' => 'integer',
              'description' => t('The user ID to which all other accounts will be related.'),
              'source' => ['data' => 'uid'],
              'optional' => FALSE,
            ],
            [
              'name' => 'values',
              'type' => 'array',
              'description' => t('An array of data that should be used to create the subuser.'),
              'source' => ['data' => 'values'],
              'optional' => FALSE,
            ],
            [
              'name' => 'request_time',
              'type' => 'string',
              'description' => t('The time for the request'),
              'source' => ['data' => 'request_time'],
              'optional' => FALSE,
            ],
          ],
        ],

        'subuserList' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('List subusers'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_service_resources_subuser_list',
          'args' => [
            [
              'name' => 'uid',
              'type' => 'integer',
              'description' => t('The user ID to which all other accounts will be related.'),
              'source' => ['data' => 'uid'],
              'optional' => FALSE,
            ],
            [
              'name' => 'rid',
              'type' => 'integer',
              'description' => t('The role ID.'),
              'source' => ['data' => 'rid'],
              'optional' => TRUE,
            ],
          ],
        ],

        'subuserListFromView' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('List subusers from Views'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_service_resources_subuser_list_views',
          'args' => [
            [
              'name' => 'uid',
              'type' => 'integer',
              'description' => t('The user ID to which all other accounts will be related.'),
              'source' => ['data' => 'uid'],
              'optional' => FALSE,
            ],
          ],
        ],

        'subuserUserUpdate' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Update a subuser'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_service_resources_subuser_update',
          'args' => [
            [
              'name' => 'form_state',
              'type' => 'array',
              'description' => t('The form state values.'),
              'source' => ['data' => 'form_state'],
              'optional' => FALSE,
            ],
          ],
        ],

        'subuserUserDelete' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Delete a subuser'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_service_resources_subuser_delete',
          'args' => [
            [
              'name' => 'form_state',
              'type' => 'array',
              'description' => t('The form state values.'),
              'source' => ['data' => 'form_state'],
              'optional' => FALSE,
            ],
          ],
        ],

        'getUserPassHash' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Get the user hashed password'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_service_resources_get_user_hashed_password',
          'args' => [
            [
              'name' => 'uid',
              'type' => 'string',
              'description' => t('User ID'),
              'source' => ['data' => 'uid'],
              'optional' => FALSE,
            ],
          ],
        ],

        'userPassRehash' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Rehash a user password'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_service_resources_user_pass_rehash',
          'args' => [
            [
              'name' => 'pass',
              'type' => 'string',
              'description' => t('The user password'),
              'source' => ['data' => 'pass'],
              'optional' => FALSE,
            ],
            [
              'name' => 'timestamp',
              'type' => 'string',
              'description' => t('Timestamp'),
              'source' => ['data' => 'timestamp'],
              'optional' => FALSE,
            ],
            [
              'name' => 'login',
              'type' => 'string',
              'description' => t('Login'),
              'source' => ['data' => 'login'],
              'optional' => FALSE,
            ],
            [
              'name' => 'uid',
              'type' => 'string',
              'description' => t('User ID'),
              'source' => ['data' => 'uid'],
              'optional' => FALSE,
            ],
          ],
        ],

        'getCSHSFormattedTermsByVocabularyName' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Get a CSHS formatted terms array from a given vocabulary name'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_service_resources_get_cshs_formatted_terms_by_vocabulary_name',
          'args' => [
            [
              'name' => 'vocabulary_name',
              'type' => 'string',
              'description' => t('The vocabulary name'),
              'source' => ['data' => 'vocabulary_name'],
              'optional' => FALSE,
            ],
            [
              'name' => 'parent',
              'type' => 'integer',
              'description' => t('Parent ID'),
              'source' => ['data' => 'parent'],
              'optional' => TRUE,
            ],
          ],
        ],

        'getUserByUuid' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Get a user by UUID'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_service_resources_get_user_by_uuid',
          'args' => [
            [
              'name' => 'uuid',
              'type' => 'string',
              'description' => t('The UUID for the user'),
              'source' => ['data' => 'uuid'],
              'optional' => FALSE,
            ],
          ],
        ],

        'updateUserType' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Update the user type by using the user ID'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_service_resources_update_user_type',
          'args' => [
            [
              'name' => 'id',
              'type' => 'string',
              'description' => t('The id for the user'),
              'source' => ['data' => 'id'],
              'optional' => FALSE,
            ],
            [
              'name' => 'type',
              'type' => 'string',
              'description' => t('The type to set the user as'),
              'source' => ['data' => 'type'],
              'optional' => FALSE,
            ],
          ],
        ],

        'getBundles' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Get bundles'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_service_resources_get_bundles',
          'args' => [
          ],
        ],

        'getNodeByNid' => [
          'file' => [
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ],
          'help' => t('Get a node by NID'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments append' => TRUE,
          'callback' => '_kms_service_resources_get_node_by_nid',
          'args' => [
            [
              'name' => 'nid',
              'type' => 'string',
              'description' => t('The nid for the node'),
              'source' => ['data' => 'nid'],
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

  // Transfer field data.
  $account['email'] = $account['mail'];
  $account['terms_and_conditions'] = $account['field_terms_and_conditions'][LANGUAGE_NONE];
  $account['user_type'] = $account['field_user_type'][LANGUAGE_NONE];
  $account['contact_me'] = $account['field_contact_me'][LANGUAGE_NONE];

  // Validate our data.
  $validation = _kms_services_resources_user_resource_create_validate($account);

  // Handle validation fail.
  if (!empty($validation)) {
    return services_error(t('Data could not be validated.'), 422, ['errors' => $validation]);
  }

  $new_user = [
    'name' => $account['name'],
    'pass' => $account['pass'],
    'mail' => $account['mail'],
    'init' => $account['mail'],
    'status' => 1,
    'timezone' => NULL,
    'roles' => [
      DRUPAL_AUTHENTICATED_RID => 'authenticated user',
    ],
  ];

  // User type and terms & conditions.
  $new_user['field_terms_and_conditions']['und'][0]['value'] = (int) $account['field_terms_and_conditions']['und'];
  $new_user['field_user_type']['und'][0]['tid'] = $account['user_type'];
  // $new_user['user_type']['und'][0]['tid'] = $account['field_user_type']['und'][0];

  $new_user['notify'] = TRUE;

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

  _kms_services_resources_user_resource_create_user_mail_notify('register_no_approval_required', $user);

  return $user;
}

function _kms_services_resources_user_resource_create_user_mail_notify($op, $account, $language = NULL) {
  $params['account'] = $account;
  $language = $language ? $language : user_preferred_language($account);

  $mail = drupal_mail('kms_user', $op, $account->mail, $language, $params);
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
 * Retrieve a user.
 */
function _kms_services_resources_user_resource_retrieve($uid) {
    module_load_include('inc', 'services', 'resources/user_resource');

    $account = _user_resource_retrieve($uid);

    return $account;
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
function _kms_services_resources_get_permissions_by_bid($bid, $permissions = [], $options = []) {
  // When they come from API call they will be null instead of an empty array.
  if (!$permissions) {
    $permissions = [];
  }

  // When they come from API call they will be null instead of an empty array.
  if (!$options) {
    $options = [];
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

function _kms_services_resources_get_user_entity_wrapper_field_values($uid, $fields = []) {
  // Init vars.
  $services = [];

  // If empty fields sent from the API args.
  if (!$fields) {
    $fields = [];
  }

  $userObj = user_load(intval($uid));
  if (!$userObj) {
    return services_error(t('Could not load user.'), 404);
  }

  // Get the wrapper to get easier access to field values.
  $userWrapper = entity_metadata_wrapper('user', $userObj->uid);

  if (!empty($fields)) {
    foreach ($fields as $field) {

      $sids = $userWrapper->$field->value();
      if (!empty($sids)) {
        array_walk($sids, function ($sid) use (&$services) {
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
function _kms_service_resources_get_my_page_with_fields($predefined_datacollections, $status = NULL) {

  // Set the status.
  if (!$status) {
    $status = NODE_NOT_PUBLISHED;
  }
  else {
    $status = NODE_PUBLISHED;
  }

  // Handle if we get an empty
  if (!$predefined_datacollections) {
    $predefined_datacollections = [];
  }

  $query = db_select('field_data_field_min_side', 'ms');
  $query->leftJoin('field_data_body', 'b', 'ms.entity_id = b.entity_id');
  $query->leftJoin('node', 'n', 'ms.entity_id = n.nid');
  $query->fields('ms', [
    'entity_id',
    'field_min_side_url',
    'field_min_side_title',
  ]);
  $query->fields('b', ['body_value', 'body_summary']);
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
function _kms_service_resources_get_bundle_perms_by_uid($uid, $permissions = [], $options = []) {
  // This is a rework of _kms_permissions_get_bundle_perms_by_uid from the
  // kms_permission module as that function does not return anything and
  // we need to get the permissions back.

  // Init. vars.
  $bundles = [];

  $options += [
    'key_prefix' => TRUE,
    'flattened' => FALSE,
  ];

  // Get all the services.
  $service_list = kms_permissions_get_service_list();

  // Load user.
  $user = user_load($uid);

  // Get default and users bundles.
  $default = _kms_permissions_get_access_bundles('default');
  $field_access_bundles = field_get_items('user', $user, 'field_access_bundles');

  // Merge them.
  if (is_array($field_access_bundles)) {
    array_walk($field_access_bundles, function (&$row) {
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
    'permissions' => $permissions,
    'service_list' => $service_list,
  ];
}

/**
 * Return whether a given user is a subuser from the UID.
 *
 * @param integer $uid
 *
 * @return boolean
 */
function _kms_service_resources_is_subuser($uid) {
  module_load_include('module', 'kms_subuser', 'kms_subuser');
  return kms_subuser_is_subuser($uid);
}

/**
 * Return whether as user with $uid is a super administrator.
 *
 * @param integer $uid
 *
 * @return bool
 */
function _kms_service_resources_is_superadmin($uid) {
  $user = user_load($uid);
  return kms_user_is_superadmin($user);
}

/**
 * Load all related accounts.
 *
 * @param $account
 *   The user account to which all other accounts will be related.
 * @param $children
 *   (Optional) Boolean TRUE to load children of account, otherwise FALSE to
 *   load parent(s) of account.
 *
 * @return
 *   An associative array of related accounts were key and value is user ID.
 */
function _kms_service_resources_subuser_load_all($uid, $children = TRUE) {
  $account = user_load($uid);

  return subuser_load_all($account, $children);
}

/**
 * Get an array of sub user roles.
 *
 * @return array
 */
function _kms_service_resources_get_subuser_roles() {
  return [
    DRUPAL_AUTHENTICATED_RID => 'authenticated user',
    KMS_SUBUSER_ROLE_ID => KMS_SUBUSER_ROLE_NAME,
  ];
}

/**
 * Insert a sub user.
 *
 * @param integer $uid
 * @param array $values
 * @param integer $request_time
 *
 * @return array
 * @throws \Exception
 * @throws \ServicesException
 */
function _kms_service_resources_subuser_insert($uid, $values, $request_time) {
  module_load_include('module', 'kms_subuser', 'kms_subuser');
  $user = user_load($uid);

  $name = trim($values['name']);
  $pass = trim($values['pass']);
  $trimmed_mail = trim($values['mail']);
  $mail = empty($trimmed_mail) ? KMS_SUBUSER_FAKE_MAIL : $trimmed_mail;

  $subuser = [
    'name' => $name,
    'pass' => $pass,
    'mail' => $mail,
    'init' => $mail,
    'status' => 1,
    'access' => $request_time,
    'roles' => kms_subuser_default_roles(),
  ];

  $uwrapper = entity_metadata_wrapper('user', $user);

  // $account returns user object.
  $account = user_save(NULL, $subuser);

  $suwrapper = entity_metadata_wrapper('user', $account);

  // Save user remark.
  $suwrapper->field_user_remark->set($values['user_remark']);

  // Save expire.
  if (!empty($values['user_expire'])) {
    $suwrapper->field_expire_date->set(strtotime($values['user_expire']));
  }

  // Save user type (same as master).
  $suwrapper->field_user_type->set(array_keys(_kms_csv_user_types($uwrapper)));

  // Set address values, can be empty.
  $suwrapper->field_address = [
    'first_name' => $values['first_name'],
    'last_name' => $values['last_name'],
    'country' => 'DA',
  ];

  // Set phone number, can be empty.
  $suwrapper->field_phone->set($values['phone']);

  $suwrapper->save();

  // Save subuser relation.
  kms_subuser_save_relation($user->uid, $account->uid);

  // Clone permissions (bundles, permissions etc.)
  kms_permissions_clone_perms($user, $account);

  // Insert user data into oracle.
  $account->pass = $pass;
  kms_subuser_insert_account_oracle($user, $account);
  $subuser = kms_subuser_load($account->uid);
  if ($subuser) {
    kms_subuser_send_mail('register_subuser', $subuser);
    return [
      'result' => 'register_subuser_ok',
    ];
  }
  else {
    services_error('There was a problem creating the subuser.', 422);
  }
}

/**
 * Get a list of sub users.
 *
 * @param integer $uid
 * @param integer $rid
 *
 * @return array
 */
function _kms_service_resources_subuser_list($uid, $rid) {

  // Get the role.
  if (!$rid) {
    $role = user_role_load_by_name('subuser');
    if ($role) {
      $rid = $role->rid;
    }
  }

  // This is stolen from the KMS Subuser views.
  $query = "SELECT
    users.name AS users_name,
    users.uid AS uid,
    field_data_field_address.field_address_name_line AS field_data_field_address_field_address_name_line,
    users.status AS users_status,
    users.created AS users_created,
    'user' AS field_data_field_expire_date_user_entity_type
    FROM
    {users} users
    INNER JOIN {field_data_endpoints} field_data_endpoints ON users.uid = field_data_endpoints.endpoints_entity_id AND (field_data_endpoints.bundle = 'subuser' AND field_data_endpoints.endpoints_entity_type = 'user')
    INNER JOIN {field_data_endpoints} field_data_endpoints2 ON field_data_endpoints.entity_id = field_data_endpoints2.entity_id AND (field_data_endpoints2.endpoints_entity_type = 'user' AND field_data_endpoints2.endpoints_r_index !=  field_data_endpoints.endpoints_r_index AND 1 = '1')
    INNER JOIN {users} users_users ON field_data_endpoints2.endpoints_entity_id = users_users.uid AND field_data_endpoints2.endpoints_entity_type = 'user'
    INNER JOIN {users_roles} users_roles ON users.uid = users_roles.uid
    LEFT JOIN {field_data_field_address} field_data_field_address ON users.uid = field_data_field_address.entity_id AND field_data_field_address.entity_type = 'user'
    WHERE (( (users_users.uid = :uid ) )AND(( (users_roles.rid = :rid) )))
    ORDER BY users_created DESC";

  $result = db_query($query, [':uid' => $uid, ':rid' => $rid]);

  $data = [];
  foreach ($result as $row) {
    $data[] = (array) $row;
  }

  return $data;
}

/**
 * Get the Views HTML with sub user list.
 *
 * @param integer $uid
 *
 * @return string
 */
function _kms_service_resources_subuser_list_views($uid) {
  // Get the views data. Bypass the access part as we are not logged in
  // properly through the API.
  $view = views_get_view('kms_subuser');
  $views_data = $view->preview('block_1', [$uid]);
  // All < and > are converted to \u003C and \u003E
  // All " are converted to \u0022.
  $json = json_encode($views_data, JSON_HEX_QUOT | JSON_HEX_TAG);

  return $json;
}

/**
 * Update a subuser.
 *
 * @param $form_state
 *
 * @return bool
 */
function _kms_service_resources_subuser_update($form_state) {
  module_load_include('module', 'kms_subuser', 'kms_subuser');
  $form = [];
  kms_subuser_update_form_submit($form, $form_state);

  return ['result' => TRUE];
}

/**
 * Delete a subuser.
 *
 * @param $from_state
 *
 * @return array
 */
function _kms_service_resources_subuser_delete($from_state) {
  module_load_include('module', 'kms_subuser', 'kms_subuser');

  $form = [];
  kms_subuser_cancel_form_delete($form, $from_state);

  return ['result' => TRUE];
}

/**
 * Rehash the password.
 *
 * @param string $pass
 * @param string $timestamp
 * @param string $login
 * @param string $uid
 *
 * @return array
 */
function _kms_service_resources_user_pass_rehash($pass, $timestamp, $login, $uid) {
  $rehash = user_pass_rehash($pass, $timestamp, $login, $uid);

  return ['result' => $rehash];
}

/**
 * Only get the hashed password value.
 *
 * @param integer $uid
 *
 * @return mixed
 */
function _kms_service_resources_get_user_hashed_password($uid) {
  $user = user_load($uid);

  if (!$user) {
    return '';
  }

  return $user->pass;
}

/**
 * Get an array of formatted taxonomy terms valid for CSHS.
 *
 * @param string $vocabulary_name
 * @param integer $parent
 *
 * @return array
 */
function _kms_service_resources_get_cshs_formatted_terms_by_vocabulary_name($vocabulary_name, $parent = 0) {

  // Setup properties directly instead of calling _options_properties().
  $properties = [
    'filter_xss' => FALSE,
    'strip_tags' => TRUE,
    'strip_tags_and_unescape' => TRUE,
    'empty_option' => 'option_none',
    'optgroups' => FALSE,
  ];

  if ($parent === NULL) {
    $parent = 0;
  }

  // Get all terms as options.
  $options = [];
  if ($vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary_name)) {
    if ($terms = taxonomy_get_tree($vocabulary->vid, $parent)) {
      if (module_exists('i18n_taxonomy')) {
        // Localize terms.
        $terms = i18n_taxonomy_localize_terms($terms);
      }
      foreach ($terms as $term) {
        $options[$term->tid] = [
          'name' => str_repeat('- ', $term->depth) . $term->name,
          'parent_tid' => _kms_service_resources_shift_parent($term->parents),
        ];
      }
    }
  }

  // Sanitize the options.
  _options_prepare_options($options, $properties);

  // Always add an empty option.
  $options = _kms_service_resources_add_none_option($options);

  return $options;

}

/**
 * Helper that returns the first tid of an array of parents from a term object.
 *
 * @param $parent_tids An array of all parents from a term object
 *
 * @return int|mixed The first parent tid
 */
function _kms_service_resources_shift_parent($parent_tids) {
  if (count($parent_tids)) {
    $parent_tids = array_values($parent_tids);
    $parent_tid = array_shift($parent_tids);
    return $parent_tid;
  }
  return 0;
}

/**
 * Add an empty option.
 *
 * @param $options
 *
 * @return array
 */
function _kms_service_resources_add_none_option($options) {
  return [
      '_none' => [
        'name' => t('- Please select -'),
        'parent_tid' => 0,
      ],
    ] + $options;
}

/**
 * Get a user from a given UUID.
 *
 * @param string $uuid
 *
 * @return mixed
 * @throws \ServicesException
 */
function _kms_service_resources_get_user_by_uuid($uuid) {

  // Get the user ID from the UUID.
  $user_uid = db_select('users', 'u')
    ->fields('u', ['uid'])
    ->condition('u.uuid', $uuid, '=')
    ->execute()
    ->fetchAssoc();

  if (!$user_uid || !is_array($user_uid)) {
    return services_error(t('User with the given UUID could not be found.'), 404);
  }

  // Get the user ID.
  $uid = reset($user_uid);
  if (!$uid) {
    return services_error(t('User data did not contain correctly formatted result.'), 422);
  }

  $user = user_load($uid);
  if (!$user) {
    return services_error(t('User could not be loaded.'), 422);
  }

  return $user;
}

/**
 * Update the field_user_type for a user with the given $user_type_id.
 *
 * @param $id
 *   User ID
 * @param $user_type_tid
 *   User type Term ID.
 *
 * @return mixed
 * @throws \Exception
 * @throws \ServicesException
 */
function _kms_service_resources_update_user_type($id, $user_type_tid) {

  $user = user_load($id);
  if (!$user) {
    return services_error(t('User could not be loaded.'), 404);
  }

  // Wrap it and save it.
  $user_wrapper = entity_metadata_wrapper('user', $user);
  $user_wrapper->field_user_type->set([$user_type_tid]);
  $user_wrapper->save();

  return $user;
}

/**
 * Get a list of all the bundles (nodes).
 *
 * @return array
 */
function _kms_service_resources_get_bundles() {
  $data = [];

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'access_bundle');

  $result = $query->execute();
  if (!empty($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = node_load_multiple($nids);

    foreach ($nodes as $node) {
      // Store uuid instead of id.
      if (!empty($node->field_colour)) {
        $tid = $node->field_colour[LANGUAGE_NONE][0]['tid'];
        $term = taxonomy_term_load($tid);
        $node->field_colour[LANGUAGE_NONE][0]['uuid'] = $term->uuid;
      }

      // Store uuid instead of id.
      if (!empty($node->field_predefined_datacollections)) {
        $PdNids = array_column($node->field_predefined_datacollections[LANGUAGE_NONE], 'target_id');
        $PdNodes = node_load_multiple($PdNids);

        foreach ($node->field_predefined_datacollections[LANGUAGE_NONE] as $key => $target) {
          $PdNode = $PdNodes[$target['target_id']];
          $node->field_predefined_datacollections[LANGUAGE_NONE][$key]['uuid'] = $PdNode->uuid;
        }
      }

      $data[] = $node;
    }
  }

  return $data;
}

/**
 * Get a node by its nid.
 *
 * Made as the normal node api load nodes using UUID.
 *
 * @param $nid
 *
 * @return bool|mixed
 * @throws \ServicesException
 */
function _kms_service_resources_get_node_by_nid($nid) {
  $node = node_load($nid);
  if (!$node) {
    return services_error(t('Node could not be loaded.'), 404);
  }

  return $node;
}