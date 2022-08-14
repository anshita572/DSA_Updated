function countdown()
{
const countDownDate=new Date("Aug 17,2022").getTime();
// console.log(countDownDate);
const currentDate=new Date().getTime();
const gap=countDownDate-currentDate; //This difference will be in milliseconds
// console.log(gap);
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
document.querySelector("#hours").innerHTML=hoursRemaining;
document.querySelector("#min").innerHTML=minRemaining;
document.querySelector("#sec").innerHTML=secRemaining;
setInterval(countdown,1000);//call this function every second
}
countdown();