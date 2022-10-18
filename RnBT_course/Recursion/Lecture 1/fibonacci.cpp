// fibonacci series : 0,1,1,2,3,5,8,13...
//TC : O(2^n)
//SC : O(n)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int fibonacci(int n)
{ // base case
    if (n == 0)
    {
        return 0;
    }
    if (n == 1 || n == 2)
    {
        return 1;
    }
    //recursive relation
    int ans = fibonacci(n - 1) + fibonacci(n - 2);
    return ans;
}
int main()
{
    int n = 3;
    cout << n << "th term : " << fibonacci(n) << endl;
    return 0;
}