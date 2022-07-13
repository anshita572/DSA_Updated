var buttonColors = ["red", "blue", "green", "yellow"];
var gamePattern = [];
var userClickedPattern = [];
var started = false;
var level=0;
var green=false;
$(document).keydown(function(e)
{
    if(e.key==='g')
    {
        var greenSound = new Audio("./sounds/green.mp3");
     greenSound.play();
     green=true;
    clickOrKeypress();
  //  $(".g").addClass("pressed");
  // userClickedPattern.push(e.key);
  // var userChosenColor = $(e.key).attr("id");
  // console.log(userChosenColor);
  // userClickedPattern.push(userChosenColor);
  // checkAnswer(userClickedPattern.length-1);
  //animatePress(e.key);
  // animatePress(userChosenColor);
    
    
}
});
function clickOrKeypress()
{ if(green===true)
  {var userChosenColor = $("e.key").attr("id");
userClickedPattern.push(userChosenColor);
// console.log(userClickedPattern);
playButtonSound(userChosenColor);
animatePress(userChosenColor);
checkAnswer(userClickedPattern.length-1);}
}
$(".btn").on("click", function () {
  var userChosenColor = $(this).attr("id");
  userClickedPattern.push(userChosenColor);
  // console.log(userClickedPattern);
  playButtonSound(userChosenColor);
  animatePress(userChosenColor);
  checkAnswer(userClickedPattern.length-1);
});
function playButtonSound(name) {
  var playSound = new Audio("./sounds/" + name + ".mp3");
  playSound.play();
}
function animatePress(currentColor) {
  $("." + currentColor).addClass("pressed");
  setTimeout(function () {
    $("." + currentColor).removeClass("pressed");
  }, 100);
}
$(document).keypress(function (event) {
  // console.log(event.key);
  if (started === false) {
    // $("h1").html("Level "+level);
    nextSequence();
    started = true;
   
  }
});
function restart()
{
    level=0;
    gamePattern=[];
    started=false;
}
function checkAnswer(currentLevel)
{if(userClickedPattern[currentLevel]===gamePattern[currentLevel])
{
    //console.log("right");
if(userClickedPattern.length===gamePattern.length)
{
    setTimeout(function()
    {nextSequence();},100);
}}
else
{
   // console.log("wrong");
   var wrongSound = new Audio("./sounds/wrong.mp3");
  wrongSound.play();
  $("body").addClass("game-over");
  setTimeout(function()
  {$("body").removeClass("game-over");},200);
  $("h1").text("Game Over,Press any key to restart");
  restart();
}}

//randomly a color is chosen,it animates and plays its sound automatically randomly for the next level
function nextSequence() {
    userClickedPattern=[];
    level++;
  $("h1").html("Level "+level);
  var randomNumber = Math.floor(Math.random() * 4);

  var randomChosenColor = buttonColors[randomNumber];
  gamePattern.push(randomChosenColor);
  $("#" + randomChosenColor)
    .fadeIn(100)
    .fadeOut(100)
    .fadeIn(100);
  playButtonSound(randomChosenColor);
  

}
