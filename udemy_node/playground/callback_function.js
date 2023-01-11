//A callback function is a function that’s passed as an argument(or parameter) to another function
setTimeout(() => {
  console.log("2 seconds are up");
}, 2000);
const names = ["Tim", "Jill", "Rubina", "Roger"];
const shortNames = names.filter(() => {
  return names.length <= 4;
});
// The geocode function is set up to take in two parameters. The first is the address to geocode.
// The second is the callback function to run when the geocoding process is complete
const geocode = (address, callback) => {
  setTimeout(() => {
    const data = {
      latitude: 0,
      longitude: 0,
    };
    callback(data);
  }, 2000);
};
geocode("London", (myData) => {
  console.log(myData);
});
// const add=(x,y,sum)=>{
//     setTimeout(()=>{
//         sum(x+y)
//     },2000)
// }
// add(1,4,(sum)=>{
//     console.log(sum)
// })
