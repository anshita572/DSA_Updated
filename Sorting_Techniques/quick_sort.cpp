//Quick Sort
//Space Compelxity : O(n)
//Time Complexity :
                   //1. Best case :  O(nlogn)
                  //2.Average case :  O(nlogn)
                //3. Worst case : O(n^2)
#include<iostream>
using namespace std;
int partition(int arr[],int start,int end)
{
    int pivot=arr[start]; //pivot is element at 0th index
    // i.e pivot is at 0th index (pivotIndex=0)
    int count=0;
    for(int i=start+1;i<=end;i++)
    {if(arr[i]<=pivot)
      {  count++;}
      }
    int pivotIndex=start+count;
    //swapping the pivot element i.e. at index 0 with 
   //element at pivotIndex
    swap(arr[pivotIndex],arr[start]);
//Now after swapping the pivot element,it is at it's right position
int i=start;
int j=end;
while(i<pivotIndex && j>pivotIndex)
{while(arr[i]<=pivot)   //pivot=arr[pivotIndex]
{
    i++;
}
while(arr[j]>pivot)
{
    j--;
}
if(i<pivotIndex && j>pivotIndex)
{swap(arr[i++],arr[j--]);
}
}

return pivotIndex;
}
void quickSort(int arr[],int start,int end)
{
    //base condition
    if(start>=end)
    {return;}
    int p=partition(arr,start,end);
    //Sorting the left part
    quickSort(arr,start,p-1); //recursive call
    //Sorting the right part
    quickSort(arr,p+1,end);  //recursive call
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
quickSort(arr,0,n-1);
for(int i=0;i<n;i++)
{
    cout<<arr[i]<<" ";
}
cout<<endl;
return 0;
}