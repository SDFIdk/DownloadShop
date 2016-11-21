/**
 * @file
 */
function fonf(cb){
  if (cb.checked == true) {
    var myboxes = document.getElementsByClassName('service-free-checkbox');
    for (var i = 0; i < myboxes.length; i++) {
      myboxes[i].checked = true;
    }
  }
  else {
    var myboxes = document.getElementsByClassName('service-free-checkbox');
    for (var i = 0; i < myboxes.length; i++) {
      myboxes[i].checked = false;
    }
  }
}

function serviceTypeCheckboxes(cb){
  if (cb.checked == true) {
    var myboxes = document.getElementsByClassName('service-type-checkbox');
    for (var i = 0; i < myboxes.length; i++) {
      myboxes[i].checked = true;
    }
  }
  else {
    var myboxes = document.getElementsByClassName('service-type-checkbox');
    for (var i = 0; i < myboxes.length; i++) {
      myboxes[i].checked = false;
    }
  }
}
