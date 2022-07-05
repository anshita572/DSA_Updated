function whosPaying(names) {
   
    var numberOfPeople=names.length;
     var random=Math.floor(Math.random() * numberOfPeople);
     var randomPerson=names[random];
     return randomPerson+" is paying for lunch today ";
     
  }
  names=["Reena","Meena","Teena","Sabina"];
  whosPaying(names);
  
  