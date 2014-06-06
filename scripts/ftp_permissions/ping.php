<?php
#!/usr/bin/env drush

// Example of execution:
// drush scr --root=/home/drupal/kms.test/site/htdocs ping.php --script-path=/home/drupal/kms.test/site/scripts/ftp_permissions

// Check if we can bootstrap.
$self = drush_sitealias_get_record('@self');
if (empty($self)) {
  drush_die("I can't bootstrap from the current location.", 0);
}
$ftp_script_hosts = array(
  'loadftp1.kmsext.dk',
  'loadftp2.kmsext.dk',
);

// Run the ftp thing.
kms_permissions_ftp_scan_store_structure();

if (variable_get('kms_ftp_perm_change')) {
  $wd_msg = array();
  // Trigger external script.
  foreach ($ftp_script_hosts as $host) {
    exec(sprintf('ssh -i  $HOME/.ssh/updateftpservers %s', $host), $message, $exit_code);
    $wd_msg[] = $message;
  }
  // Set variable to false,
  // as script should revisit the view and update things accordingly.
  variable_set('kms_ftp_perm_change', FALSE);
  watchdog(
    'Permissions FTP',
    'Ftp cron script ran with messages: @messages',
    array('@messages' => implode(', ', $wd_msg)),
    WATCHDOG_NOTICE
  );
}
