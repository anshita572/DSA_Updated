// https://leetcode.com/problems/minimum-cost-for-tickets/description/

//We have 3 choices and we find the minimum out of them.The twist is whenever we take a 7-days or 30-days pass , we need to skip those days ,so use a FOR loop for that
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solveTab(vector<int> &days, vector<int> &costs)
    {
        vector<int> dp(days.size() + 1, INT_MAX);
        dp[days.size()] = 0;
        for (int index = days.size() - 1; index >= 0; index--)
        {
            int op1 = costs[0] + dp[index + 1];
            int i;
            for (i = index; i < days.size() && days[i] < days[index] + 7; i++)
            {
                // skip 7 days
            }
            int op2 = costs[1] + dp[i];
            for (i = index; i < days.size() && days[i] < days[index] + 30; i++)
            {
                // skip 30 days
            }
            int op3 = costs[2] + dp[i];
            dp[index] = min(op1, min(op2, op3));
        }
        return dp[0];
    }
    int solve(vector<int> &days, vector<int> &costs, int index, vector<int> &dp)
    {
        if (index >= days.size())
        {
            return 0;
        }
        if (dp[index] != -1)
        {
            return dp[index];
        }
        int op1 = costs[0] + solve(days, costs, index + 1, dp);
        int i;
        for (i = index; i < days.size() && days[i] < days[index] + 7; i++)
        {
            // skip 7 days
        }
        int op2 = costs[1] + solve(days, costs, i, dp);
        for (i = index; i < days.size() && days[i] < days[index] + 30; i++)
        {
            // skip 30 days
        }
        int op3 = costs[2] + solve(days, costs, i, dp);
        return dp[index] = min(op1, min(op2, op3));
    }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        //    cout<<days.size()<<endl;
        // vector<int>dp(days.size(),-1);
        //   return solve(days,costs,0,dp);
        return solveTab(days, costs);
    }
};