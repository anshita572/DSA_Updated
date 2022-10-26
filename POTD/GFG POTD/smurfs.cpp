//https://practice.geeksforgeeks.org/problems/the-smurfs4201/1
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//TC : O(n)   SC : O(1)
class Solution{
public:
//Sb observation ka khel h ! Try few test cases and you will understand !
// 1. if R,G,B all are even ,ans will be always 2
// 2.if R,G,B all are odd ,ans will be always 2
// 3. if all are of same color ,ans will always be n
// 4. else i.e. some are even ,some are odd ,ans will always be 1
    int findMin(int n, char a[]){
        int redCount=0;
        int greenCount=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]=='R')
            {redCount++;}
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]=='G')
            {greenCount++;}
        }
        int blueCount=n-(redCount+greenCount);
        if((redCount==0 && greenCount==0) || (greenCount==0 && blueCount==0)
    || (redCount==0 && blueCount==0))
    {return n;}
        if((redCount % 2==0 && greenCount % 2==0 && blueCount % 2==0 )||
        (redCount&1 && greenCount&1 && blueCount&1 ))
        {return 2;}
        else
        {return 1;}
    }
};