// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix
// TC : O(E log V), SC : O(V+E)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>>st;
        vector<int>distance(V,1e9);
        distance[S] = 0;
        st.insert({0,S});
        while(!st.empty()){
            auto it = *(st.begin());
            int dist = it.first;
            int node = it.second;
            st.erase(it);   // just like we pop in queue
            for(auto i : adj[node]){
                int edgeWeight = i[1];
                int adjNode = i[0];
                if(dist + edgeWeight < distance[adjNode]){
                    if(distance[adjNode] != 1e9){
                        st.erase({distance[adjNode], adjNode});
                    }
                    distance[adjNode] = dist + edgeWeight;
                    st.insert({distance[adjNode], adjNode});
                    
                }
            }
            
        }
        return distance;
    }
};