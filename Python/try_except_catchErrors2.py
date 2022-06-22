try:
      num1 = int(input("Enter first number\n"))
      num2 = int(input("Enter second number\n"))
      divide = num1 / num2  #10/0 -->zeroDivisionError
      print(divide)
      num3=int(input("Enter a number : "))
      print(num1)
      
except ValueError:
      print("Invalid input")
except ZeroDivisionError :
    print("Division by zero error")
#OR :
#except ZeroDivisionError as err :
#    print(err)
    