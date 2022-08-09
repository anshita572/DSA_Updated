// https://www.codingninjas.com/codestudio/problems/median-of-a-row-wise-sorted-matrix_1115473?leftPanelTab=0

//Time Complexity: O(32 * R * log(C))
//Space Complexity: O(1)


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int findMedian(vector<vector<int>> &matrix, int m, int n)
{ // finding min and max element in matrix
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        mini = min(matrix[i][0], mini);
        maxi = max(matrix[i][n - 1], maxi);
    }
    int total = (m * n) + 1;
    int medianPosition = total / 2;

    while (mini < maxi)
    {
        int mid = mini + (maxi - mini) / 2;
        int count = 0; // count no. of elements <= mid
        for (int i = 0; i < m; i++)
        {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        if (count >= medianPosition)
        {
            maxi = mid;
        }
        else
        {
            mini = mid + 1;
        }
    }
    return mini;
}