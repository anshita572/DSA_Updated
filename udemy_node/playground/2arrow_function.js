// const square=function(x)
// {return x*x}
const square=(x)=>{
return x*x}
//OR
// const square=(x)=> x*x  //for single statement
console.log(square(4))

//ES6
const myEvent={
    eventName:'Birthday party',
    guestList:['Reena','Teena','Meena'],
    printGuestList(){ //ES6 (shorthand instead of writing function)
        console.log("Guest list for "+this.eventName)
        this.guestList.forEach((guest) => { //arrow 2 function
            console.log(guest+' is attending '+this.eventName)
        })

    }

}
myEvent.printGuestList()