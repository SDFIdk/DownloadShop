<?php
/**
 * @file
 * user_fields.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function user_fields_taxonomy_default_vocabularies() {
  return array(
    'bundle' => array(
      'name' => 'Bundles',
      'machine_name' => 'bundle',
      'description' => 'Grouping of product display nodes and services',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-10',
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
    'user_type' => array(
      'name' => 'User type',
      'machine_name' => 'user_type',
      'description' => 'User classification',
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
    'webservices' => array(
      'name' => 'Webservices',
      'machine_name' => 'webservices',
      'description' => 'KMS Webservices',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-9',
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
