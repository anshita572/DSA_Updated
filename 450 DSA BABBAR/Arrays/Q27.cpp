//https://www.codingninjas.com/codestudio/problems/check-subset_762948?leftPanelTab=0
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
bool checkSubset(vector < int > & arr1, vector < int > & arr2, int n, int m) {
   unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {mp[arr1[i]]++;}
    for(int j=0;j<m;j++)
    {if(mp[arr2[j]]>0) //decreasing frequency by 1 so that duplicate elements in arr2 are not counted
    {mp[arr2[j]]--;}
    else
    {return false;}
        
    }
    return true;
    
}