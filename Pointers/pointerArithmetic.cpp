#include <iostream>
using namespace std;
int main()
{
    int a = 5;
    int *p = &a;
    cout << p << endl;
    cout << p + 1 << endl; //increase by 4 bytes(size of int)
    double b = 3.14;
    double *q = &b;
    cout << q << endl;
    cout << q + 1 << endl; //increase by 8 bytes(size of double)
    char c = 'h';
    char *r = &c;
    cout << r << endl;
    cout << r + 1 << endl; //increase by 1 byte(size of char)

    return 0;
}