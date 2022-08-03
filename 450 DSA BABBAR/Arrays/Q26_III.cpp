//https://practice.geeksforgeeks.org/problems/stock-buy-and-sell2615/0?company%5B%5D=D-E-Shaw&page=1&query=company%5B%5DD-E-Shawpage1

//Exactly same as Q26_I but here instead of calculating profit,we are calculating days by subtracting indices
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void stockBuySell(int price[], int n) {
    int i=0;
        int buy=0;
        int sell=0;
        vector<vector<int>>ans;
        while(i<n-1)
        {  vector<int>temp;
            while(i<n-1 && price[i+1]<=price[i])//(future < present),so buy in future
            {i++;}
            //imp if statement ,otherwise buy and sell index will be same
             if(i==n-1)
              break;
            buy=i;
            temp.push_back(buy);
            while(i<n-1 && price[i+1]>price[i])//(future > present),so sell in future
                  {i++;}
                sell=i;
                temp.push_back(sell);
                ans.push_back(temp);
              
        }
         if(ans.empty()){
       cout << "No Profit" << endl;
       return;
   }
    for (auto i:ans){
       cout << "("<< i[0] << " "<< i[1] << ") ";
   }
   cout << endl;
   return ;
}