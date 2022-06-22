names = ['A', 'B', 'C', 'D', 'E']
roll_no = [1, 2, 3, 4, 5]
students = ["Reena", "Teena", "Meena", "Heena", "Rubina"]
names.extend(roll_no)
# appending names list i.e. adding roll_no.s to name list
print(names)
# adding string individually(but can't add numbers like this)
roll_no.extend('6')
print(roll_no)
students.insert(2, "Sabina")
# this inserted Sabina at 2nd index of list students
print(students)
students.remove("Meena")
# removed Meena
print(students)
students.pop()  # last element will be removed
print(students)
print(students.index("Teena"))  # prints the index of Teena

print(students)
students.sort()  # sorts the list alphabetically
print(students)
print(students.index("Teena"))
roll_no.reverse()
print(roll_no)
students2 = students.copy()
print(students2)
# copies the entire student list in students2 list
students.clear()  # clears the entire list
print(students)
