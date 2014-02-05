# KMS Oci Queue

## Testing
In tests affecting all users the amount of users are reduced to 30 in debug mode.

The debug mode is controlled by the constant: KMS_OCI_QUEUE_DEBUG. (TRUE = is in debug mode).


### Urls:
+ Cron page: [http://kms.dev/admin/config/system/cron][cron page].
+ Oci queue report page: [http://kms.dev/admin/reports/kms-oci-queue][report page].

### Users

#### Insert user

##### How to test:
+ Go to: [opret-mig-som-bruger](http://kms.dev//content/opret-mig-som-bruger).
+ Fill in test user data.
+ Watch newly created job on [report page].
+ Run KMS OCI Queue cron job on [cron page]. http://kms.dev/admin/ultimate-cron/service/start/kms_oci_queue_cron?destination=admin/config/system/cron
+ Watch changes in job log at [report page].
+ Run Ultimate Cron queue job: kms_oci_queue_query on [cron page]. http://kms.dev/admin/ultimate-cron/service/start/ultimate_cron_queue_kms_oci_queue_query?destination=admin/config/system/cron
+ Watch changes in job log at [report page].
+ A job file should have been created in: public://kms_oci_queue/jobs. Check that it is there with correct data.
+ Run cron script on server like this: ``php -e /vagrant_sites/kms.dev/scripts/query_engine/query_engine.php``
+ Watch changes in job log at [report page]. Status should be: 'Done'.
+ Check oracle database if data has been imported.

##### How to test assignment of default bundle:
+ Needs to be done

#### Update user

##### How to test:
+ Needs to be done

### Bundles

#### Update bundle

##### Should cover:
+ Insert bundle default
+ Insert bundle custom
+ Update bundle default
+ Update bundle custom

##### How to test:
+ Change an existing bundle.
+ Watch newly created job on [report page].
+ Run KMS OCI Queue cron job on [cron page]. http://kms.dev/admin/ultimate-cron/service/start/kms_oci_queue_cron?destination=admin/config/system/cron
+ Watch changes in job log at [report page].
+ Run Ultimate Cron queue job: kms_oci_queue_query on [cron page]. http://kms.dev/admin/ultimate-cron/service/start/ultimate_cron_queue_kms_oci_queue_query?destination=admin/config/system/cron
+ Watch changes in job log at [report page].
+ A job file should have been created in: public://kms_oci_queue/jobs. Check that it is there with correct data.
+ Run cron script on server like this: ``php -e /vagrant_sites/kms.dev/scripts/query_engine/query_engine.php``
+ Watch changes in job log at [report page]. Status should be: 'Done'.
+ Check oracle database if data has been imported.

### Subusers

#### Insert subuser

##### How to test:
+ Needs to be done

#### Update subuser

##### How to test:
+ Needs to be done

#### Subuser expires

##### How to test:
+ Needs to be done

[cron page]: http://kms.dev/admin/config/system/cron
[report page]: http://kms.dev/admin/reports/kms-oci-queue