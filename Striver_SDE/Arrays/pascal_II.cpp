// https://leetcode.com/problems/pascals-triangle-ii/description/
// M1 : brute force TC : O(r*c) , SC : O(1)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getElement(int r,int c){
        long long res = 1;
        for(int i = 0; i < c; i++){
            res = res * (r-i);
            res = res / (i+1);
        }
        return res;
    }
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        ans.push_back(1);
        for(int c = 1; c < rowIndex+1; c++){
            int res = getElement(rowIndex,c);
            ans.push_back(res);
        }
        return ans;
    }
};

// M2 Optimal : TC : O(r) , SC : O(1)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
         vector<int>ans;
         long long res = 1;
         ans.push_back(1);
        for(int i = 1; i <= rowIndex; i++){
            res = res * (rowIndex - i+1);
            res = res / i;
            ans.push_back(res);
        }
        return ans;
    }
};