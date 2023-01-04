//https://leetcode.com/problems/minimum-sideway-jumps/description/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
//     int solveTab(vector<int>& obstacles)
//     { int n=obstacles.size();
//         vector<vector<int>>dp(4,vector<int>(n,INT_MAX));
//     //analysing base case
//     for(int i=0;i<=3;i++)
//     {dp[i][n-1]=0;}
    
//     for(int currLane=1;currLane<=3;currLane++)
//     {for(int currPos=n-1;currPos>=0;currPos--)
//     { int ans=0;
//         if(obstacles[currPos+1] != currLane)
//     {ans=dp[currLane][currPos+1];}
//     else //sideways
//     {int mini = INT_MAX;
//     for(int i=1;i<=3;i++) //i represents lane
//     {if(i!= currLane && i!=obstacles[currPos]) //apni hi jagah pe same place pe jump nhi kr rhe && aage obstacle nhi h i pe
//     {mini=min(mini,1+dp[i][currPos]);}
//    }
//     ans=mini;
//     }
//        dp[currLane][currPos]=ans; 
//     }}
//     return min(dp[2][0],min(1+dp[1][0],1+dp[3][0]));
//     }
    int solve(vector<int>& obstacles,int currLane,int currPos, vector<vector<int>>&dp)
    {int destination = obstacles.size()-1;
    if(currPos == destination)
     {return 0;}
     if(dp[currLane][currPos]!=-1)
     {return dp[currLane][currPos];}
    //straight path
    if(obstacles[currPos+1] != currLane)
    {return dp[currLane][currPos]= solve(obstacles,currLane,currPos+1,dp);}
    else //sideways
    {int mini = INT_MAX;
    for(int i=1;i<=3;i++) //i represents lane
    {if(i!= currLane && i!=obstacles[currPos]) //apni hi jagah pe same place pe jump nhi kr rhe && aage obstacle nhi h i pe
    {mini=min(mini,1+solve(obstacles,i,currPos,dp));}
   }
    return dp[currLane][currPos]=mini;
    }
    }
    int minSideJumps(vector<int>& obstacles) {
      int currLane = 2;
      int currPos = 0;
      int n = obstacles.size();
      vector<vector<int>>dp(4,vector<int>(n,-1));
      return solve(obstacles,currLane,currPos,dp);  
    // return solveTab(obstacles);
    }
};