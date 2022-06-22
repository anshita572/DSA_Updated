secret_word="panda"
guess=""
guess_count=0
while guess!=secret_word :
    if guess_count <3 :
     guess=input("Enter your guess : ")
     guess_count=guess_count+1
    
if guess_count<3 :    
    print("Congratulations,You won!")
    
elif guess_count==3 and guess==secret_word: 
        print("Congratulations,You won!")
elif guess_count==3 and guess!=secret_word: 
     print("Oops!You lost the game")