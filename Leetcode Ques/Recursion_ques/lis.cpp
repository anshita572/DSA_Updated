//https://leetcode.com/problems/longest-increasing-subsequence/
//TLE with recursion ,optimised with DP + binary search
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int curr,int prev,vector<int>& nums)
    {
        if(curr==nums.size())
        {return 0;}
        int pick=0;
        if(prev==-1 || nums[curr]>nums[prev])
        {pick=1+solve(curr+1,curr,nums);}
        int notPick= solve(curr+1,prev,nums);
        return max(pick,notPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int curr=0;
        int prev=-1;
       return solve(curr,prev,nums);
    }
};