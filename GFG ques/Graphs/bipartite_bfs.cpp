// https://practice.geeksforgeeks.org/problems/bipartite-graph/1
// TC : O(V+E) , SC : O(V)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool bfs(int V, vector<int>adj[],int color[]){
        queue<int>q;
        q.push(V);
        color[V] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i : adj[node]){
                if(color[i]==-1){
                    q.push(i);
                    color[i] = !color[node];
                }
                else if(color[i] == color[node])
                   {return false;}
            }
            
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    for(int i=0;i<V;i++)
	     {color[i] = -1;}
	     for(int i=0;i<V;i++){
	         if(color[i] == -1){
	             if(bfs(i,adj,color) == false)
	               {return false;}
	         }
	     }
	     return true;
	}
};
