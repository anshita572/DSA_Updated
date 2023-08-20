// print max subarray using kadane's algo , in case of tie print any subarray
// TC : O(n) , SC : O(1)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    
	    int sum = 0;
	    int maxi = INT_MIN;
	    int start = -1;
	    int end = -1;
	    int s = 0;
	    vector<int>ans;
	   for(int i = 0; i < n; i++){
	       if(sum == 0){
	           s = i;
	       }
	       sum += a[i];
	       if(sum > maxi){
	           maxi = sum;
	           start = s;
	           end = i;
	       }
	       if(sum < 0){
	           sum = 0;
	       }
	   }
	   for(int i = start; i <= end; i++){
	       ans.push_back(a[i]);
	   }
	   return ans;
	}
};