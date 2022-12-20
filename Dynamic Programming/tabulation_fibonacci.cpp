#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//Recursion
int solve(int n)
{
    //base case
    if(n==0)
    {return 0;}
    if(n==1)
    {return 1;}
    int ans=solve(n-1)+solve(n-2);
    return ans;
}
int tabuSolve(int n)
{vector<int>dp(n+1,0);
dp[0]=0;
dp[1]=1;
for(int i=2;i<=n;i++)
{int ans=dp[i-1]+dp[i-2];
dp[i]=ans;
}
return dp[n];

}
int main(){
int n=6;
cout<<n<<"th term : "<<tabuSolve(n);
return 0;
}