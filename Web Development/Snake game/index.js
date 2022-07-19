// var direction={x:0,y:0};//initially snake is stationary
// var foodSound=new Audio("./music/food.mp3");
// var moveSound=new Audio("./music/move.mp3");
// var musicSound=new Audio("./music/music.mp3");
// var gameOverSound=new Audio("./music/gameover.mp3");

var snakeHead = [{ x: 9, y: 9 },{ x: 10, y: 9 }]; //initially snake is in 11th row and 11th column
var food={x:5,y:5};//initially food is in 5th row and 5th column
var lastRenderTime = 0;
var snakeSpeed = 2;
function main(currentTime) {
  //game loop
  window.requestAnimationFrame(main);
  var secondsTillLastRender = (currentTime - lastRenderTime) / 1000; //1000 so as to convert in seconds
  if (secondsTillLastRender < 1 / snakeSpeed) {
    //snake will move 2 times(=snake speed) in a second
    // if secondsTillLastRender <1/2 ,don't render
    return;
  }
 // console.log("render");
  lastRenderTime = currentTime;
  display();
}
window.requestAnimationFrame(main);
function update() {
  //to update snake array and food
  

   
}
function display() {
  //to display snake array
  const gameBoard = document.getElementById('board');
 gameBoard.innerHTML="";
  snakeHead.forEach((snakeSegment) => {
    var snakeElement = document.createElement('div');
    snakeElement.style.gridRowStart = snakeSegment.x;
    snakeElement.style.gridColumnStart = snakeSegment.y;
    snakeElement.classList.add('snake-head');
    gameBoard.appendChild(snakeElement);
  });
  //to display food
    var foodElement = document.createElement('div');
    foodElement.style.gridRowStart = food.x;
    foodElement.style.gridColumnStart = food.y;
    foodElement.classList.add('snake-food');
   gameBoard.appendChild(foodElement);
  
}
