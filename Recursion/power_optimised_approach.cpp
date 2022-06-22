#include <iostream>
using namespace std;
int power(int x, int n) // x^n
{
    if (n == 0)   //base case
    {
        return 1;
    }
    int ans = power(x, n / 2); //recursive call
    if (n % 2 == 0)     //if n is even
    {
        return ans * ans;
    }
    else             //if n is odd
    {
        return x * ans * ans;
    }
}

int main()
{
    int x, n;
    cout << "Enter the number" << endl;
    cin >> x;
    cout << "Enter the power" << endl;
    cin >> n;
    cout << power(x, n) << endl;
    return 0;
}
