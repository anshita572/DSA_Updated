#include<iostream>
using namespace std;
void display(int arr[],int size,int start=0)
{
    for(int i=start;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={1,4,6,7,8};
    display(arr,5);
    cout<<endl;
    display(arr,5,2);

return 0;
}