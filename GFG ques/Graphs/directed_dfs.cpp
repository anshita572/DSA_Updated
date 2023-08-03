// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// TC : O(V+E) , SC : O(V)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    
    bool detect(int V,vector<int> adj[],int vis[],int dfs_vis[]) 
    {  vis[V]=1;
       dfs_vis[V] = 1;
      for(auto i:adj[V]){
       if(!vis[i]){
          if(detect(i,adj,vis,dfs_vis)==true)
          {return true;}
         }  
         else if(dfs_vis[i]==1)
         {return true;}
      }
        dfs_vis[V] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V]={0};
        int dfs_vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i])
           { if(detect(i,adj,vis,dfs_vis))
            {return true;}
           }
        }
        return false;
    }
};