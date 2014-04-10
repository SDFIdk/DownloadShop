<?php
#!/usr/bin/env drush

// Example of execution:
// drush scr /vagrant_sites/kms.dev/scripts/oracle/create_ctl_file.php --class=KmsPermsExtractServices --working_dir=$(pwd)


// check if we can bootstrap
$self = drush_sitealias_get_record('@self');
if (empty($self)) {
  drush_die("I can't bootstrap from the current location.", 0);
}

if (drush_get_option('class') && class_exists(drush_get_option('class'))) {
  $class = drush_get_option('class');
  $working_dir = drush_get_option('working_dir') ? drush_get_option('working_dir') : '.';
  $extractor = new $class($working_dir);
  $extractor->writeFiles();
}