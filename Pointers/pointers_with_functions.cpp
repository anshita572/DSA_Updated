//Imp note : address has not been updated in main
//Address has been updated inside the function
//value has been updated in main as well
#include <iostream>
using namespace std;
void display(int *p)
{
    cout << *p << endl;
}
void update_address(int *p)
{
    p = p + 1;
    cout << "Inside function address after update : " <<
     p << endl;
}
void update_value(int *p)
{
    *p = *p + 1;
}
int main()
{
    int n = 5;
    int *p = &n;
    display(p);
    cout << "Before update address : " << p << endl;
    update_address(p);
    cout << "After update address : " << p << endl;
    cout << "Before update value : " << *p << endl;
    update_value(p);
    cout << "After update value : " << *p << endl;
    return 0;
}
