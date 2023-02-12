// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solveSO(vector<int> &prices, int fee)
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
                    int canSell = prices[i] - fee + next[1];
                    int skip = next[0];
                    profit = max(canSell, skip);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return curr[1];
    }
    int maxProfit(vector<int> &prices, int fee)
    {
        return solveSO(prices, fee);
    }
};