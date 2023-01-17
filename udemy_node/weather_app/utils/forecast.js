const request = require("postman-request");
const forecast=(latitude,longitude,callback)=>{
    const url="http://api.weatherstack.com/current?access_key=09187944b07f74bed43b43349282afa5&query="+latitude+","+longitude+"&units=f"
    request({url:url,json:true},(error,response)=>{
        if(error)
        {callback('Unable to connect to weather service',undefined)}
        else if(response.body.error)
        {callback('Unable to find location',undefined)}
        else{
            callback(undefined,response.body.current.weather_descriptions[0]+".It is currently "+response.body.current.temperature+" degrees out.It feels like "+response.body.current.feelslike +" degrees out")
        }
    })
}
module.exports=forecast