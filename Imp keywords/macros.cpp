#include <iostream>
using namespace std;
#define pi 3.14
int main()
{
    int r = 5;
    // pi=pi+2; //-->error (can't update micro)
    double area = pi * r * r;
    cout << area << endl;
    return 0;
}