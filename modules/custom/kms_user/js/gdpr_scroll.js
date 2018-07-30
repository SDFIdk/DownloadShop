(function ($) {
  Drupal.behaviors.kms_user_gdpr_scroll = {
    attach: function (context, settings) {
      // Make sure that the consent body is read before you can accept.
      $('#consent-body').scroll(function () {
        var hT = $('#scroll-to').offset().top,
            hH = $('#scroll-to').outerHeight(),
            wH = $(window).height(),
            wS = $(this).scrollTop();

        if ((wS - 20) > (hT + hH - wH)) {
          $('#edit-consent-check').removeAttr('disabled');
        }
      });

      // When the consent check is clicked, we can enable the continue button.
      $('#edit-consent-check').change(function () {
        if ($('#edit-consent-check').is(':checked') == true) {
          $('#edit-submit').removeAttr('disabled');
        }
      });

      $('#terms-body').scroll(function () {
        var hT = $('#scroll-to').offset().top,
            hH = $('#scroll-to').outerHeight(),
            wH = $(window).height(),
            wS = $(this).scrollTop();

        if ((wS - 20) > (hT + hH - wH)) {
          $('#term-check').removeAttr('disabled');
        }
      });

      $('#term-check').change(function () {
        if ($('#edit-consent-check').is(':checked') == true) {
          $('#edit-submit').removeAttr('disabled');
        }
      });
    }
  };
})(jQuery);