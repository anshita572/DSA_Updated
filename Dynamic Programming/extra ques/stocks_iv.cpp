// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// M1 (same as stocks_iii ,just add k instead of 2 limit)
class Solution
{
public:
    int solveSO(vector<int> &prices, int k)
    {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        vector<vector<int>> next(2, vector<int>(k + 1, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limit = 1; limit <= k; limit++)
                {
                    int profit = 0;
                    if (buy == 1)
                    {
                        int canBuy = -prices[i] + next[0][limit];
                        int skip = next[1][limit];
                        profit = max(canBuy, skip);
                    }
                    else
                    {
                        int canSell = prices[i] + next[1][limit - 1];
                        int skip = next[0][limit];
                        profit = max(canSell, skip);
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return curr[1][k];
    }
    int maxProfit(int k, vector<int> &prices)
    {
        return solveSO(prices, k);
    }
};

// M2
class Solution
{
public:
    int solveSO(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<int> curr(2 * k + 1, 0);
        vector<int> next(2 * k + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int opNo = 1; opNo <= 2 * k; opNo++)
            {
                int profit = 0;
                if (opNo % 2 == 0)
                {
                    int canBuy = -prices[i] + next[opNo - 1];
                    int skip = next[opNo];
                    profit = max(canBuy, skip);
                }
                else
                {
                    int canSell = +prices[i] + next[opNo - 1];
                    int skip = next[opNo];
                    profit = max(canSell, skip);
                }
                curr[opNo] = profit;
            }
            next = curr;
        }
        return curr[2 * k];
    }
    int solveTab(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int opNo = 1; opNo <= 2 * k; opNo++)
            {
                int profit = 0;
                if (opNo % 2 == 0)
                {
                    int canBuy = -prices[i] + dp[i + 1][opNo - 1];
                    int skip = dp[i + 1][opNo];
                    profit = max(canBuy, skip);
                }
                else
                {
                    int canSell = +prices[i] + dp[i + 1][opNo - 1];
                    int skip = dp[i + 1][opNo];
                    profit = max(canSell, skip);
                }
                dp[i][opNo] = profit;
            }
        }
        return dp[0][2 * k];
    }
    int solve(int k, vector<int> &prices, int i, int opNo, vector<vector<int>> &dp)
    {
        if (i == prices.size() || opNo == 0)
        {
            return 0;
        }
        if (dp[i][opNo] != -1)
        {
            return dp[i][opNo];
        }
        int profit = 0;
        if (opNo % 2 == 0)
        {
            int canBuy = -prices[i] + solve(k, prices, i + 1, opNo - 1, dp);
            int skip = solve(k, prices, i + 1, opNo, dp);
            profit = max(canBuy, skip);
        }
        else
        {
            int canSell = +prices[i] + solve(k, prices, i + 1, opNo - 1, dp);
            int skip = solve(k, prices, i + 1, opNo, dp);
            profit = max(canSell, skip);
        }
        return dp[i][opNo] = profit;
    }
    int maxProfit(int k, vector<int> &prices)
    {
        // int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(2*k+1,-1));
        // return solve(k,prices,0,2*k,dp);
        // return solveTab(k,prices);
        return solveSO(k, prices);
    }
};