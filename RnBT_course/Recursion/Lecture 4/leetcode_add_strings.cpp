//https://leetcode.com/problems/add-strings/
//TC :O(n+m)   SC : O(n+m)   (n+m=length of num1,num2)
// When you subtract '0' from a character that represents a digit (0 to 9), you get the actual integer value that the character represents.This is necessary because characters are represented by their ASCII values, and subtracting '0' adjusts them to their actual integer values.
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(string num1, string num2,int i,int j,int carry,string &ans)
    {
        if(i<0 && j<0 && carry==0)
        {return;}
        int first=0;
        int second=0;
        if(i>=0)
        {  first=num1[i]-'0';}
        if(j>=0)
        {second=num2[j]-'0';}
        int sum=first+second+carry;
        int last_dig=sum % 10;
        carry=sum/10;
        solve(num1,num2,i-1,j-1,carry,ans);
        ans=ans+to_string(last_dig);
        

    }
    string addStrings(string num1, string num2) {
        int i=num1.length()-1;
        int j=num2.length()-1;
       string ans;
        solve(num1,num2,i,j,0,ans);
        
        
        return ans;
    }
};