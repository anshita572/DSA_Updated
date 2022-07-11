$("h1").css("color","red"); // 2nd parameter specified,will change it to red
console.log($("h1").css("font-size"));//2nd parameter not specified,will print the current font-size
$("h1").addClass("big");
$("h1").text("Hey");
// $("button").text("<em>Don't click</em>");
$("button").html("<em>Don't click</em>");
// See difference b/w line no. 5 and 6
$("a").attr("href","https://www.youtube.com");
//click event listener
// $("h1").click(function()
// {$("h1").css("color","purple");});
$("button").click(function()
{$("h1").css("color","purple");});
$("input").keypress(function(event)
{
    console.log(event.key);
});
$(document).keypress(function(event)
{$("h1").text(event.key);});
$("h1").on("click",function()
{$("h1").css("color","green");});

$("h1").before("<button>Before Button</button>");
$("h1").after("<button>After Button</button>");
$("h1").prepend("<button>Prepend Button</button>");
$("h1").append("<button>Append Button</button>");

//Animations
//  $("h1").on("mouseover",function()
//  {$("h1").hide();});
// $("button").on("click",function()
//  {$("h1").toggle();});
// $("button").on("click",function()
//  {$("h1").fadeOut();});

 //other animations : show,fadeIn,slideUp,slideDown,fadeToggle,slideToggle
//  $("button").on("click",function()
//  {$("h1").animate({opacity:0.5});});
$("button").on("click",function()
 {$("h1").slideUp().slideDown().animate({opacity:0.5});});