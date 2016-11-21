/**
 * Ip release form JS
 */

(function ($) {
  Drupal.behaviors.kms_services = {
    attach: function(context, settings) {
      $('#kms_services_login_form_return').hide();
      var url = $('#kms_services_login_form').attr('action');


      $('#kms_services_login_form_submit').click(function(event) {
        var error = 1;
        event.preventDefault();
        $('#kms_services_login_form').find('.messages').remove();
        var login = $('#kms_services_login_form_login').val();
        var pass = $('#kms_services_login_form_pass').val();

        if(login == '') {
          $('#kms_services_login_form').prepend('<div class="messages error">' + Drupal.t('Username field is required.') + '</div>');
          error = 0;
        }

        if(pass == '') {
          $('#kms_services_login_form').prepend('<div class="messages error">' + Drupal.t('Pasword field is required.') + '</div>');
          error = 0;
        }

        if(error == 0) {
          return;
        }

        var link = url + '?login=' + login + '&password=' + pass + '&request=UnlockIP';

        jQuery.post(link, function(data) {
          var n = data.search("Brugernavn");
          $("#ip_release_message p").html(data);
          $('.kms_services_login_form_login_wrap').hide();
          $('.kms_services_login_form_pass_wrap').hide();
          $('#kms_services_login_form_submit').hide();
          if(n != -1) {
            $('#kms_services_login_form_return').show();
          }
        });

        $('#kms_services_login_form_return').click(function(event) {
          event.preventDefault();
          $("#ip_release_message p").html('');
          $('.kms_services_login_form_login_wrap').show();
          $('.kms_services_login_form_pass_wrap').show();
          $('#kms_services_login_form_submit').show();
          $('#kms_services_login_form_return').hide();
        });

      });
    }
  };
})(jQuery);