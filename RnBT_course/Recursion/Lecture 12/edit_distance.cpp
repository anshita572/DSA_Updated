//https://leetcode.com/problems/edit-distance/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(string s1,string s2,int i,int j)
    {
        //base case
        if(i>=s1.length())
        {return s2.length()-j;}//this number of operations will be added
        if(j>=s2.length())
        {return s1.length()-i;}
        if(s1[i]==s2[j]) //match
        {return 0+solve(s1,s2,i+1,j+1);}//no need of any operation ,check next char
        else //not match
        {int insertAns=1+solve(s1,s2,i,j+1);
        int deleteAns=1+solve(s1,s2,i+1,j);
        int replaceAns=1+solve(s1,s2,i+1,j+1);
         int ans=min(insertAns,min(deleteAns,replaceAns));
        return ans;
        }
        
    }
    int minDistance(string word1, string word2) {
        int ans=solve(word1,word2,0,0);
        return ans;
    }
};