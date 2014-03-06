/**
 * Created by mikkel on 12/2/13.
 */
(function ($) {
  Drupal.behaviors.kms_perms_checkboxes = {
    attach: function(context, settings) {

      if (settings.kms_permissions.form_id == 'user_profile_form') {
        // Prevent click on default bundles.
        $('#edit-field-access-bundles-und .default-bundle', context).bind('click', function(event){
          event.stopPropagation();
          event.preventDefault();
          return false;
        });
        // Manipulate service checkboxes from the bundle selections.
        var bids = Drupal.behaviors.kms_perms_checkboxes.getBids(context);
        Drupal.behaviors.kms_perms_checkboxes.servicesFromBundles(bids, context);

        // // Manipulate service checkboxes from the bundle selections on bundle selection change.
        $('#edit-field-access-bundles-und .form-type-checkbox input', context).not('.default-bundle').click(function () {
          var bids = Drupal.behaviors.kms_perms_checkboxes.getBids(context);
          Drupal.behaviors.kms_perms_checkboxes.servicesFromBundles(bids, context);
        });
      }

    },
    servicesFromBundles: function(bids, context) {
      // Blur service checkboxes while fetching service ids from ajax request.
      $('.group-webservices').foggy();
      // Load service ids by bundle ids.
      $.ajax({
        url: '/kms-permissions/ajax/load-sids-by-bid',
        type: 'POST',
        data: {bids: bids},
        success: function(xhr) {

          // Remove 'click jail' and checkes status from all checkboxes.
          $('.group-webservices .form-type-checkbox input').each(function(){
            $(this).parent().removeClass('disabled');
          });
          // Populate sids with sids returned by request.
          sids = xhr.sids;
          // Iterate over returned sids. Check corresponding checkboxes and hijack click event.
          for (var i=0; i < sids.length; i++){
            var sid = xhr.sids[i];

            if(!isNaN(sid)){
              var selector = '.group-webservices .form-type-checkbox input[id^="edit-field-bundle-webservices-"][id$=-' + sid + ']';
              $(selector, context).parent().addClass('disabled');
            }

            if(sid.substring(0,3) == 'pre')
            {
              var pre_selector = '.group-tab-predefined .form-type-checkbox input[id^="edit-field-predefined-datacollections-und-"][id$=-' + sid.substring(4,7) + ']';
              $(pre_selector, context).parent().addClass('disabled');
            }

            if(sid.substring(0,3) == 'ftp')
            {
              var ftp_selector = '.group-tab-ftp .form-type-checkbox input[id^="edit-field-ftp-permissions-und-"][id$=-' + sid.substring(4,7) + ']';
              $(ftp_selector, context).parent().addClass('disabled');
            }

            if(sid.length == 32)
            {
              var app_selector = '.group-tab-applications .form-type-checkbox input[id^="edit-field-applications-und-"][id$=-' + sid.toLowerCase()+ ']';
              $(app_selector, context).parent().addClass('disabled');
            }


          }

          $('.group-webservices').foggy(false);
        },
        complete: function() {
          // Unblur service checkboxes when request is done.
          $('.group-webservices').foggy(false);
        }
      });
    },
    getBids: function(context) {
      // Collect bundle ids.
      var bids = [];
      $('#edit-field-access-bundles-und .form-type-checkbox input:checked', context).each(function(){
        bids.push($(this).val());
      });
      return bids;
    },
    checkUncheckAll: function(theElement, scope) {
    $('.' + scope + ' input.form-checkbox').each(function(){
        if(!$(this).parent().hasClass('disabled')) $(this).attr("checked", theElement.checked);
      });
    }
  };
})(jQuery, Drupal);
