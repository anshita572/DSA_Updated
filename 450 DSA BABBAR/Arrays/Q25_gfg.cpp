//https://practice.geeksforgeeks.org/problems/count-element-occurences/0?category%5B%5D=Searching&page=1&query=category%5B%5DSearchingpage1

//TC :O(n)
//SC:O(n)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
       unordered_map<int,int>m;
       int x=n/k;
       int count=0;
       for(int i=0;i<n;i++)
       {m[arr[i]]++;}
       for(auto i:m)
       {
           if(i.second > x)
           {count++;}
       }
       return count;
       
    }
};