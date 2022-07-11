//https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include <bits/stdc++.h>
using namespace std;

void adjList(unordered_map<int,set<int>>&adj,vector<pair<int, int>> &edges)
{
    for(int i=0;i<edges.size();i++)
    {   int u=edges[i].first;
        int v=edges[i].second;
     adj[u].insert(v);
     adj[v].insert(u);
       
    }
}
void bfs(unordered_map<int,set<int>>&adj, 
unordered_map<int,bool>&visited,int node,vector<int>&ans)
{
    queue<int>q;
    q.push(node);
    visited[node]=true;
    while(!q.empty())
    {
        int frontNode=q.front();
        q.pop();
        //store frontNode into ans
        ans.push_back(frontNode);
        //traverse all neighbours of frontNode
        for(auto i:adj[frontNode])
        {
        if(visited[i]==false)
        {  q.push(i);
            visited[i]=true;
            
        }
        }
    }
    
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{ unordered_map<int,set<int>>adj;
 unordered_map<int,bool>visited;
 vector<int>ans;
    adjList(adj,edges);
 for(int i=0;i<vertex;i++)
 {
     if(visited[i]==false)
     { bfs(adj,visited,i,ans);}
 }
return ans;
}