//https://leetcode.com/problems/shuffle-string/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//Brute Force : TC :O(n^2)  SC:O(n)
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans="";
        int index=0;
        while(index < indices.size())
        {
        for(int i=0;i<indices.size();i++)
        {
           if(indices[i]==index)
           {ans.push_back(s[i]);
           break;}
        }
            index++;
        }
        return ans;
    }
};
//Optimised : TC :O(n)  SC :O(1)
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int i=0;
        while(i < indices.size())
        {
            if(i == indices[i])
            {i++;}
            else
            {swap(s[i],s[indices[i]]);
            swap(indices[i],indices[indices[i]]);}
        }
        return s;
    }
};