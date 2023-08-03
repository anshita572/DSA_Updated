// https://practice.geeksforgeeks.org/problems/topological-sort/1
// TC : O(V+E) , SC : O(V)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{   
	    vector<int>indegree(V,0);
	   //int indegree[V]={0};
	    vector<int>ans;
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
	        q.pop();
	        for(auto i : adj[node])
	        {indegree[i]--;
	        if(indegree[i] == 0)
	        {q.push(i);}
	        }
	    }
	    return ans;
	}
};