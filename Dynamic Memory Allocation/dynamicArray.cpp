#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of array : "<<endl;
    cin>>n;
int *arr=new int[n];  //creating array dynamically
cout<<"Enter the elements of array : "<<endl;
for(int i=0;i<n;i++)
{cin>>arr[i];}
for(int i=0;i<n;i++)
{
    cout<<arr[i]<<" ";
}
delete []arr;  //releasing memory
return 0;
}