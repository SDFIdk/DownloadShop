(function ($) {

  Drupal.behaviors.kmsSubuserPopup = {
    attach: function(context, settings) {

      $.ajax({
        url: '/kms-subuser/ajax/load-view/1',
        type: 'GET',
        success: function(xhr) {
          $('#subuser-view-wrapper').html(xhr);
          // console.log($('#subuser-view-wrapper table'));
          $('#subuser-view-wrapper table').dataTable({
            "bPaginate": false,
            "oLanguage": {
              "sSearch": Drupal.t('Search'),
              "sInfo": Drupal.t('Showing _START_ to _END_ of _TOTAL_ records'),
              "sInfoEmpty": Drupal.t('Showing 0 to 0 of 0 records'),
            }
          });

          if (!$('#kms-subuser-add-form-wrapper .error').length > 0) {
            $('#kms-subuser-add-form input[type="text"]').val('');
          }

        }
      });
      
    }
  }

})(jQuery, Drupal);
