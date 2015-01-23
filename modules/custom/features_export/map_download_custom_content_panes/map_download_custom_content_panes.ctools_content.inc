<?php
/**
 * @file
 * map_download_custom_content_panes.ctools_content.inc
 */

/**
 * Implements hook_default_ctools_custom_content().
 */
function map_download_custom_content_panes_default_ctools_custom_content() {
  $export = array();

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'buffer_description';
  $content->admin_title = 'buffer_description';
  $content->admin_description = '';
  $content->category = '';
  $content->settings = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<p>Du kan vælge at tilføje en buffer til det valgte område. Hvis du fx vælger en buffer på 1000 meter, så udvides området med 1000 meter væk fra områdets centrum. Vælger du en buffer på 0 meter, anvendes den områdegrænse, som du har valgt.</p>',
    'format' => 'filtered_html',
    'substitute' => 1,
  );
  $export['buffer_description'] = $content;

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'clipping_description';
  $content->admin_title = 'clipping_description';
  $content->admin_description = '';
  $content->category = '';
  $content->settings = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<p>Et blødt klip langs områdegrænse medfører, at de objekter, som område&shy;grænsen går igennem, medtages hele i udtrækket. Alternativet er et hårdt klip, hvor alt udenfor områdegrænsen klippes væk.</p><p>&nbsp;</p><p>Eksempelvis: En områdegrænse går igennem en sø. Her vil valg af blødt klip medføre at hele søen udtrækkes. Et hårdt klip vil skære søen over og kun den del, der ligger indenfor områdegrænsen, udtrækkes.&nbsp;</p>',
    'format' => 'filtered_html',
    'substitute' => 1,
  );
  $export['clipping_description'] = $content;

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'predefined_selections';
  $content->admin_title = 'Predefined selections';
  $content->admin_description = '';
  $content->category = '';
  $content->settings = array(
    'admin_title' => '',
    'title' => 'Predefined selections',
    'body' => '<p>Færdige udtræk kan downloades med det samme. Vær opmærksom på, at data kan være op til 3 måneder gamle, da disse udtræk typisk udføres en gang i kvartalet.</p><p><br />Større datasæt er inddelt efter administrative grænser eller i blokke (fx 10 x 10 km blokke). Vælg én af de mulige inddelinger i listen under &rdquo;Færdige udtræk&rdquo;.</p>',
    'format' => 'filtered_html',
    'substitute' => 0,
  );
  $export['predefined_selections'] = $content;

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'userdefined_selections';
  $content->admin_title = 'Userdefined selections';
  $content->admin_description = '';
  $content->category = '';
  $content->settings = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<p>Med brugerdefinerede udtræk får du et nyt udtræk af data, hvilket især kan være interessant for matrikeldata, som ajourføres dagligt.</p><p>&nbsp;</p><p>Du kan vælge mellem flere forskellige dataformater og koordinatsystemer end du har adgang til via færdige udtræk.</p><p>&nbsp;</p><p>Du vælger selv et område ved enten at tegne en firkant eller ved at vælge én eller flere administrative enheder.&nbsp;</p><p>&nbsp;</p><p>Normalt vil udtrækket være klart i løbet af få timer, men der kan gå op til 1-2 dage - afhængigt af den aktuelle belastning på systemet. For at styre belastningen på systemet er det kun muligt at udtrække data for mindre områder på denne måde.</p>',
    'format' => 'filtered_html',
    'substitute' => 1,
  );
  $export['userdefined_selections'] = $content;

  return $export;
}
