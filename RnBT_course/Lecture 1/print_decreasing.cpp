//TC : O(n)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void print_dec(int n)
{
    if(n==0) //base case
    {return;}
    cout<<n<<" ";
    print_dec(n-1);
}
int main(){
int n=7;
print_dec(n);
return 0;
}