# Lists (like arrays in c++)
friends = ["Reena", "Teena", "Meena", "Heena", "Rubina"]
print(friends)  # printing the entire list
print(friends[0])  # printing element at 0th index
print(friends[2])
print(friends[-1])  # printing element at -1th index
print(friends[-2])
print(friends[-3])
# last element can be said to be at -1th index,second
# last at -2th index and so on
print(friends[1:])  # print elements on and after 1st index
print(friends[2:4])  # elements will be printed from
# index 2 to index 3(not including 4th index element)
names = [1, 2, "hello", True]
# A list of combination of various data types is also
# a valid list in python
print(names)
names[0] = "hey"  # modifying element at 0th index
print(names[0])
print(len(names)) # to print the length of list
