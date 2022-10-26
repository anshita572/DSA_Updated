//https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

//Brute Force : TC : O(n)   SC :O(n) (extra space to store ans1 and ans2)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string ans1="";
        string ans2="";
        for(int i=0;i<word1.size();i++)
        {ans1+=word1[i];}
        for(int i=0;i<word2.size();i++)
        {ans2+=word2[i];}
        if(ans1==ans2)
        {return true;}
        else
        {return false;}
        
        
    }
};
//Optimized : TC:O(n)  SC:O(1)
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i=0,j=0;
        int m=0,n=0;
        while(i<word1.size() && j < word2.size())
        {
            if(word1[i][m]!=word2[j][n])
            {return false;}
            else
            {m++;
            n++;}
            if(m>=word1[i].size())
            {i++;
            m=0;}
             if(n>=word2[j].size())
            {j++;
            n=0;}
        }
        if(i==word1.size() && j==word2.size())
        {return true;}
        else
        {return false;}
    }
};
