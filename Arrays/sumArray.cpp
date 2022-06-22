#include<iostream>
using namespace std;
int findSum(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
    }
    return sum;
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
   cout<<findSum(arr,n);
	
return 0;
}