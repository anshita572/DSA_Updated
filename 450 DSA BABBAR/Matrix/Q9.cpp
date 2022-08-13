//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//Brute force TC :O(n^2) SC:O(n^2)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat[0].size();
        vector<int>temp;
    for(int i=0;i<n;i++)
  {
      for(int j=0;j<n;j++)
      {
          temp.push_back(mat[i][j]);
      }
  }
  sort(temp.begin(),temp.end());
  int ans=temp[k-1];
  return ans;
    }
};
//Optimised : TC : doubt ,SC :O(1)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix[0].size();
        int l=matrix[0][0]; //smallest element
        int h=matrix[n-1][n-1]; //largest element
        while(l<h)
        {
            int mid=l+(h-l)/2;
            int count=0; 
            for(int i=0;i<n;i++)
            {//counts no of elements <= mid
                count+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            if(count < k)
            {l=mid+1;}
            else
            {h=mid;}
        }
        return l;
    }
};