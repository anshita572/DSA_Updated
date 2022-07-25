//https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    long long ans=INT_MAX;
    long long difference=0;
    
    sort(a.begin(),a.end());
    //n-m=total no. of windows possible in an array of size n
    for(long long i=0;i<=n-m;i++)
    {  long long j=m-1+i;
        difference=a[j]-a[i];
        ans=min(difference,ans);
    }
    return ans;
    }   
};