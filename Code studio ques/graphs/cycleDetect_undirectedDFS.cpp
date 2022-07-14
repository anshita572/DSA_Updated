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

bool isCyclicDFS(unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj,int parent,int src)
{ //parent[src]=-1;
    visited[src]=true;
    for(auto i:adj[src])
    {
        if(visited[i]==false)
        {bool ans=isCyclicDFS(visited,adj,src,i);
        //visited[i]=true;
        if(ans)
        {return true;}}
        else if( i!=parent)
        {return true;}
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{unordered_map<int,list<int>>adj;
    adjList(adj,edges);
 unordered_map<int,bool>visited;
//  unordered_map<int,int>parent;
 int parent;
    for(int i=0;i<n;i++)
    {if(visited[i]==false)
    {bool ans=isCyclicDFS(visited,adj,-1,i);
    
    if(ans==true)
    {return "Yes";}
    }
   }
    return "No";
}
