const express=require("express");
const https=require("https");
const bodyParser=require("body-parser");
const app=express();
app.use(bodyParser.urlencoded({extended:true}));
app.get("/",function(req,res)
{res.sendFile(__dirname+"/index.html");
})
app.post("/",function(req,res)
{
//    console.log(req.body.cityName);
const query=req.body.cityName;
const apiKey="6c0d2266fa8ac89b14ac8a9fc3b59a76";
const unit="metric";
    const url="https://api.openweathermap.org/data/2.5/weather?q="+query+"&appid="+apiKey+"&units="+unit;
https.get(url,function(response)
{console.log(response.statusCode);
response.on("data",function(data)
{
    // console.log(data);
    const weatherData=JSON.parse(data);
    // console.log(weatherData);

    // const obj={
    //     Name : "Anshita",
    //     FavoriteFood : "Rice",
    //     Interests : "Development"
    // }
    // console.log(JSON.stringify(obj));
    // //stringify : minimises the space (ek hi line m sb kuch)
const tempData=weatherData.main.temp
// console.log(tempData);
const description=weatherData.weather[0].description;
// console.log(description);
const icon=weatherData.weather[0].icon;
const imageURL=" http://openweathermap.org/img/wn/"+ icon + "@2x.png"
res.write("<h1>The temperature in "+query+ " is "+tempData+" degree Celsius</h1>");
res.write("<h2>The weather is currently "+description+"</h2>");
res.write("<img src="+imageURL+">");
res.send();
})})
    // res.send("hello");

})




app.listen(3000,function()
{console.log("Server is running on port 3000");})