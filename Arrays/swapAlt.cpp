#include<iostream>
using namespace std;
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void swapAlt(int arr[],int n)
{
    int i=0;
    int j=i+1;
    while(j<n)
    {
        swap(arr[i],arr[j]);
        i=i+2;
        j=j+2;
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
    swapAlt(arr,n);
    display(arr,n);
return 0;
}