//https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

// https://leetcode.com/problems/sliding-window-maximum/

//Brute Force : TC : O(n^2) SC :O(1)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {vector <int>ans;
    for(int i=0;i<=n-k;i++)
    {int maxi=INT_MIN;
        for(int j=i;j<i+k;j++)
        {
            maxi=max(arr[j],maxi);
            
        }
        ans.push_back(maxi);
    }
    return ans;
        
    }
};
//Optimized : TC: O(n)   SC:O(k)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        for(int i=0;i<nums.size();i++)
        { if(!dq.empty() && dq.front()==i-k)
        {dq.pop_front();}
         while(!dq.empty() && nums[dq.back()]<nums[i])
         {dq.pop_back();}
         dq.push_back(i);
         if(i>=k-1)
         {ans.push_back(nums[dq.front()]);}
        }
        return ans;
    }
};