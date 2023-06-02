// https://leetcode.com/problems/search-in-a-binary-search-tree/description/
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int X) {
        if(root == NULL)
        {return NULL;}
        if(root->val==X)
        {return root;}
        else if(X > root->val)
        {root->right=searchBST(root->right,X);
        return root->right;
        }
        else
        {root->left=searchBST(root->left,X);
        return root->left;
        }
    }
};