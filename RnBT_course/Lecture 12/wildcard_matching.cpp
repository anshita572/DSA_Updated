//https://leetcode.com/problems/wildcard-matching/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool solve(string s, string p,int s_len,int p_len)
    {
        //3 base cases
        if(s_len==0 && p_len==0)  //dono strings finish i.e sb match krte krte end tak pahunch gye
        {return true;}
        if(s_len>0 && p_len==0) //s is remaining but pattern p hi finish ho gya
        {return false;}
        if(s_len==0 && p_len>0) //s is finished but pattern p is remaining
            //return true only p has '*' else false
        {
            for(int i=p_len-1;i>=0;i--)
            {if(p[i]!='*')
            {return false;}
            }
            return true;
        }
        if(s[s_len-1]==p[p_len-1] || p[p_len-1]=='?')
        {return solve(s,p,s_len-1,p_len-1);}
        else if(p[p_len-1]=='*')
        {return solve(s,p,s_len,p_len-1) || solve(s,p,s_len-1,p_len);}
        //2 calls : one call to consider * as empty ,another call to consider call as *char and then do OR of them and return true/false accordingly
        else
        {return false;}
    }
    bool isMatch(string s, string p) {
       return solve(s,p,s.length(),p.length()); 
    }
};