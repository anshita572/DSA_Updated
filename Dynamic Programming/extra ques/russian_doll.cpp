// Variant of LIS
// https://leetcode.com/problems/russian-doll-envelopes/description/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return a[1] > b[1];
        }
        else
        {
            return a[0] < b[0];
        }
    }
    int solveBS(vector<vector<int>> &nums)
    {
        sort(nums.begin(), nums.end(), cmp);
        vector<int> ans;
        ans.push_back(nums[0][1]);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i][1] > ans.back())
            {
                ans.push_back(nums[i][1]);
            }
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), nums[i][1]) - ans.begin();
                ans[index] = nums[i][1];
            }
        }
        return ans.size();
    }
    int solve(vector<vector<int>> &nums, int curr, int prev, vector<vector<int>> &dp)
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
        if (prev == -1 || (nums[prev][0] < nums[curr][0] && nums[prev][1] < nums[curr][1]))
        {
            inc = 1 + solve(nums, curr + 1, curr, dp);
        }
        exc = solve(nums, curr + 1, prev, dp);
        return dp[curr][prev + 1] = max(inc, exc);
    }
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        // int n=envelopes.size();
        // sort(envelopes.begin(),envelopes.end());
        //  vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return solve(envelopes,0,-1,dp);
        return solveBS(envelopes);
    }
};