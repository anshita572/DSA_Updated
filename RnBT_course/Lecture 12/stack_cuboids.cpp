//https://leetcode.com/problems/maximum-height-by-stacking-cuboids/#:~:text=You%20can%20place%20the%2011x7,is%206%20*%2017%20%3D%20102.
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSafe(vector<vector<int>>& cuboids,int curr,int prev)
    {
        if(cuboids[curr][0]<=cuboids[prev][0] && cuboids[curr][1]<=cuboids[prev][1] && cuboids[curr][2]<=cuboids[prev][2])
        {return true;}
        return false;
    }
    int solve(vector<vector<int>>& cuboids,int n,int curr,int prev)
    {
        if(curr<0)//base case
        {return 0;}
        int pick=0;
        if(prev==-1 || isSafe(cuboids,curr,prev))
        {
          pick=cuboids[curr][2]+solve(cuboids,n,curr-1,curr);  
        }
        int notPick=solve(cuboids,n,curr-1,prev);
        return max(pick,notPick);
        
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        //sorting l,b,h of each cuboid
       for(int i=0;i<cuboids.size();i++)
       {
           sort(cuboids[i].begin(),cuboids[i].end());
       }
        //sort all cuboids according to first parameter(width)
        sort(cuboids.begin(),cuboids.end());//[i][0]
        int n=cuboids.size();
        int ans=solve(cuboids,n,n-1,-1);
        return ans;
    }
};