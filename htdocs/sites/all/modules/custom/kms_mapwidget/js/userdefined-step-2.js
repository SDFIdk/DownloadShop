(function($, Drupal) {
  Drupal.behaviors.step2 = { 
	  attach: function (context, settings) { 

    $("select", context).change(function () {
      $(".selected-description").hide();
      $("select option:selected",context).each(function () {
        //console.log("#desc-" + $(this).attr('value'));
        $("#desc-" + $(this).attr('value')).show();
      });
    })

    $("select").trigger('change');
 
    } 
  };
}(jQuery, Drupal));
