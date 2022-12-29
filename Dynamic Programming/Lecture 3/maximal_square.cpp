// https://leetcode.com/problems/maximal-square/description/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solveTab(vector<vector<char>> &matrix, int &maxi)
    {
        int row = matrix.size();    // total no of rows
        int col = matrix[0].size(); // total no of columns
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
        for (int i = row - 1; i >= 0; i--)
        {
            for (int j = col - 1; j >= 0; j--)
            {
                int bottom = dp[i + 1][j];
                int diagonal = dp[i + 1][j + 1];
                int right = dp[i][j + 1];
                if (matrix[i][j] == '1')
                {
                    dp[i][j] = min(bottom, min(diagonal, right)) + 1; // adding 1 so that jis 1 pe ho tum usko include krne k liye
                    maxi = max(maxi, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
    }
    int solve(vector<vector<char>> &matrix, int i, int j, int &maxi, vector<vector<int>> &dp)
    {
        if (i >= matrix.size() || j >= matrix[0].size())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int bottom = solve(matrix, i + 1, j, maxi, dp);
        int diagonal = solve(matrix, i + 1, j + 1, maxi, dp);
        int right = solve(matrix, i, j + 1, maxi, dp);
        if (matrix[i][j] == '1')
        {
            int side = min(bottom, min(diagonal, right)) + 1;
            maxi = max(maxi, side);
            dp[i][j] = side;
            return side;
        }
        else
        {
            return 0;
        }
    }
    int maximalSquare(vector<vector<char>> &matrix)
    {

        // int i=matrix.size(); //total no of rows
        // int j=matrix[0].size(); //total no of columns
        // vector<vector<int>>dp(i,vector<int>(j,-1));
        int maxi = 0;
        // solve(matrix,0,0,maxi,dp);
        solveTab(matrix, maxi);
        return maxi * maxi;
    }
};