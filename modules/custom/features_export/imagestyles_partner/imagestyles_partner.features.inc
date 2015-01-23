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
    'name' => 'partner_image_middle',
    'effects' => array(
      8 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '258',
          'height' => '150',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: partner_image_middle_large.
  $styles['partner_image_middle_large'] = array(
    'name' => 'partner_image_middle_large',
    'effects' => array(
      10 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '1032',
          'height' => '600',
          'upscale' => 0,
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: partner_logo.
  $styles['partner_logo'] = array(
    'name' => 'partner_logo',
    'effects' => array(
      7 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '180',
          'height' => '80',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: partnerlist.
  $styles['partnerlist'] = array(
    'name' => 'partnerlist',
    'effects' => array(
      4 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '260',
          'height' => '112',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: partnerlist_logo.
  $styles['partnerlist_logo'] = array(
    'name' => 'partnerlist_logo',
    'effects' => array(
      6 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '150',
          'height' => '45',
          'upscale' => 0,
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: topimage_partner.
  $styles['topimage_partner'] = array(
    'name' => 'topimage_partner',
    'effects' => array(
      3 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '1120',
          'height' => '265',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}
