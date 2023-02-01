// https://leetcode.com/problems/combination-sum-iv/description/

// TC : O(nums.size*target)
// SC : O(target)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solveTab(vector<int> &nums, int target)
    {
        vector<unsigned int> dp(target + 1, 0); // unsigned otherwise integer overflow https://leetcode.com/problems/combination-sum-iv/solutions/2122873/c-overflow-issue-explained/?orderBy=most_votes&topicTags=dynamic-programming
        dp[0] = 1;
        for (int k = 1; k <= target; k++)
        {
            int ans = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (k - nums[i] >= 0)
                {
                    dp[k] += dp[k - nums[i]];
                }
            }
        }
        return dp[target];
    }
    int solve(vector<int> &nums, int target, vector<int> &dp)
    {
        if (target == 0)
        {
            return 1;
        }
        if (target < 0)
        {
            return 0;
        }
        if (dp[target] != -1)
        {
            return dp[target];
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans += solve(nums, target - nums[i], dp);
        }
        return dp[target] = ans;
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        // vector<int>dp(target+1,-1);
        // return solve(nums,target,dp);
        return solveTab(nums, target);
    }
};