//https://leetcode.com/problems/max-number-of-k-sum-pairs/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int maxOperations(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		int ans = 0;
		for(int i = 0; i < nums.size(); i++){
            int b=k-nums[i];
			if(m[b] > 0){//check if b is present in map
			   m[b]--;
				ans++;
			}
			else{
				m[nums[i]]++;
			}
		}
		return ans;
	}
};