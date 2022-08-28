#include<iostream>
#include <bits/stdc++.h>
using namespace std;
// int getIndex(int arr[],int index,int size,int &target)
// {
//     if(index==size)
//     {return -1;}
//     if(arr[index]==target)
//     {return index;}
//     return getIndex(arr,index+1,size,target);

// }
int getIndex(int arr[],int index,int count,int size,int &target)
{
    if(count==size)
    {return -1;}
    if(arr[count]==target)
    {return index;}
    return getIndex(arr+1,index+1,count+1,size-1,target);

}
int main(){
    int size=8;
int arr[size]={1,3,4,2,5,2,2,1};
int index;
int target=2;
cout<<getIndex(arr,0,size,0,target);
return 0;
}