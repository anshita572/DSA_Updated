//https://leetcode.com/problems/majority-element-ii/
//TC :O(n)
//SC:O(n)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//⌊ n/3 ⌋ : floor of n/3 like floor of 5.9=5
class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n=arr.size();
    unordered_map<int,int>m;
       int x=n/3;
       vector<int>ans;
       for(int i=0;i<n;i++)
       {m[arr[i]]++;}
       for(auto i:m)
       {
           if(i.second > x)
           {ans.push_back(i.first);}
       }
     
        return ans;
    }
};