//for single button
// function MyClick()
// {alert("I am clicked");}
// document.querySelector("button.w").addEventListener("click",MyClick);

//for all buttons
var n=document.querySelectorAll(".drum").length; //n=no. of drum buttons i.e. 7
for(var i=0;i<n;i++)
{
    document.querySelectorAll(".drum")[i].addEventListener("click",function()
    {alert("I am clicked");})
}