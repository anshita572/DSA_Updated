//https://leetcode.com/problems/house-robber/
//https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solveSO(vector<int>&arr, int n)
{int next1=0;
int next2=0;
int curr;
         for(int i=n-1;i>=0;i--)
         {int include=arr[i]+next2;
         int exclude=next1;
         curr=max(include,exclude);
             next2=next1;
             next1=curr;
         }
         return curr;}

    // int solveMemo(vector<int>& arr,int n,int i, vector<int>&dp)
    //  {
    //      if(i>=n)
    //      {return 0;}
    //      if(dp[i]!=-1)
    //      {return dp[i];}
    //      int include=arr[i]+solveMemo(arr,n,i+2,dp);
    //      int exclude=solveMemo(arr,n,i+1,dp);
    //      int ans=max(include,exclude);
    //      dp[i]=ans;
    //      return ans;
    //  }
    // int solveTab(vector<int>&arr, int n)
    //  {   vector<int>dp1(n+2,0);
    //      for(int i=n-1;i>=0;i--)
    //      {int include=arr[i]+dp1[i+2];
    //      int exclude=dp1[i+1];
    //      dp1[i]=max(include,exclude);}
    //      return dp1[0];
    //  }
    int rob(vector<int>& nums) {
        int n=nums.size();
    //     vector<int>dp(n,-1);
	//    return solveMemo(nums,n,0,dp);
    // return solveTab(nums,n);
    return solveSO(nums,n);
    }
};