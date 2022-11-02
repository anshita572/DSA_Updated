//https://leetcode.com/problems/word-break/
//TLE (will be optimized by DP)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool solve(string s,int index,set<string>st)
    {if(index==s.length())
    {return true;}
     string subString="";
     for(int i=index;i<s.length();i++)
     {subString.push_back(s[i]);
     if(st.count(subString))
     {bool ans=solve(s,i+1,st);
     if(ans)
     {return true;}}
     }
     return false;
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        for(auto it:wordDict)
        {st.insert(it);}
        bool ans=solve(s,0,st);
        return ans;
    }
};