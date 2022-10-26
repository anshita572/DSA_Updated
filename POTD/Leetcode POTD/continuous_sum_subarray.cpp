//https://leetcode.com/problems/continuous-subarray-sum/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//Brute Force (TLE)  TC :O(n^2) SC:O(1)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       int n=nums.size();
        for(int i=0;i<n;i++)
        {int sum=nums[i];
            for(int j=i+1;j<n;j++)
            {
               sum+=nums[j];
                if(sum % k == 0)
                {return true;}
            }
        }
        return false;
    }
};
//Optimized :TC :O(n)   SC:O(n)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       int n=nums.size();
       map<int,int>mp;
        mp[0]=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(mp.find(sum % k)==mp.end()) //if remainder already not present ,insert in map key and value(=i+1)
            {mp[sum % k]=i+1;}
            else if(mp[sum % k]<i) //to make sure that size of subarray >=2
            {return true;}
        }
        return false;
    }
    
};