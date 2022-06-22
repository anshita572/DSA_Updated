// Head recursion
// Print counting (1 to n)
#include <iostream>
using namespace std;
void printCounting(int n)
{
    if (n == 0) // base case
    {
        return;
    }
    printCounting(n - 1); // recursive relation
    cout << n << endl;    // processing
}
int main()
{
    int n;
    cout << "Enter a number" << endl;
    cin >> n;
    cout << endl;
    printCounting(n);
}
