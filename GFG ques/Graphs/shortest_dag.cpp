// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
// TC - O(N+M) SC - O(N)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
       vector<vector<int>>adj[N];
        for(auto i : edges){
            adj[i[0]].push_back({i[1],i[2]});
            // adj[i[1]].push_back(i[0]);
        }
        vector<int>distance(N,INT_MAX);
        distance[0] = 0;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                int nbr = it[0];
                int dist = it[1];
                if(distance[node] + dist < distance[nbr]){
                    distance[nbr] = distance[node] + dist;
                    q.push(nbr);
                }
            }
        }
         for(int i=0;i<N;i++){
                if(distance[i] == INT_MAX)
                {distance[i] = -1;}
         }
         return distance;
    }
};