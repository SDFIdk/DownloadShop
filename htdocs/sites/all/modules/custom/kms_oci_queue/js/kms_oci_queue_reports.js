(function ($) {
  Drupal.behaviors.kmsOciQueueReports = {
    attach: function(context, settings) {
      $('td.job-log-trigger', context).click(function(){
        var jobId = $(this).attr("data-jid");
        var currentTd = $(this);
        $.ajax({
          url: '/kms-oci-queue/ajax/load-log/' + jobId,
          type: 'GET',
          success: function(xhr) {
            $('.kms-oci-queue-job-log', context).not('[data-jid="' + jobId + '"]').hide();
            $('.kms-oci-queue-job-log[data-jid="' + jobId + '"]', context).show();
            $('.kms-oci-queue-job-log[data-jid="' + jobId + '"] td', context).html(xhr.html);
            $('td.job-log-trigger', context).not(currentTd).removeClass('active');
            currentTd.addClass('active');
            console.log(currentTd);

          }
        });
      });
    }
  }


})(jQuery, Drupal);


