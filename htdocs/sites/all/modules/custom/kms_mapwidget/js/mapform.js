(function($, Drupal) {
  Drupal.behaviors.mapform = { 
	  attach: function (context, settings) { 

	    $('input:checkbox[name^="userdefined"]').click( function() {
	      $('input:checkbox[name^="predefined"]').each(function(i) {
            this.checked = false;
          });
          $('input:checkbox[name^="userdefined"]').each(function(i) {
            this.checked = false;
          });
          this.checked = true;
	    });

	    $('input:checkbox[name^="predefined"]').click( function() {
	      $('input:checkbox[name^="userdefined"]').each(function(i) {
            this.checked = false;
          });
          $('input:checkbox[name^="predefined"]').each(function(i) {
            this.checked = false;
          });
          this.checked = true;
	    });

      $("#predefined_description").easyModal({overlayOpacity: 0.5});
      $("#predefined_button").click(function(e) {
         $("#predefined_description").trigger("openModal");
         e.preventDefault();
      });

      $("#userdefined_description").easyModal({overlayOpacity: 0.5});
      $("#userdefined_button").click(function(e) {
         $("#userdefined_description").trigger("openModal");
         e.preventDefault();
      });

    } 
  };
}(jQuery, Drupal));
