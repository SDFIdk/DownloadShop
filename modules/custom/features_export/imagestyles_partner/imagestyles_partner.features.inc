<?php
/**
 * @file
 * imagestyles_partner.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function imagestyles_partner_image_default_styles() {
  $styles = array();

  // Exported image style: partner_image_middle.
  $styles['partner_image_middle'] = array(
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 258,
          'height' => 150,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'partner_image_middle',
  );

  // Exported image style: partner_image_middle_large.
  $styles['partner_image_middle_large'] = array(
    'effects' => array(
      10 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1032,
          'height' => 600,
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'partner_image_middle_large',
  );

  // Exported image style: partner_logo.
  $styles['partner_logo'] = array(
    'effects' => array(
      7 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 180,
          'height' => 80,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'partner_logo',
  );

  // Exported image style: partnerlist.
  $styles['partnerlist'] = array(
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 260,
          'height' => 112,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'partnerlist',
  );

  // Exported image style: partnerlist_logo.
  $styles['partnerlist_logo'] = array(
    'effects' => array(
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 150,
          'height' => 45,
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'partnerlist_logo',
  );

  // Exported image style: topimage_partner.
  $styles['topimage_partner'] = array(
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1120,
          'height' => 265,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'topimage_partner',
  );

  return $styles;
}
