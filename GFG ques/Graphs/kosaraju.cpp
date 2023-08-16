// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=strongly-connected-components-kosarajus-algo

// https://takeuforward.org/graph/strongly-connected-components-kosarajus-algorithm-g-54/
// TC: O(V+E) SC: O(V+E)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	void dfs(int node,int vis[],stack<int>&st,vector<vector<int>>& adj){
	    vis[node] = 1;
	    for(auto it : adj[node]){
	        if(!vis[it]){
	          dfs(it,vis,st,adj);
	        }
	    }
	    st.push(node);
	}
   	void dfs2(int node,int vis[],vector<vector<int>>& adj){
	    vis[node] = 1;
	    for(auto it : adj[node]){
	        if(!vis[it]){
	          dfs2(it,vis,adj);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int>st;
        int vis[V] = {0};
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
         vector<vector<int>>adjT(V);
         for(int i = 0; i < V; i++){
             vis[i] = 0;
             for(auto it : adj[i]){
                 // i -> it , after reverse : it -> i
                 adjT[it].push_back(i);
             }
         }
        int scc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                dfs2(node,vis,adjT);
                scc++;
            }
        }
        return scc;
    }
};
