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

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
   unordered_map<int,list<int>>adj;
    adjList(adj,edges);
    //find indegree of all nodes
    vector<int>indegree(v);
    for(auto i :adj)
    {
        for(auto j:i.second)
        {indegree[j]++;}
    }
    //push nodes with 0 indegree in queue
   queue<int>q;
    for(int i=0;i<v;i++)
    {
    if(indegree[i]==0)
    q.push(i);
    }
    //do bfs and update indegrees
    vector<int>ans;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(auto i:adj[front])
        {
            indegree[i]--;
            if(indegree[i]==0)
            {q.push(i);}
        }
    }
    return ans;
}