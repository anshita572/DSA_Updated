//Constructor function in js <=> Class in C++
//name of function has to start with a capital letter so that it is a constructor function and not just a normal function
function Student(name,age,stream,languages)
{
    this.name=name;
    this.age=age;
    this.stream=stream;
    this.languages=languages;
    this.say=function(){alert("I am a student");//Method function
}
}
var s1=new Student("Ramesh",19,"Science",["English","Hindi"]);
console.log(s1.languages);
s1.say();