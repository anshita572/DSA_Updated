//https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1#

//TC :O(n^2)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//TC : O(n^2) because due to height call TC :O(n) and due to diameter O(n)
class Solution {
  public:
  int height(struct Node* node){
        if(node==NULL)
        {
            return 0;
        }
        int left=height(node->left);
        int right=height(node->right);
        int ans=max(left,right)+1;
        return ans;
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
       //base case
       if(root==NULL)
       {
           return 0;
       }
       int option1=diameter(root->left);
       int option2=diameter(root->right);
       int option3=height(root->left)+height(root->right)+1;
       int ans=max(option1,max(option2,option3));
       return ans;
    }
};



