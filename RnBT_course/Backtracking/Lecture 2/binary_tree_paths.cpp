//https://leetcode.com/problems/binary-tree-paths/
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