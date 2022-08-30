//Binary Search using Recursion
#include<iostream>
using namespace std;

int BinarySearch(int arr[],int start,int end,int key)
{
    
    if(end>=start)
    {
    int mid=start+(end-start)/2;
    if(arr[mid]==key)
    {return mid;}
    else if(arr[mid]>key) 
    {return BinarySearch(arr,start,mid-1,key);}
    else    //if(arr[mid]<key)
    {return BinarySearch(arr,mid+1,end,key);}
}
return -1;
}
int main(){
int n,key;
cout<<"Enter the size of array"<<endl;
cin>>n;
int start=0;
int end=n-1;
int arr[n];
cout<<"Enter the elements of array"<<endl;
for(int i=0;i<n;i++)
{ 
 cin>>arr[i];
}
cout<<"Enter the key"<<endl;
cin>>key;
int result = BinarySearch(arr, 0, n - 1, key);
cout<<"Element is present at index : "<<result+1<<endl;
return 0;
}