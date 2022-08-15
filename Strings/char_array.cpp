#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
char name[30];
cout<<"Enter your full name"<<endl;
//cin>>name;
cin.getline(name,30);
 //name[3]='\0';
cout<<"Your name is : "<<name;
return 0;
}