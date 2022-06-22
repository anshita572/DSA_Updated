#include<iostream>
using namespace std;
int main(){
int *p=new int;
*p=5;
cout<<*p<<endl;
char *ch= new char;
cout<<"Enter a charcter : "<<endl;
cin>>*ch;
cout<<*ch<<endl;
delete p;  //releasing memory
delete ch;//releasing memory
return 0;
}