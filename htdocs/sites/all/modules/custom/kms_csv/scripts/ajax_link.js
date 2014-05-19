(function ($) {
  Drupal.behaviors.myModule = {
    attach: function (context, settings) {
      jQuery(".mydownloads .file a").bind('click', function(e) {
        $.ajax({
		type: "POST",
		url: "/trigerdownload/"+$(this).attr('id')+"/"+$(this).attr('rel'),
		async: true,
		data: {
			'from_js' : true,
		},
		dataType: "json",
		success: function (status) {
		if (data.message) {
			 
			}
		  },
		  error: function (xmlhttp) {
			alert('An error occured: ' + xmlhttp.status);
		  }
		});
		
      });
    }
  };
}(jQuery));