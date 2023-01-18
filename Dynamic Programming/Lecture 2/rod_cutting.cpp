//https://practice.geeksforgeeks.org/problems/cutted-segments1642/1
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int solveTab(int n,int x,int y,int z)
    {vector<int>dp(n+1,INT_MIN);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {if(i-x>=0)
        {dp[i]=max(dp[i],dp[i-x]+1);}
        if(i-y>=0)
        {dp[i]=max(dp[i],dp[i-y]+1);}
        if(i-z>=0)
        {dp[i]=max(dp[i],dp[i-z]+1);}
    }
    int ans=dp[n];
    return ans;
    }
    int solveMemo(int n,int x,int y,int z,vector<int>&dp)
    {if(n==0)
    {return 0;}
    if(n<0)
    {return INT_MIN;}
    if(dp[n]!=-1)
    {return dp[n];}
    int op1=solveMemo(n-x,x,y,z,dp);
     
    int op2=solveMemo(n-y,x,y,z,dp);
    
    int op3=solveMemo(n-z,x,y,z,dp);
    int ans=1+max(op1,max(op2,op3));
    dp[n]=ans;
    return ans;
    
        
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {vector<int>dp(n+1,-1);
        // int ans= solveMemo(n,x,y,z,dp);
        int ans= solveTab(n,x,y,z);
        if(ans<0)
        {ans=0;} //if not possible to cut ,return 0 according to question
        return ans;
    }
};
