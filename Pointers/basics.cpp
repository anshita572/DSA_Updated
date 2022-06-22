#include <iostream>
using namespace std;
int main()
{
    int num = 5;
    cout << "Value is : " << num << endl;
    cout << "Address is : " << &num << endl;

    int *ptr = &num;
    cout << "Value is : " << *ptr << endl;
    cout << "Address is : " << ptr << endl;
    //cout<<sizeof(ptr);//size of pointer is 8
    (*ptr)++;
    cout << "Value is : " << num << endl;
    //Copying a pointer
    int *q=ptr;
    cout<<*q<<" <-> "<<*ptr<<endl;
    cout<<q<<" <-> "<<ptr<<endl;
    return 0;
}