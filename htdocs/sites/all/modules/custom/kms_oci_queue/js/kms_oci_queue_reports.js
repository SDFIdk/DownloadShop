(function ($) {
  Drupal.behaviors.kmsOciQueueReports = {
    attach: function(context, settings) {
      // Poll job tables.
      pollJobs();
      jobLogTrigger();
      $('a', context).bt({width: 300});

      // Update job tables with polling.
      function pollJobs() {
        setTimeout(function () {
          $.ajax({
            url: "/kms-oci-queue/ajax/poll-jobs",
            type: 'GET',
            success: function(xhr){
              if (xhr.stateChanged) {
                $('.kms-oci-queue-jobs-overview', context).html(xhr.html);
                $('.bt-wrapper').hide();
                jobLogTrigger();
                $('a', context).bt({width: 300});              }
            },
            complete: pollJobs,
            timeout: 4500
          });
        }, 4500);
      }

      function jobLogTrigger() {
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
              },
              complete: function() {
                currentTd.removeClass('loading');
              }
            });
          }
        });
      }

    }
  }



})(jQuery, Drupal);


