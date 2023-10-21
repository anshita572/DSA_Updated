//https://leetcode.com/problems/binary-tree-paths/
// M1 : with backtracking
// TC : O(n) , SC : O(h) where h is the height of the tree 
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  void solve(TreeNode* root,string path,vector<string>&ans)
    {
        //base case
        if(root==NULL)
        {return;}
      if(root->left ==  NULL && root->right == NULL)
      {   path=path+to_string(root->val);
          ans.push_back(path);
          return;}
      string old_path=path;
       path=path+to_string(root->val); //pushing the value of current node
      path.push_back('-');
      path.push_back('>');
      solve(root->left,path,ans);
      solve(root->right,path,ans);
      path=old_path;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path="";
        vector<string>ans;
        solve(root,path,ans);
        return ans;
            
    }
};
// M2 : using recursion without backtracking
// If you write vector<int>& path in the solve function, it will modify the same path vector in both recursive calls, leading to incorrect results. Instead, use vector<int> path without the reference.
class Solution {
public:
    void solve(TreeNode* root, string path,  vector<string>&ans){
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            path += to_string(root->val);
            ans.push_back(path);
        }
        path += to_string(root->val);
        path.push_back('-');
        path.push_back('>');
        solve(root->left,path,ans);
        solve(root->right,path,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
         vector<string>ans;
         string path = "";
         solve(root,path,ans);
         return ans;
    }
};

