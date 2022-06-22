#include <iostream>
using namespace std;
int main()
{
    int i = 6;
    int *p1 = &i;
    int **p2 = &p1; //Double pointer
    cout << "Address of i : " << p1 << endl;
    cout << "Address of p1 : " << &p1 << endl;
    cout << "Value of i : " << *p1 << endl;
    cout << "Address of p1 : " << p2 << endl;
    cout << "Address of p2 : " << &p2 << endl;
    cout << "Value of p1 (i.e the address of i) : " << *p2 << endl;
    cout << "value of i : " << **p2 << endl;
    return 0;
}