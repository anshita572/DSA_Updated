# open(FileName,mode)
#open takes 2 parameters name of file and mode
# modes are r(read),w(write),a(append),r+(read,write)
FirstFile=open(".vscode\Python\FirstFile.txt","r")  #FirstFile is variable name(can be any name)
print(FirstFile.readable()) #boolean function
#returns true if file can be read otherwise false
#since in open we have specified read mode,it will return true

#print(FirstFile.read()) #-->will print the contents of file


#print(FirstFile.readline()) #will print firstLine
#print(FirstFile.readline()) #will now print secondLine

print(FirstFile.readlines()[2]) #will print thirdLine of array(list)
#another way using for loop :
# for name in FirstFile.readlines() :
# print(name)
FirstFile.close()


