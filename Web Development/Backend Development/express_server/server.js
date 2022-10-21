const express=require("express");
const app=express();
app.get("/",function(request,response)
{
    // console.log(request);
    response.send("<h1>Hello</h1>");
})
app.get("/contact",function(request,response)
{
    // console.log(request);
    response.send("Contact me at abc@gmail.com");
})
app.get("/about",function(request,response)
{
    // console.log(request);
    response.send("Hey there ! <br> I am a programmer");
})
app.listen(3001,function(){
    console.log("Server started on port 3001")
});