#include <iostream>
using namespace std;
int main()
{
    int m;
    cout << "Enter number of elements in row 0 : " << endl;
    cin >> m;
    int *row0 = new int[m];
    cout << "Enter elements of row 0 : " << endl;
    int n;
    cout << "Enter number of elements in row 1 : " << endl;
    cin >> n;
    int *row1 = new int[n];
    cout << "Enter elements of row 1 : " << endl;
    int row;
    int **jaggedArray=new int*[row];
    
    return 0;
}