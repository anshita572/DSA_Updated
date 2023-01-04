// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solveTab(vector<int> &values)
    {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 2; j < n; j++)
            {
                int mini = INT_MAX;
                for (int k = i + 1; k < j; k++)
                {
                    mini = min(mini, values[i] * values[j] * values[k] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = mini;
            }
        }
        return dp[0][n - 1];
    }
    int solveMem(vector<int> &values, int i, int j, vector<vector<int>> &dp)
    {
        // base case
        if (i + 1 == j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int mini = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            mini = min(mini, values[i] * values[j] * values[k] + solveMem(values, i, k, dp) + solveMem(values, k, j, dp));
        }
        return dp[i][j] = mini;
    }
    int minScoreTriangulation(vector<int> &values)
    {
        // int n=values.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return solveMem(values,0,n-1,dp);
        return solveTab(values);
    }
};