#include<iostream>
using namespace std;
void display(int arr[],int size)  //just for understanding what is happening
{
    cout<<"Size of array : "<<size<<endl;
    for(int i=0; i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int findSum(int arr[],int n)
{display(arr,n);
    if(n==0)
    {return 0;}
    if(n==1)
    {return arr[0];}
    int sum;
    sum=arr[0]+arr[1];
    arr[1]=sum;
 return findSum(arr+1,n-1);
 
 
}
int main(){
 int arr[4]={2,4,11,8};
 cout<<findSum(arr,4);
return 0;
}