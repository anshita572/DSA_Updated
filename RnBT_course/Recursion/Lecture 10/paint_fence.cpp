// https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1
//TLE with recursion((TC : 2^n))
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
// DP : Memoisation , TC : O(n), SC : O(n)
class Solution{
    public:
    long long mod = 1000000007;
    long long solve(int n, int k, vector<long long>&dp){
        if(n == 1){
            return k;
        }
        if(n == 2){
            return k*k;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int same = (solve(n-2,k,dp)*(k-1)) % mod;
        int diff = (solve(n-1,k,dp)*(k-1)) % mod;
        return dp[n] = (same + diff) % mod;
    }
    long long countWays(int n, int k){
        vector<long long>dp(n+1,-1);
        return solve(n,k,dp);
    }
};