//Check for leap year
function isLeap(year) 
{
    if (year % 4 === 0)
    {
        if(year % 100 != 0)
        {console.log(year+" is a leap year");}
        else //if divisible by 100
        {
            if(year % 400 === 0)
        {console.log(year+" is a leap year");}
        else //if not divisble by 400
        {console.log(year+" is not a leap year");}
            
        }
    }

     else //not divisible by 4
        {console.log(year+" is not a leap year");}
}
var year=prompt("Enter a year");
isLeap(year);