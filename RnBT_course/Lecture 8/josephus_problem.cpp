//https://practice.geeksforgeeks.org/problems/josephus-problem/1

//Exactly same as leetcode circular game
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int solve(int n,int k)
    {
        if(n==1)
        {return 0;}
        return (solve(n-1,k)+k)%n;
    }
    int josephus(int n, int k)
    {
        int ans=solve(n,k)+1;
        return ans;
    }
};