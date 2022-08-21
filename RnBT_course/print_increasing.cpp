#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void print_inc(int n)
{
    if(n==0)
    {return;}
    print_inc(n-1);
    cout<<n<<" ";
}
int main(){
int n=7;
print_inc(n);
return 0;
}