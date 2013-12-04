/**
 * Created by mikkel on 12/2/13.
 */

(function ($) {
  Drupal.behaviors.kms_perms_user_checkboxes = {
    attach: function(context, settings) {
      $('#edit-field-access-bundles-und .form-type-checkbox input', context).click(function () {

        var bids = [];
        $('#edit-field-access-bundles-und .form-type-checkbox input:checked', context).each(function(){
          bids.push($(this).val())
        })

        $('.group-webservices').foggy();
        $.ajax({
          url: '/kms-permissions/ajax/load-sids-by-bid',
          type: 'POST',
          'data': {bids: bids},
          success: function(xhr) {
            $('.group-webservices .form-type-checkbox input', context)
              .attr('checked', false)
              .attr('disabled', false);
            for (var i=0; i < xhr.sids.length; i++){
              var sid = xhr.sids[i];
              var selector = '.group-webservices .form-type-checkbox input[id^="edit-field-bundle-webservices-"][id$=-' + sid + ']'
              $(selector, context).attr("checked", "checked").attr("disabled", "disabled");
            }
          },
          complete: function() {
            $('.group-webservices').foggy(false);
          }
        });

      })

    }
  };
})(jQuery, Drupal);
