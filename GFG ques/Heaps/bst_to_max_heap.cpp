// https://practice.geeksforgeeks.org/problems/bst-to-max-heap/1
// TC : O(N) , SC : O(N)
class Solution{
  public:
    void solve1(Node* root,vector<int>&inorder) //inorder
    {if(root == NULL)
     {return;}
     solve1(root->left,inorder);
     inorder.push_back(root->data);
     solve1(root->right,inorder);
        
    }
    void solve2(Node* root,vector<int>&inorder,int &index) //postorder
    {if(root == NULL)
      {return;}
      solve2(root->left,inorder,index);
      solve2(root->right,inorder,index);
      root->data=inorder[index++];
      
        
    }
    void convertToMaxHeapUtil(Node* root)
    {
       vector<int>inorder;
       int index=0;
       solve1(root,inorder);
       solve2(root,inorder,index);
    }    
};