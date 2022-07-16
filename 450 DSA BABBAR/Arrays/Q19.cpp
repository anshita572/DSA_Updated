// https://www.codingninjas.com/codestudio/problems/common-elements-in-three-sorted-arrays_1113130?leftPanelTab=0

// TC :O(n) and SC:O(1)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> findCommonElements(vector<int> &A, vector<int> &B, vector<int> &C)
{
    vector<int> ans;
    int n1 = A.size();
    int n2 = B.size();
    int n3 = C.size();
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n1 && j < n2 && k < n3)
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            ans.push_back(A[i]);
            i++;
            j++;
            k++;
        }
        else if (A[i] < B[j])
        {
            i++;
        }
        else if (B[j] < C[k])
        {
            j++;
        }
        else
        {
            k++;
        }
        // to avoid repeated elements
        while (A[i] == A[i - 1] && i >= 1) //if i=0,i-1 will be -1 so doing i>=1 so that if i=1 ,i-1=0
        {
            i++;
        }
        while (B[j] == B[j - 1] && j >= 1)
        {
            j++;
        }
        while (C[k] == C[k - 1] && k >= 1)
        {
            k++;
        }
    }
    return ans;
}