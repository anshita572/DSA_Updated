// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
// TC : O(n^3) , SC : O(1) //if we don't consider the input matrix given
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //   Do it in-place means update the input matrix itself , don't store
    //   answer in a separate matrix
    void shortest_distance(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = 1e9;
                }
                if (i == j)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = min(matrix[i][j],
                                       (matrix[i][k] + matrix[k][j]));
                }
            }
        }
        // to check for negative cycle
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][i] < 0)
            {
                cout << "Negative cycle exists";
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1e9)
                {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};