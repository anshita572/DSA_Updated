var arr=[1,2,3,4,5];
console.log(arr);
var n1=arr[1];
console.log(n1);

var guests=["REENA","MEENA","TEENA","HEENA"];
var names=prompt("Enter your name");
names=names.toUpperCase();
if(guests.includes(names))
{console.log("Hey "+names+" ! Welcome to the party");}
else
{console.log("Sorry " +names+" ! You are not invited");}