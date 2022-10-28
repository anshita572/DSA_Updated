//https://leetcode.com/problems/subsets/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//TC : O(2^n)
//SC : O(2^n*length of each subset)
class Solution {
public:
    void solve(vector<int>& nums,int i, vector<int>&temp,
    vector<vector<int>>&ans)
    {
        if(i>=nums.size())
        {ans.push_back(temp);
        return;}
        //include
        temp.push_back(nums[i]);
        solve(nums,i+1,temp,ans);
        temp.pop_back();//backtrack
        //exclude
        solve(nums,i+1,temp,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>>ans;
         vector<int>temp;
         solve(nums,0,temp,ans);
         return ans;
    }
};