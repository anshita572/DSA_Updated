//Assuming you live upto 90 years ,how many days,weeks,months are left till we turn 90
function lifeInWeeks(age)
    {
var remainingAge=90-age;
var days=365*remainingAge;
var weeks=52*remainingAge;
var months=remainingAge*12;
console.log("You have "+days+" days, " +weeks+" weeks, " +months+" months left ");
    }
lifeInWeeks(20);