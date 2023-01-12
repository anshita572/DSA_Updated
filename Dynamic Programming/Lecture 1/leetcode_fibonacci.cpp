// https://leetcode.com/problems/fibonacci-number/description/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solveSO(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        int prev2 = 0;
        int prev1 = 1;
        int curr = 0;
        for (int i = 2; i <= n; i++)
        {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
    int solveTab(int n)
    {
        if (n == 0)
            return 0; // to avoid runtime error (if n==0,dp[1] does not exist(invalid),so runtime error)
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    int solveMemo(int n, vector<int> &dp)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = solveMemo(n - 1, dp) + solveMemo(n - 2, dp);
    }
    int fib(int n)
    {
        // vector<int>dp(n+1,-1);
        // return solveMemo(n,dp);
        // return solveTab(n);
        return solveSO(n);
    }
};