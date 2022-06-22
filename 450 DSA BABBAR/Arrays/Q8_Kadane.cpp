//https://leetcode.com/problems/maximum-subarray/

//TC : O(N)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
             sum = sum + nums[i];
            maxi=max(sum,maxi);
            if(sum < 0)//we want max sum,-ve sum will decrease it,so neglect -ve sum 
            {sum=0;}
        }
        return maxi;
    }
};
