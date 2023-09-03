//https://leetcode.com/problems/is-subsequence/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
// Iterative : TC : O(n) SC:O(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        int count = 0;
        for(int i = 0; i < t.size(); i++){
            if(s[j] == t[i]){
                count++;
                j++;
            }
        }
        if(count == s.size()){
            return true;
        }
        return false;
    }
};
// Recursive : TC : O(n) SC:O(n)
class Solution {
public:
    void solve(string s, string t,int i,int j,int& count)
    {
        if(j==t.length())
        {return;}
        if(s[i]==t[j])
        {count++;
            solve(s,t,i+1,j+1,count);}
        else //if(s[i]!=t[j])
        {solve(s,t,i,j+1,count);}
    }
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        int count=0;
        solve(s,t,i,j,count);
        if(count==s.length())
        {return true;}
        else
        {return false;}
    }
};