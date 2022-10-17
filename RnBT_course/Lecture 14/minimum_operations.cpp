// C++ program for above approach
#include <bits/stdc++.h>
using namespace std;
 
// Recursive function to find minimum operation
// required to reduce A and B to 1
int solve(int a, int b)
{if(a==1 && b==1)
{return 0;}  //No operations required if already 1,1
if(a%b==0 && b%a==0)
{return 1;}
int ans1=1+solve(a-1,b);
int ans2=1+solve(a,b-1);
int ans3;
int ans4;
if(a%b==0)
{ ans3=1+solve(a/b,b);}
if(b%a==0)
{ ans4=1+solve(a,b/a);}
   int res1=min(ans1,ans2);
   int res2=min(ans3,ans4);
   return min(ans1,ans2);
}
 
// Driver Code
int main()
{
    int A = 13;
    int B = 5;
 
    cout << solve(A, B);
}