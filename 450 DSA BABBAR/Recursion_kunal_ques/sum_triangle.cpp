//https://practice.geeksforgeeks.org/problems/sum-triangle-for-given-array1
//TC : 
//SC : 
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void getSum(vector<long long>arr,vector<long long>&ans,int n)
{if(n==1)
    {return;}
    vector<long long>temp;
    for(int i=0;i<n-1;i++)
    {temp.push_back(arr[i]+arr[i+1]);}
    int size=temp.size();
    getSum(temp,ans,size);
    for(auto i:temp)
    {ans.push_back(i);}
}
vector<long long> getTriangle(int arr[], int n)
{   vector<long long>ans;
vector<long long>temp;
 for(int i=0;i<n;i++){
  temp.push_back(arr[i]);
  }
getSum(temp,ans,n);
for(int i=0;i<n;i++){
   ans.push_back(arr[i]);
  }
    return ans;
}