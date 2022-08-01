//https://www.codingninjas.com/codestudio/problems/bridges-in-graph_893026?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#include <unordered_map>
#include <list>
void dfs(int node,int parent,int& timer,vector<int>&discovery,vector<int>&low, unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited,
 vector<vector<int>>&ans)
{
    visited[node]=true;
    discovery[node]=low[node]=timer;
    timer++;
    for(auto i:adj[node])
    {
        if(i==parent)
        {continue;}//don't go to parent,ignore it
         if(!visited[i])
        {dfs(i,node,timer,discovery,low,adj,visited,ans);
        low[node]=min(low[node],low[i]);
         //check if edge is bridge
        if(low[i]>discovery[node])
        {
            vector<int>result;
            result.push_back(node);
            result.push_back(i);
            ans.push_back(result);
        }}
        else //visited h but current node ka parent bhi nhi h => back edge (when the neighbour is visited and also not a parent then update low with minimum possible time to reach the node)
        {
            low[node]=min(low[node],discovery[i]);
        }
            
    }
    
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v,  int e) {
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++)//adjaceny list
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>>ans;
    int timer=0;
    vector<int>discovery(v);
    vector<int>low(v);
    int parent=-1;
    unordered_map<int,bool>visited;
    for(int i=0;i<v;i++)
    {  discovery[i]=-1;
        low[i]=-1;
    }
    //dfs
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            dfs(i,parent,timer,discovery,low,adj,visited,ans);
        }
    }
    return ans;

}