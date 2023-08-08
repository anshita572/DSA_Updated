// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance
// TC - O(N+M) SC - O(N)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int>adj[N];
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>distance(N,INT_MAX);
        distance[src] = 0;
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(distance[node] + 1 < distance[it]){
                    distance[it] = distance[node] + 1;
                    q.push(it);
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
