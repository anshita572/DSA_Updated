var arr=[1,2,3,4,5];
console.log(arr);
var n1=arr[1];
console.log(n1);

var guests=["REENA","MEENA","TEENA","HEENA"];
var name=prompt("Enter your name");
name=name.toUpperCase();
if(guests.includes(name))
{console.log("Hey "+name+" ! Welcome to the party");}
else
{console.log("Sorry " +name+" ! You are not invited");}