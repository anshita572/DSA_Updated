//https://leetcode.com/problems/min-cost-climbing-stairs/description/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int solveSO(vector<int>& cost,int n)
{int prev1=cost[1];
int prev2=cost[0];
for(int i=2;i<n;i++)
{ int ans=cost[i]+min(prev1,prev2);
        prev2=prev1;
        prev1=ans;
}
return min(prev1,prev2);
}
int solveTab(vector<int>& cost,int n)
{  vector<int>dp(n+1,0);
dp[0]=cost[0];
dp[1]=cost[1];
for(int i=2;i<n;i++)
{ int ans=cost[i]+min(dp[i-1],dp[i-2]);
         dp[i]= ans;
}
return min(dp[n-1],dp[n-2]);
}
    int solve(vector<int>& cost,int n,vector<int>&dp)
    {
        if(n==0)
        {return cost[0];}
        if(n==1)
        {return cost[1];}
        if(dp[n]!=-1)
        {return dp[n];}
        int ans=cost[n]+min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return dp[n]= ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        // vector<int>dp(n,-1);
        // return min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        // return solveTab(cost,n);
         return solveSO(cost,n);

    }
};