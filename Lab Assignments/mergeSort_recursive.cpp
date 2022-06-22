//Merge Sort
#include<iostream>
using namespace std;
void merge(int arr[],int start,int end)
{   int mid=start+(end-start)/2;
    int n1=mid-start+1;  
    int n2=end-mid;     
    int *subArray1=new int[n1]; 
    int *subArray2=new int[n2];
int k=start;
for(int i=0;i<n1;i++)
{
    subArray1[i]=arr[k++];
}

 k=mid+1;
for(int j=0;j<n2;j++)
{
    subArray2[j]=arr[k++];
}

int i=0;     
int j=0;    
k=start;   
while(i<n1 && j<n2)
{if(subArray1[i]<subArray2[j])
{
    arr[k++]=subArray1[i++];
}
else       //if(subArray2[j]<subArray1[i])
{
    arr[k++]=subArray2[j++];
}
}
if(i>n1)
{
    while(j<n2)
    {
      arr[k++]=subArray2[j++];
    }
}
else      //(j>n2)

{
    while(i<n1)
    {
      arr[k++]=subArray1[i++];
    }
}
delete []subArray1;
delete []subArray2;
}

void mergeSort(int arr[],int start,int end)
{
    if(start>=end)
    {return;}
int mid=start+(end-start)/2;
    
   
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,end);
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