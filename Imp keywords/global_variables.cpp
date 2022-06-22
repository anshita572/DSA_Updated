//NEVER  use global variables (BAD PRACTICE)
//ALWAYS use reference variables instead
#include<iostream>
using namespace std;
int n=10; //global variable
void fun1()
{
    cout<<n<<endl;
}
void fun2()
{
    cout<<n<<endl;
}
int main(){
cout<<n<<endl;
fun1();
fun2();
return 0;
}