num1 = input("Enter first number\n")
num2 = input("Enter second number\n")
add = num1 + num2
print(add)
# by default the entered inputs are considered as strings
# so if i write 3 and 4 ,they we concatenate
# and the output is 34 instead of 7
# so write int/float before num1 and num2
num3 = input("Enter first number\n")
num4 = input("Enter second number\n")
add = float(num3) + float(num4)
print("Sum = " + str(add))
# similarly can use -,/,*
