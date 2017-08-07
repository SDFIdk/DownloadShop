(function($, Drupal) {
  Drupal.behaviors.mapform = { 
	  attach: function (context, settings) { 
      
      if (Drupal.settings.kms_mapwidget.step == 1) {
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

        $("#predefined_description").easyModal({overlayClose: true});
        $("#predefined_button").click(function(e) {
           $("#predefined_description").trigger("openModal");
           e.preventDefault();
        });

        $("#userdefined_description").easyModal({overlayClose: true});
        $("#userdefined_button").click(function(e) {
           $("#userdefined_description").trigger("openModal");
           e.preventDefault();
        });
        
        // Open greenland permission modul on step 1 if cookie is not present.
        var greenland_permission = $.cookie('greenland_permission');

        if (greenland_permission !== 'yes') {
          $("#greenland_permission", context).easyModal({
            autoOpen:true,
            overlayClose: false,
            closeOnEscape: false
          });

          // Trigger onClose action if cancel if user clicks cancel.
          $('button.cancel').click(function(e){
            var ref = document.referrer;
            if (ref.match(/.*geodataprodukter.*/i)) {
              window.history.back();
            } else {
              window.location.href = '/content/geodataprodukter';
            }
            e.preventDefault();
          });
          
          // Enable the confirm button if checkbox is checked.
          $('div.modal-checkbox input').click(function () {
            if ($('div.modal-checkbox input:checked').length > 0) {
              $('button.confirm').removeAttr('disabled');
            } else {
              $('button.confirm').attr('disabled', 'disabled');
            }
          });

          // Set cookie with permission if user clicks confirm
          // and close modal dialog.
          $('button.confirm').click(function(e){
            $.cookie('greenland_permission', 'yes');
            $('#greenland_permission').trigger('closeModal');
            e.preventDefault();
          });
        }

      }

    } 
  };
}(jQuery, Drupal));
