// https://leetcode.com/problems/edit-distance/description/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solveSO(string &s1, string &s2)
    {
        vector<int> curr(s2.size() + 1, 0);
        vector<int> next(s2.size() + 1, 0);
        for (int j = 0; j < s2.size(); j++)
        {
            curr[j] = s2.size() - j;
        }
        for (int i = 0; i < s1.size(); i++)
        {
            curr[s2.size()] = s1.size() - i;
        }
        for (int i = s1.size() - 1; i >= 0; i--)
        {
            for (int j = s2.size() - 1; j >= 0; j--)
            {
                if (s1[i] == s2[j])
                {
                    curr[j] = next[j + 1];
                }
                else
                {
                    int insert = curr[j + 1];
                    int remove = next[j];
                    int replace = next[j + 1];
                    curr[j] = 1 + min(insert, min(remove, replace));
                }
            }
            next = curr;
        }
        return curr[0];
    }
    int solveTab(string s1, string s2)
    {
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
        // converting base cases
        for (int j = 0; j < s2.length(); j++) // s1 has finished (s2>s1)
        {
            dp[s1.length()][j] = s2.length() - j;
        }
        for (int i = 0; i < s1.length(); i++)
        {
            dp[i][s2.length()] = s1.length() - i;
        }
        for (int i = s1.length() - 1; i >= 0; i--)
        {
            for (int j = s2.length() - 1; j >= 0; j--)
            {
                if (s1[i] == s2[j]) // match
                {
                    dp[i][j] = dp[i + 1][j + 1];
                }    // no need of any operation ,check next char
                else // not match
                {
                    int insertAns = 1 + dp[i][j + 1]; // 1+ means we are counting that operation
                    int deleteAns = 1 + dp[i + 1][j];
                    int replaceAns = 1 + dp[i + 1][j + 1];
                    int ans = min(insertAns, min(deleteAns, replaceAns));
                    dp[i][j] = ans;
                }
            }
        }
        return dp[0][0];
    }
    int solve(string s1, string s2, int i, int j, vector<vector<int>> &dp)
    {
        // base case
        if (i >= s1.length())
        {
            return s2.length() - j;
        } // this number of operations will be added
        if (j >= s2.length())
        {
            return s1.length() - i;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (s1[i] == s2[j]) // match
        {
            return dp[i][j] = 0 + solve(s1, s2, i + 1, j + 1, dp);
        }    // no need of any operation ,check next char
        else // not match
        {
            int insertAns = 1 + solve(s1, s2, i, j + 1, dp); // 1+ means we are counting that operation
            int deleteAns = 1 + solve(s1, s2, i + 1, j, dp);
            int replaceAns = 1 + solve(s1, s2, i + 1, j + 1, dp);
            int ans = min(insertAns, min(deleteAns, replaceAns));
            return dp[i][j] = ans;
        }
    }
    int minDistance(string word1, string word2)
    {
        // vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        // int ans = solve(word1, word2, 0, 0, dp);
        // return ans;
        // return solveTab(word1, word2);
        return solveSO(word1, word2);
    }
};