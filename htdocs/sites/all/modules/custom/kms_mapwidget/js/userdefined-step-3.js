(function($, Drupal) {
  Drupal.behaviors.step3 = { 
	  attach: function (context, settings) { 
      $("#buffer_description").easyModal({overlayOpacity: 0.5});
      $("#buffer_button").click(function(e) {
         $("#buffer_description").trigger("openModal");
         e.preventDefault();
      });
      $("#clipping_description").easyModal({overlayOpacity: 0.5});
      $("#clipping_button").click(function(e) {
         $("#clipping_description").trigger("openModal");
         e.preventDefault();
      });
    } 
  };
}(jQuery, Drupal));
