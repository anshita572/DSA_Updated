// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// TC : O(V+E) , SC : O(V)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int V, vector<int> adj[], int arr[], vector<int>&ans){
        arr[V] = 1;
        ans.push_back(V);
        for(auto i: adj[V]){
            if(!arr[i])
            {dfs(i,adj,arr,ans);}
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       vector<int>ans;
       int arr[V] = {0}; // visited array
       int startNode=0;
       dfs(startNode,adj,arr,ans);
       return ans;
    }
};