(function($) {
    $('#edit-myservicestoggle')
        .parents('.form-item')
        .siblings('.form-item')
        .hide();
    $('#edit-myservicestoggle').on('click', function() {
        $('#edit-otherservices').click();
    });
})(jQuery);