// https://leetcode.com/problems/number-of-provinces/description/
// TC - O(N*M) SC - O(N*M)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void bfs(int i, vector<int> adj[], vector<int>&vis){
        queue<int>q;
        vis[i]= 1;
        q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
           for(auto it : adj[node]){
               if(!vis[it]){
               q.push(it);
               vis[it] = 1;
             }
           }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<int> adj[n];
        vector<int>vis(n,0);
        int count = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i = 0; i < n; i++){
                if(!vis[i]){
                    count++;
                    bfs(i,adj,vis);
                }
        }
        return count;
    }
};