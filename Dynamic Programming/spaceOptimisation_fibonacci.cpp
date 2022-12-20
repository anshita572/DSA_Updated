#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//Bottom up (Tabulation)
int tabuSolve(int n)
{vector<int>dp(n+1,0);
dp[0]=0;
dp[1]=1;
for(int i=2;i<=n;i++)
{int ans=dp[i-1]+dp[i-2];
dp[i]=ans;
}
return dp[n];
}
//Space Optimisation
int solveSO(int n)
{
    int prev1=1;
    int prev2=0;
    int curr;
    for(int i=2;i<=n;i++)
    {
        curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return curr;
}
int main(){
int n=6;
cout<<n<<"th term : "<<solveSO(n);
return 0;
}