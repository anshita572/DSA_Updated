//Merge Sort
//Time Complexity :  O(nlogn)
//Space Compelxity : O(n)

//Method 2 : Creating a new array and copying the values

#include<iostream>
using namespace std;
void merge(int arr[],int start,int end)
{   
//merging and sorting the 2 subarrays
int mid=start+(end-start)/2;
int i=0;        //i : index for subArray1
int j=mid+1;    //j : index for subArray2
int k=0;    //k : index for arr i.e. which is our main array
int tempArr[k];
while(i<=mid && j<=end)
{if(arr[i]<=arr[j])
{
    tempArr[k++]=arr[i++];
}
else       //if(subArray2[j]<subArray1[i])
{
    tempArr[k++]=arr[j++];
}
}
if(i>mid)//subArray1 is finished but some elements of 
//subArray2 are still remaining,so copy those elements of
//subArray2 in arr
{
    while(j<=end)
    {
      tempArr[k++]=arr[j++];
    }
}
else      //(j>n2)
//subArray2 is finished but some elements of 
//subArray1 are still remaining,so copy those elements of
//subArray1 in arr
{
    while(i<=mid)
    {
      tempArr[k++]=arr[i++];
    }
}
for(int k=start;k<=end;k++)
{
arr[k]=tempArr[k];
}
}

void mergeSort(int arr[],int start,int end)
{//base case
    if(start>=end)
    {return;}
int mid=start+(end-start)/2;
    
    //else (start,end)
    mergeSort(arr,start,mid);//recursive call
    mergeSort(arr,mid+1,end);//recursive call
    merge(arr,start,end);//calling merge function
}
int main(){
int n;
cout<<"Enter the size of array"<<endl;
cin>>n;
int arr[n];
cout<<"Enter the elements of array"<<endl;
for(int i=0;i<n;i++)
{ 
 cin>>arr[i];
}
mergeSort(arr,0,n-1);
for(int i=0;i<n;i++)
{ 
 cout<<arr[i]<<" ";
}
cout<<endl;
return 0;
}