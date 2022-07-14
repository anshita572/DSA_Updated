//https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include <bits/stdc++.h>
using namespace std;
void adjList(unordered_map<int,list<int>>&adj,vector<vector<int>> &edges)
{ for(int i=0;i<edges.size();i++)
{ int u=edges[i][0];
    int v=edges[i][1];
    adj[u].push_back(v);
    adj[v].push_back(u);
}
}
void dfs(unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj,
        int node,vector<int>&component)
{
    component.push_back(node);
    visited[node]=true;
    for(auto i:adj[node])
    {
        if(!visited[i])
        {dfs(visited,adj,i,component);}//recursive call
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{unordered_map<int,bool>visited;
 unordered_map<int,list<int>>adj;
 vector<vector<int>> ans;
 adjList(adj,edges);
    for(int i=0;i<V;i++)
    {if(visited[i]==false)
    {vector<int>component;
        dfs(visited,adj,i,component);
     ans.push_back(component);
    }}
    return ans;
}