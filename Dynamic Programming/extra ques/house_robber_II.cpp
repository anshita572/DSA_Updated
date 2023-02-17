// https://leetcode.com/problems/house-robber-ii/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Similar to Pizza with 3N slices
class Solution
{
public:
    int solveSO(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        int curr = 0;
        int next1 = 0;
        int next2 = 0;
        int curr2 = 0;
        int next12 = 0;
        int next22 = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            int inc = nums[i] + next2;
            int exc = next1;
            curr = max(inc, exc);
            next2 = next1;
            next1 = curr;
        }
        int case1 = curr;
        for (int i = n - 1; i >= 1; i--)
        {
            int inc = nums[i] + next22;
            int exc = next12;
            curr2 = max(inc, exc);
            next22 = next12;
            next12 = curr2;
        }
        int case2 = curr2;
        return max(case1, case2);
    }
    int solveTab(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        vector<int> dp1(n + 2, 0);
        vector<int> dp2(n + 2, 0);
        for (int i = n - 2; i >= 0; i--)
        {
            int inc = nums[i] + dp1[i + 2];
            int exc = dp1[i + 1];
            dp1[i] = max(inc, exc);
        }
        int case1 = dp1[0];
        for (int i = n - 1; i >= 1; i--)
        {
            int inc = nums[i] + dp2[i + 2];
            int exc = dp2[i + 1];
            dp2[i] = max(inc, exc);
        }
        int case2 = dp2[1];
        return max(case1, case2);
    }
    int solve(vector<int> &nums, int i, int n, vector<int> &dp)
    {
        if (i > n)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int inc = nums[i] + solve(nums, i + 2, n, dp);
        int exc = solve(nums, i + 1, n, dp);
        return dp[i] = max(inc, exc);
    }
    int rob(vector<int> &nums)
    {
        //  int n=nums.size();
        //  if(n==1)
        //  {return nums[0];}
        //  vector<int>dp1(n+1,-1);
        //  //if n==1 ,n-2=>1-2=-1 =>invalid ,so in line 14 handled this case separtely
        //  int case1=solve(nums,0,n-2,dp1);
        //  vector<int>dp2(n+1,-1);
        //   //if n==1 ,calling for 1st index that does not exist ,there is only one index i.e. 0,so in line 14 handled this case separtely
        //  int case2=solve(nums,1,n-1,dp2);
        //  return max(case1,case2);
        // return solveTab(nums);
        return solveSO(nums);
    }
};
