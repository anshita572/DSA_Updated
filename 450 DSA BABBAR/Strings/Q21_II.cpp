//https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1

//acc to ques ,swapping should be adjacent only
//TC:O(n) SC:O(1)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
       int count=0;
       int ans=0;
       for(int i=0;i<S.length();i++)
       {
           if(S[i]=='[')
           {count++;}
           else
           {count--;
               if(count<0)
               {ans=ans-count;}
           }
       }
       return ans;
    }
};