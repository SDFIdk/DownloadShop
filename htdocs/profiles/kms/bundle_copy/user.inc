<?php

$data = array(
  'bundles' => array(
    'user' => NULL,
  ),
  'fields' => array(
    'field_access_bundles' => array(
      'entity_types' => array(),
      'field_permissions' => array(
        'type' => '2',
      ),
      'foreign keys' => array(
        'nid' => array(
          'table' => 'node',
          'columns' => array(
            'nid' => 'nid',
          ),
        ),
      ),
      'indexes' => array(
        'nid' => array(
          0 => 'nid',
        ),
      ),
      'settings' => array(
        'referenceable_types' => array(
          'access_bundle' => 'access_bundle',
          'downloads' => 0,
          'front' => 0,
          'kort_test' => 0,
          'page' => 0,
          'panel' => 0,
          'product_display' => 0,
          'product_listing' => 0,
          'user_registration_form' => 0,
        ),
        'view' => array(
          'args' => array(),
          'display_name' => '',
          'view_name' => '',
        ),
      ),
      'translatable' => '0',
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_access_bundles' => array(
                'nid' => 'field_access_bundles_nid',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_access_bundles' => array(
                'nid' => 'field_access_bundles_nid',
              ),
            ),
          ),
        ),
      ),
      'field_name' => 'field_access_bundles',
      'type' => 'node_reference',
      'module' => 'node_reference',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '-1',
      'deleted' => '0',
      'columns' => array(
        'nid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'user' => array(
          0 => 'user',
        ),
      ),
    ),
    'field_address' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_address' => array(
                'country' => 'field_address_country',
                'administrative_area' => 'field_address_administrative_area',
                'sub_administrative_area' => 'field_address_sub_administrative_area',
                'locality' => 'field_address_locality',
                'dependent_locality' => 'field_address_dependent_locality',
                'postal_code' => 'field_address_postal_code',
                'thoroughfare' => 'field_address_thoroughfare',
                'premise' => 'field_address_premise',
                'sub_premise' => 'field_address_sub_premise',
                'organisation_name' => 'field_address_organisation_name',
                'name_line' => 'field_address_name_line',
                'first_name' => 'field_address_first_name',
                'last_name' => 'field_address_last_name',
                'data' => 'field_address_data',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_address' => array(
                'country' => 'field_address_country',
                'administrative_area' => 'field_address_administrative_area',
                'sub_administrative_area' => 'field_address_sub_administrative_area',
                'locality' => 'field_address_locality',
                'dependent_locality' => 'field_address_dependent_locality',
                'postal_code' => 'field_address_postal_code',
                'thoroughfare' => 'field_address_thoroughfare',
                'premise' => 'field_address_premise',
                'sub_premise' => 'field_address_sub_premise',
                'organisation_name' => 'field_address_organisation_name',
                'name_line' => 'field_address_name_line',
                'first_name' => 'field_address_first_name',
                'last_name' => 'field_address_last_name',
                'data' => 'field_address_data',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'field_permissions' => array(
        'type' => '2',
      ),
      'field_name' => 'field_address',
      'type' => 'addressfield',
      'module' => 'addressfield',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'country' => array(
          'description' => 'Two letter ISO country code of this address.',
          'type' => 'varchar',
          'length' => 2,
          'not null' => FALSE,
          'default' => '',
        ),
        'administrative_area' => array(
          'description' => 'The administrative area of this address. (i.e. State/Province)',
          'type' => 'varchar',
          'length' => 255,
          'default' => '',
          'not null' => FALSE,
        ),
        'sub_administrative_area' => array(
          'description' => 'The sub administrative area of this address.',
          'type' => 'varchar',
          'length' => 255,
          'default' => '',
          'not null' => FALSE,
        ),
        'locality' => array(
          'description' => 'The locality of this address. (i.e. City)',
          'type' => 'varchar',
          'length' => 255,
          'default' => '',
          'not null' => FALSE,
        ),
        'dependent_locality' => array(
          'description' => 'The dependent locality of this address.',
          'type' => 'varchar',
          'length' => 255,
          'default' => '',
          'not null' => FALSE,
        ),
        'postal_code' => array(
          'description' => 'The postal code of this address.',
          'type' => 'varchar',
          'length' => 255,
          'default' => '',
          'not null' => FALSE,
        ),
        'thoroughfare' => array(
          'description' => 'The thoroughfare of this address. (i.e. Street address)',
          'type' => 'varchar',
          'length' => 255,
          'default' => '',
          'not null' => FALSE,
        ),
        'premise' => array(
          'description' => 'The premise of this address. (i.e. Apartment / Suite number)',
          'type' => 'varchar',
          'length' => 255,
          'default' => '',
          'not null' => FALSE,
        ),
        'sub_premise' => array(
          'description' => 'The sub_premise of this address.',
          'type' => 'varchar',
          'length' => 255,
          'default' => '',
          'not null' => FALSE,
        ),
        'organisation_name' => array(
          'description' => 'Contents of a primary OrganisationName element in the xNL XML.',
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
          'default' => '',
        ),
        'name_line' => array(
          'description' => 'Contents of a primary NameLine element in the xNL XML.',
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
          'default' => '',
        ),
        'first_name' => array(
          'description' => 'Contents of the FirstName element of a primary PersonName element in the xNL XML.',
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
          'default' => '',
        ),
        'last_name' => array(
          'description' => 'Contents of the LastName element of a primary PersonName element in the xNL XML.',
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
          'default' => '',
        ),
        'data' => array(
          'description' => 'Additional data for this address.',
          'type' => 'text',
          'size' => 'big',
          'not null' => FALSE,
          'serialize' => TRUE,
        ),
      ),
      'bundles' => array(
        'user' => array(
          0 => 'user',
        ),
      ),
    ),
    'field_billing_address' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_billing_address' => array(
                'country' => 'field_billing_address_country',
                'administrative_area' => 'field_billing_address_administrative_area',
                'sub_administrative_area' => 'field_billing_address_sub_administrative_area',
                'locality' => 'field_billing_address_locality',
                'dependent_locality' => 'field_billing_address_dependent_locality',
                'postal_code' => 'field_billing_address_postal_code',
                'thoroughfare' => 'field_billing_address_thoroughfare',
                'premise' => 'field_billing_address_premise',
                'sub_premise' => 'field_billing_address_sub_premise',
                'organisation_name' => 'field_billing_address_organisation_name',
                'name_line' => 'field_billing_address_name_line',
                'first_name' => 'field_billing_address_first_name',
                'last_name' => 'field_billing_address_last_name',
                'data' => 'field_billing_address_data',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_billing_address' => array(
                'country' => 'field_billing_address_country',
                'administrative_area' => 'field_billing_address_administrative_area',
                'sub_administrative_area' => 'field_billing_address_sub_administrative_area',
                'locality' => 'field_billing_address_locality',
                'dependent_locality' => 'field_billing_address_dependent_locality',
                'postal_code' => 'field_billing_address_postal_code',
                'thoroughfare' => 'field_billing_address_thoroughfare',
                'premise' => 'field_billing_address_premise',
                'sub_premise' => 'field_billing_address_sub_premise',
                'organisation_name' => 'field_billing_address_organisation_name',
                'name_line' => 'field_billing_address_name_line',
                'first_name' => 'field_billing_address_first_name',
                'last_name' => 'field_billing_address_last_name',
                'data' => 'field_billing_address_data',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'field_permissions' => array(
        'type' => '2',
      ),
      'field_name' => 'field_billing_address',
      'type' => 'addressfield',
      'module' => 'addressfield',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'country' => array(
          'description' => 'Two letter ISO country code of this address.',
          'type' => 'varchar',
          'length' => 2,
          'not null' => FALSE,
          'default' => '',
        ),
        'administrative_area' => array(
          'description' => 'The administrative area of this address. (i.e. State/Province)',
          'type' => 'varchar',
          'length' => 255,
          'default' => '',
          'not null' => FALSE,
        ),
        'sub_administrative_area' => array(
          'description' => 'The sub administrative area of this address.',
          'type' => 'varchar',
          'length' => 255,
          'default' => '',
          'not null' => FALSE,
        ),
        'locality' => array(
          'description' => 'The locality of this address. (i.e. City)',
          'type' => 'varchar',
          'length' => 255,
          'default' => '',
          'not null' => FALSE,
        ),
        'dependent_locality' => array(
          'description' => 'The dependent locality of this address.',
          'type' => 'varchar',
          'length' => 255,
          'default' => '',
          'not null' => FALSE,
        ),
        'postal_code' => array(
          'description' => 'The postal code of this address.',
          'type' => 'varchar',
          'length' => 255,
          'default' => '',
          'not null' => FALSE,
        ),
        'thoroughfare' => array(
          'description' => 'The thoroughfare of this address. (i.e. Street address)',
          'type' => 'varchar',
          'length' => 255,
          'default' => '',
          'not null' => FALSE,
        ),
        'premise' => array(
          'description' => 'The premise of this address. (i.e. Apartment / Suite number)',
          'type' => 'varchar',
          'length' => 255,
          'default' => '',
          'not null' => FALSE,
        ),
        'sub_premise' => array(
          'description' => 'The sub_premise of this address.',
          'type' => 'varchar',
          'length' => 255,
          'default' => '',
          'not null' => FALSE,
        ),
        'organisation_name' => array(
          'description' => 'Contents of a primary OrganisationName element in the xNL XML.',
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
          'default' => '',
        ),
        'name_line' => array(
          'description' => 'Contents of a primary NameLine element in the xNL XML.',
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
          'default' => '',
        ),
        'first_name' => array(
          'description' => 'Contents of the FirstName element of a primary PersonName element in the xNL XML.',
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
          'default' => '',
        ),
        'last_name' => array(
          'description' => 'Contents of the LastName element of a primary PersonName element in the xNL XML.',
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
          'default' => '',
        ),
        'data' => array(
          'description' => 'Additional data for this address.',
          'type' => 'text',
          'size' => 'big',
          'not null' => FALSE,
          'serialize' => TRUE,
        ),
      ),
      'bundles' => array(
        'user' => array(
          0 => 'user',
        ),
      ),
    ),
    'field_bundle_webservices_geo' => array(
      'entity_types' => array(),
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_bundle_webservices_geo' => array(
                'value' => 'field_bundle_webservices_geo_value',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_bundle_webservices_geo' => array(
                'value' => 'field_bundle_webservices_geo_value',
              ),
            ),
          ),
        ),
      ),
      'field_name' => 'field_bundle_webservices_geo',
      'type' => 'list_text',
      'module' => 'list',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '-1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'node' => array(
          0 => 'access_bundle',
        ),
        'user' => array(
          0 => 'user',
        ),
      ),
    ),
    'field_bundle_webservices_wfs' => array(
      'entity_types' => array(),
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_bundle_webservices_wfs' => array(
                'value' => 'field_bundle_webservices_wfs_value',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_bundle_webservices_wfs' => array(
                'value' => 'field_bundle_webservices_wfs_value',
              ),
            ),
          ),
        ),
      ),
      'field_name' => 'field_bundle_webservices_wfs',
      'type' => 'list_text',
      'module' => 'list',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '-1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'node' => array(
          0 => 'access_bundle',
        ),
        'user' => array(
          0 => 'user',
        ),
      ),
    ),
    'field_bundles' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'bundle',
            'parent' => '0',
          ),
        ),
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_bundles' => array(
                'tid' => 'field_bundles_tid',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_bundles' => array(
                'tid' => 'field_bundles_tid',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'tid' => array(
          'table' => 'taxonomy_term_data',
          'columns' => array(
            'tid' => 'tid',
          ),
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'field_permissions' => array(
        'type' => '2',
      ),
      'field_name' => 'field_bundles',
      'type' => 'taxonomy_term_reference',
      'module' => 'taxonomy',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '-1',
      'deleted' => '0',
      'columns' => array(
        'tid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'user' => array(
          0 => 'user',
        ),
      ),
    ),
    'field_contact_me' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'allowed_values' => array(
          0 => 'Nej',
          1 => 'Ja',
        ),
        'allowed_values_function' => '',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_contact_me' => array(
                'value' => 'field_contact_me_value',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_contact_me' => array(
                'value' => 'field_contact_me_value',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'field_permissions' => array(
        'type' => '0',
      ),
      'field_name' => 'field_contact_me',
      'type' => 'list_boolean',
      'module' => 'list',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'int',
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'user' => array(
          0 => 'user',
        ),
      ),
    ),
    'field_debtor_nr' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_debtor_nr' => array(
                'value' => 'field_debtor_nr_value',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_debtor_nr' => array(
                'value' => 'field_debtor_nr_value',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'field_permissions' => array(
        'type' => '2',
      ),
      'field_name' => 'field_debtor_nr',
      'type' => 'number_integer',
      'module' => 'number',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'int',
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'user' => array(
          0 => 'user',
        ),
      ),
    ),
    'field_expire_date' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'granularity' => array(
          'month' => 'month',
          'day' => 'day',
          'year' => 'year',
          'hour' => 0,
          'minute' => 0,
          'second' => 0,
        ),
        'tz_handling' => 'none',
        'timezone_db' => '',
        'cache_enabled' => 0,
        'cache_count' => '4',
        'todate' => '',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_expire_date' => array(
                'value' => 'field_expire_date_value',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_expire_date' => array(
                'value' => 'field_expire_date_value',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'field_permissions' => array(
        'type' => '2',
      ),
      'field_name' => 'field_expire_date',
      'type' => 'datestamp',
      'module' => 'date',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'int',
          'not null' => FALSE,
          'sortable' => TRUE,
          'views' => TRUE,
        ),
      ),
      'bundles' => array(
        'user' => array(
          0 => 'user',
        ),
      ),
    ),
    'field_kms_user_id' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => '255',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_kms_user_id' => array(
                'value' => 'field_kms_user_id_value',
                'format' => 'field_kms_user_id_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_kms_user_id' => array(
                'value' => 'field_kms_user_id_value',
                'format' => 'field_kms_user_id_format',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'format' => array(
          'table' => 'filter_format',
          'columns' => array(
            'format' => 'format',
          ),
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'field_permissions' => array(
        'type' => '2',
      ),
      'field_name' => 'field_kms_user_id',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'user' => array(
          0 => 'user',
        ),
      ),
    ),
    'field_newsletter' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'allowed_values' => array(
          0 => 'Nej',
          1 => 'Ja',
        ),
        'allowed_values_function' => '',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_newsletter' => array(
                'value' => 'field_newsletter_value',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_newsletter' => array(
                'value' => 'field_newsletter_value',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'field_permissions' => array(
        'type' => '0',
      ),
      'field_name' => 'field_newsletter',
      'type' => 'list_boolean',
      'module' => 'list',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'int',
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'user' => array(
          0 => 'user',
        ),
      ),
    ),
    'field_pass_clear' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => '255',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_pass_clear' => array(
                'value' => 'field_pass_clear_value',
                'format' => 'field_pass_clear_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_pass_clear' => array(
                'value' => 'field_pass_clear_value',
                'format' => 'field_pass_clear_format',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'format' => array(
          'table' => 'filter_format',
          'columns' => array(
            'format' => 'format',
          ),
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'field_permissions' => array(
        'type' => '2',
      ),
      'field_name' => 'field_pass_clear',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'user' => array(
          0 => 'user',
        ),
      ),
    ),
    'field_phone' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => '255',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_phone' => array(
                'value' => 'field_phone_value',
                'format' => 'field_phone_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_phone' => array(
                'value' => 'field_phone_value',
                'format' => 'field_phone_format',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'format' => array(
          'table' => 'filter_format',
          'columns' => array(
            'format' => 'format',
          ),
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'field_permissions' => array(
        'type' => '2',
      ),
      'field_name' => 'field_phone',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'user' => array(
          0 => 'user',
        ),
      ),
    ),
    'field_terms_and_conditions' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'allowed_values' => array(
          0 => 'Nej',
          1 => 'Ja',
        ),
        'allowed_values_function' => '',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_terms_and_conditions' => array(
                'value' => 'field_terms_and_conditions_value',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_terms_and_conditions' => array(
                'value' => 'field_terms_and_conditions_value',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'field_permissions' => array(
        'type' => '2',
      ),
      'field_name' => 'field_terms_and_conditions',
      'type' => 'list_boolean',
      'module' => 'list',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'int',
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'user' => array(
          0 => 'user',
        ),
      ),
    ),
    'field_updated' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'granularity' => array(
          'month' => 'month',
          'day' => 'day',
          'hour' => 'hour',
          'minute' => 'minute',
          'year' => 'year',
          'second' => 0,
        ),
        'tz_handling' => 'site',
        'timezone_db' => 'UTC',
        'cache_enabled' => 0,
        'cache_count' => '4',
        'todate' => '',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_updated' => array(
                'value' => 'field_updated_value',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_updated' => array(
                'value' => 'field_updated_value',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'field_permissions' => array(
        'type' => '2',
      ),
      'field_name' => 'field_updated',
      'type' => 'datestamp',
      'module' => 'date',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'int',
          'not null' => FALSE,
          'sortable' => TRUE,
          'views' => TRUE,
        ),
      ),
      'bundles' => array(
        'user' => array(
          0 => 'user',
        ),
      ),
    ),
    'field_user_remark' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_user_remark' => array(
                'value' => 'field_user_remark_value',
                'format' => 'field_user_remark_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_user_remark' => array(
                'value' => 'field_user_remark_value',
                'format' => 'field_user_remark_format',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'format' => array(
          'table' => 'filter_format',
          'columns' => array(
            'format' => 'format',
          ),
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'field_permissions' => array(
        'type' => '2',
      ),
      'field_name' => 'field_user_remark',
      'type' => 'text_long',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'text',
          'size' => 'big',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'user' => array(
          0 => 'user',
        ),
      ),
    ),
    'field_user_type' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'user_type',
            'parent' => '0',
          ),
        ),
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_user_type' => array(
                'tid' => 'field_user_type_tid',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_user_type' => array(
                'tid' => 'field_user_type_tid',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'tid' => array(
          'table' => 'taxonomy_term_data',
          'columns' => array(
            'tid' => 'tid',
          ),
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'field_permissions' => array(
        'type' => '2',
      ),
      'field_name' => 'field_user_type',
      'type' => 'taxonomy_term_reference',
      'module' => 'taxonomy',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '-1',
      'deleted' => '0',
      'columns' => array(
        'tid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'user' => array(
          0 => 'user',
        ),
      ),
    ),
    'field_user_type_info' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_user_type_info' => array(
                'value' => 'field_user_type_info_value',
                'format' => 'field_user_type_info_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_user_type_info' => array(
                'value' => 'field_user_type_info_value',
                'format' => 'field_user_type_info_format',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'format' => array(
          'table' => 'filter_format',
          'columns' => array(
            'format' => 'format',
          ),
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'field_permissions' => array(
        'type' => '2',
      ),
      'field_name' => 'field_user_type_info',
      'type' => 'text_long',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'text',
          'size' => 'big',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'user' => array(
          0 => 'user',
        ),
      ),
    ),
    'field_webservices_extra' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'webservices',
            'parent' => '0',
          ),
        ),
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_webservices_extra' => array(
                'tid' => 'field_webservices_extra_tid',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_webservices_extra' => array(
                'tid' => 'field_webservices_extra_tid',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'tid' => array(
          'table' => 'taxonomy_term_data',
          'columns' => array(
            'tid' => 'tid',
          ),
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'field_permissions' => array(
        'type' => '2',
      ),
      'field_name' => 'field_webservices_extra',
      'type' => 'taxonomy_term_reference',
      'module' => 'taxonomy',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '-1',
      'deleted' => '0',
      'columns' => array(
        'tid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'user' => array(
          0 => 'user',
        ),
      ),
    ),
  ),
  'instances' => array(
    'field_access_bundles' => array(
      0 => array(
        'default_value' => NULL,
        'description' => '',
        'display' => array(
          'default' => array(
            'label' => 'above',
            'module' => 'node_reference',
            'settings' => array(),
            'type' => 'node_reference_default',
            'weight' => 25,
          ),
        ),
        'label' => 'Bundles',
        'required' => 0,
        'settings' => array(
          'user_register_form' => 0,
        ),
        'widget' => array(
          'active' => 1,
          'module' => 'options',
          'settings' => array(),
          'type' => 'options_buttons',
          'weight' => '8',
        ),
        'field_name' => 'field_access_bundles',
        'entity_type' => 'user',
        'bundle' => 'user',
        'deleted' => '0',
      ),
    ),
    'field_address' => array(
      0 => array(
        'default_value' => array(
          0 => array(
            'element_key' => 'user|user|field_address|und|0',
            'thoroughfare' => '',
            'premise' => '',
            'postal_code' => '',
            'locality' => '',
            'country' => 'DK',
            'organisation_name' => '',
            'first_name' => '',
            'last_name' => '',
          ),
        ),
        'description' => '',
        'display' => array(
          'default' => array(
            'label' => 'above',
            'module' => 'addressfield',
            'settings' => array(
              'format_handlers' => array(
                0 => 'address',
              ),
              'use_widget_handlers' => 1,
            ),
            'type' => 'addressfield_default',
            'weight' => 0,
          ),
        ),
        'label' => 'Address',
        'required' => 0,
        'settings' => array(
          'user_register_form' => 0,
        ),
        'widget' => array(
          'active' => 1,
          'module' => 'addressfield',
          'settings' => array(
            'available_countries' => array(
              'DK' => 'DK',
              'NO' => 'NO',
              'SE' => 'SE',
              'US' => 'US',
            ),
            'format_handlers' => array(
              'address' => 'address',
              'organisation' => 'organisation',
              'name-full' => 'name-full',
              'address-hide-country' => 0,
              'name-oneline' => 0,
            ),
          ),
          'type' => 'addressfield_standard',
          'weight' => '4',
        ),
        'field_name' => 'field_address',
        'entity_type' => 'user',
        'bundle' => 'user',
        'deleted' => '0',
      ),
    ),
    'field_billing_address' => array(
      0 => array(
        'label' => 'Faktureringsadresse',
        'widget' => array(
          'weight' => '6',
          'type' => 'addressfield_standard',
          'module' => 'addressfield',
          'active' => 1,
          'settings' => array(
            'available_countries' => array(
              'DK' => 'DK',
            ),
            'format_handlers' => array(
              'address' => 'address',
              'address-hide-country' => 'address-hide-country',
              'organisation' => 0,
              'name-full' => 0,
              'name-oneline' => 0,
            ),
          ),
        ),
        'settings' => array(
          'user_register_form' => 1,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'addressfield_default',
            'settings' => array(
              'use_widget_handlers' => 1,
              'format_handlers' => array(
                0 => 'address',
              ),
            ),
            'module' => 'addressfield',
            'weight' => 9,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => array(
          0 => array(
            'element_key' => 'user|user|field_billing_address|und|0',
            'thoroughfare' => '',
            'premise' => '',
            'postal_code' => '',
            'locality' => '',
            'country' => 'DK',
          ),
        ),
        'field_name' => 'field_billing_address',
        'entity_type' => 'user',
        'bundle' => 'user',
        'deleted' => '0',
      ),
    ),
    'field_bundle_webservices_geo' => array(
      0 => array(
        'label' => 'Webservices (GEO)',
        'widget' => array(
          'weight' => '10',
          'type' => 'kms_services',
          'module' => 'kms_permissions',
          'active' => 1,
          'settings' => array(
            'type' => 'GEO',
          ),
        ),
        'settings' => array(
          'user_register_form' => 0,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'list_default',
            'settings' => array(),
            'module' => 'list',
            'weight' => 26,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_bundle_webservices_geo',
        'entity_type' => 'user',
        'bundle' => 'user',
        'deleted' => '0',
      ),
    ),
    'field_bundle_webservices_wfs' => array(
      0 => array(
        'label' => 'Webservices (WFS)',
        'widget' => array(
          'weight' => '47',
          'type' => 'kms_services',
          'module' => 'kms_permissions',
          'active' => 1,
          'settings' => array(
            'type' => 'WFS',
          ),
        ),
        'settings' => array(
          'user_register_form' => 0,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'list_default',
            'settings' => array(),
            'module' => 'list',
            'weight' => 27,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_bundle_webservices_wfs',
        'entity_type' => 'user',
        'bundle' => 'user',
        'deleted' => '0',
      ),
    ),
    'field_bundles' => array(
      0 => array(
        'label' => 'Bundles',
        'widget' => array(
          'weight' => '10',
          'type' => 'options_buttons',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => 1,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'taxonomy_term_reference_link',
            'settings' => array(),
            'module' => 'taxonomy',
            'weight' => 13,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_bundles',
        'entity_type' => 'user',
        'bundle' => 'user',
        'deleted' => '0',
      ),
    ),
    'field_contact_me' => array(
      0 => array(
        'default_value' => array(
          0 => array(
            'value' => 0,
          ),
        ),
        'description' => '',
        'display' => array(
          'default' => array(
            'label' => 'above',
            'module' => 'list',
            'settings' => array(),
            'type' => 'list_default',
            'weight' => 5,
          ),
        ),
        'label' => 'Geodatastyrelsen må gerne kontakte mig i forbindelse med tilfredshed- og brugerundersøgelser',
        'required' => 0,
        'settings' => array(
          'user_register_form' => 1,
        ),
        'widget' => array(
          'active' => 1,
          'module' => 'options',
          'settings' => array(
            'display_label' => 1,
          ),
          'type' => 'options_onoff',
          'weight' => '42',
        ),
        'field_name' => 'field_contact_me',
        'entity_type' => 'user',
        'bundle' => 'user',
        'deleted' => '0',
      ),
    ),
    'field_debtor_nr' => array(
      0 => array(
        'label' => 'Debitor nr',
        'widget' => array(
          'weight' => '4',
          'type' => 'number',
          'module' => 'number',
          'active' => 0,
          'settings' => array(),
        ),
        'settings' => array(
          'min' => '',
          'max' => '',
          'prefix' => '',
          'suffix' => '',
          'user_register_form' => 0,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'number_integer',
            'settings' => array(
              'thousand_separator' => ' ',
              'decimal_separator' => '.',
              'scale' => 0,
              'prefix_suffix' => TRUE,
            ),
            'module' => 'number',
            'weight' => 11,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_debtor_nr',
        'entity_type' => 'user',
        'bundle' => 'user',
        'deleted' => '0',
      ),
    ),
    'field_expire_date' => array(
      0 => array(
        'description' => '',
        'display' => array(
          'default' => array(
            'label' => 'above',
            'module' => 'date',
            'settings' => array(
              'format_type' => 'long',
              'fromto' => 'both',
              'multiple_from' => '',
              'multiple_number' => '',
              'multiple_to' => '',
            ),
            'type' => 'date_default',
            'weight' => 23,
          ),
        ),
        'label' => 'Udløbsdato',
        'required' => 0,
        'settings' => array(
          'default_value' => 'blank',
          'default_value2' => 'same',
          'default_value_code' => '',
          'default_value_code2' => '',
          'user_register_form' => 1,
        ),
        'widget' => array(
          'active' => 1,
          'module' => 'date',
          'settings' => array(
            'increment' => '15',
            'input_format' => 'm/d/Y - H:i:s',
            'input_format_custom' => '',
            'label_position' => 'within',
            'text_parts' => array(),
            'year_range' => '-3:+3',
          ),
          'type' => 'date_select',
          'weight' => '43',
        ),
        'field_name' => 'field_expire_date',
        'entity_type' => 'user',
        'bundle' => 'user',
        'deleted' => '0',
      ),
    ),
    'field_kms_user_id' => array(
      0 => array(
        'label' => 'KMS User ID',
        'widget' => array(
          'weight' => '3',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
          'user_register_form' => 1,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'text_default',
            'settings' => array(),
            'module' => 'text',
            'weight' => 3,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_kms_user_id',
        'entity_type' => 'user',
        'bundle' => 'user',
        'deleted' => '0',
      ),
    ),
    'field_newsletter' => array(
      0 => array(
        'label' => 'Ja tak, jeg vil gerne modtage jeres nyhedsbrev',
        'widget' => array(
          'weight' => '40',
          'type' => 'options_onoff',
          'module' => 'options',
          'active' => 1,
          'settings' => array(
            'display_label' => 1,
          ),
        ),
        'settings' => array(
          'user_register_form' => 1,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'list_default',
            'settings' => array(),
            'module' => 'list',
            'weight' => 19,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => array(
          0 => array(
            'value' => 0,
          ),
        ),
        'field_name' => 'field_newsletter',
        'entity_type' => 'user',
        'bundle' => 'user',
        'deleted' => '0',
      ),
    ),
    'field_pass_clear' => array(
      0 => array(
        'default_value' => NULL,
        'description' => '',
        'display' => array(
          'default' => array(
            'label' => 'above',
            'module' => 'text',
            'settings' => array(),
            'type' => 'text_default',
            'weight' => 24,
          ),
        ),
        'label' => 'Kodeord',
        'required' => 0,
        'settings' => array(
          'text_processing' => '0',
          'user_register_form' => 0,
        ),
        'widget' => array(
          'active' => 1,
          'module' => 'text',
          'settings' => array(
            'size' => '60',
          ),
          'type' => 'text_textfield',
          'weight' => '3',
        ),
        'field_name' => 'field_pass_clear',
        'entity_type' => 'user',
        'bundle' => 'user',
        'deleted' => '0',
      ),
    ),
    'field_phone' => array(
      0 => array(
        'label' => 'Telefon',
        'widget' => array(
          'weight' => '5',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
          'user_register_form' => 1,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'text_default',
            'settings' => array(),
            'module' => 'text',
            'weight' => 16,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_phone',
        'entity_type' => 'user',
        'bundle' => 'user',
        'deleted' => '0',
      ),
    ),
    'field_terms_and_conditions' => array(
      0 => array(
        'label' => 'Jeg accepterer de rettigheder der er tilknyttet data',
        'widget' => array(
          'weight' => '39',
          'type' => 'options_onoff',
          'module' => 'options',
          'active' => 1,
          'settings' => array(
            'display_label' => 1,
          ),
        ),
        'settings' => array(
          'user_register_form' => 1,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'list_default',
            'settings' => array(),
            'module' => 'list',
            'weight' => 18,
          ),
        ),
        'required' => 1,
        'description' => '',
        'default_value' => array(
          0 => array(
            'value' => 0,
          ),
        ),
        'field_name' => 'field_terms_and_conditions',
        'entity_type' => 'user',
        'bundle' => 'user',
        'deleted' => '0',
      ),
    ),
    'field_updated' => array(
      0 => array(
        'label' => 'Updated',
        'widget' => array(
          'weight' => '44',
          'type' => 'date_text',
          'module' => 'date',
          'active' => 1,
          'settings' => array(
            'input_format' => 'm/d/Y - H:i:s',
            'input_format_custom' => '',
            'year_range' => '-3:+3',
            'increment' => 15,
            'label_position' => 'above',
            'text_parts' => array(),
          ),
        ),
        'settings' => array(
          'default_value' => 'blank',
          'default_value_code' => '',
          'default_value2' => 'same',
          'default_value_code2' => '',
          'user_register_form' => 0,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'date_default',
            'settings' => array(
              'format_type' => 'long',
              'multiple_number' => '',
              'multiple_from' => '',
              'multiple_to' => '',
              'fromto' => 'both',
            ),
            'module' => 'date',
            'weight' => 21,
          ),
        ),
        'required' => 0,
        'description' => '',
        'field_name' => 'field_updated',
        'entity_type' => 'user',
        'bundle' => 'user',
        'deleted' => '0',
      ),
    ),
    'field_user_remark' => array(
      0 => array(
        'label' => 'Brugerbemærkning',
        'widget' => array(
          'weight' => '45',
          'type' => 'text_textarea',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'rows' => '5',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
          'user_register_form' => 1,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'text_default',
            'settings' => array(),
            'module' => 'text',
            'weight' => 20,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_user_remark',
        'entity_type' => 'user',
        'bundle' => 'user',
        'deleted' => '0',
      ),
    ),
    'field_user_type' => array(
      0 => array(
        'label' => 'Brugertype',
        'widget' => array(
          'weight' => '2',
          'type' => 'taxonomy_hs',
          'module' => 'hs_taxonomy',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => 1,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'taxonomy_term_reference_link',
            'settings' => array(),
            'module' => 'taxonomy',
            'weight' => 12,
          ),
        ),
        'required' => 1,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_user_type',
        'entity_type' => 'user',
        'bundle' => 'user',
        'deleted' => '0',
      ),
    ),
    'field_user_type_info' => array(
      0 => array(
        'default_value' => NULL,
        'description' => '',
        'display' => array(
          'default' => array(
            'label' => 'above',
            'module' => 'text',
            'settings' => array(),
            'type' => 'text_default',
            'weight' => 6,
          ),
        ),
        'label' => 'Bruger type info',
        'required' => 0,
        'settings' => array(
          'text_processing' => '0',
          'user_register_form' => 1,
        ),
        'widget' => array(
          'active' => 1,
          'module' => 'text',
          'settings' => array(
            'rows' => '3',
          ),
          'type' => 'text_textarea',
          'weight' => '3',
        ),
        'field_name' => 'field_user_type_info',
        'entity_type' => 'user',
        'bundle' => 'user',
        'deleted' => '0',
      ),
    ),
    'field_webservices_extra' => array(
      0 => array(
        'label' => 'Ekstra webservices',
        'widget' => array(
          'weight' => '12',
          'type' => 'options_buttons',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => 1,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'taxonomy_term_reference_link',
            'settings' => array(),
            'module' => 'taxonomy',
            'weight' => 15,
          ),
        ),
        'required' => 0,
        'description' => '',
        'default_value' => NULL,
        'field_name' => 'field_webservices_extra',
        'entity_type' => 'user',
        'bundle' => 'user',
        'deleted' => '0',
      ),
    ),
  ),
  'fieldgroups' => array(
    'group_master_data|user|user|form' => (object) array(
        'id' => '11',
        'identifier' => 'group_master_data|user|user|form',
        'group_name' => 'group_master_data',
        'entity_type' => 'user',
        'bundle' => 'user',
        'mode' => 'form',
        'parent_name' => '',
        'table' => 'field_group',
        'type' => 'Overridden',
        'export_type' => 3,
        'disabled' => FALSE,
        'export_module' => 'user_fields',
        'label' => 'Stamdata',
        'weight' => '1',
        'children' => array(
          0 => 'field_phone',
          1 => 'field_pass_clear',
          2 => 'field_billing_address',
          3 => 'field_address',
          4 => 'account',
        ),
        'format_type' => 'fieldset',
        'format_settings' => array(
          'label' => 'Stamdata',
          'instance_settings' => array(
            'required_fields' => 1,
            'classes' => '',
            'description' => '',
          ),
          'formatter' => 'open',
        ),
      ),
    'group_wfs|user|user|form' => (object) array(
        'id' => '18',
        'identifier' => 'group_wfs|user|user|form',
        'group_name' => 'group_wfs',
        'entity_type' => 'user',
        'bundle' => 'user',
        'mode' => 'form',
        'parent_name' => 'group_webservices',
        'table' => 'field_group',
        'type' => 'Normal',
        'export_type' => 1,
        'disabled' => FALSE,
        'label' => 'WFS',
        'weight' => '11',
        'children' => array(
          0 => 'field_bundle_webservices_wfs',
        ),
        'format_type' => 'htab',
        'format_settings' => array(
          'formatter' => 'closed',
          'instance_settings' => array(
            'description' => '',
            'classes' => '',
            'required_fields' => 1,
          ),
        ),
      ),
    'group_webservices|user|user|form' => (object) array(
        'id' => '17',
        'identifier' => 'group_webservices|user|user|form',
        'group_name' => 'group_webservices',
        'entity_type' => 'user',
        'bundle' => 'user',
        'mode' => 'form',
        'parent_name' => 'group_access_bundles',
        'table' => 'field_group',
        'type' => 'Normal',
        'export_type' => 1,
        'disabled' => FALSE,
        'label' => 'Webservices',
        'weight' => '9',
        'children' => array(
          0 => 'group_wfs',
          1 => 'group_webservices_geo',
        ),
        'format_type' => 'htabs',
        'format_settings' => array(
          'formatter' => '',
          'instance_settings' => array(
            'classes' => '',
          ),
        ),
      ),
    'group_other|user|user|form' => (object) array(
        'id' => '14',
        'identifier' => 'group_other|user|user|form',
        'group_name' => 'group_other',
        'entity_type' => 'user',
        'bundle' => 'user',
        'mode' => 'form',
        'parent_name' => '',
        'table' => 'field_group',
        'type' => 'Overridden',
        'export_type' => 3,
        'disabled' => FALSE,
        'export_module' => 'user_fields',
        'label' => 'Andet',
        'weight' => '5',
        'children' => array(
          0 => 'field_user_remark',
          1 => 'field_updated',
          2 => 'field_expire_date',
        ),
        'format_type' => 'fieldset',
        'format_settings' => array(
          'label' => 'Andet',
          'instance_settings' => array(
            'required_fields' => 1,
            'classes' => '',
            'description' => '',
          ),
          'formatter' => 'collapsible',
        ),
      ),
    'group_webservices_geo|user|user|form' => (object) array(
        'id' => '16',
        'identifier' => 'group_webservices_geo|user|user|form',
        'group_name' => 'group_webservices_geo',
        'entity_type' => 'user',
        'bundle' => 'user',
        'mode' => 'form',
        'parent_name' => 'group_webservices',
        'table' => 'field_group',
        'type' => 'Normal',
        'export_type' => 1,
        'disabled' => FALSE,
        'label' => 'GEO',
        'weight' => '10',
        'children' => array(
          0 => 'field_bundle_webservices_geo',
        ),
        'format_type' => 'htab',
        'format_settings' => array(
          'formatter' => 'closed',
          'instance_settings' => array(
            'description' => '',
            'classes' => '',
            'required_fields' => 1,
          ),
        ),
      ),
    'group_access_bundles|user|user|form' => (object) array(
        'id' => '8',
        'identifier' => 'group_access_bundles|user|user|form',
        'group_name' => 'group_access_bundles',
        'entity_type' => 'user',
        'bundle' => 'user',
        'mode' => 'form',
        'parent_name' => '',
        'table' => 'field_group',
        'type' => 'Overridden',
        'export_type' => 3,
        'export_module' => 'user_fields',
        'label' => 'Access bundles',
        'weight' => '4',
        'children' => array(
          0 => 'field_access_bundles',
          1 => 'group_webservices',
        ),
        'format_type' => 'fieldset',
        'format_settings' => array(
          'formatter' => 'collapsible',
          'instance_settings' => array(
            'description' => '',
            'classes' => '',
            'required_fields' => 1,
          ),
        ),
      ),
    'group_user_type|user|user|form' => (object) array(
        'id' => '15',
        'identifier' => 'group_user_type|user|user|form',
        'group_name' => 'group_user_type',
        'entity_type' => 'user',
        'bundle' => 'user',
        'mode' => 'form',
        'parent_name' => '',
        'table' => 'field_group',
        'type' => 'Overridden',
        'export_type' => 3,
        'disabled' => FALSE,
        'export_module' => 'user_fields',
        'label' => 'Brugertype',
        'weight' => '0',
        'children' => array(
          0 => 'field_user_type_info',
          1 => 'field_user_type',
        ),
        'format_type' => 'fieldset',
        'format_settings' => array(
          'label' => 'Brugertype',
          'instance_settings' => array(
            'required_fields' => 1,
            'classes' => '',
            'description' => '',
          ),
          'formatter' => 'collapsible',
        ),
      ),
    'group_default_fields|user|user|form' => (object) array(
        'id' => '10',
        'identifier' => 'group_default_fields|user|user|form',
        'group_name' => 'group_default_fields',
        'entity_type' => 'user',
        'bundle' => 'user',
        'mode' => 'form',
        'parent_name' => '',
        'table' => 'field_group',
        'type' => 'Overridden',
        'export_type' => 3,
        'disabled' => FALSE,
        'export_module' => 'user_fields',
        'label' => 'Standard felter',
        'weight' => '6',
        'children' => array(
          0 => 'metatags',
          1 => 'timezone',
          2 => 'locale',
          3 => 'wysiwyg',
        ),
        'format_type' => 'fieldset',
        'format_settings' => array(
          'label' => 'Standard felter',
          'instance_settings' => array(
            'required_fields' => 1,
            'classes' => '',
            'description' => '',
          ),
          'formatter' => 'collapsed',
        ),
      ),
    'group_options|user|user|form' => (object) array(
        'id' => '13',
        'identifier' => 'group_options|user|user|form',
        'group_name' => 'group_options',
        'entity_type' => 'user',
        'bundle' => 'user',
        'mode' => 'form',
        'parent_name' => '',
        'table' => 'field_group',
        'type' => 'Overridden',
        'export_type' => 3,
        'disabled' => FALSE,
        'export_module' => 'user_fields',
        'label' => 'Valg',
        'weight' => '7',
        'children' => array(
          0 => 'field_newsletter',
          1 => 'field_contact_me',
          2 => 'field_terms_and_conditions',
        ),
        'format_type' => 'fieldset',
        'format_settings' => array(
          'label' => 'Valg',
          'instance_settings' => array(
            'required_fields' => 1,
            'classes' => '',
            'description' => '',
          ),
          'formatter' => 'open',
        ),
      ),
    'group_navision|user|user|form' => (object) array(
        'id' => '12',
        'identifier' => 'group_navision|user|user|form',
        'group_name' => 'group_navision',
        'entity_type' => 'user',
        'bundle' => 'user',
        'mode' => 'form',
        'parent_name' => '',
        'table' => 'field_group',
        'type' => 'Overridden',
        'export_type' => 3,
        'disabled' => FALSE,
        'export_module' => 'user_fields',
        'label' => 'Navision',
        'weight' => '2',
        'children' => array(
          0 => 'field_kms_user_id',
          1 => 'field_debtor_nr',
        ),
        'format_type' => 'fieldset',
        'format_settings' => array(
          'label' => 'Navision',
          'instance_settings' => array(
            'required_fields' => 1,
            'classes' => '',
            'description' => '',
          ),
          'formatter' => 'open',
        ),
      ),
  ),
);