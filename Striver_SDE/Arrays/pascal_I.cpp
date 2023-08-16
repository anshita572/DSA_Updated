// https://leetcode.com/problems/pascals-triangle/
// TC : O(n^2) ,SC : O(1)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int>genRow(int row){
        vector<int>ans;
        long long res = 1;
        ans.push_back(1);
        for(int col = 1; col < row; col++){
            res = res * (row-col);
            res = res / col;
            ans.push_back(res);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        vector<int>ans;
        for(int i = 1; i <= numRows; i++){
            ans = genRow(i);
            pascal.push_back(ans);
        }
        return pascal;
    }
};