//https://leetcode.com/problems/n-th-tribonacci-number/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//M1 : recursion (TLE)  TC : O(3^n)
class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
        {return 0;}
        if(n==1 || n==2)
        {return 1;}
        return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
};
//M2 : Iterative (TC :O(n))
class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
        {return 0;}
        if(n==1 || n==2)
        {return 1;}
        int a=0;
        int b=1;
        int c=1;
        int d;
        for(int i=3;i<=n;i++)
        {d=a+b+c;
        a=b;
        b=c;
        c=d;}
        return d;
    }
};