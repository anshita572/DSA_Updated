//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

//TC :O(log n) SC:O(1)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        auto it1=lower_bound(nums.begin(),nums.end(),target);
        int first=it1-nums.begin();
        if(it1 != nums.end() && nums[first]==target)
        {ans.push_back(first);}
        else //Not found
        {ans.push_back(-1);}
        auto it2=upper_bound(nums.begin(),nums.end(),target);
        int last=it2-nums.begin();
        last-=1;
        if(last>=0 && nums[last]==target)
        {ans.push_back(last);}
        else //Not found
        {ans.push_back(-1);}
        return ans;
    }
};