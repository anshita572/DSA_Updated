#include<iostream>
using namespace std;
int count=1; //global variable
//M1
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

//M2
void print_inc_dec(int n,int start_val)
{if(start_val > n)
{return;}
cout<<start_val<<" ";
print_inc_dec(n,start_val+1);
cout<<start_val<<" ";

}
// M3
void print(int n , int s){
    if(n==0){
        return;
    }
    cout<<s<<" ";
    print(n-1,s+1);
    cout<<s<<" ";
}
int main(){
int n=7;
int start_val=1;
print(n,start_val);
return 0;
}