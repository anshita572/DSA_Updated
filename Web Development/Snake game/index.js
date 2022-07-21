let direction = { x: 0, y: 0 }; //jis direction m we r moving the snake
var score = 0;
var snakeHead = [{ x: 9, y: 9 }]; //initially snake is in 11th row and 11th column
var food = { x: 5, y: 5 }; //initially food is in 5th row and 5th column
var lastRenderTime = 0;
var snakeSpeed = 7;
function main(currentTime) {
  //game loop
  window.requestAnimationFrame(main);
  var secondsTillLastRender = (currentTime - lastRenderTime) / 1000; //1000 so as to convert in seconds
  if (secondsTillLastRender < 1 / snakeSpeed) {
    //snake will move 5 times(=snake speed) in a second
    // if secondsTillLastRender <1/2 ,don't render
    return;
  }
  // console.log("render");
  lastRenderTime = currentTime;
 // start();
  gameOperations();
}
// function start()
// {$(document).keypress(function (e) {
//   if (e.keyCode==="Enter")
//   {gameOperations();}
// }
// );
// }
window.requestAnimationFrame(main);
function isCollide(snake) {
  //if snake bumps into itself
  for (var i = 1; i < snakeHead.length; i++) {
    {
      if (snake[0].x === snake[i].x && snake[0].y === snake[i].y) return true;
    }
  }
  //if snake bumps into any of the walls
  if (
  snake[0].x >= 18 ||
    snake[0].x <= 0 || snake[0].y >= 18 ||
    snake[0].y <= 0
  ) {
    return true;
  }
  return false;
}

function gameOperations() {
  document.addEventListener("keydown", function (e) {
  
    // var moveSound = new Audio("./music/move.mp3");
    // moveSound.play();
    // $("h1").remove();
    direction = { x: 1, y: 0 };
    $(".heading").text("Enjoy the amazing adventure !");
    //  console.log(event.key);

    switch (e.key) {
      case "ArrowUp":
        console.log("ArrowUp");
        direction.x = 0;
        direction.y = -1;
        break;
      case "ArrowDown":
        console.log("ArrowDown");
        direction.x = 0;
        direction.y = 1;
        break;
      case "ArrowLeft":
        direction.x = -1;
        direction.y = 0;
        console.log("ArrowLeft");
        break;
      case "ArrowRight":
        console.log("ArrowRight");
        direction.x = 1;
        direction.y = 0;
        break;

      default:
        break;
    }
  
  });


  //if snake has eaten food ,regenerate food randomly
  if (snakeHead[0].x === food.x && snakeHead[0].y === food.y) {
    //if coordinates of snake Head and food meet=>snake has eaten food
    var foodSound = new Audio("./music/food.mp3");
    foodSound.play();
    snakeHead.unshift({
      x: snakeHead[0].x + direction.x,
      y: snakeHead[0].y + direction.y,
    });
    score++;
    var randomFoodPosition = Math.floor(Math.random() * 18) + 1;
    food = { x: randomFoodPosition, y: randomFoodPosition };
  }
  //moving the snake
  for (var i = snakeHead.length - 2; i >= 0; i--) {
    snakeHead[i + 1] = { ...snakeHead[i] };
  }
  snakeHead[0].x = snakeHead[0].x + direction.x;
  snakeHead[0].y = snakeHead[0].y + direction.y;

  //to display snake array
  const gameBoard = document.getElementById("board");
  gameBoard.innerHTML = "";
  snakeHead.forEach((snakeSegment) => {
    var snakeElement = document.createElement("div");
    snakeElement.style.gridRowStart = snakeSegment.y;
    snakeElement.style.gridColumnStart = snakeSegment.x;
    snakeElement.classList.add("snake-head");
    gameBoard.appendChild(snakeElement);
  });
  //to display food
  var foodElement = document.createElement("div");
  foodElement.style.gridRowStart = food.x;
  foodElement.style.gridColumnStart = food.y;
  foodElement.classList.add("snake-food");
  gameBoard.appendChild(foodElement);

  //to update snake array and food
  if (isCollide(snakeHead)) {
    var gameOverSound = new Audio("./music/gameover.mp3");
    gameOverSound.play();
    
   $("h1").text("Game over ! Press any key to play again");
    snakeHead = [
      { x: 9, y: 9 }
    ];
    direction = { x: 0, y: 0 };
    score = 0;
  }
}
