(function ($) {
  var result = 0, prevResult = 0;
  Drupal.behaviors.kmsSubuserPopup = {
    attach: function(context, settings) {
      // Some external script is injecting divs with css files in the head.
      // Lets get rid of them:
      $('head div').remove();

      // Load subuser view.
      $('#subuser-view-wrapper').subuserView(settings.kms_user.uid);

      // If number of view result is increasing then clear form.
      $("body").bind("ajaxComplete", function(e, xhr, sett){
          Drupal.behaviors.ZZCToolsModal.attach(context);
          result = $('#subuser-view-wrapper table td.views-field-name').length;
          if (prevResult != 0 && result != prevResult) {
            $('#kms-subuser-form input[type="text"]').val('');
            $('#kms-subuser-form textarea').text('');
            $('#kms-subuser-form .form-item-name').hide();
            $('#kms-subuser-form .form-item-pass').hide();
            $('#kms-subuser-form .form-item-user-expire').hide();
            $('#kms-subuser-form .form-item-user-remark').hide();
            $('#kms-subuser-form .form-submit').hide();
            $('#kms-subuser-form input[name="add_subuser"]').removeAttr('checked');
          }
          prevResult = result;
      });
    }
  }

  $.fn.subuserView = function (uid) {
    return this.each(function() {
      el = $(this);
      $.ajax({
        url: '/kms-subuser/ajax/load-view/' + uid,
        type: 'GET',
        success: function(xhr) {
          el.html(xhr);
          el.find('table').dataTable({
            "bPaginate": false,
            "oLanguage": {
              "sSearch": Drupal.t('Search'),
              "sInfo": Drupal.t('Showing _START_ to _END_ of _TOTAL_ records'),
              "sInfoEmpty": Drupal.t('Showing 0 to 0 of 0 records'),
            }
          });
           
        }
      });      
    });
    
  }

})(jQuery, Drupal);


