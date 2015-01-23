<?php
/**
 * @file
 * kms_access_bundles.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function kms_access_bundles_taxonomy_default_vocabularies() {
  return array(
    'bundle_colours' => array(
      'name' => 'Bundle colours',
      'machine_name' => 'bundle_colours',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'metatags' => array(),
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
