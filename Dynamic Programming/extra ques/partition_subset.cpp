//https://leetcode.com/problems/partition-equal-subset-sum/description/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool solve(vector<int>& nums,int target,int currSum,int i, vector<vector<int>>&dp)
    {if(i>=nums.size() || currSum > target)
    {return 0;}
    if(currSum == target)
    {return 1;}
    if(dp[i][currSum]!=-1)
    {return dp[i][currSum];}
    bool inc=solve(nums,target,currSum+nums[i],i+1,dp);
    bool exc=solve(nums,target,currSum,i+1,dp);
    return dp[i][currSum]= inc || exc; //if true false,true hi return ho
    }
    bool canPartition(vector<int>& nums) {
      int sum=0;
      for(int i=0;i<nums.size();i++)
      {
          sum=sum+nums[i];
      }
      if(sum % 2 != 0) //if sum is odd
      {return false;}
      else //if sum is even
      {int target=sum/2;
      vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
      return solve(nums,target,0,0,dp);
      }
       
    }
};