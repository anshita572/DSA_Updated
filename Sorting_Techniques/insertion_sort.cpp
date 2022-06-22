//https://bit.ly/3EstWN7 
//Insertion Sort
//Adaptable and stable sorting technique
//Time complexity : 1. worst and average case: O(n^2)
                  //2.best case :O(n)
//Space complexity :O(1)
#include<iostream>
using namespace std;
void insertionSort(int arr[],int n)
{//1st or outer for loop for no. of rounds
    for(int i=1;i<n;i++)//Starting from i=1 as considering
                       //element at 0th index as sorted
   { int temp=arr[i];
    int j=i-1;
   for(;j>=0;j--)
    {
      if(arr[j]>temp)
      //shift
      {arr[j+1]=arr[j];}
      else
      {break;} //breaking or coming out of the inner for loop
    }
    arr[j+1]=temp;
   }
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
insertionSort(arr,n);
for(int i=0;i<n;i++)
{ 
 cout<<arr[i]<<" ";
}
cout<<endl;
return 0;
}