(function ($) {
  Drupal.behaviors.kmsMapwidgetGtm = {

    attach: function (context, settings) {

      // On download click, get data and add to datalayer
      $('span.file > a[target="filetargetframe"]').click(function(e){
        dataLayer.push({
          'event': 'download bestilling',
          'producttype': $(this).parents('tr').attr('data-product-type'),
          'usertype' : $(this).parents('table').attr('data-user-type')
        });
      });
    }

  };
})(jQuery, Drupal);