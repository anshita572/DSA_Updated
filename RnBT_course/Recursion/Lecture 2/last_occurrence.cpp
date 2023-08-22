#include<iostream>
#include <bits/stdc++.h>
using namespace std;
// M1
int getIndex(int arr[],int index,int size,int target)
{
    if(index<0)
    {return -1;}
    if(arr[index]==target)
    {return index;}
    return getIndex(arr,index-1,size,target);

}
// M2
int solve(int arr[],int i,int size,int tar,int ans){
 if(i == size){
    return ans;
 }
 if(arr[i] == tar){
    ans = i;
 }
return solve(arr,i+1,size,tar,ans);
}
int main(){
int size=8;
int arr[size]={1,3,4,2,5,2,2,1};
int index;
int target=2;
cout<<getIndex(arr,size-1,size,target)<<endl;
cout<<solve(arr,0,size,target,-1);
return 0;
}