const express=require("express");
const bodyParser=require("body-parser");
const app=express();
app.use(bodyParser.urlencoded({extend:true}));
app.get("/",function(req,res)
{res.sendFile(__dirname + "/index.html");}) 
//__dirname will give file path of calculator.js
// console.log(__dirname);
app.post("/",function(req,res) //app.post to handle any post requests
{var num1=Number(req.body.first_num);
    var num2=Number(req.body.second_num);
    var ans=num1+num2;
    res.send("Result of addition = "+ans);})
app.listen(4000,function()
{console.log("Server is running on port 4000");});