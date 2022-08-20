//https://leetcode.com/problems/longest-palindromic-substring/

//TC :O(n^2) SC:O(1)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int maxi=0;
        int start_index=0;
        for(int i=1;i<n;i++)
        {
            //odd length palindrome
            int low=i-1;
            int high=i+1;
            while(low>=0 && high<n && s[low]==s[high])
            {
                if(high-low+1 > maxi)
                {maxi=high-low+1;
                start_index=low;}
                low--;
                high++;
            }
             //even length palindrome
             low=i-1;
             high=i;
            while(low>=0 && high<n && s[low]==s[high])
            {
                if(high-low+1 > maxi)
                {maxi=high-low+1;
                 start_index=low;}
                low--;
                high++;
            }
        }
       
         
        if(maxi==0)
        {  s=s[0];
            return s;}
        return s.substr(start_index,maxi);
        
    }
};