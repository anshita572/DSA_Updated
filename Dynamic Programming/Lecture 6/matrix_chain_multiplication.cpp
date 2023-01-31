// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

// TC : O(n^3)
// SC:O(n^2)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solveTab(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int i = N - 1; i >= 1; i--)
        {
            for (int j = i + 1; j < N; j++)
            {
                int mini = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    int ans = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                    mini = min(mini, ans);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][N - 1];
    }
    int solve(int N, int arr[], int i, int j, vector<vector<int>> &dp)
    {
        if (i == j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int mini = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int ans = arr[i - 1] * arr[k] * arr[j] + solve(N, arr, i, k, dp) +
                      solve(N, arr, k + 1, j, dp);
            mini = min(mini, ans);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // vector<vector<int>>dp(N,vector<int>(N,-1));
        // return solve(N,arr,1,N-1,dp);
        return solveTab(N, arr);
    }
};