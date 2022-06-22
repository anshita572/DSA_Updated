#num1=int(input("Enter a number : "))
#print(num1)
#if i enter a decimal no or a string ,it will throw an
#error and my execution will be stopped.So to avoid
#stopping the execution,we will issue a warning to user
try:
      num2=int(input("Enter a number : "))
      print(num2)
except:
      print("Invalid input")


#except -->will handle all kind of errors
#But we can make different except for specific errors