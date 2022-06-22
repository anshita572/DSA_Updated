// Tail recursion
// Print counting (n to 1)
#include <iostream>
using namespace std;
void printCounting(int n)
{
    if (n == 0) //base case
    {
        return;  
    }
    cout << n << endl; //processing
    printCounting(n - 1); //recursive relation
}
int main()
{
    int n;
    cout << "Enter a number" << endl;
    cin >> n;
    cout << endl;
    printCounting(n);
}
