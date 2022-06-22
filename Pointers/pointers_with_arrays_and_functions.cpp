#include <iostream>
using namespace std;
int getSum(int arr[], int n)
//OR
//int getSum(int *arr, int n)
{   cout<<"Size of arr : "<<sizeof(arr)<<endl;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    cout << getSum(arr, 5) << endl;
    cout << getSum(arr+2, 3) << endl;
    //Sum of array from index 2 (i.e. element-->3)
    //size of array=3(3,4,5 (3 elements))
    return 0;
}