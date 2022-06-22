#include<iostream>
using namespace std;
int getSum(int arr[],int size)
{
    if(size==0)
    {return 0;}
    if(size==1)
    {return arr[0];}
    else
    {int remainingPart=getSum(arr+1,size-1);
        int sum=arr[0]+remainingPart;
        
    return sum;
    
    }
}
void subArray(int arr[], int n)
{
    // Pick starting point
    for (int i=0; i <n; i++)
    {
        // Pick ending point
        for (int j=i; j<n; j++)
        {
            // Print subarray between current starting
            // and ending points
            for (int k=i; k<=j; k++)
            {}
               // cout << arr[k] << " ";
 
           // cout << endl;
        }
    }
   cout<<getSum(arr,n)<<" ";
}
int main(){
int arr[] = {-1,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
   // cout << "All Non-empty Subarrays\n";
    subArray(arr, n);
return 0;
}