//ClimbStair : https://bit.ly/32VA96H
#include<iostream>
using namespace std;
int ClimbStair(long long n)
{  //base case
    if(n<0)
    {return 0;}
   else if(n==0)
    {return 1;}
    else 
    //recursive call
    {
    int ans=ClimbStair(n-1)+ClimbStair(n-2);
    return ans;
    }
}
int main()
{
    int n;
    cout<<"Enter the stair you want to climb"<<endl;
    cin>>n;
    cout<<"No. of distinct ways to reach stair no. "<<n
    <<" : ";
    cout<<ClimbStair(n);
}