//https://leetcode.com/problems/sum-of-all-subset-xor-totals/
// M1 : backtracking
// TC : O(2^n) SC:O(n)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(vector<int>& nums,int i,int &XOR,int &sum)
    {if(i==nums.size())
    {sum=sum+XOR;
    return;}
     //include
    XOR=XOR^nums[i];
     solve(nums,i+1,XOR,sum);
         XOR=XOR^nums[i]; //backtrack
     //exclude
     solve(nums,i+1,XOR,sum);
     
    }
    int subsetXORSum(vector<int>& nums) {
        int sum=0;
        int XOR=0;
        solve(nums,0,XOR,sum);
        return sum;
    }
};

// M2 : recursion
// TC : O(2^n) SC:O(n)
class Solution {
public:
    int solve(vector<int>& nums, int xorVal, int i){
        if(i == nums.size()){
            return xorVal;
        }
        
        int inc = solve(nums, xorVal ^ nums[i], i+1);
        int exc = solve(nums, xorVal, i+1);
        return inc + exc;
    }
    int subsetXORSum(vector<int>& nums) {
        int xorVal = 0;
        int i = 0;
        return solve(nums, xorVal, i);
    }
};

// M3 : Bit manipulation (couldn't understand)



