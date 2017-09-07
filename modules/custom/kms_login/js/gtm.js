(function ($) {
  Drupal.behaviors.kms_login = {

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