//Binary Search
//Time Complexity : O(log n)
#include<iostream>
using namespace std;
int binarySearch(int arr[],int n,int key)
{
    int start=0;
    int end=n-1;
    
    while(start<=end)
    {int mid= start + (end-start)/2;
        if(arr[mid]==key)
        {return mid;}
        else if(key>arr[mid])
        {
            start=mid+1;
        }
        else //if(key<arr[mid])
        {
            end=mid-1;
        }
    }
    return -1;
}
int main(){
int n;
cout<<"Enter the size of array"<<endl;
cin>>n;
int arr[n];
cout<<"Enter the elements of array"<<endl;
for(int i=0;i<n;i++)
{ cin>>arr[i];
}
int key;
cout<<"Enter the key"<<endl;
cin>>key;
cout<<binarySearch(arr,n,key)<<endl;
return 0;
}