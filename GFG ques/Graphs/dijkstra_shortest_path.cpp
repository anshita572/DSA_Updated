// https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph
// TC : O(E log V), SC : O(V+E)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>>adj[n+1];
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        vector<int>distance(n+1,1e9);
        vector<int>parent(n+1);
        for(int i = 1; i <= n; i++){
            parent[i] = -1;
        }
        distance[1] = 0;
        pq.push({0,1});
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int edgeWeight = it.second;
                int adjNode = it.first;
                if(dist + edgeWeight < distance[adjNode]){
                    distance[adjNode] = dist + edgeWeight;
                    pq.push({distance[adjNode],adjNode});
                    parent[adjNode] = node;
                }
                
            }
        }
        if(distance[n] == 1e9){
            return {-1};
        }
        vector<int>ans;
        int node = n;
        while(parent[node] != -1){
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};