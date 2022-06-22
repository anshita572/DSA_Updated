#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{/* // Just for understanding
for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;*/
    if (n == 0 || n == 1)//base case (already sorted)
    {
        return;
    }
    //solving 1 case
    for (int i = 0; i < n - 1; i++) //n-1 as if i<n,then i+1 bahar ho jayega size of array se
    {  if(arr[i]>arr[i+1])
       { swap(arr[i], arr[i + 1]);}
    }
    bubbleSort(arr, n - 1);//recursive call
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
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}