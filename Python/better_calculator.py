num1=int(input("Enter first number : ")) #int
num2=int(input("Enter second number : ")) #int
operator=(input("Enter the operator : "))#string
if operator=="+" :
    print(num1+num2)
elif operator=="-":
    print(num1-num2)
elif operator=="*":
   print (num1*num2)
elif operator=="/":
   print(num1/num2)
else :
    print("Invalid operator")