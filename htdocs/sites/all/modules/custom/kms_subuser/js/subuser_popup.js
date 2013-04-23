(function ($) {
  var result = 0, prevResult = 0;
  Drupal.behaviors.kmsSubuserPopup = {
    attach: function(context, settings) {
      $.ajax({
        url: '/kms-subuser/ajax/load-view/' + settings.kms_user.uid,
        type: 'GET',
        success: function(xhr) {
          $('#subuser-view-wrapper').html(xhr);
          $('#subuser-view-wrapper table').dataTable({
            "bPaginate": false,
            "oLanguage": {
              "sSearch": Drupal.t('Search'),
              "sInfo": Drupal.t('Showing _START_ to _END_ of _TOTAL_ records'),
              "sInfoEmpty": Drupal.t('Showing 0 to 0 of 0 records'),
            }
          });
           
          // If number of view result is increasing then clear form.
          $("body").bind("ajaxComplete", function(e, xhr, sett){
              result = $('#subuser-view-wrapper table td.views-field-name').length;
              if (prevResult != 0 && result > prevResult) {
                $('#kms-subuser-add-form input[type="text"]').val('');
                $('#kms-subuser-add-form textarea').text('');
                $('#kms-subuser-add-form input[name="add_subuser"]')
                 .trigger('click').removeAttr('checked');
              }
              prevResult = result;
          });

        }
      });
      
    }
  }

})(jQuery, Drupal);
