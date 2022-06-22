#include<iostream>
using namespace std;
int getLength(char ch[])
{
    int count=0;
for(int i=0;ch[i]!='\0';i++)
{count++;}
return count;

}
int main(){
int n;
char name[30];
cout<<"Enter a string"<<endl;
cin>>name;
cout<<"Length of string : "<<getLength(name);
return 0;
}