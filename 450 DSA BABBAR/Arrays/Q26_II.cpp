//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini1=INT_MAX;
        int mini2=INT_MAX;
        int profit1=0; 
        int profit2=0;
        int temp_profit1=0; 
        int temp_profit2=0;
        int netBuyPrice=0;
        int n=prices.size();
        for(int i=0;i<n;i++)
        { //for 1st transaction
            mini1=min(prices[i],mini1);
            temp_profit1=prices[i]-mini1;
            if(temp_profit1 > profit1)
            {profit1=temp_profit1;}
            netBuyPrice=prices[i]-profit1;//effective buying price (by deducting profit of previous transaction)
            
            //2nd transaction
            mini2=min(netBuyPrice,mini2);
            temp_profit2=prices[i]-mini2;
             if(temp_profit2 > profit2)
            {profit2=temp_profit2;}
        }
        return profit2;
    }
};