// https://leetcode.com/problems/reducing-dishes/description/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solveSO(vector<int> &sat)
    {
        int n = sat.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        vector<int> curr(n + 1, 0); // index curr row
        vector<int> next(n + 1, 0); // index next row
        for (int index = n - 1; index >= 0; index--)
        {
            for (int time = n - 1; time >= 0; time--)
            {
                int include = sat[index] * (time + 1) + next[time + 1];
                int exclude = next[time];
                curr[time] = max(include, exclude);
            }
            next = curr;
        }
        return curr[0];
    }
    int solveTab(vector<int> &sat)
    {
        int n = sat.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int time = n - 1; time >= 0; time--)
            {
                int include = sat[index] * (time + 1) + dp[index + 1][time + 1];
                int exclude = dp[index + 1][time];
                dp[index][time] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    int solveMem(vector<int> &sat, int index, int time, vector<vector<int>> &dp)
    {
        if (index == sat.size())
        {
            return 0;
        }
        if (dp[index][time] != -1)
        {
            return dp[index][time];
        }
        int include = sat[index] * (time + 1) + solveMem(sat, index + 1, time + 1, dp);
        int exclude = solveMem(sat, index + 1, time, dp);
        return dp[index][time] = max(include, exclude);
    }
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        // int n=satisfaction.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        //     return solveMem(satisfaction,0,0,dp);
        // return solveTab(satisfaction);
        return solveSO(satisfaction);
    }
};