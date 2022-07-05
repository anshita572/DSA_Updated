var numbers=[];
var count=1;
function fizzBuzz() {
   

   if(count % 15 === 0) //if(count % 3 === 0 && count % 5 === 0)
    {numbers.push("FizzBuzz");} 
   else if(count % 3 === 0)
    {numbers.push("Fizz");}
   else if(count % 5 === 0)
    {numbers.push("Buzz");}
   else{
            numbers.push(count);
        }
    
      count++;
  console.log(numbers);
}


