#include<iostream>
using namespace std;
int main(){
 int arr[6] = {11, 21, 31};
    int *p = arr;
    cout << p[2] << endl;
     //cout<<*p[2]<<endl; -->error
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<*(p+2)<<endl;
   
return 0;
}