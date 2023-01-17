const request = require("postman-request");
 const geocode=(address,apiKey,callback)=>{
  const url2="http://api.positionstack.com/v1/forward?access_key="+apiKey+"&query="+address
  request({url:url2,json:true},(error,response)=>{
    if(error)
    {callback('Unable to connect to location services',undefined)} //(error,response)<=>('Unable to connect',undefined)
    else if(response.body.error)
    {callback('Unable to find geolocation',undefined)}
    else{
      callback(undefined,{
        latitude:response.body.data[0].latitude,
        longitude :response.body.data[0].longitude,
        place_name:response.body.data[0].name
      })
    }
  })
 }
 module.exports=geocode