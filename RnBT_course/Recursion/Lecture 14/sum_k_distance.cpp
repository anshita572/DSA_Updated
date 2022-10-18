//https://practice.geeksforgeeks.org/problems/ebb840c27b36a8c8ad121fd576a2fa6f2bc1e6f2/1

//Doubt : Code giving wrong ans and dry run not clear
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
struct Node
{
    int data;
    Node* left;
    Node* right;
};
 void traverse(Node* root,unordered_map<Node*,Node*>parent)
 {
     if(root==NULL)
     {return;}
     if(root->left!=NULL)
    { parent[root->left]=root;
     traverse(root->left,parent);}
     if(root->right!=NULL)
    { parent[root->right]=root;
     traverse(root->right,parent);}
 }
Node* findTarget(Node* root,int target)
{
    if(root==NULL)
    {return NULL;}
    if(root->data==target)
    {return root;}
    Node*leftAns=findTarget(root->left,target);
    if(leftAns!=NULL)
    {return leftAns;}
     Node*rightAns=findTarget(root->right,target);
    if(rightAns!=NULL)
    {return rightAns;}
}
void solve(Node* root, int target, int k,unordered_map<Node*,Node*>parent,
unordered_map<Node*,bool>visited,int &ans)
{
    if(k<0)
    {return;}
    if(root==NULL)
     {return;}
    if(visited.find(root) != visited.end()) return;
    // if(visited[root]==true)
    // {return;}
    // if(target==NULL)
    // {return;}
    visited[root]=true;
    ans=ans+root->data;
    solve(root->left,target,k-1,parent,visited,ans);
    solve(root->right,target,k-1,parent,visited,ans);
    solve(parent[root],target,k-1,parent,visited,ans);
}

    int sum_at_distK(Node* root, int target, int k)
    {unordered_map<Node*,Node*>parent;
    parent[root]=NULL;
     traverse(root,parent);
     Node* targetNode=findTarget(root,target);
     unordered_map<Node*,bool>visited;
     int ans=0;
     solve(targetNode,target,k,parent,visited,ans);
     return ans;
    }
};
