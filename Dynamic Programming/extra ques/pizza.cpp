// https://leetcode.com/problems/pizza-with-3n-slices/description/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solveSO(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> curr((n / 3) + 1, 0);
        vector<int> next1((n / 3) + 1, 0);
        vector<int> next2((n / 3) + 1, 0);
        vector<int> curr2((n / 3) + 1, 0);
        vector<int> next12((n / 3) + 1, 0);
        vector<int> next22((n / 3) + 1, 0);
        for (int i = n - 2; i >= 0; i--)
        {
            for (int mySlice = 1; mySlice <= n / 3; mySlice++)
            {
                int inc = nums[i] + next2[mySlice - 1];
                int exc = next1[mySlice];
                curr[mySlice] = max(inc, exc);
            }
            next2 = next1;
            next1 = curr;
        }
        int case1 = curr[n / 3];
        for (int i = n - 1; i >= 1; i--)
        {
            for (int mySlice = 1; mySlice <= n / 3; mySlice++)
            {
                int inc = nums[i] + next22[mySlice - 1];
                int exc = next12[mySlice];
                curr2[mySlice] = max(inc, exc);
            }
            next22 = next12;
            next12 = curr2;
        }
        int case2 = curr2[n / 3];
        return max(case1, case2);
    }
    int solveTab(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>((n / 3) + 1, 0));
        //  vector<vector<int>>dp2(n+2,vector<int>((n/3)+1,0));
        // can take 2 dp arrays but here possible with 1 dp array as 2nd case k liye pehle waale dp array m hi overwrite ho jaayega
        for (int i = n - 2; i >= 0; i--)
        {
            for (int mySlice = 1; mySlice <= n / 3; mySlice++)
            {
                int inc = nums[i] + dp[i + 2][mySlice - 1];
                int exc = dp[i + 1][mySlice];
                dp[i][mySlice] = max(inc, exc);
            }
        }
        int case1 = dp[0][n / 3];
        for (int i = n - 1; i >= 1; i--)
        {
            for (int mySlice = 1; mySlice <= n / 3; mySlice++)
            {
                int inc = nums[i] + dp[i + 2][mySlice - 1];
                int exc = dp[i + 1][mySlice];
                dp[i][mySlice] = max(inc, exc);
            }
        }
        int case2 = dp[1][n / 3];
        return max(case1, case2);
    }
    int solve(vector<int> &nums, int i, int n, int mySlice, vector<vector<int>> &dp)
    {
        if (i > n || mySlice == 0)
        {
            return 0;
        }
        if (dp[i][mySlice] != -1)
        {
            return dp[i][mySlice];
        }
        int inc = nums[i] + solve(nums, i + 2, n, mySlice - 1, dp);
        int exc = solve(nums, i + 1, n, mySlice, dp);
        return dp[i][mySlice] = max(inc, exc);
    }
    int maxSizeSlices(vector<int> &slices)
    {
        // int n=slices.size();
        // vector<vector<int>>dp1(n+1,vector<int>((n/3)+1,-1));
        //  vector<vector<int>>dp2(n+1,vector<int>((n/3)+1,-1));
        //  //ans1 k liye jo dp array call kraa toh usme kuch values store hongi and agar vahi dp array ans2 k liye use krenge that will be wrong,so create 2 dp arrays
        // int ans1=solve(slices,1,n-1,n/3,dp1);
        // int ans2=solve(slices,0,n-2,n/3,dp2);
        // return max(ans1,ans2);
        // return solveTab(slices);
        return solveSO(slices);
    }
};