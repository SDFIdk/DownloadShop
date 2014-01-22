/**
 * Created by mikkel on 12/2/13.
 */
(function ($) {
  Drupal.behaviors.kms_perms_user_checkboxes = {
    attach: function(context, settings) {
      // Prevent click on default bundles.
      $('#edit-field-access-bundles-und .default-bundle', context).bind('click', function(event){
        event.stopPropagation();
        event.preventDefault();
        return false;
      });

      // Manipulate service checkboxes from the bundle selections.
      var bids = Drupal.behaviors.kms_perms_user_checkboxes.getBids(context);
      Drupal.behaviors.kms_perms_user_checkboxes.servicesFromBundles(bids, context);

      // // Manipulate service checkboxes from the bundle selections on bundle selection change.
      $('#edit-field-access-bundles-und .form-type-checkbox input', context).not('.default-bundle').click(function () {
        var bids = Drupal.behaviors.kms_perms_user_checkboxes.getBids(context);
        Drupal.behaviors.kms_perms_user_checkboxes.servicesFromBundles(bids, context);
      });

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
            var selector = '.group-webservices .form-type-checkbox input[id^="edit-field-bundle-webservices-"][id$=-' + sid + ']'
            $(selector, context).parent().addClass('disabled');
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
        bids.push($(this).val())
      });
      return bids;
    },
    checkUncheckAll: function(theElement, scope) {
    $('.'+scope+' input.form-checkbox').each(function(){
        if(!$(this).parent().hasClass('disabled')) $(this).attr("checked", theElement.checked);
      });
    }
  };
})(jQuery, Drupal);
