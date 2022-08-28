#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void getIndex(int arr[],int index,int size,int target,vector<int>&ans)
{
    if(index==size)
    {return;}
    if(arr[index]==target)
    {ans.push_back(index);}
     getIndex(arr,index+1,size,target,ans);

}

int main(){
    int size=8;
int arr[size]={1,3,4,2,5,2,2,1};
int index;
int target=2;
vector<int>ans;
getIndex(arr,0,size,target,ans);
for(auto i:ans)
{cout<<i<<" ";}
return 0;
}