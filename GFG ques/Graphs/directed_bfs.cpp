// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// TC : O(V+E) , SC : O(V)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>indegree(V,0);
	   //int indegree[V]={0};
	    vector<int>ans;
	    int count = 0;
	    for(int i=0;i<V;i++){
	        for(auto it : adj[i])
	        {indegree[it]++;}
	    }
	    queue<int>q;
	    for(int i=0;i<V;i++)
	    {if(indegree[i] == 0)
	        {q.push(i);}
	    }
	    while(!q.empty()){
	        int node = q.front();
	        ans.push_back(node);
	        count++;
	        q.pop();
	        for(auto i : adj[node])
	        {indegree[i]--;
	        if(indegree[i] == 0)
	        {q.push(i);}
	        }
	    }
	    if(count != V)
	       {return true;}
	  return false;
    }
};