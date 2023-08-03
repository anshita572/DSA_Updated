// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// TC : O(V+E) , SC : O(V)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
      vector<int>ans;
      unordered_map<int,bool>mp;
      queue<int>q;
      mp[0]=true;
      q.push(0);
      while(!q.empty()){
          int node = q.front();
          q.pop();
          ans.push_back(node);
    
          for(auto i : adj[node]) {
              if(mp[i] == false){
                  q.push(i);
                  mp[i] = true;
              }
          }
      }
      return ans;
    }
};