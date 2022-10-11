//TLE with recursion
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    long long countWays(int n, int k){
        long long int mod=1e9+7;
        if(n==1)
        {return k;}
        if(n==2)
        {return k*k;}
        int same=countWays(n-2,k)*(k-1);
        int different=countWays(n-1,k)*(k-1);
        int ans=same+different;
        return ans%mod;
    }
};