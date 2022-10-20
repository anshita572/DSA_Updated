//https://leetcode.com/problems/fibonacci-number/
// fibonacci series : 0,1,1,2,3,5,8,13...
//M1 : Recursion
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
//M2 : Iterative (TC : O(n)  SC : O(1))
class Solution {
public:
    int fib(int n) {
      if(n==0 || n==1)
      {return n;}
        int a=0;
        int b=1;
        int c;
        for(int i=1;i<n;i++)
        {c=a+b;
        a=b;
        b=c;}
        return c;
    }
};