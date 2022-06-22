//https://bit.ly/3pvCTz9 
//Bubble Sort
//Space complexity : O(1)
//Time complexity : 1. Best case : O(n)
                  //2.Worst case : O(n^2)
                 //3.Average case : O(n^2)

#include<iostream>
using namespace std;
void bubbleSort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {  bool swapped=false;   //for optimisation
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {swap(arr[j],arr[j+1]);
            swapped =true;}  
        }
        if(swapped==false)  //already sorted
        {break;}
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
bubbleSort(arr,n);
for(int i=0;i<n;i++)
{ 
 cout<<arr[i]<<" ";
}
cout<<endl;
return 0;
}