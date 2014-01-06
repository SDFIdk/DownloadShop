(function ($) {
  Drupal.behaviors.kms_permissions = {
    checkUncheckAll: function(theElement, scope) {
	  $('.'+scope+' input.form-checkbox').each(function(){
          $(this).attr("checked", theElement.checked);
      });
    }
  };
})(jQuery);