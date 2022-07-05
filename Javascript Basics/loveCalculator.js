// Generate a love calculator
//Works in chrome console
prompt("Enter your name");
prompt("Enter your crush's name");
var loveScore=Math.random()*100;
loveScore=Math.floor(loveScore)+1; //range from 1 to 100
if(loveScore <= 30)
{
    console.log(" Your love score = "+loveScore+" % Sorry! You are not compatible with each other");
}


if(loveScore >30 && loveScore <= 70)
{
    console.log(" Your love score = "+loveScore+" %");
}
if(loveScore > 70)
{
    console.log(" Your love score = "+loveScore+" % Congratulations! You both are made for each other");
}

