//https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//Brute force:TC :O(n^2)
class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
       int count=0; //count represents window size i.e. total no of numbers that 
       //need to stay together
       int ans=INT_MAX;
       for(int i=0;i<n;i++)
       {if (arr[i]<=k)
           {count++;}
       }
       //travelling each subarray,finding swapCount and returning minimum swapCount
       for(int i=0;i<n-count+1;i++)
       {
           int swapCount=0;
           for(int j=i;j<i+count;j++)
           {
               if(arr[j]>k)
               {swapCount++;}
           }
           ans=min(ans,swapCount);
       }
       return ans;
    }
};
//Optimised : TC:O(n)
class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
       int count=0; //count represents window size i.e. total no of numbers that 
       //need to stay together
        for(int i=0;i<n;i++)
       {if (arr[i]<=k)
           {count++;}
       }
       int swapCount=0;
       //traveresing the 1st window
       for(int i=0;i<count;i++)
       {
           if(arr[i]>k)
           {swapCount++;}
       }
       int ans=swapCount;//storing 1st swapCount
       //traversing remaining windows
       for(int i=0,j=count;j<n;i++,j++)
       {
           if(arr[i]>k)
           {swapCount--;}
           if(arr[j]>k)
           {swapCount++;}
          ans=min(ans,swapCount);
       }
      return ans;
    }
};