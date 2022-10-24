const express=require("express");
const bodyParser=require("body-parser");
const app=express();
app.use(bodyParser.urlencoded({extend:true}));
app.get("/",function(req,res)
{res.sendFile(__dirname+"/index.html");})
app.post("/",function(req,res)
{var w=Number(req.body.weight);
var h=Number(req.body.height);
var ans=w/h;
res.send("Your BMI = "+ans);
})
app.listen(3000,function()
{console.log("Server is running on port 3000");})
