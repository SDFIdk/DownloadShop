(function ($) {
  Drupal.behaviors.kms_user_forms = {
    attach: function(context, settings) {
      // Ugly but working fix. If user is not super admin then hide stuff.
      if(!settings.kms_user.isSuperAdmin) {
        $('.street-block').hide();
        $('.form-item-field-address-und-0-organisation-name').hide();
        $('.form-item-field-address-und-0-postal-code').hide();
        $('.form-item-field-address-und-0-locality').hide();
        $('.form-item-field-address-und-0-country').hide();
      }
    }
  };
})(jQuery, Drupal);
