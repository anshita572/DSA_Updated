// https://leetcode.com/problems/counting-bits/description/
// TC
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int n,vector<int>&ans){
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        if(ans[n] != -1){
            return ans[n];
        }
        if(n & 1){
            return ans[n] = solve(n/2,ans) + 1;
        }
        else{
            return ans[n] = solve(n/2,ans);
        }
    }
    vector<int> countBits(int n) {
        vector<int>ans(n+1,-1);
        for(int i = 0; i <=n; i++){
        ans[i] = solve(i,ans);}
        return ans;
    }
};