#import Question class from MCQ_ques.py
from  MCQ_ques  import Question 
#We will create a list(or an array) of questions
questions=[
"Which planet is called the red planet?\n(a)Earth\n(b)Mars\n(c)Mercury\n",
"Which is the largest country?\n(a)India\n(b)China\n(c)Russia\n",
"Virat Kohli is a famous:\n(a)Cricketer\n(b)Chess player\n(c)Basketball player\n"

]
#we will create an array where we will create objects
#of Question class that will store correct answers to
#corresponding indices of ques
ques_ans=[
    Question(questions[0],"b"),
    Question(questions[1],"c"),
    Question(questions[2],"a")
]
 #creating a function to input answer and check it
def run_quiz(ques_ans):
     score=0
     for question in ques_ans :
         ans=input(question.ques_ans)
         if ans ==(question.ans):
             score=score+1
     
     print("You got "+str(score)+"/" + str(len(questions))+" correct")

run_quiz(questions)
