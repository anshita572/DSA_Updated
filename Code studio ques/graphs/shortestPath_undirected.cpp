//https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

//TC :O(N+E) , SC :O(N+E)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	unordered_map<int,list<int>>adj;
    //creating adjacency list
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //do bfs and store parent of each node;
    queue<int>q;
    unordered_map<int,int>parent;
    unordered_map<int,bool>visited;
   
        visited[s]=true;
        parent[s]=-1;
        q.push(s);
       while(!q.empty())
       {
           int front=q.front();
           q.pop();
           for(auto i:adj[front])
           {
               if(visited[i]==false)
               {
                   visited[i]=true;
                   parent[i]=front;
                   q.push(i);
               }
               
           }
       }
    //preparing shortest path
        int currentNode=t;
        vector<int>ans;
        ans.push_back(t);
        while(currentNode!=s)
        {
            currentNode=parent[currentNode];
            ans.push_back(currentNode);
        }
       reverse(ans.begin(),ans.end());
	   return ans;
	
}
