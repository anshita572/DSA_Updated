#include<iostream>
using namespace std;
int count=1;
void print_inc_dec(int n)
{
    if(n==0)
    {return;}
    cout<<count<<" ";
    count++;
    print_inc_dec(n-1);
    count--;
    cout<<count<<" ";
}
int main(){
int n=7;
print_inc_dec(n);
return 0;
}