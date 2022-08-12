#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//Sort the array in descending order
bool comp(int a,int b)
{
   if(a>=b)
   {return true;}
   else
   {return false;}
}
int main(){
int n=5;
int arr[n]={3,5,1,4,2};
sort(arr,arr+n,comp); //TC :O(n logn)
//OR
// sort(arr,arr+n,greater<int>());
for(int i=0;i<n;i++)
{cout<<arr[i]<<" ";}
return 0;
}