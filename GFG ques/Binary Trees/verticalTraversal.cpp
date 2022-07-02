//https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1#
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int,vector<int>>m; 
        // int for horizontal distance(hd),vector<int>> for list of nodes
        queue<pair<Node*,int>>q;
        //Node* for node and int for hd
        vector<int>ans;
        if(root==NULL)
        {return ans;}
        q.push(make_pair(root,0));
        while(!q.empty())
        {
             pair<Node*,int>temp=q.front();
             //Node* for node and int for hd
             q.pop();
             Node*curr=temp.first;
             int hd=temp.second;
             m[hd].push_back(curr->data);
             if(curr->left)
             {
                 q.push(make_pair(curr->left,hd-1));
             }
             if(curr->right)
             {
                 q.push(make_pair(curr->right,hd+1));
             }
             
        }
        for(auto i : m)
             {
                 for(auto j:i.second)
                 {
                     ans.push_back(j);
                 }
             }
            
         return ans;
        
        
    }
};