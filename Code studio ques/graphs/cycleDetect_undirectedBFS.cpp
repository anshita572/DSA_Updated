//https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include <bits/stdc++.h>
using namespace std;
void adjList(unordered_map<int,list<int>>&adj,
            vector<vector<int>>& edges)
{
    for(int i=0;i<edges.size();i++)
    {   int u=edges[i][0];
        int v=edges[i][1];
     adj[u].push_back(v);
     adj[v].push_back(u);
       
    }
}
bool isCyclicBFS(unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj,unordered_map<int,int>parent,int src)
{
    parent[src]=-1;
    queue<int>q;
    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
        int frontNode=q.front();
        q.pop();
        for(auto i :adj[frontNode])
        {
            if(visited[i]==true && 
            i!=parent[frontNode] )//i is not parent of frontNode
            {return true;}
            else if(visited[i]==false)
            {
                q.push(i);
                visited[i]=true;
                parent[i]=frontNode;
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{unordered_map<int,list<int>>adj;
    adjList(adj,edges);
 unordered_map<int,bool>visited;
 unordered_map<int,int>parent;
    for(int i=0;i<n;i++)
    {if(visited[i]==false)
    {bool ans=isCyclicBFS(visited,adj,parent,i);
    
    if(ans==true)
    {return "Yes";}
    }
   }
    return "No";
}
