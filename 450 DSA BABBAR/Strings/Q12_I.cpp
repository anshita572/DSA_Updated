//https://practice.geeksforgeeks.org/problems/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/1

//TC :O(n) SC:O(1)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubStr(string str){
        int n=str.length();
        int count0=0;
        int count1=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='0')
            {count0++;}
            else //if(str[i]=='1')
            {count1++;}
            if(count0==count1)
            {ans++;
            }
            
        }
        if(count0!=count1)
            {return -1;}
        return ans;
    }
};
