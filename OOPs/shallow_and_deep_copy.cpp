#include<iostream>
#include<string.h>
using namespace std;
class student{
public:
char *name;
int rollNo;
void setName(char name[])
{
    strcpy(this->name,name);
}
void print()
{
    cout<<this->name<<endl;
  //  cout<<this->rollNo<<endl;
}

};
int main(){
student s1;
char name[10]="Reena";
s1.setName(name);
s1.print();
student s2=s1;
s2.print();
char newName[20]="Ramesh";
s2.setName(newName);
s1.print(); //shallow copy
s2.print();
return 0;
}