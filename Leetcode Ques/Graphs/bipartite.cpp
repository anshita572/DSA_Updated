// https://leetcode.com/problems/is-graph-bipartite/description/
// TC : O(V+E) , SC : O(V)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool bfs(int V,vector<vector<int>>& graph,int color[]){
        queue<int>q;
        q.push(V);
        color[V] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i : graph[node]){
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
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];
	    for(int i=0;i<n;i++)
	     {color[i] = -1;}
	     for(int i=0;i<n;i++){
	         if(color[i] == -1){
	             if(bfs(i,graph,color) == false)
	               {return false;}
	         }
	     }
	     return true;
    }
};