/**
 * Created by mikkel on 12/2/13.
 */

(function ($) {
  Drupal.behaviors.kms_perms_user_checkboxes = {
    attach: function(context, settings) {
      $('#edit-field-access-bundles-und .form-type-checkbox input').click(function () {
        var bundleCheckBox = $(this);
        $.ajax({
          url: '/kms-permissions/ajax/load-sids/' + bundleCheckBox.val(),
          type: 'GET',
          success: function(xhr) {
            var serviceIds = xhr.sids;
            for (var i=0; i < serviceIds.length; i++){
              var serviceId = serviceIds[i];
              var selector = 'input[id^="edit-field-bundle-webservices-"][id$=-' + serviceId + ']';
              $(selector, context).attr('checked', bundleCheckBox.attr('checked'));
              $(selector, context).attr('disabled', bundleCheckBox.attr('checked'));
            }
          }
        });
      })

    }
  };
})(jQuery, Drupal);
