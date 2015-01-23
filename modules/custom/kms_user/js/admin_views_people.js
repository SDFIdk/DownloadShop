/**
 * Created by mikkel on 12/18/13.
 */

(function ($) {
  Drupal.behaviors.kms_user_admin_views_people = {
    attach: function(context, settings) {
      /* Custom filter for webservice START */
      //check if service type is selected
      if($("select[name='exposed_services']").val() != 0){
        changeServicesList();
        $(".form-item-seperate-permissions").show();
      }

      //Trigger when service type select was changed
      $("select[name='exposed_services']").live("change",function(){
        //if service type is changed to all
        if($("select[name='exposed_services']").val() == 0){
          $("#edit-exposed-services-list").hide();
          $(".form-item-seperate-permissions").hide();
          //if seperate permissions is checked, then unclick it
          if($("#edit-seperate-permissions").is(":checked")){
            $("#edit-seperate-permissions").click();
          }
          $("#edit-exposed-services-list").find("option").remove().end();
        }else{
          //show service list
          $(".form-item-seperate-permissions").show();
          changeServicesList();
        }
      });

      //This functions gets json array of services in selected service type
      function changeServicesList(){
        var custom_services = ['ftp', 'applications', 'predefined_datacollections'];
        var webid = $("select[name='exposed_services']").val();
        var prefix = '';
        if ( $.inArray(webid, custom_services) > -1 ) {
            prefix = webid + '_';
        }
        $("#edit-exposed-services-list").fadeOut();
        var webid_link = "/kms-user/json/webservices/" + webid;
        $.ajax({
           url: webid_link,
            dataType: 'json',
            success: function(data){
                $("#edit-exposed-services-list").find("option").remove().end();
                jQuery.each(data, function(index, item){
                  $("#edit-exposed-services-list").append("<option value='" + prefix + item.id + "'>" + item.name + "</option>");
                });
                sortDropDownListByText();
             },
            complete: function(data){
              var first = selectSelectedWebserviceList(window.location.search);
              $("#edit-exposed-services-list").fadeIn();
              if (typeof first !== "undefined") {
                var $s = $('#edit-exposed-services-list');
                var optionTop = $s.find('[value="'+first+'"]').offset().top;
                var selectTop = $s.offset().top;
                $('#edit-exposed-services-list').animate({scrollTop: optionTop - selectTop}, 1);
              }
            }
         });
      }

      function sortDropDownListByText() {
        // Loop for each select element on the page.
        $("#edit-exposed-services-list").each(function() {
          // Keep track of the selected option.
          var selectedValue = $(this).val();
          // Sort all the options by text. I could easily sort these by val.
          $(this).html($("option", $(this)).sort(function(a, b) {
            return a.text.toUpperCase() == b.text.toUpperCase() ? 0 : a.text.toUpperCase() < b.text.toUpperCase() ? -1 : 1
          }));
          // Select one option.
          $(this).val(selectedValue);
        });
      }

      function selectSelectedWebserviceList(str) {
        str = decodeURIComponent(str);
        var chunks = str.split("&");
        var selectedServices = [];
        var i = 0;
        for(var c=0; c < chunks.length; c++) {
          var split = chunks[c].split("=", 2);
          if(split[0] == "exposed_services_list[]"){
            selectedServices[i] = split[1];
            i++;
          }
        }
        $("#edit-exposed-services-list").val(selectedServices);

        return selectedServices[0];
      }

      /* Custom filter for webservice END */


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
