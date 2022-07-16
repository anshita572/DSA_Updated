//https://www.codingninjas.com/codestudio/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void adjList(unordered_map<int,list<int>>&adj,vector<vector<int>> &edges)
{
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
         adj[u].push_back(v);
         //directed so no v.push_back(u)
    }
}
void topoSort_DFS(int node, vector<bool>&visited,unordered_map<int,list<int>>&adj,stack<int>&s)
{
    visited[node]=true;
    for(auto i:adj[node])
    {if(!visited[i])
    {
        topoSort_DFS(i,visited,adj,s);
    }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
   unordered_map<int,list<int>>adj;
    adjList(adj,edges);
    
    vector<bool>visited(v);
    stack<int>s;
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {topoSort_DFS(i,visited,adj,s);}
    }
    vector<int>ans;
    
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}