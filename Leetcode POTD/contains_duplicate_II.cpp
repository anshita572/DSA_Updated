//https://leetcode.com/problems/contains-duplicate-ii/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//Brute Force (TLE) TC : O(n^2) SC : O(1)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
     int n=nums.size();
     for(int i=0;i<n;i++)
     {
         for(int j=i+1;j<n;j++)
         {if(nums[i]==nums[j] && (j-i<=k))
             {return true;}
        }
     }
        return false;
    }
};
//Optimized TC : O(n) SC:O(n)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(mp.count(nums[i])) //check if element(key) already present in map
            {if((i-mp[nums[i]])<=k) //check if difference <= k
            {return true;}
            }
            
            mp[nums[i]]=i; //if not already present in map then insert or if present but difference !<k ,overwrite
        }
        return false;
    }
};
//e.g. [1,0,1,1] 
// mp[1]=0,mp[0]=1,mp[1]=2(overwrites mp[1]=0),mp[1]=3 (condition matches =>returns true)
