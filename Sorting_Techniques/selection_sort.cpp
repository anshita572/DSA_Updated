//https://bit.ly/3DrsGsv 
//Selection Sort
//Time complexity : O(n^2)
//Space complexity : O(1)
#include<iostream>
using namespace std;
void selectionSort(int arr[],int n)
{
    for(int i=0;i<n-1;i++) //this loop is for rounds/passes
    {//int minIndex=i;
        for(int j=i+1;j<n;j++)
        {
           // if(arr[j]<arr[minIndex])
           if(arr[j]<arr[i])
           { //minIndex=j;}   //updating minIndex
             swap (arr[i],arr[j]);}
            
        }
       // swap (arr[i],arr[minIndex]);
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
selectionSort(arr,n);
for(int i=0;i<n;i++)
{ 
 cout<<arr[i]<<" ";
}
cout<<endl;
return 0;
}
