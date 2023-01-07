console.log("Start");
setTimeout(() => {
  console.log("2 second timer");
}, 2000);
setTimeout(() => {
    console.log("0 second timer");
  }, 0);
console.log("Stop");
//  setTimeout is asynchronous and non-blocking.
//  The setTimeout call doesn’t block Node.js from running
// other code while it’s waiting for the 2 seconds to pass.
