// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
// TC : O(E*logE) , SC : O(V+E)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Disjoint{
   
        vector<int>parent;
        vector<int>size;
     public:
        Disjoint(int n){
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i = 0; i <= n; i++){
                parent[i] = i;
            }
        }
        int findUpar(int node){         //find ultimate parent
                if(parent[node] == node){
                    return node;
                }
                return parent[node] = findUpar(parent[node]); // path compression

                // without path compression
                //  return node = findUpar(parent[node]);
        }   
        void unionBysize(int u,int v){
            int ulp_u = findUpar(u);  //ultimate parent of u 
            int ulp_v = findUpar(v);
            if(ulp_u == ulp_v){
                return;
            }
            if(size[ulp_u] > size[ulp_v]){
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
            else // if(size[ulp_u] <= size[ulp_v])
            {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            
        }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    { vector<pair<int,pair<int,int>>>edges;
      for(int i = 0; i < V; i++){
          for(auto it : adj[i]){
              int wt = it[1];
              int adjNode = it[0];
              int node = i;
              edges.push_back({wt,{node,adjNode}});
          }
      }
      sort(edges.begin(),edges.end());
      Disjoint ds(V);
      int sum = 0;
      for(auto it : edges){
          int wt = it.first;
          int u = it.second.first;
          int v = it.second.second;
          if(ds.findUpar(u) != ds.findUpar(v)){
              sum += wt;
              ds.unionBysize(u,v);
          }
      }
      return sum;
        
    }
};