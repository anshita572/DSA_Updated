//https://leetcode.com/problems/subsets/
// M1 : with backtracking
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
// M2 : using only recursion without backtracking
// If you write vector<int>& temp in the solve function, it will modify the same temp vector in both recursive calls, leading to incorrect results. Instead, use vector<int> temp without the reference.
class Solution {
public:
    void solve(vector<int>& nums,int i, vector<int>temp,
    vector<vector<int>>&ans)
    {
        if(i>=nums.size())
        {ans.push_back(temp);
        return;}
        solve(nums,i+1,temp,ans);
        temp.push_back(nums[i]);
        solve(nums,i+1,temp,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>>ans;
         vector<int>temp;
         solve(nums,0,temp,ans);
         return ans;
    }
};