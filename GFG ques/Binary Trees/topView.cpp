#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
       vector<int>ans;
       if(root==NULL)
       {
           return ans;
       }
       map<int,int>topNode; //int : for node->data,int for hd
       queue<pair<Node*,int> > q;
       q.push(make_pair(root,0));
       while(!q.empty())
       {pair<Node*,int>temp=q.front();
       q.pop();
       Node*curr=temp.first;
       int hd=temp.second;
       if(topNode.find(hd)==topNode.end())
       {
           topNode[hd]=curr->data;
       }
       if(curr->left)
       {
           q.push(make_pair(curr->left,hd-1));
       }
         if(curr->right)
       {
           q.push(make_pair(curr->right,hd+1));
       }
           
       }
       for(auto i:topNode)
       {
           ans.push_back(i.second);
       }
       return ans;
    }

};