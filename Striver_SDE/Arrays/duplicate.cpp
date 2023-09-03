// https://leetcode.com/problems/find-the-duplicate-number/description/
// TC : O(n) , SC : O(1)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(fast != slow);
        fast = nums[0];
        while(fast != slow){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};