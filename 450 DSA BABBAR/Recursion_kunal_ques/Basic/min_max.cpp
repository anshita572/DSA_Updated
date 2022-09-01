//https://practice.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/0
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void getMax(long long a[],long long i, int n,long long &maxi)
{if(i==n)
{return;}
maxi=max(a[i],maxi);
getMax(a,i+1,n,maxi);
    
}
void getMin(long long a[],long long i, int n,long long &mini)
{if(i==n)
{return;}
mini=min(a[i],mini);
getMin(a,i+1,n,mini);
    
}
pair<long long, long long> getMinMax(long long a[], int n) {
    long long maxi=INT_MIN;
    long long mini=INT_MAX;
    long long i=0;
    getMax(a,i,n,maxi);
    i=0;
    getMin(a,i,n,mini);
    
    pair<long long,long long>ans;
    ans={mini,maxi};
    return ans;
}