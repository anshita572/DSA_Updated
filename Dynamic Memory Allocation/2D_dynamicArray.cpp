#include <iostream>
using namespace std;
int main()
{
    int row, col;
    cout << "Enter the number of rows : " << endl;
    cin >> row;
    cout << "Enter the number of columns : " << endl;
    cin >> col;
    int **arr = new int *[row];
    cout << "Enter the elements of 2D array : " << endl;

    // creating 2D array dynamically
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }
    // Taking input
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    // Printing output
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    // releasing memory
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}