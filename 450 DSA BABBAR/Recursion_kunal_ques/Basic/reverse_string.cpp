//https://leetcode.com/problems/reverse-string/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // void solve(vector<char>& s,int l,int h)
    // {
    //     if(l>=h)
    //     {return;}
    //     swap(s[l],s[h]);
    //     solve(s,l+1,h-1);
    // }
    // void reverseString(vector<char>& s) {
    //     solve(s,0,s.size()-1);
    // }
    void solve(string s ,string &ans,int i)
    {
        if(i==s.length())
        {return;}
        solve(s,ans,i+1);
        ans.push_back(s[i]);
    }
};