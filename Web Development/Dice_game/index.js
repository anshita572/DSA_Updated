var randomNumber1=Math.floor(Math.random()*6) +1; //generates a random no b/w 1 to 6
var randomImage="dice"+randomNumber1+".png";//dice1.png to dice6.png
var randomImageSource="./images/"+randomImage; //./images/dice1.png to ./images/dice6.png 
document.querySelector("img.img1").setAttribute("src",randomImageSource);
var randomNumber2=Math.floor(Math.random()*6)+1;
var randomImageSource2="./images/dice"+randomNumber2+".png";
document.querySelector("img.img2").setAttribute("src",randomImageSource2);
var winner;
if(randomNumber1 > randomNumber2)
{ document.querySelector("h1.container").innerHTML="Player 1 Wins !🚩";

}
else if(randomNumber2 > randomNumber1)
{ document.querySelector("h1.container").innerHTML="Player 2 Wins !🚩";

}
else{
    document.querySelector("h1.container").innerHTML="Draw !";
}