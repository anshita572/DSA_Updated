//TC : O(nlogn)
//SC :O(n)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void merge(int arr[],int s,int mid,int e)
{
    int n1=mid-s+1;
    int n2=e-mid;
    int *first=new int[n1];
    int *second=new int[n2];
    int i=0;
    //copy values in first and second
    for(int index=s;index<=mid;index++)
    {first[i]=arr[index];
    i++;}
    int j=0;
    for(int index=mid+1;index<=e;index++)
    {second[j]=arr[index];
    j++;}
    //merge these 2 arrays into original array
    int originalArrayIndex=s;
    int index1=0;
    int index2=0;
    while(index1<n1 && index2<n2)
    {if(first[index1]<second[index2])
    {
        arr[originalArrayIndex]=first[index1];
        index1++;
        originalArrayIndex++;
    }
    else//if(first[index1]>=second[index2])
    {
        arr[originalArrayIndex]=second[index2];
        index2++;
        originalArrayIndex++;
    }
    }
    while(index1<n1)
    { arr[originalArrayIndex]=first[index1];
        index1++;
        originalArrayIndex++;
    }
    while(index2<n2)
    {arr[originalArrayIndex]=second[index2];
        index2++;
        originalArrayIndex++;}
 
}
void mergeSort(int arr[],int s,int e)
{if(s>=e)//base case
{return;}
int mid=s+(e-s)/2;
mergeSort(arr,s,mid);//left part
mergeSort(arr,mid+1,e);//right part
//merge sorted arrays
merge(arr,s,mid,e);
}
int main(){
int n=7;
int arr[n]={3,4,1,5,6,29,8};
mergeSort(arr,0,n-1);
for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
return 0;
}