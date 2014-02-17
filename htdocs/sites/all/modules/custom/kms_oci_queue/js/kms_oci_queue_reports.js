(function ($) {
  Drupal.behaviors.kmsOciQueueReports = {
    attach: function(context, settings) {
      // Poll job tables.
      pollJobs();

      $('td.job-log-trigger', context).click(function(){
        var jobId = $(this).attr("data-jid");
        var currentTd = $(this);
        if(currentTd.hasClass('active')) {
          $('.kms-oci-queue-job-log[data-jid="' + jobId + '"]', context).hide();
          currentTd.removeClass('active');
        }
        else {
          currentTd.addClass('loading');
          $.ajax({
            url: '/kms-oci-queue/ajax/load-log/' + jobId,
            type: 'GET',
            success: function(xhr) {
              $('.kms-oci-queue-job-log', context).not('[data-jid="' + jobId + '"]').hide();
              $('.kms-oci-queue-job-log[data-jid="' + jobId + '"]', context).show();
              $('.kms-oci-queue-job-log[data-jid="' + jobId + '"] td', context).html(xhr.html);
              $('td.job-log-trigger', context).not(currentTd).removeClass('active');
              currentTd.addClass('active');
              $.cookie('kms-oci-queue-job-log-open-jid', jobId);
            },
            complete: function() {
              currentTd.removeClass('loading');
            }
          });
        }
      });

      // Update job tables with polling.
      function pollJobs() {
        setTimeout(function () {
          $.ajax({
            url: "/kms-oci-queue/ajax/poll-jobs",
            type: 'GET',
            success: function(xhr){
              console.log(xhr.stateChanged);
              if (xhr.stateChanged) {
                $('.kms-oci-queue-jobs-overview', context).html(xhr.html);
                $('.bt-wrapper').hide();
                Drupal.behaviors.beautytips.attach(context, settings);
                Drupal.behaviors.kmsOciQueueReports.attach(context, settings);
              }

            },
            complete: pollJobs,
            timeout: 8000
          });
        }, 8000);
      }

    }
  }


})(jQuery, Drupal);


