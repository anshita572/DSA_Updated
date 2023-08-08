// https://leetcode.com/problems/course-schedule-ii/
// TC - O(V+E) SC - O(V+E)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
       vector<vector<int>>adj(n);
       for(auto it : prerequisites){
           adj[it[1]].push_back(it[0]);
       }

        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it :adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                 q.push(i);
            }
        }
       
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto it :adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(ans.size() == n){
            return ans;
        }
        return vector<int>();
    }
};