//https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1

//TC :O(N^2)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> factorial(int N){
        vector<int>ans;
        ans.push_back(1);
       
        for(int i=2;i<=N;i++)
        {  int carry=0;
            for(int j=0;j<ans.size();j++)
            {
                int product=ans[j]*i+carry;
                carry=product/10;
                ans[j]=product%10;
            }
        
        while(carry!=0)
        {
            ans.push_back(carry%10);
            carry=carry/10;
           
        }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};