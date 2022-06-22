//https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#
//TC : O(n)

#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
      sort(arr,arr+n);
        int difference=arr[n-1]-arr[0];
        int smallest=arr[0]+k; //sbme 'k' add krne k baad arr[0] will be the smallest
        int largest=arr[n-1]-k;//sbme 'k' subtract krne k baad arr[n-1] will be the largest
        int mini,maxi;
        for(int i=0;i<n-1;i++)
        {
            mini=min(smallest,arr[i+1]-k);
            maxi=max(largest,arr[i]+k);
            // if(mini < 0)
            // {continue;}
            difference=min(difference,(maxi-mini));
        }
        return difference;
    }
};