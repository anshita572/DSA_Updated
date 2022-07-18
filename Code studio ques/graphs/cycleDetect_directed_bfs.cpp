//https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void adjList(unordered_map<int,list<int>>&adj,vector < pair < int, int >> & edges)
{
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first-1;
        int v=edges[i].second-1;
         adj[u].push_back(v);
         //directed so no v.push_back(u)
    }
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
   unordered_map<int,list<int>>adj;
  adjList(adj,edges);
     //find indegree of all nodes
    vector<int>indegree(n);
    for(auto i :adj)
    {
        for(auto j:i.second)
        {indegree[j]++;}
    }
    //push nodes with 0 indegree in queue
   queue<int>q;
    for(int i=0;i<n;i++)
    {
    if(indegree[i]==0)
    q.push(i);
    }
    //do bfs and update indegrees
   int count=0;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        count++;
 
        for(auto i:adj[front])
        {
            indegree[i]--;
            if(indegree[i]==0)
            {q.push(i);}
        }
    }
    if(count==n)
    {return false;}
    else
    {return true;}

  
}