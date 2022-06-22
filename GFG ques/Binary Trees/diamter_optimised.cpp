//https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1#
//TC :O(n)
//SC:O(height) ,max height can be n

class Solution {
  public:
  
  pair<int,int>findDiameter(Node* root)
  {
      //base case
      if(root==NULL)
      {
          pair<int,int>p=make_pair(0,0);
          return p;
      }
      pair<int,int>left=findDiameter(root->left);
      pair<int,int>right=findDiameter(root->right);
      int op1=left.first; //first represents diameter
      int op2=right.first;//first represents diameter
      int op3=left.second+right.second+1;//second represents height
      pair<int,int>ans;
      ans.first=max(op1,max(op2,op3));
      ans.second=max(left.second,right.second)+1;
      return ans;
       
  }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
       return findDiameter(root).first;//as we need to find only diameter so first
    }
};