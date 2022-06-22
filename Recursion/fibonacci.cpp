//Leetcode :509 Fibonacci Number
//https://leetcode.com/problems/fibonacci-number/
//Fibonacci Series : 0,1,1,2,3,5,8,13,21
//where acc to ques, 0 is 0th term,1 is 1st term,2 is 3rd term...so on
//if you want 0 to be 1st term ,then base case :
//if(n==1)return 0 and if(n==2)return 1
#include<iostream>
using namespace std;
int fibonacci(int n)  //nth term
{if(n==0)         //base case
{
    return 0;
}
else if (n==1)   //base case
{
    return 1;
}
else            //recursive call
{
int ans=fibonacci(n-1)+fibonacci(n-2);
return ans;
}
}
int main()
{
    int n;
    cout<<"Enter the term"<<endl;
    cin>>n;
    cout<<n<<"th term is : ";
    cout<<fibonacci(n);
}