function bottlesBought(money,cost)
{
    var bottles = Math.floor(money / cost);
    console.log(+bottles + " bottles bought");
}
function getMilk(money, cost) {
  //cost per bottle
  console.log("leaveHouse");
  console.log("moveRight");
  console.log("moveRight");
  console.log("moveUp");
  console.log("moveUp");
  console.log("moveUp");
  console.log("moveUp");
  console.log("moveRight");
  console.log("moveRight");
  console.log("moveLeft");
  console.log("moveLeft");
  console.log("moveDown");
  console.log("moveDown");
  console.log("moveDown");
  console.log("moveDown");
  console.log("moveLeft");
  console.log("moveLeft");
  console.log("enterHouse");

  //calling bottlesBought function
  bottlesBought(money,cost);

 //calculating balance remaining
  var balance = money % cost;
  return balance;
}
var ans=getMilk(16,5);//Rs 16 money and Rs 5 per bottle cost
console.log("Balance = "+ans);
