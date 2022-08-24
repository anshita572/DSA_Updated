//https://leetcode.com/problems/valid-parentheses/
//TC : O(n)  SC:O(n)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if((ch=='(')||(ch=='{')||(ch=='['))
            {st.push(ch);}
            else //if ch == closing brackets
            {
                if(!st.empty())
                {
                    char top=st.top();
                    if((top=='(' && ch==')')||(top=='{' && ch=='}')||(top=='[' && ch==']'))
                    {st.pop();}
                    else
                    {return false;}
                }
                else //if(st.empty())
                {return false;}
            }
        }
        if(st.empty())
        {return true;}
        else
        {return false;}
    }
};