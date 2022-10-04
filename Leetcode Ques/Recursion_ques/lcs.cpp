//https://leetcode.com/problems/longest-common-subsequence/
//TLE with recursion ,optimized with DP
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int i,int j,string text1, string text2)
    {
        if(i==text1.size()|| j==text2.size())
        {
            return 0;
        }
        if(text1[i]==text2[j])
        {return 1+solve(i+1,j+1,text1,text2);}
        else
        {return max(solve(i+1,j,text1,text2),solve(i,j+1,text1,text2));}
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i=0;
        int j=0;
        return solve(i,j,text1,text2);
    }
};