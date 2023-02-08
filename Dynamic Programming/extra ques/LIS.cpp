// https://leetcode.com/problems/longest-increasing-subsequence/description/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solveBS(vector<int> &nums)
    {
        vector<int> ans;
        ans.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > ans.back())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
    int solveSO(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);
        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int inc = 0;
                int exc = 0;
                if (prev == -1 || nums[prev] < nums[curr])
                {
                    inc = 1 + nextRow[curr + 1];
                }
                exc = nextRow[prev + 1];
                currRow[prev + 1] = max(inc, exc);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
    int solveTab(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int inc = 0;
                int exc = 0;
                if (prev == -1 || nums[prev] < nums[curr])
                {
                    inc = 1 + dp[curr + 1][curr + 1];
                }
                exc = dp[curr + 1][prev + 1];
                dp[curr][prev + 1] = max(inc, exc);
            }
        }
        return dp[0][0]; // return dp[0][-1+1]
    }
    int solve(vector<int> &nums, int curr, int prev, vector<vector<int>> &dp)
    {
        if (curr == nums.size())
        {
            return 0;
        }
        if (dp[curr][prev + 1] != -1)
        {
            return dp[curr][prev + 1];
        }
        int inc = 0;
        int exc = 0;
        if (prev == -1 || nums[prev] < nums[curr])
        {
            inc = 1 + solve(nums, curr + 1, curr, dp);
        }
        exc = solve(nums, curr + 1, prev, dp);
        return dp[curr][prev + 1] = max(inc, exc);
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        //   vector<vector<int>>dp(n,vector<int>(n+1,-1));
        //    return solve(nums,0,-1,dp);
        // return solveTab(nums);
        //  return solveSO(nums);
        return solveBS(nums);
    }
};