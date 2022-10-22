//https://practice.geeksforgeeks.org/problems/filling-bucket0529/1
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//M1 : TLE TC :O(2^n)  SC:O(n)
class Solution {
  public:
    int fillingBucket(int N) {
        if(N==1)
        {return 1;}
        if(N==2)
        {return 2;}
        return fillingBucket(N-1)+ fillingBucket(N-2);
    }
};
//M2 TC :O(n)  SC:O(1)
class Solution {
  public:
    int fillingBucket(int N) {
         int M = 100000000;
        if(N==1)
        {return 1;}
        if(N==2)
        {return 2;}
        int a=1;
        int b=2;
        int c;
        for(int i=3;i<=N;i++)
        {c=(a+b)%M;
            a=b;
            b=c;
        }
        c=c%M;
        return c;
    }
};