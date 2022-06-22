#include <iostream>
using namespace std;
void display(int arr[],int size)  //just for understanding what is happening
{
    cout<<"Size of array : "<<size<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
bool LinearSearch(int arr[], int size, int key)
{  display(arr,size);
    if (size == 0) // base case
    // We have reached the end of array and key was not found
    {
        return false;
    }
    if (arr[0] == key)
    {
        return true;
    }
    else // if(arr[0]!=key)
    {
        bool remainingPart = LinearSearch(arr + 1, size - 1, key);
        return remainingPart;
    }
}

int main()
{
    int n;
    cout << "Enter the size of array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "Enter the key" << endl;
    cin >> key;
    if (LinearSearch(arr, n, key))
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
    return 0;
}
