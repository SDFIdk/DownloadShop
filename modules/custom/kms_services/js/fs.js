/**
 * @file
 */
(function($) {

  Drupal.behaviors.collapse = {
    attach : function(context, settings) {
      $('fieldset.collapsible', context)
        .once(
          'collapse',
          function() {
            var $fieldset = $(this);
            // Expand fieldset if there are errors inside,
            // or if it contains an
            // element that is targeted by the uri fragment
            // identifier.
            var anchor = location.hash
            && location.hash != '#' ? ', '
                      + location.hash : '';
            if ($('.error' + anchor, $fieldset).length) {
              $fieldset.removeClass('collapsed');
            }

            var summary = $('<span class="summary"></span>');
            $fieldset.bind(
                      'summaryUpdated',
            function() {
              var text = $.trim($fieldset
                .drupalGetSummary());
              summary.html(text ? ' (' + text
                                  + ')' : '');
            }).trigger('summaryUpdated');

            // Turn the legend into a clickable link, but
            // retain span.fieldset-legend
            // for CSS positioning.
            var $legend = $('> legend .fieldset-legend',
                      this);

            $(
            '<span class="fieldset-legend-prefix element-invisible"></span>')
              .append(
                      $fieldset.hasClass('collapsed') ? Drupal
                              .t('Show')
                              : Drupal.t('Hide'))
                              .prependTo($legend).after(' ');

            // .wrapInner() does not retain bound events.
            var $link = $(
            '<a class="fieldset-title" href="#"></a>')
              .prepend($legend.contents())
              .appendTo($legend)
              .click(
            function() {
              var fieldset = $fieldset
                .get(0);
              // Don't animate multiple
              // times.
              if (!fieldset.animating) {
                fieldset.animating = true;
                Drupal.toggleFieldset(fieldset);
              }
              return false;
            });
              var service_to_expand = window.location.hash;
              if(service_to_expand.length !== 0) {
                service_to_expand = service_to_expand.replace(/_/g, '-');
                $(service_to_expand + ' a').click();
              }

            $legend.append(summary);
          });
    },

    retrieveform : function(element, service_type, service_name) {
      if (true) {
        $.get(Drupal.settings.basePath + 'kms_services/form/'+service_type+'/'+service_name,
        function(data) {
          $(element).parent().children('div').html(data);
          $(element).parent().children('div').find('div.form-item-cities').hide();
          $(element).parent().children('div').find('div.form-item-username').hide();
          $(element).parent().children('div').find('div.form-item-password').hide();
        })
      }
    },

    enablecities: function(element) {
      if($(element).attr('value') == 'ArcGIS') {
        $(element).parents('#edit-fieldset-url').find('div.form-item-cities').show();
      } else {
        $(element).parents('#edit-fieldset-url').find('div.form-item-cities').hide();
      }
    },

    enableuser: function(element) {
      if($(element).attr('value') == 1) {
        $(element).parents('#edit-fieldset-url').find('.form-uri-generate-username').parent('div').show();
        $(element).parents('#edit-fieldset-url').find('.form-uri-generate-password').parent('div').show();
      } else {
        $(element).parents('#edit-fieldset-url').find('.form-uri-generate-username').parent('div').hide();
        $(element).parents('#edit-fieldset-url').find('.form-uri-generate-password').parent('div').hide();
      }
    },

    generateurl: function(element) {
      if($('#generate_url_service').length) {
        $form_values = $(element).parents('#kms-services-url-form');
        var service = $form_values.find('select[name=service_type]').attr('value');
        var service_name = $form_values.find('select[name=service_name]').attr('value');
      } else {
        $form_values = $(element).parent().parent();
        var service = $form_values.find('fieldset input[name=service_type]').attr('value');
        var service_name = $form_values.find('fieldset input[name=service_name]').attr('value');
      }

      var program_choice = $form_values.find('fieldset input[name=program_choice]:checked').attr('value');
      $usertype = $form_values.find('fieldset input[name=usertype]:checked').attr('value');
      
      if (program_choice == 'QGIS') {
        var logPar = 'LOGIN';
        var passPar = 'PASSWORD';
      }
      else {
        var logPar = 'login';
        var passPar = 'password';
      }

      $url =  'https://kortforsyningen.kms.dk/service?' +
              'servicename=' + service_name +
              '&client=' + program_choice +
              '&request=GetCapabilities' +
              '&service=' + service +
              //Conditional version attribute
              ((program_choice == 'Geomedia' ||
                program_choice == 'Gaia' ||
                program_choice == 'Udig' ||
                program_choice == 'QGIS' ||
                program_choice == 'arcGIS' ||
                program_choice == 'AutoCad' ||
                program_choice == 'MapInfo')
                ? '&version=1.1.1' : "") +
              //Conditional coordinates attribute
              (program_choice == 'ArcGIS' ? '&bbox=' + $form_values.find('fieldset select[name=cities]').attr('value'): "") +
              //Conditional login attributes
              ($usertype == 1 ? '&' + logPar + '=' + $form_values.find('fieldset input[name=username]').attr('value') +
                                '&' + passPar + '=' + $form_values.find('fieldset input[name=password]').attr('value') : "" );

      $('.rendered-url').remove();
      $(element).after($('<textarea class="rendered-url">'+$url+'</textarea>'));
    },

  };

  // Toggle the visibility of a fieldset using smooth animations.
  Drupal.toggleFieldset = function(fieldset) {
    var $fieldset = $(fieldset);
    if ($fieldset.is('.collapsed')) {
      var $content = $('> .fieldset-wrapper', fieldset).hide();
      $fieldset.removeClass('collapsed').trigger({
        type : 'collapsed',
        value : false
      }).find('> legend span.fieldset-legend-prefix').html(
      Drupal.t('Hide'));
      $content.slideDown({
        duration : 'fast',
        easing : 'linear',
        complete : function() {
          Drupal.collapseScrollIntoView(fieldset);
          fieldset.animating = false;
          // CUSTOM CODE:
          if ($fieldset.hasClass('service-fieldset-data')) {
            $.get(Drupal.settings.basePath + $fieldset.attr('rel'), function(data) {
              var $temp = $fieldset.find('.response')
                .html(data);
            });
          }
        },
        step : function() {
          // Scroll the fieldset into view.
          Drupal.collapseScrollIntoView(fieldset);
        }
      });
    }
    else {
      $fieldset.trigger({
        type : 'collapsed',
        value : true
      });
      $('> .fieldset-wrapper', fieldset).slideUp(
      'fast',
      function() {
        $fieldset.addClass('collapsed').find(
        '> legend span.fieldset-legend-prefix').html(
                                Drupal.t('Show'));
        fieldset.animating = false;
      });
    }
  };

  // Scroll a given fieldset into view as much as possible.
  Drupal.collapseScrollIntoView = function(node) {
    var h = document.documentElement.clientHeight
    || document.body.clientHeight || 0;
    var offset = document.documentElement.scrollTop
    || document.body.scrollTop || 0;
    var posY = $(node).offset().top;
    var fudge = 55;
    if (posY + node.offsetHeight + fudge > h + offset) {
      if (node.offsetHeight > h) {
        window.scrollTo(0, posY);
      }
      else {
        window.scrollTo(0, posY + node.offsetHeight - h + fudge);
      }
    }
  };

})(jQuery);
