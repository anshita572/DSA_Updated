#include<iostream>
#include <bits/stdc++.h>
using namespace std;
// int printMax(int arr[],int index,int size)
// { if(index==size)
// {return INT_MIN;}
// int myAns=arr[index];
// int recursionAns=printMax(arr,index+1,size);
// return max(myAns,recursionAns);
// }
void printMax(int arr[],int index,int size,int &maxi)
{if(index==size)
{return;}
    maxi=max(arr[index],maxi);
    printMax(arr,index+1,size,maxi);
}
int main(){
    int size=5;
    int index=0;
    int maxi=INT_MIN;
int arr[size]={2,1,5,9,4};
// cout<<printMax(arr,index,size);
printMax(arr,index,size,maxi);
cout<<maxi<<endl;
return 0;
}
