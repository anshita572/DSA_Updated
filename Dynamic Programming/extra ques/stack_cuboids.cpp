// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isSafe(vector<vector<int>> &cuboids, int prev, int curr)
    {
        if (cuboids[curr][0] <= cuboids[prev][0] && cuboids[curr][1] <= cuboids[prev][1] && cuboids[curr][2] <= cuboids[prev][2])
        {
            return true;
        }
        return false;
    }
    int solve(vector<vector<int>> &cuboids, int prev, int curr, vector<vector<int>> &dp)
    {
        if (curr < 0)
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
            inc = cuboids[curr][2] + solve(cuboids, curr, curr - 1, dp);
        }
        int exc = solve(cuboids, prev, curr - 1, dp);
        return dp[prev + 1][curr] = max(inc, exc);
    }
    int maxHeight(vector<vector<int>> &cuboids)
    {
        int n = cuboids.size();
        for (int i = 0; i < n; i++) // sort within itself
        {
            sort(cuboids[i].begin(), cuboids[i].end());
        }
        sort(cuboids.begin(), cuboids.end()); // sort all according to width
        vector<vector<int>> dp(n + 1, (vector<int>(n, -1)));
        return solve(cuboids, -1, n - 1, dp);
    }
};