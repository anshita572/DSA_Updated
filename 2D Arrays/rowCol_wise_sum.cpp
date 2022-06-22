#include<iostream>
using namespace std;
void rowSum(int arr[][3],int row,int col)
{for(int row=0;row<3;row++)
{ int sum=0;
    for(int col=0; col<3;col++)
{
    sum=sum+arr[row][col];
}
cout<<sum<<" ";
}
cout<<endl;
}
void colSum(int arr[][3],int row,int col)
{ for(int col=0; col<3;col++)
{ int sum=0;
    for(int row=0;row<3;row++)
{
    sum=sum+arr[row][col];
}
cout<<sum<<" ";
}
cout<<endl;
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
    rowSum(arr,3,3);
    colSum(arr,3,3);
return 0;
}