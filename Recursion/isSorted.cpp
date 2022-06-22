// To check if array is sorted or not using recursion
#include <iostream>
using namespace std;
bool isSorted(int arr[], int size)
{
    // base case
    if (size == 0 || size == 1)
    {
        return true;
    }

    if (arr[0] > arr[1])
    {
        return false;
    }
    else // if(arr[0]<arr[1])
    {
        bool remainingPart = isSorted(arr + 1, size - 1);
        return remainingPart;
    }
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
    if (isSorted(arr, size))
    {
        cout << "Array is sorted" << endl;
    }
    else
    {
        cout << "Array is not sorted" << endl;
    }
    return 0;
}