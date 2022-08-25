//https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1
//TC:O(n)  SC:O(1)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int minFlips (string S)
{
   int count1=0;
   int count2=0;
   //even pos should have 0 and odd pos should have 1
   for(int i=0;i<S.length();i++)
   {
       if(i%2==0 && S[i]!='0')
       {count1++;}
       if(i%2==1 && S[i]!='1')
       {count1++;}
   }
   //odd pos should have 0 and even pos should have 1
    for(int i=0;i<S.length();i++)
   {
       if(i%2==1 && S[i]!='0')
       {count2++;}
      if(i%2==0 && S[i]!='1')
       {count2++;}
   }
   return min(count1,count2);
}