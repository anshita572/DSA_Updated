//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX;
        int profit=0; //overall profit
        int temp_profit=0; //profit if sold now
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            mini=min(prices[i],mini);
            temp_profit=prices[i]-mini;
            if(temp_profit > profit)
            {profit=temp_profit;}
        }
       
        return profit;
    }
};