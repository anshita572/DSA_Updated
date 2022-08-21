#include<iostream>
#include <bits/stdc++.h>
using namespace std;
long long factorial(long long n)
{
    if(n==0)
    {return 1;}
    long long ans=n*factorial(n-1);
    return ans;
}
int main(){
long long n=13;
cout<<factorial(n)<<endl;
return 0;
}