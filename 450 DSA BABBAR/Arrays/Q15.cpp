//https://leetcode.com/problems/next-permutation/
//TC:O(n)
//SC:O(1)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i,j;
        for(i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {break;}
        }
        if(i<0) //if no breakpoint found ,e.g. 3,2,1 ;ans will be 1,2,3 simply reverse the array
        {reverse(nums.begin(),nums.end());}
        else //if breakpoint found
        {
            for(j=n-1;j>=0;j--)
            {
                if(nums[j]>nums[i])
                {break;}
            }
            swap(nums[i],nums[j]);
        reverse(nums.begin()+i+1,nums.end());
        }
        
        
    }
};