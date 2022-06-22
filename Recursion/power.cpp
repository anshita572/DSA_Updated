#include <iostream>
using namespace std;
int power(int x, int n)
{
    if (n == 0)   //base case
    {
        return 1;
    }
    return x * power(x, n - 1); //recursive relation
}
int main()
{
    int x;
    cout << "Enter the number" << endl;
    cin >> x;
    int n;
    cout << "Enter the power" << endl;
    cin >> n;
    cout << x << " to the power " << n << " = " << power(x, n) << endl;
}

