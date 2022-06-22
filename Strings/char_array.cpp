#include<iostream>
using namespace std;
int main(){
char name[30];
cout<<"Enter your full name"<<endl;
cin>>name;
name[3]='\0';
cout<<"Your name is : "<<name;
return 0;
}