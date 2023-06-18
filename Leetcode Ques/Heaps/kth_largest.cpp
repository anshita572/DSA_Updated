// https://leetcode.com/problems/kth-largest-element-in-an-array/description/
// TC : O(k + (N - k) * log k)
// SC : O(k)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
      priority_queue<int,vector<int>,greater<int>>pq;  //Min heap
      int n=arr.size();
      for(int i=0;i<k;i++)
      {pq.push(arr[i]);}
      for(int i=k;i<n;i++)
      {if(arr[i]>pq.top())
          {pq.pop();
           pq.push(arr[i]);
          }
      }
      return pq.top();
    }
};