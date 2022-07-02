console.log("hello");
console.log(2 + 3);
// commented codes work in chrome console
// typeof(123);

// typeof("Anshita");

// typeof(true);

// alert("hello");

// alert(2+3);

var x = "Anshita";
console.log(x); //console in terminal
// alert(x); //Anshita will be popped up
//  var y =prompt("Enter your name");
// alert(y);
// alert("My name is : "+x +" and Your name is : "+y );

//Swapping 2 numbers
var a = 3;
var b = 8;
console.log("a = " + a);
console.log("b = " + b);
var c = a;
a = b;
b = c;
console.log("a = " + a);
console.log("b = " + b);
var message = "Hello";
var myName = "Anshita";
console.log(message + " " + myName);
//message.length;
// alert(message + " " +myName );

//string length
// var message=prompt("Enter your message");
// alert("You have written "+message.length+
//       " characters and " +(180-message.length)+
//      " characters remaining");

var myName = "Anshita";
var cut = myName.slice(0, 2);
//characters cut=uppperBound - lowerBound (2-0=2 =>An)
console.log(cut);

// var message=prompt("Enter your message");
// var cut=message.slice(0,140);
// alert(cut);

var YourName = "Anshita";
YourName = YourName.toUpperCase();
console.log(YourName);
YourName = YourName.toLowerCase();
console.log(YourName);

//The user entered name should be greeted with Hello Username with first letter capital and rest of the letters small
var x = prompt("Enter your name");

var z = x.slice(0, 1); //separting the first letter
z = z.toUpperCase(); //converting first letter to uppercase
var y = x.slice(1, x.length); //separting rest of letters
y = y.toLowerCase(); //converting rest of letters to lower case
alert("Hello " + z + y);
