#include<iostream>
using namespace std;
void pass_by_value(int n)
{n++;}
void pass_by_reference(int &n)
{n++;}
int main(){
int i=5;
cout<<"Before : "<<i<<endl;
pass_by_value(i);
cout<<"After : "<<i<<endl;
cout<<"Before : "<<i<<endl;
pass_by_reference(i);
cout<<"After : "<<i<<endl;

return 0;
}