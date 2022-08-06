#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void merge(int arr1[],int arr2[],int n)
{int arr3[2*n];
int i=0;
int j=0;
int k=0;
while(i<n && j<n)
{
    if(arr1[i]<arr2[j])
    {
        arr3[k++]=arr1[i++];
    }
    else
    {
        arr3[k++]=arr2[j++];
    }
    
}
while(i<n)
{arr3[k++]=arr1[i++];}
while(j<n)
{arr3[k++]=arr2[j++];} 
for(int i=0;i<2*n;i++)
{cout<<arr3[i]<<" ";}
cout<<endl; 
 cout<<(arr3[2*n / 2] + arr3[(2*n / 2) - 1]) / 2;  
}
int main(){
int arr1[5]={1,12,15,26,38};
int arr2[5]={2,13,17,30,45};
merge(arr1,arr2,5);



return 0;
}