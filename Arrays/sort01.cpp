//Sort an array of 0's and 1's
//2-pointer approach
//Time Complexity : O(n)
#include<iostream>
using namespace std;
void sort(int arr[],int n)
{
    int i=0;
    int j=n-1;
    while(i<=j && j<n)
    {
        if(arr[i]==0)
        {i++;}
        if(arr[j]==1)
        {j--;}
        if(arr[i]==1 && arr[j]==0 && i<=j)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
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
    sort(arr,n);
    display(arr,n);
return 0;
}