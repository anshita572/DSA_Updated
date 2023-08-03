// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// TC : O(V+E) , SC : O(V)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detect(int node, int vis[],vector<int> adj[]){
        vis[node] = 1;
        queue<pair<int,int>>q;
        q.push({node,-1});
        while(!q.empty()){
            int front = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto i : adj[front]){
                if(!vis[i]){
                    vis[i] = 1;
                    q.push({i,front});
                }
                else if (parent != i)  // else if it is visited but 
                //it is not a parent
                {return true;} //cycle found
                //else if it is a parent and it is visted that's totally fine
               //it does not mean that it has a cycle.Only parent is allowed
              // to be visited, any other node that is not a parent but is
              // already visited => there is a cycle
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]={0};
        
        // if there are multiple components
        for (int i=0;i<V;i++){
            if(!vis[i])
            {if(detect(i,vis,adj))
                {return true;}
            }
        }
       return false;
    }
};
