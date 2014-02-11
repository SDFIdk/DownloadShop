# KMS Oci Queue

## Construction:

+ A job is stored as one row in the ``kms_oci_queue_job`` table.
+ A job has several log entries stored in the ``kms_oci_queue_log`` table.
+ A job is tied with a queue item in a query creator queue.
+ The query creator queue item creates queue items in the query queue.
+ Every item in the query queue creates a line in a job file.
+ When the job file is created it is imported into Oracle
by the [query_engine script](#query_engine_script).

## Cron handling:

### Cron jobs:
+ [cron job - KMS OCI Queue]
+ [cron job - kms_oci_queue_query]
+ <a name="query_engine_script"></a>query_engine script:
``php -e /vagrant_sites/kms.dev/scripts/query_engine/query_engine.php``

## Process
The queue process goes as described:

+ A KMS Oci Queue job is created when different actions are happening.
+ When the job is created an item in the query creator queue is created.
The item contains data that is necessary for creating query items in the query queue.
+ When the query constructor queue is being processed it creates items in the query queue.
+ When the query queue is being processed it creates lines in a job file.
+ When the [query_engine script](#query_engine_script) is invoked in the crontab
it imports the job file and thereby completes the job.

## Testing
In tests affecting all users the amount of users are reduced to 30 in debug mode.

The debug mode is controlled by the constant: ``KMS_OCI_QUEUE_DEBUG``. (TRUE = is in debug mode).

Some handy commands in order to run tests from CLI and clear data from db:

+ ``drush eval 'kms_test_db_cleanup_kms_oci_mess()'``. Removes data from job and log table and queues.
+ ``drush eval 'kms_test_insert_new_user_test([UID])'``. Create a user with fields (fields that are relevant to KMS OCI Queue) cloned from another user.


### Urls:
+ Cron page: [http://test.download.kortforsyningen.dk/admin/config/system/cron][cron page].
+ Oci queue report page: [http://test.download.kortforsyningen.dk/admin/reports/kms-oci-queue][report page].

### Users

#### Insert user
``kms_user.module``, inside ``_kms_user_submit_insert_user_oracle($form, &$form_state)``, line 572.

##### How to test:
+ Go to: /content/opret-mig-som-bruger.
+ Fill in test user data.
+ Watch that jobs have been created at [report page].
+ Run KMS OCI Queue cron [cron job - KMS OCI Queue].
+ Wait and watch changes in job log at [report page].
+ Run ``kms_oci_queue_query``[cron job - kms_oci_queue_query]
+ A job file should have been created in: ``public://kms_oci_queue/jobs.`` Check that it is there with correct data.
+ Run query engine script [query_engine script](#query_engine_script) to import the job file(s) and watch changes in job log at [report page]. Status should be: 'Done'.
+ Check oracle database if data has been imported.

##### Test from CLI:
``drush eval 'kms_test_insert_user()'``. Inserts some test user info with a unix timestamp as user id.

##### How to test assignment of default bundle:
+ It happens in the test: "Insert user".

#### Update user
``kms_user.module``, inside ``_kms_user_submit_update_user_oracle($form, &$form_state)``, line 624.

##### How to test:
+ Edit user from /admin/people
+ Change values
+ Save user
+ Watch that jobs have been created at [report page].
+ Run KMS OCI Queue cron [cron job - KMS OCI Queue].
+ Wait and watch changes in job log at [report page].
+ Run ``kms_oci_queue_query``[cron job - kms_oci_queue_query]
+ A job file should have been created in: ``public://kms_oci_queue/jobs.``
Check that it is there with correct data.
+ Run query engine script [query_engine script](#query_engine_script) to import the job file(s)
and watch changes in job log at [report page]. Status should be: 'Done'.
+ Check oracle database if data has been imported.

#### Delete user
``kms_user.module``, inside ``kms_user_smuser_delete($user)``, in line 788.

##### How to test:
+ Cancel a user. Eg. by calling /user/UID/cancel. Choose delete user and its content.
+ Watch that jobs have been created at [report page].
+ Run KMS OCI Queue cron [cron job - KMS OCI Queue].
+ Wait and watch changes in job log at [report page].
+ Run ``kms_oci_queue_query``[cron job - kms_oci_queue_query]
+ A job file should have been created in: ``public://kms_oci_queue/jobs``.
Check that it is there with correct data.
+ Run query engine script [query_engine script](#query_engine_script) to import the job file(s)
and watch changes in job log at [report page]. Status should be: 'Done'.
+ Check oracle database if user data has been deleted.

#### Expire user
``kms_user.module``, inside ``kms_user_smuser_deactivate($account)``, in line 867.

##### How to test:
+ Edit a user at /user/UID/edit or pick one from /admin/people and edit.
+ Set an expire date in the past and save user.
+ Run cron.
+ Watch that q job have been created at [report page].
+ Run KMS OCI Queue cron [cron job - KMS OCI Queue].
+ Wait and watch changes in job log at [report page].
+ Run ``kms_oci_queue_query``[cron job - kms_oci_queue_query]
+ A job file should have been created in: ``public://kms_oci_queue/jobs``.
Check that it is there with correct data.
+ Run query engine script [query_engine script](#query_engine_script) to import the job file(s)
and watch changes in job log at [report page]. Status should be: 'Done'.
+ Check oracle database. Disabled should be set to 1 on the user.

### Bundles

#### Insert Bundle
+ Have to double check.

#### Update bundle
``kms_permissions.module``, inside ``kms_permissions_access_bundle_update($form, $form_state)``, in line 867.

##### How to test:
+ Change an existing bundle.
+ Run KMS OCI Queue cron [cron job - KMS OCI Queue].
+ Wait and watch changes in job log at [report page].
+ Run ``kms_oci_queue_query``[cron job - kms_oci_queue_query]
+ A job file should have been created in: ``public://kms_oci_queue/jobs.`` Check that it is there with correct data.
+ Run query engine script [query_engine script](#query_engine_script) to import the job file(s)
and watch changes in job log at [report page]. Status should be: 'Done'.
+ Check oracle database if data has been imported.

##### Test from CLI:
```drush eval 'kms_test_bundle_save([BUNDLE_ID])'``.
This function runs the job action invoked by saving the specified bundle id.

### Subusers

#### Insert subuser
``kms_subuser.module``, inside ``kms_subuser_insert_account_oracle($user, $account)``, in line 715.

##### How to test:
+ Go to your own user profile edit page /user/UID/edit.
+ Go to 'Underbruger administration' section.
+ Choose create subuser (Tilføj underbruger) and fill in data in the form.
+ Run KMS OCI Queue cron [cron job - KMS OCI Queue].
+ Wait and watch changes in job log at [report page].
+ Run ``kms_oci_queue_query``[cron job - kms_oci_queue_query]
+ A job file should have been created in: ``public://kms_oci_queue/jobs.`` Check that it is there with correct data.
+ Run query engine script [query_engine script](#query_engine_script) to import the job file(s)
and watch changes in job log at [report page]. Status should be: 'Done'.
+ Check oracle database if data has been imported.

#### Update subuser
``kms_subuser.module``, inside ``kms_subuser_update_account_oracle($user, $account)``, in line 781.

##### How to test:
+ Go to your own user profile edit page /user/UID/edit.
+ Go to 'Underbruger administration' section.
+ Choose 'edit' on one of the existing subusers and change some data in the form.
+ Run KMS OCI Queue cron [cron job - KMS OCI Queue].
+ Wait and watch changes in job log at [report page].
+ Run ``kms_oci_queue_query``[cron job - kms_oci_queue_query]
+ A job file should have been created in: ``public://kms_oci_queue/jobs.``
Check that it is there with correct data.
+ Run query engine script [query_engine script](#query_engine_script) to import the job file(s)
and watch changes in job log at [report page]. Status should be: 'Done'.
+ Check oracle database if data has been imported.

#### Delete subuser
``kms_user.module``, inside ``kms_user_smuser_delete($user)``, in line 773.


##### How to test:
+ Same steps as 'Delete user' test.

#### Update subuser perms when master user perms are changed
+ Needs to be done.

[cron page]: http://test.download.kortforsyningen.dk/admin/config/system/cron
[report page]: http://test.download.kortforsyningen.dk/admin/reports/kms-oci-queue
[cron job - KMS OCI Queue]: http://test.download.kortforsyningen.dk/admin/ultimate-cron/service/start/kms_oci_queue_query_creator_run?destination=admin/config/system/cron
[cron job - kms_oci_queue_query]: http://test.download.kortforsyningen.dk/admin/ultimate-cron/service/start/ultimate_cron_queue_kms_oci_queue_query?destination=admin/config/system/cron
