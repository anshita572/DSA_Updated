#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(int arr[],int size)
{if(size<1) //base case
{return;}
for(int i=0;i<size;i++)
{cout<<arr[i]<<" ";}
cout<<endl;
solve(arr,size/2);//recursive call
}
int main(){
int n=7;
int arr[n]={3,4,1,5,6,2,8};
solve(arr,n);
return 0;
}