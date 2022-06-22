def cube(num):
    return num*num*num  # using return statement
    print("Hi")  # any line of code after return statement
    # will not be executed as return breaks out of the
    # function.So "Hi" will not be printed


print(cube(4))
n=int(input("Enter a number : ")) 
# by default it considers whatsoever entered as a string
# so mention specifically that we want to input an integer
print(cube(n))