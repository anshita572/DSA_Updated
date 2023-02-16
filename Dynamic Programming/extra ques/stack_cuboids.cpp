// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isSafe(vector<vector<int>> &cuboids, int prev, int curr)
    {
        if (cuboids[curr][0] >= cuboids[prev][0] && cuboids[curr][1] >= cuboids[prev][1] && cuboids[curr][2] >= cuboids[prev][2])
        {
            return true;
        }
        return false;
    }
    int solveSO(vector<vector<int>> &cuboids)
    {
        int n = cuboids.size();
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);
        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = n - 1; prev >= -1; prev--)
            {
                int inc = 0;
                if (prev == -1 || isSafe(cuboids, prev, curr))
                {
                    inc = cuboids[curr][2] + nextRow[curr + 1];
                }
                int exc = nextRow[prev + 1];
                currRow[prev + 1] = max(inc, exc);
            }
            nextRow = currRow;
        }
        return currRow[0];
    }
    int solveTab(vector<vector<int>> &cuboids)
    {
        int n = cuboids.size();
        vector<vector<int>> dp(n + 1, (vector<int>(n + 1, 0)));
        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = n - 1; prev >= -1; prev--)
            {
                int inc = 0;
                if (prev == -1 || isSafe(cuboids, prev, curr))
                {
                    inc = cuboids[curr][2] + dp[curr + 1][curr + 1];
                }
                int exc = dp[prev + 1][curr + 1];
                dp[prev + 1][curr] = max(inc, exc);
            }
        }
        return dp[0][0];
    }
    int solve(vector<vector<int>> &cuboids, int prev, int curr, vector<vector<int>> &dp)
    {
        if (curr == cuboids.size())
        {
            return 0;
        }
        if (dp[prev + 1][curr] != -1)
        {
            return dp[prev + 1][curr];
        }
        int inc = 0;
        if (prev == -1 || isSafe(cuboids, prev, curr))
        {
            inc = cuboids[curr][2] + solve(cuboids, curr, curr + 1, dp);
        }
        int exc = solve(cuboids, prev, curr + 1, dp);
        return dp[prev + 1][curr] = max(inc, exc);
    }
    int maxHeight(vector<vector<int>> &cuboids)
    {
        int n = cuboids.size();
        for (int i = 0; i < n; i++) // sort within itself
        {
            sort(cuboids[i].begin(), cuboids[i].end());
        }
        sort(cuboids.begin(), cuboids.end()); // sort all acoording to width
        //     vector<vector<int>>dp(n+1,(vector<int>(n,-1)));
        // return solve(cuboids,-1,0,dp);
        // return solveTab(cuboids);
        return solveSO(cuboids);
    }
};