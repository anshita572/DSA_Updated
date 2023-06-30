// https://leetcode.com/problems/next-greater-element-i/description/
// TC : O(n),SC:O(n)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       
         stack<int>s;
         unordered_map<int,int>mp;
        vector<int>ans;
	   for(int i=nums2.size()-1;i>=0;i--)
	   {
	    while(!s.empty() && nums2[i] >= s.top())
	    {s.pop();}
	    if(!s.empty())
	    {mp[nums2[i]]=s.top();} //mp[key]=value
        // key=all elements of nums2
        // value = corresponding next greater element
	    else
	    {mp[nums2[i]]=-1;}
	    s.push(nums2[i]);
    }

    for(auto i:nums1)
    {ans.push_back(mp[i]);}
    return ans;
    }
};