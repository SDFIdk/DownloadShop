(function ($) {
  Drupal.behaviors.kmsOciQueueReports = {
    attach: function(context, settings) {
      // Poll statuses (and log).
      pollStatuses();

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

      // Update statuses with polling.
      function pollStatuses() {
        setTimeout(function () {
          $.ajax({
            url: "/kms-oci-queue/ajax/load-statuses",
            type: 'GET',
            success: function(xhr){
              var status = xhr.status;
              // Update statuses.
              for (var jobId in status) {
                $('td.status[data-jid="' + jobId + '"]', context).replaceWith(status[jobId]);
              }
            },
            complete: loadLog,
            timeout: 3000
          });
        }, 3000);
      }

      // Update log with polling if open.
      function loadLog () {
        if (typeof($.cookie('kms-oci-queue-job-log-open-jid') !== 'undefined')) {
          var jobId = $.cookie('kms-oci-queue-job-log-open-jid');
          var currentTd = $('td.job-log-trigger[data-jid="' + jobId + '"]', context);
          currentTd.addClass('loading');
          $.ajax({
            url: '/kms-oci-queue/ajax/load-log/' + jobId,
            type: 'GET',
            success: function(xhr) {
              $('.kms-oci-queue-job-log[data-jid="' + jobId + '"] td', context).html(xhr.html);
            },
            complete: function() {
              currentTd.removeClass('loading');
            }
          });
        }
        pollStatuses();
      }

    }
  }


})(jQuery, Drupal);


