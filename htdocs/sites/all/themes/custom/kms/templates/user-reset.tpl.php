<?php
 
 $header = module_invoke('panels_mini', 'block_view', 'top');
 $footer = module_invoke('panels_mini', 'block_view', 'bottom');
?>
<div class="profile"<?php print $attributes; ?>>

  <header>
    <?php echo( $header['content'] ); ?>
  </header>

  <div id="page">
    <div class="user-reset-page">  
      <?php echo drupal_render_children($variables['form']); ?>
    </div>  
  </div>

  <footer>
    <div id = "bottom" class="panel-col-bottom">
      <?php echo( $footer['content'] ); ?>
    </div>
  </footer>

</div>
