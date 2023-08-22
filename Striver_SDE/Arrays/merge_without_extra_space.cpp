// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
// M1
// TC : O(min(n, m)) + O(n*logn) + O(m*logm) , SC : O(1)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { int i = n-1;
          int j = 0;
          while(i >= 0 && j < m){
              if(arr1[i] > arr2[j]){
                  swap(arr1[i],arr2[j]);
              }
              i--;
              j++;
          }
          sort(arr1,arr1+n);
          sort(arr2,arr2+m);
            
        } 
};

// M2 
// TC : O((n+m)*log(n+m)) , SC : O(1)
class Solution{
    private:
        void swapNum(long long arr1[], long long arr2[],int i,int j){
            if(arr1[i] > arr2[j]){
                swap(arr1[i],arr2[j]);
            }
        }
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { int len = n + m;
          int gap = (len / 2) + (len % 2);
          while(gap > 0){
              int left = 0;
              int right = gap + left;
              while (right < len){
                  if(left < n && right >= n){
                      swapNum(arr1,arr2,left,right-n);
                  }
                  else if(left >= n){
                      swapNum(arr2,arr2,left-n,right-n);
                  }
                  else{
                      swapNum(arr1,arr1,left,right);
                  }
                  left++;
                  right++;
              }
              if(gap == 1){
                  break;
              }
             gap = (gap / 2) + (gap % 2);
          }
            
        } 
};