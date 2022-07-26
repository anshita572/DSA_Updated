//https://practice.geeksforgeeks.org/problems/three-way-partitioning/1
//Brute Force 
//TC:O(nlogn) SC:O(1)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& array,int a, int b)
    {
       sort(array.begin(),array.end());
       int i=0;
       int n=array.size();
       while(i<n)
       {
           if(array[i]<a)
           {i++;}
           if(array[i]>=a && array[i]<=b)
           {i++;}
           if(array[i]>b)
           {i++;}
       }
    }
};
// Optimal : Using DNF sort
//TC :O(n)
//SC:O(n)
class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& array,int a, int b)
    {
       int n=array.size();
       int low=0;
       int mid=0;
       int high=n-1;
       while(mid<=high)
       {
           if(array[mid]<a)
        {swap(array[low],array[mid]);
        array[low++];
         array[mid++];
        }
          else if(array[mid]>=a && array[mid]<=b)
        {
         array[mid++];
        }
          else //if(arr[mid]>b)
        {swap(array[mid],array[high]);
        array[high--];
        }
       }
    }

};