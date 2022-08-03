//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

//TC :O(n)
//SC:O(1)
//There is no restriction on no. of transactions.Aim is to get maximum profit
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int i=0;
        int buy=0;
        int sell=0;
        int profit=0;
        while(i<n-1)
        {
            while(i<n-1 && prices[i+1]<=prices[i])//(future < present),so buy in future
            {i++;}
            buy=prices[i];
            while(i<n-1 && prices[i+1]>prices[i])//(future > present),so sell in future
                  {i++;}
                sell=prices[i];
                profit=profit+(sell-buy);
        }
        return profit;
    }
};