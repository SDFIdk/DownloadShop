(function ($) {
  Drupal.behaviors.kms_user_gdpr_scroll = {
    attach: function (context, settings) {

      console.log('GDPR');

      $('#terms-body').scroll(function () {
        var hT = $('#scroll-to').offset().top,
            hH = $('#scroll-to').outerHeight(),
            wH = $(window).height(),
            wS = $(this).scrollTop();

        if ((wS - 20) > (hT + hH - wH)) {
          $('#edit-submit').removeAttr('disabled');
          $('#term-check').removeAttr('disabled');
        }
      });
    }
  };
})(jQuery);