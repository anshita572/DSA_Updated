# syntax
# for variable_name in list/tuple/string

# example 1 : using for loop with strings
for letter in "Hello World":
    print(letter)
# for every letter in string "Hello World" print each
#  letter in every single iteration of loop

# example 2 : using for loop with list
student = ["Reena", "Meena", "Teena"]
for name in student:
    print(name)

# Range function in Python
'''The range function in python is used to generate a 
   sequence of numbers.
We can also specify the start, stop, and step-size as 
follows: range(start, stop, step_size)

step size is usually not used with range()'''

for num in range(10):
    print(num)  # numbers will be printed from 0 to 9
for num in range(3, 7):
    print(num)  # numbers will be printed in a range from 3 to 6


# range function with lists
# accesing list elements with range function

months = ["Jan", "Feb", "Mar", "Apr"]
for names in range(len(months)):  # indexing from 0 to 3
    print(months[names])
