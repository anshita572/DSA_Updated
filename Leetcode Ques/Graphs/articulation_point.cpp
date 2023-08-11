// https://practice.geeksforgeeks.org/problems/articulation-point-1/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=articulation-point
// TC : O(V+E) , SC : O(V+E)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int node,int parent,int timer,int vis[],int tin[],int low[],
    int marked[],vector<int>adj[]){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for(auto it : adj[node]){
            if(it == parent){
                continue;
            }
            if(!vis[it]){
                dfs(it,node,timer,vis,tin,low,marked,adj);
                low[node] = min(low[node], low[it]);
                if(low[it] >= tin[node] && parent != -1){
                    marked[node] = 1;
                }
                child++;
            }
            else // if not visited
            {
                low[node] = min(low[node], tin[it]);
            }
        }
        if(child > 1 && parent == -1){
                marked[node] = 1;
            }
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
       int timer = 0;
       int vis[V] = {0};
       int tin[V];
       int low[V];
       int marked[V]={0};
       vector<int>ans;
       // if there are more than 1 component in a graph ,that's why using for loop
       for(int i = 0; i < V; i++){
           if(!vis[i]){
               dfs(i,-1,timer,vis,tin,low,marked,adj);
           }
       }
       for(int i = 0; i < V; i++){
           if(marked[i] == 1){
              ans.push_back(i);
       }
       }
       
       if(ans.size() == 0){
           return {-1};
       }
       return ans;
    }
};