#include <iostream>
using namespace std;
inline int getMax(int a, int b)
{
    int result = (a > b) ? a : b;
    return result;
    // or
    // return (a > b) ? a : b
}
int main()
{
    int a = 6;
    int b = 9;
    cout << getMax(a, b);

    return 0;
}