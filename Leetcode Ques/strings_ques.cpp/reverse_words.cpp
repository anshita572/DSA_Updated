//https://leetcode.com/problems/reverse-words-in-a-string/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        int i=n-1;
        string ans="";
        while(i>=0)
        {
            while(i>=0 && s[i]==' ') //if there are spaces in end ,do i--
            {i--;}
            int j=i;
            if(i<0)//to avoid including spaces in the beginning
            {break;}
            while(i>=0 && s[i]!=' ')
            {i--;}
            if(ans.empty())
            {ans=s.substr(i+1,j-i);}
            else //if some word is present in ans ,we need a space after it and then we will add this new word
            {ans+=" "+s.substr(i+1,j-i);}
        }
        return ans;
    }
};