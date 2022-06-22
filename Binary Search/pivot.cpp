//Find index of pivot element in a rotated sorted array
#include<iostream>
using namespace std;
int pivotIndex(int arr[],int n)
{
    int s=0;
    int e=n-1;
    while(s<e)
    {
        int mid=s+(e-s)/2;
        if(arr[mid]>=arr[0])
        {s=mid+1;}
        else //if(arr[mid]<arr[0])
        {e=mid;}
    }
    return s;    //or return e;
}
int main(){
int n;
cout<<"Enter the size of array"<<endl;
cin>>n;
int arr[n];
cout<<"Enter the elements of rotated sorted array"<<endl;
for(int i=0;i<n;i++)
{ cin>>arr[i];
}
cout<<"Index of pivot element : "<<pivotIndex(arr,n);
return 0;
}