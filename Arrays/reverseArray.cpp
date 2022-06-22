#include<iostream>
using namespace std;
void reverse(int arr[],int n)
{
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
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
    reverse(arr,n);
    display(arr,n);
return 0;
}