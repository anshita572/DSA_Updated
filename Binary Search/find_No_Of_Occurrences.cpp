// Find no. of Occurrences
// Naive approach:Simple counting,Time complexity :O(n
// Optimised solution :Using Binary Search
// Time complexity : O(log n)
#include <iostream>
using namespace std;
int firstOcc(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else // if(key<arr[mid])
        {
            e = mid - 1;
        }
    }
    return ans;
}
int lastOcc(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else // if(key<arr[mid])
        {
            e = mid - 1;
        }
    }
    return ans;
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
    int result1 = firstOcc(arr, n, key);
    int result2 = lastOcc(arr, n, key);
    if (result2 == -1 && result1 == -1)
    {
        cout << "Total no. of occurrences of " << key << " : 0 ";
    }
    else
    {
        int finalAns = result2 - result1 + 1;
        cout << "Total no. of occurrences of " << key << " : " << finalAns << endl;
    }
    return 0;
}