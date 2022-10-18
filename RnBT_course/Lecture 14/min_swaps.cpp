//https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/

//TLE (will be optimized with DP)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2,int curr_index,int prev1,int prev2)
    {
        if(curr_index==nums1.size()) //base case
        {return 0;} 
        int no_swap=INT_MAX;
        int swap=INT_MAX;
        if(prev1<nums1[curr_index] && prev2<nums2[curr_index])
        {no_swap=solve(nums1,nums2,curr_index+1,                  nums1[curr_index],nums2[curr_index]);}
        if(prev2<nums1[curr_index] && prev1<nums2[curr_index]) 
        {  swap=1+solve(nums1,nums2,curr_index+1,                  nums2[curr_index],nums1[curr_index]);}
        return min(no_swap,swap);
        
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        return solve(nums1,nums2,0,-1,-1);
    }
};