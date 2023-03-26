//https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
class Solution {
public:
int solve(TreeNode* root)
{
    if(root==NULL)
    {return 0;}
    int lh=solve(root->left);
    int rh=solve(root->right);
     if(root->left!=NULL && root->right!=NULL)
     {return 1+min(lh,rh);}
    return 1+max(lh,rh);
}
    int minDepth(TreeNode* root) {
        return solve(root);
    }
};