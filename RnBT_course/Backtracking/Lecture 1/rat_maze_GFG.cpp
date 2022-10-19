//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool isSafe(int x,int y,int n,vector<vector<int>> m,vector<vector<int>> visited)
    {
        if((x>=0 && x<=n-1) && (y>=0 && y<=n-1) && (m[x][y]!=0) &&(visited[x][y]!=1))
        {return true;}
        else
        {return false;}
    }
    void solve(vector<vector<int>>m,int n,int x,int y,
    vector<vector<int>>visited,string path,vector<string>&ans)
    {
        if(x==n-1 && y==n-1)//base case(If rat has reached destination,stop and return)
        {   ans.push_back(path);
            return;
        }
       
        //DOWN
        int new_x=x+1;
        int new_y=y;
        if(isSafe(new_x,new_y,n,m,visited))
        {    visited[x][y]=1;
            path.push_back('D');
            solve(m,n,new_x,new_y,visited,path,ans);
            //backtrack
             visited[x][y]=0; 
            path.pop_back();
        }
          //UP
         new_x=x-1;
         new_y=y;
        if(isSafe(new_x,new_y,n,m,visited))
        {   visited[x][y]=1;
            path.push_back('U');
            solve(m,n,new_x,new_y,visited,path,ans);
            
              visited[x][y]=0;
            path.pop_back();
        }
          //Left
         new_x=x;
         new_y=y-1;
        if(isSafe(new_x,new_y,n,m,visited))
        {   visited[x][y]=1;
            path.push_back('L');
            solve(m,n,new_x,new_y,visited,path,ans);
             visited[x][y]=0;
            path.pop_back();
        }
          //Right
        new_x=x;
         new_y=y+1;
        if(isSafe(new_x,new_y,n,m,visited))
        {   visited[x][y]=1;
            path.push_back('R');
            solve(m,n,new_x,new_y,visited,path,ans);
             visited[x][y]=0;
            path.pop_back();
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        int source_x=0;
        int source_y=0;
        if(m[source_x][source_y]==0)
        {return ans;}
        vector<vector<int>>visited=m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {visited[i][j]=0;}   //initialsing visited matrix with 0
        }
        string path="";
        solve(m,n,source_x,source_y,visited,path,ans);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};

    