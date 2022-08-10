// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1
// 3 approaches (scroll down)
// brute force: TC: O(m*n),SC:O(1)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int maxi = 0;
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                {
                    count++;
                }
            }
            if (count > maxi)
            {
                maxi = count;
                ans = i;
            }
        }

        return ans;
    }
};
// Optimised : TC:O(m+n),SC:O(1) (My approach (complicated and lengthy) )
class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int maxi = 0;
        int ans = -1;
        int i = 0;
        int j = 0;
        int count = 0;
        while (i < n && j < m)
        {
            if (arr[i][j] == 1)
            {
                count = m - j;
                if (count > maxi)
                {
                    maxi = count;
                    ans = i;
                }
                // Move to the next row after storing the count and index of a particular row
                i++;
                j = -1;
                count = 0;
            }

            j++;
            // in case no 1's are found in a row ,move to the next row
            if (j >= m)
            {
                i++;
                j = 0;
                count = 0;
            }
        }

        return ans;
    }
};

// optimised and simple
int rowWithMax1s(vector<vector<int>> mat, int n, int m)
{
    int i = 0, j = m - 1, ans = -1;
    while (i < n and j >= 0)
    {
        if (mat[i][j] == 1)
        {
            ans = i;
            j--;
        }
        if (mat[i][j] == 0)
        {
            i++;
        }
    }
    return ans;
}