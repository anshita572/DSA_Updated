// https://practice.geeksforgeeks.org/problems/topological-sort/1
// TC : O(V+E) , SC : O(V)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
	public:
    void topo_dfs(int node, vector<int> adj[],int vis[],stack<int>&st)
    {
        vis[node] = 1;
        for(auto i:adj[node]){
            if(!vis[i])
            {topo_dfs(i,adj,vis,st);}
        }
        st.push(node);
    }
	vector<int> topoSort(int V, vector<int> adj[]) 
	{  int vis[V] = {0};
	   stack<int>st;
	   vector<int>ans;
	   for(int i=0;i<V;i++){
	       if(!vis[i])
	       {topo_dfs(i,adj,vis,st);}
	   }
	   while(!st.empty()){
	       int top = st.top();
	       ans.push_back(top);
	       st.pop();
	       
	   }
	   return ans;
	}
};