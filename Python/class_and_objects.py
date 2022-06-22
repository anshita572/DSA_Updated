# syntax :
# class className :
class student :
    def __init__(self,name,rollNO,year):  
   #initialiser function and making attributes of student class
      self.name=name
      self.rollNo=rollNO
      self.year=year
# this student class is defining our student data type


student1=student("Reena","5","First") #student1 is object of student class
print(student1.name)
