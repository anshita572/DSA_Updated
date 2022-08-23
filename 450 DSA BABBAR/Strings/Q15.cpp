//https://leetcode.com/problems/next-greater-element-iii/

//TC :O(n) SC:O(1)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nextGreaterElement(int num) {
        string s=to_string(num); //to_string converts num to string
        int n=s.length();
        int i,j;
        for(i=n-2;i>=0;i--)
        {
            if(s[i+1]>s[i])
            {break;}
        }
        if(i<0) //if no breakpoint found ,e.g 321
        {return -1;}
        for(j=n-1;j>=0;j--) //else if breakpoint found
        {
            if(s[j]>s[i])
            {break;}
        }
        swap(s[i],s[j]);
        reverse(s.begin()+i+1,s.end());
        long long ans=stol(s); //stol converts string to long int
         if(ans >INT_MAX || ans < INT_MIN)
        {return -1;}
        return ans;
        
    }
};