//https://leetcode.com/problems/minimum-size-subarray-sum/
//Brute force 
//TC:O(n^2),SC:O(1)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
       
        
        for(int i=0;i<n;i++)
        {    int sum=0;
         int length=0;
            for(int j=i;j<n;j++)
        {
            sum=sum+nums[j];
                length++;
            if(sum>=target)
            {
            ans=min(length,ans);
                break;
           }
        }
         
        }
        //if target not found
        if(ans==INT_MAX)
        {ans=0;}
        return ans;
    }
};
//Optimal
//TC :O(n)
//SC:O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int r=0;
        int ans=INT_MAX;
        int sum=0;
        int n=nums.size();
        while(r<n)
        {
          sum=sum+nums[r];
             r++;
            while(sum >=target)
            {
                ans=min(ans,r-l);
                sum=sum-nums[l];
                l++;
            }
            
        }
        //if target not found
        if(ans==INT_MAX)
        {ans=0;}
        return ans;
    }
};
