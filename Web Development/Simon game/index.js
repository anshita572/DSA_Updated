var buttonColors=["red","blue","green","yellow"];
var gamePattern=[];
var userClickedPattern=[];
$(".btn").on("click",function()
{
    var userChosenColor=$(this).attr("id");
    userClickedPattern.push(userChosenColor);
    // console.log(userClickedPattern);
    playButtonSound(userChosenColor);
    
});
function playButtonSound(name)
{
    var playSound=new Audio("./sounds/"+name+".mp3");
    playSound.play();
}


//randomly a color is chosen,it animates and plays its sound automatically randomly for the next level
function nextSequence(){
var randomNumber=Math.floor((Math.random())*4);

var randomChosenColor=buttonColors[randomNumber];
gamePattern.push(randomChosenColor);
$("#"+randomChosenColor).fadeIn(100).fadeOut(100).fadeIn(100);
playButtonSound(randomChosenColor);

}
