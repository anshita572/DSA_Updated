#syntax :
# list_name=[[],[],[],...]
matrix=[[1,2,3],
        [6,12,5],
        [0]]    #inside this list,every element is a list itself
                # 1 is at 0th row,0th column ; 3 is at 0th row,2nd column 
print(matrix[1][2] ) #1st row and 2nd column element i.e. 5

#accesing 2D list elements using for loop
for row in matrix :
    print(row)
    
#accesing 2D list elements using nested for loop
for row in matrix :
    for column in row :
        print(column)