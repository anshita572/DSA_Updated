#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(int arr[],int s,int e)
{
    if(s>=e)
    {cout<<arr[s];
        return;}
    int mid=s+(e-s)/2;
    for(int i=0;i<=e;i++)
    {cout<<arr[i]<<" ";}
    cout<<endl;
    solve(arr,s,mid);
}
int main(){
int n=7;
int arr[n]={3,4,1,5,6,2,8};
solve(arr,0,n-1);
return 0;
}