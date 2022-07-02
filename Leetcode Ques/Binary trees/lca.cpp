//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

//TC :O(n)
//SC :O(h)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2) {
        
       if(root == NULL)
       {
           return NULL;  
       }
       if(root== n1 || root== n2)
       {return root;}
       TreeNode *leftAns=lowestCommonAncestor(root->left,n1,n2);
       TreeNode *rightAns=lowestCommonAncestor(root->right,n1,n2);
       if(leftAns != NULL && rightAns !=NULL)
       {return root;}
       else if(leftAns != NULL && rightAns ==NULL)
       {return leftAns;}
      else if(leftAns == NULL && rightAns !=NULL)
       {return rightAns;}
       else //if(leftAns == NULL && rightAns ==NULL)
       {return NULL;}
       
    }
};