//https://leetcode.com/problems/count-and-say/
//TC : O(n^2)  SC :O(n)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        {return "1";}
        if(n==2)
        {return "11";}
        string s="11";
        for(int i=3;i<=n;i++)
        {
            s=s+'\0';
            string temp="";
            int count=1;
            for(int j=1;j<s.length();j++)
            {if(s[j]==s[j-1])
            {count++;}
            else //if(s[j]!=s[j-1])
            {temp+=to_string(count); //pehle element ka count
             temp+=s[j-1]; //and then element
            count=1;}
            }
             s=temp;
        }
        return s;
    }
};