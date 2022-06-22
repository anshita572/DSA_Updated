// https://leetcode.com/problems/subsets/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
void solve(vector<int>nums,vector<int>output,int index,
vector<vector<int>> & ans)

    {if(index>=nums.size())//base case
      {ans.push_back(output);
        return;}
     //exclude
     solve(nums,output,index+1,ans);
     //include
     int element=nums[index];
    output.push_back(element);
     solve(nums,output,index+1,ans);
     output.pop_back();   
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans; //2D array
        vector<int>output; //array(linear)
        int index=0;
        solve(nums,output,index,ans);
        return ans;
    }
};