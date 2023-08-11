// https://leetcode.com/problems/critical-connections-in-a-network/
// TC : O(V+E) , SC : O(V+E)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int node,int parent,vector<int>adj[],int vis[],int timer,
            int tin[],int low[],vector<vector<int>>&ans){
                vis[node] = 1;
                tin[node] = low[node] = timer;
                timer++;
                for(auto it : adj[node]){
                    if(it == parent){
                        continue;
                    }
                    if(!vis[it]){
                        dfs(it,node,adj,vis,timer,tin,low,ans);
                        low[node] = min(low[node], low[it]);
                        if(low[it] > tin[node]){
                            ans.push_back({it,node});
                        }
                    }
                    else // if visited
                    {
                       low[node] = min(low[node], low[it]); 
                    }
                }
            }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>>ans;
        int timer = 0;
        int vis[n];
        for(int i = 0; i < n; i++){
            vis[i] = 0;
        }
        int tin[n];  // time of insertion
        int low[n]; //  lowest possible time to reach
        dfs(0,-1,adj,vis,timer,tin,low,ans);
        return ans; 
    }
};