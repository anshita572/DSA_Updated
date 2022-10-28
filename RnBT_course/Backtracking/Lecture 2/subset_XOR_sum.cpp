//https://leetcode.com/problems/sum-of-all-subset-xor-totals/
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




