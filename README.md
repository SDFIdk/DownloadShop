# KMS Oci Queue

## Testing
In tests affecting all users the amount of users are reduced to 30 in debug mode.

The debug mode is controlled by the constant: KMS\_OCI\_QUEUE\_DEBUG. (TRUE = is in debug mode).

Some handy commands in order to run tests from CLI and clear data from db:

+ drush eval 'kms\_test\_db\_cleanup\_kms\_oci\_mess()'. Removes data from job and log table and queues.
+ drush eval "kms\_test\_insert\_new\_user\_test(18580)". Create a user with fields (fields that are relevant to KMS OCI Queue) cloned from another user.


### Urls:
+ Cron page: [http://test.download.kortforsyningen.dk/admin/config/system/cron][cron page].
+ Oci queue report page: [http://test.download.kortforsyningen.dk/admin/reports/kms-oci-queue][report page].

### Users

#### Insert user

##### How to test:
+ Go to: /content/opret-mig-som-bruger.
+ Fill in test user data.
+ Run KMS OCI Queue cron [cron job - KMS OCI Queue].
+ Wait and watch changes in job log at [report page].
+ Run kms\_oci\_queue\_query [cron job - kms\_oci\_queue\_query]
+ A job file should have been created in: public://kms\_oci\_queue/jobs. Check that it is there with correct data.
+ Wait for query engine cron job to import the job file(s) and watch changes in job log at [report page]. Status should be: 'Done'.
+ Check oracle database if data has been imported.

##### Test from CLI:
drush eval 'kms\_test\_insert\_user()'. Inserts some test user info with a unix timestamp as user id.

##### How to test assignment of default bundle:
+ It happens in the test: "Insert user".

#### Update user

##### How to test:
+ Edit user from /admin/people
+ Change values
+ Save user
+ Run KMS OCI Queue cron [cron job - KMS OCI Queue].
+ Wait and watch changes in job log at [report page].
+ Run kms\_oci\_queue\_query [cron job - kms\_oci\_queue\_query]
+ A job file should have been created in: public://kms\_oci\_queue/jobs. Check that it is there with correct data.
+ Wait for query engine cron job to import the job file(s) and watch changes in job log at [report page]. Status should be: 'Done'.
+ Check oracle database if data has been imported.

#### Delete user

##### How to test:
+ Cancel a user. Eg. by calling /user/UID/cancel. Choose delete user and its content.
+ Run KMS OCI Queue cron [cron job - KMS OCI Queue].
+ Wait and watch changes in job log at [report page].
+ Run kms\_oci\_queue\_query [cron job - kms\_oci\_queue\_query]
+ A job file should have been created in: public://kms\_oci\_queue/jobs. Check that it is there with correct data.
+ Wait for query engine cron job to import the job file(s) and watch changes in job log at [report page]. Status should be: 'Done'.
+ Check oracle database if user data has been deleted.

#### Expire user

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
+ Run KMS OCI Queue cron [cron job - KMS OCI Queue].
+ Wait and watch changes in job log at [report page].
+ Run kms\_oci\_queue\_query [cron job - kms\_oci\_queue\_query]
+ A job file should have been created in: public://kms\_oci\_queue/jobs. Check that it is there with correct data.
+ Wait for query engine cron job to import the job file(s) and watch changes in job log at [report page]. Status should be: 'Done'.
+ Check oracle database if data has been imported.

##### Test from CLI:
drush eval 'kms\_test\_bundle\_save([BUNDLE\_ID])'. Is running the action invoked by saving the specified bundle id.

### Subusers

#### Insert subuser

##### How to test:
+ Go to your own user profile edit page /user/UID/edit.
+ Go to 'Underbruger administration' section.
+ Choose create subuser (Tilføj underbruger) and fill in data in the form.
+ Run KMS OCI Queue cron [cron job - KMS OCI Queue].
+ Wait and watch changes in job log at [report page].
+ Run kms\_oci\_queue\_query [cron job - kms\_oci\_queue\_query]
+ A job file should have been created in: public://kms\_oci\_queue/jobs. Check that it is there with correct data.
+ Wait for query engine cron job to import the job file(s) and watch changes in job log at [report page]. Status should be: 'Done'.
+ Check oracle database if data has been imported.

#### Update subuser

##### How to test:
+ Go to your own user profile edit page /user/UID/edit.
+ Go to 'Underbruger administration' section.
+ Choose 'edit' on one of the existing subusers and change some data in the form.
+ Run KMS OCI Queue cron [cron job - KMS OCI Queue].
+ Wait and watch changes in job log at [report page].
+ Run kms\_oci\_queue\_query [cron job - kms\_oci\_queue\_query]
+ A job file should have been created in: public://kms\_oci\_queue/jobs. Check that it is there with correct data.
+ Wait for query engine cron job to import the job file(s) and watch changes in job log at [report page]. Status should be: 'Done'.
+ Check oracle database if data has been imported.
#### Delete subuser

##### How to test:
+ Same steps as 'Delete user' test.

#### Update subuser perms when master user perms are changed
+ Needs to be done.

[cron page]: http://test.download.kortforsyningen.dk/admin/config/system/cron
[report page]: http://test.download.kortforsyningen.dk/admin/reports/kms-oci-queue
[cron job - KMS OCI Queue]: http://kms.dev/admin/ultimate-cron/service/start/kms\_oci\_queue\_query\_creator\_run?destination=admin/config/system/cron
[cron job - kms\_oci\_queue\_query]: http://kms.dev/admin/ultimate-cron/service/start/ultimate\_cron\_queue\_kms\_oci\_queue\_query?destination=admin/config/system/cron
