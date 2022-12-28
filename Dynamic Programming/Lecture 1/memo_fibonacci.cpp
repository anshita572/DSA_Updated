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
//Recursion + Memoisation
// Step 1 : create dp array and pass in function
// Step 2 : store the ans in dp array
// Step 3 :check if dp array already has ans , if yes return .Write this statement just after the base case
int solveMemo(int n,vector<int>&dp)
{
    //base case
    if(n==0)
    {return 0;}
    if(n==1)
    {return 1;}
    //step 3
    if(dp[n]!=-1)
    {return dp[n];}
    int ans=solveMemo(n-1,dp)+solveMemo(n-2,dp);
    //step 2
    dp[n]=ans;
    return ans;
}
int main(){
int n=6;
//step 1
vector<int>dp(n+1,-1);
cout<<n<<"th term : "<<solveMemo(n,dp);
return 0;
}