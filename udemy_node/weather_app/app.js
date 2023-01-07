const request = require("postman-request");
const url =
  "http://api.weatherstack.com/current?access_key=09187944b07f74bed43b43349282afa5&query=37.8267,-122.4233";
request({ url: url }, (error, response) => {
 const data = JSON.parse(response.body)
 console.log(data.current) 
});
