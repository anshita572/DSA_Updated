const express=require("express");
const https=require("https");
const app=express();
app.get("/",function(req,res)
{const url="https://api.openweathermap.org/data/2.5/weather?q=London,uk&appid=6c0d2266fa8ac89b14ac8a9fc3b59a76&units=metric";
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
console.log(tempData);
const description=weatherData.weather[0].description;
console.log(description);
})})
    res.send("hello");})




app.listen(3000,function()
{console.log("Server is running on port 3000");})