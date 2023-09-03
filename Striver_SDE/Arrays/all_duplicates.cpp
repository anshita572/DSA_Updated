// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
// TC : O(n) , SC:O(1)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i = 0; i < n; i++){
            int index = abs(nums[i])-1;
            if(nums[index] < 0){
                ans.push_back(abs(nums[i]));
            }
            nums[index] = -nums[index];
        }
        return ans;
    }
};