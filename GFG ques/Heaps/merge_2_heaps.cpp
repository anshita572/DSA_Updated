// https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
// TC : O(m+n) , SC : O(m+n)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void heapify(vector<int> &arr,int i,int n)
    {int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[largest]<arr[left])
    {largest=left;}
    if(right<n && arr[largest]<arr[right])
    {largest=right;}
    if(largest != i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,largest,n);
    }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        //merge
        vector<int>ans;
        for(auto i:a)
        {ans.push_back(i);}
        for(auto i:b)
        {ans.push_back(i);}
        int size=m+n;
        for(int i=size/2 -1;i>=0;i--)
        {heapify(ans,i,size);}
    
        return ans;
    }
};