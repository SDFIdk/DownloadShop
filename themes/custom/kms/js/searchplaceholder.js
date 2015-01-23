jQuery(document).ready(function($) {
    // DA
  $(".pane-kms-mapwidget-pane .ui-widget a.search").click(function() {
    $(".pane-kms-mapwidget-pane .ui-widget").toggleClass("show-search");
  });
  
  $(".pane-kms-mapwidget-pane input#geosearch").attr("placeholder", "Søg");
});