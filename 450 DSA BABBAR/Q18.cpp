//https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//TC :O(n)
//SC:O(n) as unordered map is used
class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
       unordered_map<int,int>m;
       int ans=0;
       for(int i=0;i<n;i++)
       {
           int b=k-arr[i]; //sum=a+b => b=sum-a
           if(m.count(b))  //if value of b is present in map
           {
               ans=ans+m[b]; //add in ans the frequency of b
           }
           m[arr[i]]++;  //add value of element and its frequency in map
       }
       return ans;
    }
    
};
