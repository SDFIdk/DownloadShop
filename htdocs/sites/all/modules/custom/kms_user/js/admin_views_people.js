/**
 * Created by mikkel on 12/18/13.
 */

(function ($) {
  Drupal.behaviors.kms_user_admin_views_people = {
    attach: function(context, settings) {

      $('.field-widget-kms-services .form-checkboxes', context).each(function(){
        $(this).hide();
        var id = $(this).attr('id');
        $('label[for="' + id + '"]').click(function() {
          $('#' + id).toggle();
        });
      });

      var viewContainer  = '.view-admin-views-user';
      $('.kms-user-reset-view', context).click(function(){
        $(viewContainer).foggy();
        $.ajax({
          url: '/kms-user/ajax/refresh-admin-views-people',
          type: 'POST',
          success: function(xhr) {
            $(viewContainer).html(xhr.view);
          },
          complete: function() {
            // Unblur service checkboxes when request is done.
            $(viewContainer).foggy(false);
            Drupal.behaviors.kms_user_admin_views_people.attach();
            Drupal.behaviors.ZZCToolsModal.attach(context);
          }
        });
        return false;
      })

    }
  };
})(jQuery, Drupal);
