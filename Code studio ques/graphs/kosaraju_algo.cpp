//https://www.codingninjas.com/codestudio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void dfs(int node, stack<int>&s,
    unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj)
{
    visited[node]=true;
    for(auto i:adj[node])
    {if(!visited[i])
    {dfs(i,s,visited,adj);}
    }
    //topo sort logic
    s.push(node);
}
void reverseDFS(int node,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj)
{visited[node]=true;
    for(auto i:adj[node])
    {if(!visited[i])
    {reverseDFS(i,visited,adj);}
    }}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	//adj list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++)
    {int u=edges[i][0];
    int v=edges[i][1];
    adj[u].push_back(v);}
    stack<int>s;
    unordered_map<int,bool>visited;
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {dfs(i,s,visited,adj);}
    }
    //do transpose of graph
    unordered_map<int,list<int>>transpose;
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
        for(auto j:adj[i])
        {transpose[j].push_back(i);}
    }
    //dfs calling using above ordering
    int count=0;
    while(!s.empty())
    {
        int top=s.top();
        s.pop();
        if(!visited[top])
        {count++;
        reverseDFS(top,visited,transpose);}
    }
    return count;
}