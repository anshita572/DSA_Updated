//https://leetcode.com/problems/longest-arithmetic-subsequence/
//TLE
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<int>& nums,int diff,int i)
    {
        if(i<0)
        {return 0;}
        int ans=0;
        for(int k=i-1;k>=0;k--)
        {
            if(nums[i]-nums[k]==diff)
            {ans=max(ans,1+solve(nums,diff,k));}
        }
        return ans;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int diff=nums[j]-nums[i];
                ans=max(ans,2+solve(nums,diff,i));
            }
        }
        return ans;
    }
};