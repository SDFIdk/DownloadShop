(function ($) {
  Drupal.behaviors.kms_user_gdpr_scroll = {
    attach: function (context, settings) {
      // Do we have #scroll-to in the DOM.
      var docContainsScrollTo = $('#scroll-to').length;
      if (docContainsScrollTo) {

        // Get placement.
        var scrollToTop = $('#scroll-to').offset().top;
        var scrollToTopBottom = scrollToTop + $('#scroll-to').outerHeight();

        if ($('#consent-body').length) {
          var consentBodyTop = $('#consent-body').offset().top;
          var consentBodyBottom = consentBodyTop + $('#consent-body').outerHeight();
        }

        if ($('#terms-body').length) {
          var consentBodyTop = $('#terms-body').offset().top;
          var consentBodyBottom = consentBodyTop + $('#terms-body').outerHeight();
        }

        var viewportTop = $(window).scrollTop();
        var viewportBottom = viewportTop + $(window).height();

        // Is the #scroll-to visible.
        var scrollTopVisible = false;
        if (scrollToTop > viewportTop && scrollToTop < viewportBottom) {
          scrollTopVisible = true;
        }

        if ($('#consent-body').length > 0 && scrollTopVisible) {
          $('#edit-consent-check').removeAttr('disabled');
          $('#edit-submit').removeAttr('disabled');
        }

        if ($('#terms-body').length > 0 && scrollTopVisible) {
          $('#term-check').removeAttr('disabled');
          $('#edit-submit').removeAttr('disabled');
        }
      }

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