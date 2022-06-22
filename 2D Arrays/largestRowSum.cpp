#include<iostream>
using namespace std;
void largestRowSum(int arr[][3],int row,int col)
{  int maxi=INT_MIN;
   int rowIndex=-1;
    for(int row=0;row<3;row++)
{ int sum=0;
    for(int col=0; col<3;col++)
{
    sum=sum+arr[row][col];
}
  if(sum>maxi)
     {maxi=sum;
     rowIndex=row;}
}
  cout<<"Max sum is : "<<maxi<<" of "<<rowIndex<<"th row";
     
}
int main(){
int arr[3][3];
cout<<"Enter the elements of matrix : "<<endl;
//inputing the matrix (row wise)
for(int row=0;row<3;row++)
{
    for(int col=0;col<3;col++)
    {
        cin>>arr[row][col];
    }
}
//printing the matrix
for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        {
            cout<<arr[row][col]<<" ";
            
        }
        cout<<endl;
    }
    largestRowSum(arr,3,3);
return 0;
}