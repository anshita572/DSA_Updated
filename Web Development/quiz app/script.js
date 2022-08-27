const quiz=[{
    question: "Q1. Who is the President of India ?",
    a:"Ram Nath Kovind",
    b:"Pratibha Patil",
    c:"Draupadi Murmu",
    d:"Pranab Mukherjee",
    ans:"ans3"
},
{question: "Q2. Which is the largest continent ?",
    a:"Africa",
    b:"Asia",
    c:"North America",
    d:"Antarctica",
    ans:"ans2"
},
{question: "Q3. When did Quit India Movement start ?",
    a:"1942",
    b:"1937",
    c:"1919",
    d:"1940",
    ans:"ans1"
},
{question: "Q4. When does summer solistice occur in Northern Hemisphere ?",
    a:"15th May",
    b:"10th June",
    c:"1st April",
    d:"21st June",
    ans:"ans4"
},
{question: "Q5. Which is the largest mammal ?",
    a:"Rhino",
    b:"Blue Whale",
    c:"Elephant",
    d:"Lion",
    ans:"ans2"
}
];
const ques=document.querySelector('.question');
const option1=document.querySelector('#option1');
const option2=document.querySelector('#option2');
const option3=document.querySelector('#option3');
const option4=document.querySelector('#option4');
const ans=document.querySelectorAll(".answers");
let count=0; //question count
let score=0;
function loadQues(){
// console.log(quiz[0].question);
 ques.innerText=quiz[count].question;
 option1.innerText=quiz[count].a;
 option2.innerText=quiz[count].b;
 option3.innerText=quiz[count].c;
 option4.innerText=quiz[count].d;
}
loadQues();
function getMarkedAns()
{let markedAns;
    ans.forEach((currAns) => {
        if(currAns.checked)
        {markedAns=currAns.id;}
        
    });
    return markedAns;
}
function deselect()
{   ans.forEach((currAns) => {
        currAns.checked=false;        
    });
    
}
function select()
{   ans.forEach((currAns) => {
        currAns.checked=true;        
    });
    
}
document.querySelector("#submit-btn").addEventListener("click",function(event){
    const checkedAns=getMarkedAns(); 
    // console.log(checkedAns);
if(checkedAns ===quiz[count].ans)
{score++;};
count++; //increment question count
deselect();
if(count===quiz.length-1)
{document.querySelector("#submit-btn").innerHTML="Submit";}
if(count <quiz.length) //move to next ques
{loadQues();}
else //when all ques are done ,show score
{document.querySelector(".inner-div").innerHTML="<div id='score'>You scored : "+score+"/"+quiz.length+" 🙂 </div><button class='reload-btn' onclick='location.reload()'>Play Again</button>";
// document.querySelector("#score").classList.remove("show-score");
}
});
// document.querySelector("#prev-btn").addEventListener("click",function(event){if(count>0)
// {count--;
// loadQues();
// getMarkedAns();
// select();}});
