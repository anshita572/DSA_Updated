// https://leetcode.com/problems/longest-common-subsequence/description/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solveSO(string &s1, string &s2)
    {
        int l1 = s1.length();
        int l2 = s2.length();
        vector<int> curr(l2 + 1, 0);
        vector<int> next(l2 + 1, 0);
        for (int i = l1 - 1; i >= 0; i--)
        {
            for (int j = l2 - 1; j >= 0; j--)
            {
                int ans = 0;
                if (s1[i] == s2[j])
                {
                    ans = 1 + next[j + 1];
                }
                else
                {
                    int op1 = next[j];
                    int op2 = curr[j + 1];
                    ans = max(op1, op2);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return curr[0];
    }
    int solveTab(string &s1, string &s2)
    {
        int l1 = s1.length();
        int l2 = s2.length();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
        for (int i = l1 - 1; i >= 0; i--)
        {
            for (int j = l2 - 1; j >= 0; j--)
            {
                if (s1[i] == s2[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    int op1 = dp[i + 1][j];
                    int op2 = dp[i][j + 1];
                    dp[i][j] = max(op1, op2);
                }
            }
        }
        return dp[0][0];
    }
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= s1.length() || j >= s2.length())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (s1[i] == s2[j])
        {
            return dp[i][j] = 1 + solve(s1, s2, i + 1, j + 1, dp);
        }
        else
        {
            int op1 = solve(s1, s2, i + 1, j, dp);
            int op2 = solve(s1, s2, i, j + 1, dp);
            return dp[i][j] = max(op1, op2);
        }
    }
    int longestCommonSubsequence(string s1, string s2)
    {
        // int i=s1.length();
        // int j=s2.length();
        // vector<vector<int>>dp(i,vector<int>(j,-1));
        // return solve(s1,s2,0,0,dp);

        //    return solveTab(s1,s2);
        return solveSO(s1, s2);
    }
};