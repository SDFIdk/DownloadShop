<?php

/**
 * Implements hook_resource().
 */
function kms_service_resources_resource()
{
  $definitions = array(
    'kms_user' => array(
      'operations' => array(
        'create' => array(
          'help' => 'Create a user',
          'callback' => '_kms_services_resources_user_resource_create',
          'file' => array(
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments' => array('create'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'account',
              'type' => 'array',
              'description' => 'The user object',
              'source' => 'data',
              'optional' => FALSE,
            ),
          ),
        ),
      ),
    ),
    'kms_services' => array(
      'operations' => array(
        'index' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ),
          'callback' => '_kms_services_resources_get_services_list',
          'args' => array(
            array(
              'name' => 'page',
              'optional' => TRUE,
              'type' => 'int',
              'description' => 'The zero-based index of the page to get, defaults to 0.',
              'default value' => 0,
              'source' => array('param' => 'page'),
            ),
            array(
              'name' => 'fields',
              'optional' => TRUE,
              'type' => 'string',
              'description' => 'The fields to get.',
              'default value' => '*',
              'source' => array('param' => 'fields'),
            ),
            array(
              'name' => 'parameters',
              'optional' => TRUE,
              'type' => 'array',
              'description' => 'Parameters array',
              'default value' => array(),
              'source' => array('param' => 'parameters'),
            ),
            array(
              'name' => 'pagesize',
              'optional' => TRUE,
              'type' => 'int',
              'description' => 'Number of records to get per page.',
              'default value' => variable_get('services_node_index_page_size', 20),
              'source' => array('param' => 'pagesize'),
            ),
          ),
          'access arguments' => array('access content'),
        ),
      ),
      'actions' => array(
        'getUsersWithSeperateServices' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'kms_services_resources',
            'name' => 'kms_services_resources.services',
          ),
          'help' => t('Get all users that has specified separate services'),
          'access callback' => '_kms_services_resources_user_resource_access',
          'access arguments' => array('create'),
          'access arguments append' => TRUE,
          'callback' => '_kms_services_resources_get_uids_by_separate_services',
          'args' => array(
            array(
              'name' => 'services',
              'type' => 'string',
              'description' => t('Array of services array(\'field_bundle_webservices_geo\' => array(1, 4218, 4458), \'field_bundle_webservices_wms\' => array(1614))'),
              'source' => array('data' => 'services'),
              'optional' => FALSE,
            ),
            array(
              'name' => 'column_name',
              'type' => 'string',
              'description' => t('Optional column(s) to be shown. Defaults to value column if the argument is not set.'),
              'source' => array('data' => 'column_name'),
              'optional' => TRUE,
            ),
          ),
        ),
      ),
    ),
  );

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
function _kms_services_resources_user_resource_create($account)
{
  // Validate our data.
  $validation = _kms_services_resources_user_resource_create_validate($account);

  // Handle validation fail.
  if (!empty($validation)) {
    return services_error(t('Data could not be validated.'), 422, array('errors' => $validation));
  }

  $new_user = array(
    'name' => $account['name'],
    'pass' => $account['pass'],
    'mail' => $account['email'],
    'status' => $account['status'],
    'timezone' => NULL,
    'roles' => array(
      DRUPAL_AUTHENTICATED_RID => 'authenticated user',
    ),
  );

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
function _kms_services_resources_user_resource_create_validate($account)
{
  // Init. return var.
  $errors = array();

  // Is there any data at all ?
  if (empty($account) || !is_array($account) || (isset($account[0]) && $account[0] == NULL)) {
    return array('No data was submitted');
  }

  // Required for creation.
  $required_fields = array('name', 'email', 'user_type', 'terms_and_conditions');
  foreach ($required_fields as $required_field) {
    if (!key_exists($required_field, $account)) {
      $errors[] = t('Field missing @s', array('@s' => $required_field));
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
function _kms_services_resources_user_resource_access($op = 'view', $args = array())
{

  return TRUE;

  // Adds backwards compatability with regression fixed in #1083242
  if (isset($args[0])) {
    $args[0] = _services_access_value($args[0], array('account', 'data'));
  }

  // Check if the user exists if appropriate.
  if ($op != 'create' && $op != 'register') {
    $account = user_load($args[0]);
    if (!$account) {
      return services_error(t('There is no user with ID @uid.', array('@uid' => $args[0])), 404);
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
      } else {
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
function _kms_services_resources_get_services_list()
{
  $services = kms_permissions_get_service_list();

  // If nothing, return empty array.
  if (!$services) {
    return array();
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
function _kms_services_resources_get_uids_by_separate_services($services, $column_name = NULL)
{

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
  return array($uids);

}