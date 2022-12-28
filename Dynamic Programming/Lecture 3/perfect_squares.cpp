//https://leetcode.com/problems/perfect-squares/description/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solveTab(int n)
    {vector<int>dp(n+1,0);
      for(int j=1;j<=n;j++)
      { int ans=INT_MAX;
        for(int i=1;i*i<=j;i++)
        {ans=min(ans,1+dp[j-i*i]);}
        dp[j]=ans;
        }
        return dp[n];
    }
    int solveMemo(int n,vector<int>&dp)
    {
        if(n==0)
        {return 0;}
        if(dp[n]!=-1)
        {return dp[n];}
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++)
        {ans=min(ans,1+solveMemo(n-i*i,dp));}
        dp[n]=ans;
        return ans;
    }
    int numSquares(int n) {
        // vector<int>dp(n+1,-1);
        // return solveMemo(n,dp);
        return solveTab(n);
    }
};