#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int printMax(int arr[],int index,int size)
{ if(index==size)
{return INT_MIN;}
int myAns=arr[index];
int recursionAns=printMax(arr,index+1,size);
return max(myAns,recursionAns);
}
int main(){
    int size=5;
    int index=0;
int arr[size]={2,1,5,9,4};
cout<<printMax(arr,index,size);
return 0;
}
