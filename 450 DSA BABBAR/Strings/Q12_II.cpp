//https://leetcode.com/problems/count-binary-substrings/
//Return all possible consecutive combinations of 0 and 1
//M1 : brute-force TC:O(n) SC:O(n)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.length();
        vector<int>v(n);//to store count of 0s and 1s
        int index=0;
        v[index]=1;//=>v[0]=1 i.e. 0th element ka count=1
        for(int i=1;i<n;i++)
        {if(s[i]!=s[i-1])
        {index++;
        v[index]=1;}
         else
         {v[index]++;}
            
        }
        int ans=0;
        for(int i=1;i<=index;i++)
        {ans+=min(v[i],v[i-1]);}
        return ans;
        
    }
};
//M2 : Optimised TC:O(n)  SC:O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
       int n=s.length();
        int ans=0; 
        int currCount=1;
        int prevCount=0;
        for(int i=1;i<n;i++)
        {
            if(s[i]!=s[i-1])
            {ans+=min(currCount,prevCount);
            prevCount=currCount;
            currCount=1;}
            else
            {currCount++;}
        }
        ans+=min(currCount,prevCount); //to include the last group
        return ans;
    }
};
