//https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1

//This approach is applicable for leetcode ques also
//TC :O(N)
//SC :O(N) extra space for 2 subarrays is used
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    //create two subarrays.one subarray consisiting of +ve numbers and other subarray
    //consisting of -ve numbers
	void rearrange(int arr[], int n) {
	    vector<int>positive,negative;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>=0)
	        {positive.push_back(arr[i]);}
	        else// if(arr[i]<0)
	        {negative.push_back(arr[i]);}
	    }
	    //merge both subaarays into arr
	    int i=0,j=0,k=0;
	    while(i<n)
	    {
	       
	        if(j<positive.size())
	        {
	            arr[i++]=positive[j++];
	        }
	          if(k<negative.size())
	        {
	            arr[i++]=negative[k++];
	        }
	        
	    }
	}
};