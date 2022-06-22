#include <iostream>
using namespace std;
int main()
{
    int arr[10] = {1, 3, 5,7,9};
    cout << "Address of first memory block of array is : " << arr << endl;
    cout << "Address of first memory block of array is : " << &arr[0] << endl;
    cout << "Value at 0th index : " << *arr << endl;
    cout <<"New value at 0th index : "<<*arr + 1 << endl;
    cout << "Value at 1st index : " << *(arr + 1) << endl;
    //arr is address of 0th index
    //so(arr+1)=(0+1)=1 i.e address of 1st index and
    //*(arr+1)-->value at 1st index
    cout << "Value at 2nd index : " << *(arr + 2) << endl;

    //Imp : arr[i] and i[arr] mean one and the same thing
      cout << "Value at 3rd index : " << 3[arr] << endl;
    cout<<"Size of array arr is : "<<sizeof(arr)<<endl;
    //(4*10=40)
    cout<<"Size of &arr is : "<<sizeof(&arr)<<endl;
    cout<<"Size of *arr is : "<<sizeof(*arr)<<endl;
    int*p=&arr[2];
    cout<<"Size of pointer p : "<<sizeof(p)<<endl;
    cout<<"Size of value at p : "<<sizeof(*p)<<endl;
    cout<<"Size of &p : "<<sizeof(&p)<<endl;
    cout<<"Pointer ka apna khud ka address : "<<&p<<endl;
    cout<<"Address of 1st index : "<<arr+1<<endl;
    cout<<"Address of 1st index : "<<&arr[1];
    // arr=arr+1;-->error (can't change address of 0th index)
    return 0;
}