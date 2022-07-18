// var direction={x:0,y:0};//initially snake is stationary
// var foodSound=new Audio("./music/food.mp3");
// var moveSound=new Audio("./music/move.mp3");
// var musicSound=new Audio("./music/music.mp3");
// var gameOverSound=new Audio("./music/gameover.mp3");

var snakeHead=[{x:11,y:11}];//initially snake is in 11th row and 11th column
var lastRenderTime=0;
var snakeSpeed=2;
function main(currentTime) //game loop
{
    window.requestAnimationFrame(main);
    var secondsTillLastRender=(currentTime-lastRenderTime)/1000; //1000 so as to convert in seconds
    if(secondsTillLastRender<1/snakeSpeed)//snake will move 2 times(=snake speed) in a second
   // if secondsTillLastRender <1/2 ,don't render
    {return;}
    console.log('render');
    lastRenderTime=currentTime;
}
window.requestAnimationFrame(main);
function update(board) //to update snake array and food
{snakeHead.forEach(snakeSegment => {
    var snakeElement=document.createElement('div');
    snakeElement.style.gridRowStart=snakeSegment.x;
    snakeElement.style.gridColStart=snakeSegment.y;
    snakeElement.classList.add('snake-head');
    board.appendChild(snake-element);

});
    }
function display()//to display snake array and food
{}