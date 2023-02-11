// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solveSO(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy == 1)
                {
                    int canBuy = -prices[i] + next[0];
                    int skip = next[1];
                    profit = max(canBuy, skip);
                }
                else
                {
                    int canSell = prices[i] + next[1];
                    int skip = next[0];
                    profit = max(canSell, skip);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return curr[1];
    }
    int solveTab(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy == 1)
                {
                    int canBuy = -prices[i] + dp[i + 1][0];
                    int skip = dp[i + 1][1];
                    profit = max(canBuy, skip);
                }
                else
                {
                    int canSell = prices[i] + dp[i + 1][1];
                    int skip = dp[i + 1][0];
                    profit = max(canSell, skip);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
    int solve(vector<int> &prices, int i, int buy, vector<vector<int>> &dp)
    {
        if (i == prices.size())
        {
            return 0;
        }
        if (dp[i][buy] != -1)
        {
            return dp[i][buy];
        }
        int profit = 0;
        if (buy == 1)
        {
            int canBuy = -prices[i] + solve(prices, i + 1, 0, dp);
            int skip = solve(prices, i + 1, 1, dp);
            profit = max(canBuy, skip);
        }
        else
        {
            int canSell = prices[i] + solve(prices, i + 1, 1, dp);
            int skip = solve(prices, i + 1, 0, dp);
            profit = max(canSell, skip);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int> &prices)
    {
        // int n = prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return solve(prices,0,1,dp);
        //    return solveTab(prices);
        return solveSO(prices);
    }
};