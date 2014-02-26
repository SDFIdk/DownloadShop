<?php
/**
 * @file
 * Template for a 1 column panel layout.
 *
 * This template provides a two column panel display layout, with
 * additional areas for the top and the bottom.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['top']: Content in the top row.
 *   - $content['middle']: Content in the left column.
 *   - $content['bottom']: Content in the bottom row.
 */
?>
<div class="top-content clearfix">
  <div class="inner">
	  <?php print $content['top']; ?>
  </div>
</div>
<div class="panel-1col-stacked clearfix">
  <div class="inner">
    <div class="inside">
  	  <?php print $content['main-content']; ?>
    </div>
  </div>
</div>
<div class="panel-col-bottom clearfix">
	<?php print $content['bottom']; ?>
</div>
