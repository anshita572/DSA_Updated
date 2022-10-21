function countdown()
{
const countDownDate=new Date("Jan 1,2023").getTime();
// console.log(countDownDate);
const currentDate=new Date().getTime();
const gap=countDownDate-currentDate; //This difference will be in milliseconds
// console.log(gap);
const myInterval=setInterval(countdown,1000);//call this function every second
if(gap<=0)
{clearInterval(myInterval);
    document.querySelector("h1").innerHTML="Happy New Year   🤩";
    document.querySelector(".countdown-container").innerHTML= "🎉Let us Celebrate!🎉";
}
const second=1000; //1s=1000ms
const minute=second*60;
const hour=minute*60;
const day=hour*24;
const daysRemaining= Math.floor(gap/day);
//console.log(daysRemaining);
const hoursRemaining=Math.floor((gap % day)/hour);
// console.log(hoursRemaining);
const minRemaining=Math.floor((gap % hour)/minute);
const secRemaining=Math.floor((gap % minute)/second);
document.querySelector("#days").innerHTML=daysRemaining;
document.querySelector("#hours").innerHTML=addZero(hoursRemaining);
document.querySelector("#min").innerHTML=addZero(minRemaining);
document.querySelector("#sec").innerHTML=addZero(secRemaining);


}
countdown();
//if time < 10 ,add a string of 0 in front,else nothing""(space)
function addZero(time)
{ return (time < 10 ? "0" : "") + time;}
function stop()
{clearInterval(myInterval);
document.querySelector(".countdown-container").innerHTML="Expired";}
