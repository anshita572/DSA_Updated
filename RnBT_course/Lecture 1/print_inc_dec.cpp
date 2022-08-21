#include<iostream>
using namespace std;
int count=1; //global variable
//M1
// void print_inc_dec(int n)
// {
//     if(n==0)
//     {return;}
//     cout<<count<<" ";
//     count++;
//     print_inc_dec(n-1);
//     count--;
//     cout<<count<<" ";
// }
//M2
void print_inc_dec(int n,int start_val)
{if(start_val > n)
{return;}
cout<<start_val<<" ";
print_inc_dec(n,start_val+1);
cout<<start_val<<" ";

}
int main(){
int n=7;
int start_val=1;
print_inc_dec(n,start_val);
return 0;
}