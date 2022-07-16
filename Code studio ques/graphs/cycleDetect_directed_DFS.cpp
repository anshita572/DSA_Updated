//https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void adjList(unordered_map<int,list<int>>&adj,vector < pair < int, int >> & edges)
{
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;
         adj[u].push_back(v);
         //directed so no v.push_back(u)
    }
}
bool detectCycleDFS( unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited,
    unordered_map<int,bool>&dfsCall,int node)
{
    visited[node]=true;
    dfsCall[node]=true;
    for(auto i:adj[node])
    {
        if(!visited[i])
        {bool detect=detectCycleDFS(adj,visited,dfsCall,i);
        if(detect)
        {return true;}
        }
        else if(visited[i]==true && dfsCall[i]==true)
        {return true;}
    }
    dfsCall[node]=false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
   unordered_map<int,list<int>>adj;
  adjList(adj,edges);
   unordered_map<int,bool>visited;
    unordered_map<int,bool>dfsCall;
    for(int i=0;i<n;i++)
    {if(!visited[i])
    {bool ans=detectCycleDFS(adj,visited,dfsCall,i);
    if(ans)
    {return true;}}
    }
    return false;
    
}