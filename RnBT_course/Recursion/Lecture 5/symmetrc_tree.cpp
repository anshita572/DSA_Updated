//https://leetcode.com/problems/symmetric-tree/
class Solution {
public:
    bool checkMirror(TreeNode* root1 ,TreeNode* root2)
       //root1 is root->left and root2 is root->right
    {if(root1==NULL && root2==NULL)
    {return true;}
     if(root1==NULL && root2!=NULL )
    {return false;}
      if(root1!=NULL && root2==NULL )
    {return false;}
       if(root1->val!=root2->val)
    {return false;}
    bool op1=checkMirror(root1->left,root2->right);
    bool op2=checkMirror(root1->right,root2->left);
    bool ans=op1 && op2;
    return ans;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
        {return true;}
        return checkMirror(root->left,root->right);
    }
};