//https://leetcode.com/problems/generate-parentheses/
//TC : O(4^n)  SC : O(4^n)
// Every level, you are making 2 decisions and the maximum height of the decision tree is 2^n since n is the number of pairs of "(" and ")". So therefore the Time and Space Complexity would be 2*(2^n) or 4^n.
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int currOpen,int currClose,int remOpen,
    int remClose,string &temp,vector<string>&ans)
    {
        //base case
        if(remOpen==0 && remClose==0)
        {ans.push_back(temp);
        return;}
        if(remOpen > 0)
        {
            temp.push_back('(');
            solve(currOpen+1,currClose,remOpen-1,remClose,temp,ans);
            temp.pop_back();//backtrack
        }
         if(remClose > 0  && currOpen > currClose)
        {
            temp.push_back(')');
            solve(currOpen,currClose+1,remOpen,remClose-1,temp,ans);
        temp.pop_back();//backtrack 
         }
        
    }
    vector<string> generateParenthesis(int n) {
         vector<string>ans;
        string temp="(";
        int currOpen=1;
        int currClose=0;
        int remOpen=n-1;
        int remClose=n;
        solve(currOpen,currClose,remOpen,remClose,temp,ans);
        return ans;
    }
};