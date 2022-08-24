//https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
//Brute force : TC :O(n) SC:O(1)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        int count=0; //counts no of mismatches or swaps required
        for(int i=0;i<s.length();i++)
        {char ch=s[i];
         if(ch=='[')
         {st.push(ch);}
         else //if(ch==']')
         {
             if(!st.empty())
             {st.pop();}
             else //if stack is empty and closing bracket is found
             {count++;}
         }
            
        }
        int ans=(count+1)/2; //+1 if count odd aaye toh adjust ho jaaye
        return ans;
    }
};
//Optimised : TC :O(n) SC:O(1)
class Solution {
public:
    int minSwaps(string s) {
        int count=0;
        for(int i=0;i<s.length();i++)
        {
         if(s[i]=='[')
         {count++;}
         else //if(ch==']')
         {if(count>0)
         {count--;}
         }
            
        }
        int ans=(count+1)/2;
        return ans;
    }
};