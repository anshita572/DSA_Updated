// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1
// TC : O(n),SC:O(n)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long>s;
        vector<long long>ans(n);
	   for(int i=n-1;i>=0;i--)
	   {
	    while(!s.empty() && arr[i] >= s.top())
	    {s.pop();}
	    if(!s.empty())
	    {ans[i]=s.top();}
	    else
	    {ans[i]=-1;}
	    s.push(arr[i]);
    }
    return ans;
    }
};