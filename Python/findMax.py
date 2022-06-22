# Find maximum of three numbers
# Comaparison operators : == , !=, <,>,<=,>=
def find_max(num1, num2, num3):  # function
    if num1 >= num2 and num1 >= num3:  # using and operator
        return num1
    elif num2 >= num1 and num2 >= num3:
        return num2
    else:
        return num3


print(find_max(10, 50, 30))  # function call
