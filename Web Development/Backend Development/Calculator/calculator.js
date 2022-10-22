const express=require("express");
const app=express();
app.get("/",function(req,res)
{res.sendFile(__dirname + "/index.html");}) 
//__dirname will give file path of calculator.js
// console.log(__dirname);
app.post("/",function(req,res)
{res.send("Thanks");})
app.listen(4000,function()
{console.log("Server is running on port 4000");});