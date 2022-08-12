#include<iostream>
#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,int>a,pair<int,int>b)
{
    if(a.first<b.first)
    {return true;}
    if(a.first==b.first)
    {if(a.second>b.second)
    {return true;}}
    return false;
}
int main(){
    int n=4;
pair<int,int>arr[n]={{2,4},{5,3},{7,2},{5,9}};
//Sort according to first element in pair in ascending order and if that first element is equal, sort according to second element in descending order i.e. {{2,4},{5,9},{5,3},{7,2}}
sort(arr,arr+n,comp);
for(auto i:arr)
{
    cout<<"{"<<i.first<<","<<i.second<<"},";
}
return 0;
}