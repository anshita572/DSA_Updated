function nextSequence(){
var randomNumber=Math.floor((Math.random())*4);
}
var buttonColors=["red","blue","green","yellow"];
var randomChosenColor=buttonColors[randomNumber];
var gamePattern=[];
gamePattern.push(randomChosenColor);
$("#"+randomChosenColor);