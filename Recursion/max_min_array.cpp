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
int findMax(int arr[], int n)
{display(arr,n);
  int maxi = INT_MIN;
  if (n <= 0)
  {
    return maxi;
  }
  
  
  maxi = max(arr[0], maxi);
  cout<<maxi<<endl;
 return findMax(arr + 1, n - 1);
  //return maxi;
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
  cout << findMax(arr, size);
  return 0;
}