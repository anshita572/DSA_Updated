#include <iostream>
using namespace std;
int main()
{
    char ch[6] = "pqrst"; //size-->5-->error,one size extra for null charcater is needed
    cout << ch << endl;
    char *c = &ch[0];
    cout << c << endl;
    char temp = 'k';
    char *p = &temp;
    cout << p << endl;

    return 0;
}