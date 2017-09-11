(function ($) {
  Drupal.behaviors.kmsLogin = {

    attach: function (context, settings) {
      if (Drupal.settings.kms_login) {
        dataLayer.push({
          'event': 'login',
          'usertype': Drupal.settings.kms_login.type
        });
      }
    }

  };
})(jQuery, Drupal);