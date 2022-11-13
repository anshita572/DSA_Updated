const container = document.querySelector(".container"),
      pwShowHide = document.querySelectorAll(".showHidePw"),
      pwFields = document.querySelectorAll(".password"),
      signUp = document.querySelector(".signup-link"),
      login = document.querySelector(".login-link");

    //   js code to show/hide password and change icon
    pwShowHide.forEach(eyeIcon =>{
        eyeIcon.addEventListener("click", ()=>{
            pwFields.forEach(pwField =>{
                if(pwField.type ==="password"){
                    pwField.type = "text";

                    pwShowHide.forEach(icon =>{
                        icon.classList.replace("uil-eye-slash", "uil-eye");
                    })
                }else{
                    pwField.type = "password";

                    pwShowHide.forEach(icon =>{
                        icon.classList.replace("uil-eye", "uil-eye-slash");
                    })
                }
            }) 
        })
    })

    // js code to appear signup and login form
    signUp.addEventListener("click", ( )=>{
        container.classList.add("active");
    });
    login.addEventListener("click", ( )=>{
        container.classList.remove("active");
    });
   
    const scriptUrl='https://script.google.com/macros/s/AKfycbxQQOucpr-a0I1jpYIayuJPREnY8l9Dn35L0Zc9GdHNx43UYmNNghFAT8KL6YtGfXbX_Q/exec';

    const form=document.forms['feedback_form'];
    form.addEventListener('submit',e=>{
        e.preventDefault();
        fetch(scriptUrl,{method:'POST',body:new FormData(form)})
        .then(response => alert('Thanks for your valuable feedback'))
        .catch(error=>console.log('Error',error.message))
    })
