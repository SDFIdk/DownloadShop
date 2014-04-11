<?php
#!/usr/bin/env drush

// Example of execution:
// drush scr /vagrant_sites/kms.dev/scripts/oracle/import_sqlldr_file.php --ctl=/vagrant_sites/kms.dev/sqlldr/kms_perms_extract.smuser.ctl

// check if we can bootstrap
$self = drush_sitealias_get_record('@self');
if (empty($self)) {
  drush_die("I can't bootstrap from the current location.", 0);
}

$conn = drush_prompt(dt('Please enter connection definition'));

if (drush_get_option('ctl')) {
  $pathinfo = pathinfo(drush_get_option('ctl'));
  $filepath_log = '/tmp/' . str_replace('.ctl', '.log', $pathinfo['basename']);
  $filepath_bad = '/tmp/' . str_replace('.ctl', '.bad', $pathinfo['basename']);

  $output = shell_exec(
    sprintf(
      'sqlldr %s control=%s log=%s bad=%s',
      $conn,
      drush_get_option('ctl'),
      $filepath_log,
      $filepath_bad
    )
  );

  drush_print($output);
  drush_print(dt('Sql loader done. Log saved: @log', array('@log' => $filepath_log)));
}