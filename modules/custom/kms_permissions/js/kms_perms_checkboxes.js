/**
 * Created by mikkel on 12/2/13.
 */
(function ($) {
  Drupal.behaviors.kms_perms_checkboxes = {
    attach: function(context, settings) {

      if (settings.kms_permissions.form_id == 'user_profile_form' || settings.kms_permissions.form_id == 'user_register_form') {
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

          var selector_fields= new Array();
          selector_fields['webservices'] = 'bundle-webservices';
          selector_fields['tab-predefined'] = 'predefined-datacollections-und';
          selector_fields['tab-ftp'] = 'ftp-permissions-und';
          selector_fields['tab-applications'] = 'applications-und';

          // Iterate over returned sids. Check corresponding checkboxes and hijack click event.
          for (var i in sids){
            for (var j in sids[i]){
              var selector = '.group-'+ i +' .form-type-checkbox input[id^="edit-field-' + selector_fields[i] + '-"][id$=-' + sids[i][j].toLowerCase() + ']';
              $(selector, context).parent().addClass('disabled');
            }
          }

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
