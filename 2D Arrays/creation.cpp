#include<iostream>
using namespace std;

int main(){
//int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
//int arr[3][4]={{1,11,111,1111},{2,22,222,2222},{3,33,333,3333},{4,44,444,4444}};

int m,n;
cout<<"Enter the rows : "<<endl;
cin>>m;
cout<<"Enter the columns : "<<endl;
cin>>n;
int arr[m][n];
cout<<"Enter the elements of matrix : "<<endl;
//inputing the matrix (row wise)
for(int row=0;row<m;row++)
{
    for(int col=0;col<n;col++)
    {
        cin>>arr[row][col];
    }
}
//inputing the matrix (column wise)
/*for(int col=0;col<n;col++)
{
    for(int row=0;row<m;row++)
    {
        cin>>arr[row][col];
    }
}*/
//printing the matrix
for(int row=0;row<m;row++)
    {
        for(int col=0;col<n;col++)
        {
            cout<<arr[row][col]<<" ";
            
        }
        cout<<endl;
    }
return 0;
}