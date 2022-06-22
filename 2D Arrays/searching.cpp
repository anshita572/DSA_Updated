#include<iostream>
using namespace std;
bool isPresent(int arr[][3],int row,int col,int key)
{
for(int row=0;row<3;row++)
{
    for(int col=0;col<3;col++)
    {
        if(key==arr[row][col])
        {return true;}
    }
}
return false;
}
int main(){
int m,n;
cout<<"Enter the rows : "<<endl;
cin>>m;
cout<<"Enter the columns : "<<endl;
cin>>n;
int arr[3][3];
cout<<"Enter the elements of matrix : "<<endl;
//inputing the matrix (row wise)
for(int row=0;row<m;row++)
{
    for(int col=0;col<n;col++)
    {
        cin>>arr[row][col];
    }
}
//printing the matrix
for(int row=0;row<m;row++)
    {
        for(int col=0;col<n;col++)
        {
            cout<<arr[row][col]<<" ";
            
        }
        cout<<endl;
    }
    int key;
    cout<<"Enter the key :  ";
    cin>>key;
    if(isPresent(arr,3,3,key))
    {cout<<"Present";}
    else
    {cout<<"Not present";}
return 0;
}