//https://leetcode.com/problems/duplicate-zeros/description/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//M1-Brute Force : TC :O(n^2) SC : O(1)
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        for(int i=arr.size()-1;i>=0;i--)
        {
            if(arr[i]==0)
            {for(int j=arr.size()-1;j>i;j--)
            {arr[j]=arr[j-1];}
            }
        }
    }
};
//M2-Optimized : TC : O(n) SC : O(1)
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int len=arr.size();
        int count=0;
        for(int i=0;i<len;i++)
        {
            if(arr[i]==0)
            {count++;}
        }
        int new_len=len+count;
        for(int i=len-1,j=new_len-1;i>=0 && j>=0;i--,j--)
        {
            if(arr[i]!=0)
            {
                if(j<len)
                {arr[j]=arr[i];}
                
            }
            else //if(arr[i]==0)
            {
                if(j<len)
                {arr[j]=arr[i];}
                j--;
                if(j<len)
                {arr[j]=arr[i];}
            }
        }
    }
};