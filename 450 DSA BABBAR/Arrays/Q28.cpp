//https://leetcode.com/problems/3sum/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        int i=0;
        
        for(int i=0;i<n-2;i++)
        {   int j=i+1;
            int k=n-1;
            int sum=0-nums[i];
            if(i==0 ||(i>0 && nums[i]!=nums[i-1]))//so that nums[i] is not repeated or duplicated
            while(j<k)
            {
               if(nums[j]+nums[k]==sum)
               {
                   ans.push_back({nums[i],nums[j],nums[k]});
                   while(j<k && nums[j]==nums[j+1])
                   {j++;}
                   while(j<k && nums[k]==nums[k-1])
                   {k--;}
                   j++;
                   k--;
/*after coming out of while loops at line no 19 and 21 ,you will be at that repeated element ,so further j++ and k-- at line no. 22 and 23 to skip that repeated element*/
                   
               }
                else if(nums[j]+nums[k]<sum)
                {j++;}
                else //if(nums[j]+nums[k]>sum)
                {k--;}
            }
        }
        return ans;
    }
};