//https://leetcode.com/problems/longest-common-prefix/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//Brute Force : TC :O(nlogn) SC:O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int n=s.size();
        sort(s.begin(),s.end());
        string a=s[0];
        string b=s[n-1];
        string ans="";
        for(int i=0;i<a.length();i++)
        {
            if(a[i]==b[i])
            {ans+=a[i];}
            else
            {break;} //i.e not found ,return empty string
        }
        return ans;
    }
};
//Optimised : TC :O(n) SC :O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int n=s.size();
        string first=s[0];
        string ans="";
        for(int i=0;i<first.size();i++)
        {for(int j=1;j<n;j++)
        {
            if(s[0][i]!=s[j][i])
            {return ans;}
        }
        ans.push_back(s[0][i]);}
        return ans;
    }
};