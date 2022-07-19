//https://leetcode.com/problems/longest-consecutive-sequence/
//TC :O(n)
//SC :O(n)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s;
        
        int longest_sequence=0;
        for(int i=0;i<n;i++)
        {
           s.insert(nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(s.count(nums[i]-1))
            {continue;}
            else
            {  int current_element=nums[i];
             int count=0;
              
                while(s.count(current_element))//O(1) as unordered set
              {    
                    count++;  
                    current_element++;
              }
             longest_sequence=max(longest_sequence,count);
           }
             
          
        }
        return longest_sequence;
    }
};