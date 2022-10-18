#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//M1
// void print(int arr[],int index,int size)
// {
//     if(index==size)
//     {return;}
//     print(arr,index+1,size);
//     cout<<arr[index]<<" ";
// }
void print(int arr[],int index)
{if(index<0)
    {return;}
    cout<<arr[index]<<" ";
    print(arr,index-1);
}
int main(){
    int size=5;
    // int index=0;
    int index=size-1;
int arr[size]={2,1,5,9,4};
// print(arr,index,size); //M1
print(arr,index); //M2
return 0;
}