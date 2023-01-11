const request = require("postman-request");
const url =
  "http://api.weatherstack.com/current?access_key=09187944b07f74bed43b43349282afa5&query=37.8267,-122.4233&units=f";
// request({ url: url }, (error, response) => {
//  const data = JSON.parse(response.body)
//  console.log(data.current) 
// });
request({ url: url,json:true }, (error, response) => {
  if(error) //network error(internet not working)
  {console.log('Unable to connect to weather service !')}
  else if(response.body.error) //some mistake in url
  {console.log('Unable to find location')}
  else //no error
  {console.log (response.body.current.weather_descriptions[0]+".It is currently "+response.body.current.temperature+" degrees out.It feels like "+response.body.current.feelslike +" degrees out")
}
 });
 const url2="http://api.positionstack.com/v1/forward?access_key=a544a5edf0bb14d2bff03d0151c8775e&query=1600%20Pennsylvania%20Ave%20NW,%20Washington%20DC"
 request({url:url2,json:true},(error,response)=>{
  if(error)
  {console.log('Unable to connect')}
  else if(response.body.error)
  {console.log('Unable to find geolocation')}
  else
  {console.log("Latitude = "+response.body.data[0].latitude+" and Longitude = "+response.body.data[0].longitude)}
 })
 