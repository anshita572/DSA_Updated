//https://www.codingninjas.com/codestudio/problems/count-derangements_873861?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long int solveSO(int N)
{
  long long int prev2=0;
  long long int prev1=1;
  for(int i=3;i<=N;i++)
  {
   
        long long int ans=(i-1)*((prev2)%mod +(prev1)%mod)%mod;
        prev2=prev1;
        prev1=ans;
  }
  return prev1;
}

long long int solveTab(int N)
{
  vector<long long int>dp(N+1,0);
  // dp[1]=0;
  dp[2]=1;
  for(int i=3;i<=N;i++)
  {
    //  if(dp[N]!=-1)
    //     {return dp[N];}
        long long int ans=(i-1)*((dp[i-2])%mod +(dp[i-1])%mod)%mod;
        dp[i]= ans;
  }
  return dp[N];
}

 long long int solve(int N, vector<long long int>&dp)
    {
        if(N==1)
        {return 0;}
        if(N==2)
        {return 1;}
        if(dp[N]!=-1)
        {return dp[N];}
        long long int ans=(N-1)*(solve(N-2,dp)%mod +solve(N-1,dp)%mod)%mod;
        return dp[N]= ans;
    }
long long int countDerangements(int n) {
  //  vector<long long int>dp(n+1,-1);
  //       return solve(n,dp);
  // return solveTab(n);
   return solveSO(n);
}