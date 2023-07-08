// https://practice.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
         vector<int>ans;
         int size = q.size();
        int mid = size / 2;
        queue<int>q2;
        
        for (int i = 0; i < mid; i++) {
           q2.push(q.front());
            q.pop();
        }
        
        while (!q.empty()) {
            ans.push_back(q2.front());
            ans.push_back(q.front());
            q.pop();
            q2.pop();
        }
        
        return ans;
    }
};