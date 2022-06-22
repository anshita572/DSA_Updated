#include<iostream>
using namespace std;
int main(){
char arr[] = "abcde";
    char *p = &arr[0];
    cout << p << endl;
    cout << p[0] << endl;
    cout << p[2] << endl;
return 0;
}