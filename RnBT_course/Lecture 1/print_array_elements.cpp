#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void print(int arr[],int index,int size)
{
    if(index==size)
    {return;}
    cout<<arr[index]<<" ";
    print(arr,index+1,size);
}
int main(){
    int size=5;
    int index=0;
int arr[size]={2,1,5,9,4};

print(arr,index,size);
return 0;
}