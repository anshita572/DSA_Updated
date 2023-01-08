function sendMail() {
  var params = {
    name: document.getElementById("name").value,
    email: document.getElementById("email").value,
    message: document.getElementById("message").value,
  };
  const serviceID = "service_rx9p7td";
  const templateID = "template_k4entgl";
  if (
    !document.getElementById("name").value == "" &&
    isNaN(document.getElementById("name").value) &&
    !document.getElementById("email").value == "" &&
    document.getElementById("email").value.includes("@") &&
    !document.getElementById("message").value == ""
  )
    emailjs
      .send(serviceID, templateID, params)
      .then((res) => {
        document.getElementById("name").value = "";
        document.getElementById("email").value = "";
        document.getElementById("message").value = "";
        console.log(res);
        alert("Your message has been sent successfully!!");
      })
      .catch((err) => console.log(err));
}
// $('myform').on('keypress', function(e) {
//   // Register keypress on buttons.
//   $attr = $(e.target).attr('type');
//   $node = e.target.nodeName.toLowerCase();
//   if ($attr === 'button' || $attr === 'submit' || $node === 'textarea') {
//     return true;
//   }

//   // Ignore keypress if all fields are not populated.
//   if (e.which === 13 && !fieldsArePopulated(this)) {
//     return false;
//   }
// });
// document.getElementById("myform"); form. addEventListener("submit",function(e){e. preventDefault(); return false;});
ready(function () {
  $(window).keydown(function (event) {
    if (event.keyCode == 13) {
      event.preventDefault();
      return false;
    }
  });
});
