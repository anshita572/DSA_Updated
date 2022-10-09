//TC : O(log n) (same as iterative binary search)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
bool binarySearch(int arr[],int s,int e,int key)
{if(s>e)
{return false;}
int mid=s+(e-s)/2;
if(arr[mid]==key)
{return true;}
else if(arr[mid]<key)
{return binarySearch(arr,mid+1,e,key);}
else
{return binarySearch(arr,s,mid-1,key);}}
int main(){
int n=7;
int arr[n]={1,4,5,6,8,11,17};
int key=5;
bool ans=binarySearch(arr,0,n-1,key);
if(ans)
{cout<<"Key found"<<endl;}
else
{cout<<"Key not present"<<endl;}
return 0;
}