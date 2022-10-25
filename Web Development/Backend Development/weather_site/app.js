const express=require("express");
const https=require("https");
const app=express();
app.get("/",function(req,res)
{const url="https://api.openweathermap.org/data/2.5/weather?q=London,uk&appid=6c0d2266fa8ac89b14ac8a9fc3b59a76";
https.get(url,function(response)
{console.log(response);})
    res.send("hello");})




app.listen(3000,function()
{console.log("Server is running on port 3000");})