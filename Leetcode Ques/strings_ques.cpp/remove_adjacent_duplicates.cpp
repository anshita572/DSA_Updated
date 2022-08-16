// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//M1 : TC:O(n) SC :O(1)
class Solution {
public:
    string removeDuplicates(string s) {
        int i=0;
        while(i<s.length())
        {if(s[i]==s[i+1])
        { s.erase(i,2);
            if(i>0)
            {i--;}
        }
         else {i++;}
        }
        return s;
        
    }
};
//M2 : TC :O(n) SC:O(1)
class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(ans.size()!=0)
            {
                if(ans[ans.size()-1]==s[i])
                {
                    ans.pop_back();
                }
                else
                {
                    ans.push_back(s[i]);
                }
            }
            else  //if(ans.size()==0)
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};