#include <iostream>
using namespace std;
void display(int arr[],int size)  //just for understanding what is happening
{
    cout<<"Size of array : "<<size<<endl;
    for(int i=0; i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int getSum(int arr[], int size)
{   display(arr,size);
    //base case
    if (size == 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return arr[0];
    }
    int sum = arr[0] + arr[1]; //processing
    arr[1] = sum;
    int remainingPart = getSum(arr + 1, size - 1);//recursive call
    return remainingPart;
}

int main()
{

    int size;
    cout << "Enter the size of array" << endl;
    cin >> size;
    int arr[size];
    cout << "Enter the elements of array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Sum = " << getSum(arr, size);
    return 0;
}
/* OR
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
*/