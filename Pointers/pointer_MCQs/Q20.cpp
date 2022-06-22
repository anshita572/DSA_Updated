//Imp Note :If I comment out line 5 and line 6, then
// output=4900
#include <iostream>
using namespace std;
void update(int *p)
{
    int a = 70;
    p = &a;
    *p = (*p) * (*p);
}

int main()
{
    int a = 70;
    update(&a);
    cout << a << endl;

    return 0;
}
