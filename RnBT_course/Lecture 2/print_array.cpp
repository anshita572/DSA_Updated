#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//M1
// void print(int arr[],int index,int size)
// {
//     if(index==size)
//     {return;}
//     cout<<arr[index]<<" ";
//     print(arr,index+1,size);
// }

//M2
void print(int arr[],int size)
{
    if(size==0)
    {return;}
    cout<<arr[0]<<" ";
    print(arr+1,size-1);
}
int main(){
    int size=5;
//     int index=0;
int arr[size]={2,1,5,9,4};
// print(arr,index,size); //M1
print(arr,size); //M2
return 0;
}