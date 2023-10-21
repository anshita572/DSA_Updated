// https://leetcode.com/problems/subsets-ii
// M1
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(vector<int>& nums, int i, vector<int>&temp,
    vector<vector<int>>&ans){
        ans.push_back(temp);
        for(int j = i; j < nums.size(); j++){
            if(j != i && nums[j] == nums[j-1]){
                continue;
            }
            temp.push_back(nums[j]);
            solve(nums,j+1,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector<int>>ans;
         vector<int>temp;
         sort(nums.begin(),nums.end());
         solve(nums,0,temp,ans);
         return ans;
    }
};

// M2
class Solution {
public:
    void solve(vector<int>& nums,int i, vector<int>&temp,
    vector<vector<int>>&ans)
    {
        if(i>=nums.size())
        {ans.push_back(temp);
        return;}
        temp.push_back(nums[i]);
        solve(nums,i+1,temp,ans);
        temp.pop_back();
        while(i+1 < nums.size() && nums[i] == nums[i+1]){
            i++;
        }
        solve(nums,i+1,temp,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector<int>>ans;
         vector<int>temp;
         sort(nums.begin(),nums.end());
         solve(nums,0,temp,ans);
         return ans;
    }
};



int calculateStreetLength(int L, const vector<pair<int, int>>& lights) {
    int totalLength = 0;

    // Create a copy of the vector
    vector<pair<int, int>> lightsCopy = lights;

    // Sort the lights based on their ending points
    sort(lightsCopy.begin(), lightsCopy.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    // Initialize totalLength with the range of the first light
    totalLength = lightsCopy[0].second - lightsCopy[0].first;

    // Calculate the additional lengths covered by subsequent lights
    for (int i = 1; i < L; ++i) {
        int intersection = max(0, min(lightsCopy[i].second, lightsCopy[i - 1].second) - max(lightsCopy[i].first, lightsCopy[i - 1].first));
        totalLength += (lightsCopy[i].second - lightsCopy[i].first) - intersection;
    }

    return totalLength;
}