<?php

$filter = array(
  'format' => 'filtered_html',
  'name' => 'Filtered HTML',
  'weight' => 0,
  'filters' => array(
    // URL filter.
    'filter_url' => array(
      'weight' => 0,
      'status' => 1,
    ),
    // HTML filter.
    'filter_html' => array(
      'weight' => 1,
      'status' => 1,
      'settings' => array(
        'allowed_html' => '<a><em><strong><cite><blockquote><code><ul><ol><li><dl><dt><dd><img><h1><h2><h3><h4><p><span><br><table><tr><td><tbody><iframe>'
      )
    ),
    // Line break filter.
    'filter_autop' => array(
      'weight' => 2,
      'status' => 1,
    ),
    // HTML corrector filter.
    'filter_htmlcorrector' => array(
      'weight' => 10,
      'status' => 1,
    ),
  ),
);