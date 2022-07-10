//for single button
// function MyClick()
// {alert("I am clicked");}
// document.querySelector("button.w").addEventListener("click",MyClick);

//for all buttons
var n = document.querySelectorAll(".drum").length; //n=no. of drum buttons i.e. 7
for (var i = 0; i < n; i++) {
  document
    .querySelectorAll(".drum")
    [i].addEventListener("click", function () // alert("I am clicked");
    
      //     var audio=new Audio("sounds/tom-1.mp3");
      // audio.play();
      //this tells which button got clicked w or a or so on
      // this.style.color="white";
      {makeSound(this.innerHTML);
        buttonAnimation(this.innerHTML);
      
    });
}
document.addEventListener("keydown",function(event)
{
    // alert("Key pressed");
    //console.log(event);
    makeSound(event.key);
    buttonAnimation(event.key);
});
function makeSound(key)
{
    switch (key) {
        case "w":
          var tom1 = new Audio("sounds/tom-1.mp3");
          tom1.play();
          break;
        case "a":
          var tom2 = new Audio("sounds/tom-2.mp3");
          tom2.play();
          break;
        case "s":
          var tom3 = new Audio("sounds/tom-3.mp3");
          tom3.play();
          break;
        case "d":
          var tom4 = new Audio("sounds/tom-4.mp3");
          tom4.play();
          break;
        case "j":
          var snare = new Audio("sounds/snare.mp3");
          snare.play();
          break;
        case "k":
          var crash = new Audio("sounds/crash.mp3");
          crash.play();
          break;
        case "l":
          var kick = new Audio("sounds/kick-bass.mp3");
          kick.play();
          break;

        default:console.log(this.innerHTML);
          break;
}
}
function buttonAnimation(currentKey)
{
 var activeButton=document.querySelector("."+currentKey);
                  //like(.w) where w is class of w button
    activeButton.classList.add("pressed");
    //setTimeout(function, milliseconds, param1, param2, ...)
    setTimeout(function()
    {activeButton.classList.remove("pressed");}
    ,300); //0.3 seconds or 300 milliseconds
}