// https://leetcode.com/problems/number-of-islands/description/
// TC - O(N*M) SC - O(N*M)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int i,int j, vector<vector<int>>&vis,  vector<vector<char>>& grid){
      if(i>=0 && i<grid.size() && i>=0 && j<grid[0].size() &&
         !vis[i][j] && grid[i][j]=='1'){
            vis[i][j] = 1;
            dfs(i-1,j,vis,grid);
            dfs(i+1,j,vis,grid);
            dfs(i,j-1,vis,grid);
            dfs(i,j+1,vis,grid);
        }
        
       
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        vector<vector<int>>vis(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return count;
    }
};