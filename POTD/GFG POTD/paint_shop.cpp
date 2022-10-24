//https://practice.geeksforgeeks.org/problems/earthquake-and-the-paint-shop4518/1
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
struct alphanumeric {
    string name;
    int count;
};
class Solution {
  public:
    vector<alphanumeric> sortedStrings(int N, vector<string> A) {
       map<string,int>mp;
       for(int i=0;i<N;i++)
       {
           mp[A[i]]++;
       }
       vector<alphanumeric>ans;
     for(auto it:mp)
     {ans.push_back({it.first,it.second});}
     return ans;
    }
};