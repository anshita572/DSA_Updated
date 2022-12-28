//https://leetcode.com/problems/coin-change/description/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int solveTab(vector<int>& arr, int n)
{vector<int>dp(n+1,INT_MAX);
dp[0]=0;
for(int i=1;i<=n;i++)
{int mini=INT_MAX;
    for(int j=0;j<arr.size();j++)
{if(i-arr[j]>=0)
    {int ans=dp[i-arr[j]];
    if(ans!=INT_MAX)
{mini=min(mini,ans+1);}
}}

dp[i]=mini;

}
 return dp[n];
}
int solveMemo(vector<int>& arr, int n,vector<int>&dp)
{if(n==0)
{return 0;}
if(n < 0)
{return INT_MAX;}
if(dp[n]!=-1)
{return dp[n];}
int mini=INT_MAX;
for(int i=0;i<arr.size();i++)
{int ans=solveMemo(arr,n-arr[i],dp);
if(ans!=INT_MAX)
{mini=min(mini,ans+1);}
}
dp[n]=mini;
 return mini;
}
    int coinChange(vector<int>& arr, int n) {
        // vector<int>dp(n+1,-1);
        // int ans= solveMemo(arr,n,dp);
        int ans= solveTab(arr,n);
        if(ans==INT_MAX)
        {ans=-1;}
        return ans;
    }
};