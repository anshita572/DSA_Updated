class student :
    def __init__(self,name,rollNO,year):  
   #initialiser function and making attributes of student class
      self.name=name
      self.rollNo=rollNO
      self.year=year
      student1=student("Reena",5,"First year")
      student2=student("Meena",10,"Second year")
      student3=student("Teena",52,"Third year")
      student4=student("Heena",41,"Fourth year")
      def roll_no(self) :
          if self.rollNo >=10 :
            return True
          else :
             return False
      

      print(student1.roll_no())