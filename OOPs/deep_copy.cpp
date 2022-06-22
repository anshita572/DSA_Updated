#include<iostream>
#include<string.h>
using namespace std;
class student{
public:
char *name;
int rollNo;
student(student& temp)
{
    char *ch=new char[strlen(temp.name)+1];
    ch=strcpy(ch,temp.name);
    this->name=ch;

}
void setName(char name[])
{
    strcpy(this->name,name);
}
};
int main()
{
char name[10]="Reena";
student s1;
s1.setName(name);

student s2=s1;

char newName[20]="Ramesh";


}