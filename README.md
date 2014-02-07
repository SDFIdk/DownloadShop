# KMS Oci Queue

## Testing
In tests affecting all users the amount of users are reduced to 30 in debug mode.

The debug mode is controlled by the constant: KMS_OCI_QUEUE_DEBUG. (TRUE = is in debug mode).

Some handy commands in order to run tests from CLI and clear data from db:

+ drush eval 'kms_test_db_cleanup_kms_oci_mess()'. Removes data from job and log table and queues.



### Urls:
+ Cron page: [http://kms.dev/admin/config/system/cron][cron page].
+ Oci queue report page: [http://kms.dev/admin/reports/kms-oci-queue][report page].

### Users

#### Insert user

##### How to test:
+ Go to: [opret-mig-som-bruger](http://kms.dev/content/opret-mig-som-bruger).
+ Fill in test user data.
+ Watch newly created job on [report page].
+ Wait and watch changes in job log at [report page].
+ A job file should have been created in: public://kms_oci_queue/jobs. Check that it is there with correct data.
+ Wait for query engine cron job to import the job file(s) and watch changes in job log at [report page]. Status should be: 'Done'.
+ Check oracle database if data has been imported.

##### Test from CLI:
drush eval 'kms_test_insert_user()'. Inserts some test user info with a unix timestamp as user id.

##### How to test assignment of default bundle:
+ Same test procedure as 'Insert user'.

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
+ Watch newly created job on [report page].
+ Wait and watch changes in job log at [report page].
+ A job file should have been created in: public://kms_oci_queue/jobs. Check that it is there with correct data.
+ Wait for query engine cron job to import the job file(s) and watch changes in job log at [report page]. Status should be: 'Done'.
+ Check oracle database if data has been imported.

##### Test from CLI:
drush eval 'kms_test_bundle_save([BUNDLE_ID])'. Is running the action invoked by saving the specified bundle id.

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
