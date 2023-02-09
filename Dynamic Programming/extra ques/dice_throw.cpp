// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
class Solution
{
public:
    int solveSO(int N, int k, int T)
    {
        vector<int> prev(T + 1, 0);
        vector<int> curr(T + 1, 0);
        prev[0] = 1;
        for (int n = 1; n <= N; n++)
        {
            for (int tar = 1; tar <= T; tar++)
            {
                int ans = 0;
                for (int i = 1; i <= k; i++)
                {
                    if (tar - i >= 0)
                    {
                        ans = ans % mod + prev[tar - i] % mod;
                    }
                }
                curr[tar] = ans % mod;
            }
            prev = curr;
        }
        return curr[T] % mod;
    }
    int solveTab(int N, int k, int T)
    {
        vector<vector<int>> dp(N + 1, vector<int>(T + 1, 0));
        dp[0][0] = 1;
        for (int n = 1; n <= N; n++)
        {
            for (int tar = 1; tar <= T; tar++)
            {
                int ans = 0;
                for (int i = 1; i <= k; i++)
                {
                    if (tar - i >= 0)
                    {
                        ans = ans % mod + dp[n - 1][tar - i] % mod;
                    }
                }
                dp[n][tar] = ans % mod;
            }
        }
        return dp[N][T] % mod;
    }
    int solve(int n, int k, int tar, vector<vector<int>> &dp)
    {
        if (n == 0 && tar == 0)
        {
            return 1;
        }
        if (n == 0 && tar != 0)
        {
            return 0;
        }
        if (n != 0 && tar == 0)
        {
            return 0;
        }
        if (tar < 0)
        {
            return 0;
        }
        if (dp[n][tar] != -1)
        {
            return dp[n][tar];
        }
        int ans = 0;
        for (int i = 1; i <= k; i++)
        {
            ans = ans % mod + solve(n - 1, k, tar - i, dp) % mod;
        }
        return dp[n][tar] = ans % mod;
    }
    int numRollsToTarget(int n, int k, int target)
    {
        // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        // return solve(n,k,target,dp)%mod;
        // return solveTab(n,k,target);
        return solveSO(n, k, target);
    }
};