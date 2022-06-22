//Binary Search using Recursion
//Elements should be in sorted order
//Time complexity of binary search :O(log(n))
#include<iostream>
using namespace std;
//Optional(just to have an idea how things are going on)
void display(int arr[],int start,int end)
{ cout<<"Remaining array : ";
    for(int i=start;i<=end;i++)
    {cout<<arr[i]<<" ";}
    cout<<endl;
}
bool BinarySearch(int arr[],int start,int end,int key)
{   display(arr,start,end);
    if(start>end)
    {return false;}
    int mid=start+(end-start)/2;
    cout<<"Middle element = "<<arr[mid]<<endl;
    if(arr[mid]==key)
    {
        return true;
    }
    else if(arr[mid]<key)
    {
        bool remainingPart=BinarySearch(arr,mid+1,end,key);
        return remainingPart;
    }
    else //if(arr[mid]>key)
    {
        bool remainingPart=BinarySearch(arr,start,mid-1,key);
         return remainingPart;
    }
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
if(BinarySearch(arr,start,end,key))
{cout<<"Found"<<endl;}
else
{cout<<"Not Found"<<endl;}
return 0;
}
