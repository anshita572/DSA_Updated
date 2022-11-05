//https://leetcode.com/problems/unique-number-of-occurrences/description/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++)
        {mp[arr[i]]++;}
        unordered_set<int>s;
        for(auto i : mp)
        {if(s.find(i.second)!=s.end())
        {return false;}
        else
        {s.insert(i.second);}
        }
        return true;
    }
};