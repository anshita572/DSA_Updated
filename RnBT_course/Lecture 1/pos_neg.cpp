#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void print(int n)
{
    if (n <= 0)
    {
        cout << n << " "; //0
        return; //after return,control goes to line 20 => 0 will return 1,-1 will return 2 so on
    }
    cout << -n << " "; //-5 -4 -3 -2 -1
    print(n - 1);
    cout << n << " ";
}
int main()
{
    int n;
    n = 5;
    print(n);
    return 0;
}