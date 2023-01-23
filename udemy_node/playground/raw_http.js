//Core Node module
const http=require('http')
const url="http://api.weatherstack.com/current?access_key=09187944b07f74bed43b43349282afa5&query= 37.778008,-122.431272&units=f"
let data=''
const request=http.request(url,(response)=>{
response.on('data',(chunk)=>{
data=data+chunk.toString()
})
response.on('end',()=>{
const body=JSON.parse(data)
console.log(body)
})
})
request.on('error',error=>{
    console.log('An error occurred !',error)
})
request.end()