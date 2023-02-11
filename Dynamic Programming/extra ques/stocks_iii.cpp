// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solveSO(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limit = 1; limit <= 2; limit++)
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
        return curr[1][2];
    }
    int solveTab(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limit = 1; limit <= 2; limit++)
                {
                    int profit = 0;
                    if (buy == 1)
                    {
                        int canBuy = -prices[i] + dp[i + 1][0][limit];
                        int skip = dp[i + 1][1][limit];
                        profit = max(canBuy, skip);
                    }
                    else
                    {
                        int canSell = prices[i] + dp[i + 1][1][limit - 1];
                        int skip = dp[i + 1][0][limit];
                        profit = max(canSell, skip);
                    }
                    dp[i][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
    int solve(vector<int> &prices, int i, int buy, int limit, vector<vector<vector<int>>> &dp)
    {
        if (i == prices.size() || limit == 0)
        {
            return 0;
        }
        if (dp[i][buy][limit] != -1)
        {
            return dp[i][buy][limit];
        }
        int profit = 0;
        if (buy == 1)
        {
            int canBuy = -prices[i] + solve(prices, i + 1, 0, limit, dp);
            int skip = solve(prices, i + 1, 1, limit, dp);
            profit = max(canBuy, skip);
        }
        else
        {
            int canSell = prices[i] + solve(prices, i + 1, 1, limit - 1, dp);
            int skip = solve(prices, i + 1, 0, limit, dp);
            profit = max(canSell, skip);
        }
        return dp[i][buy][limit] = profit;
    }
    int maxProfit(vector<int> &prices)
    {
        // int n=prices.size();
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        // return solve(prices,0,1,2,dp);
        // return solveTab(prices);
        return solveSO(prices);
    }
};