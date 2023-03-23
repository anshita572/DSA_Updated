//https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
class Solution {
public:
    int solve(TreeNode* root)
    {
        if(root==NULL)
        {return 0;}
        int leftAns=1+solve(root->left);
        int rightAns=1+solve(root->right);
        return max(leftAns,rightAns);
    }
    int maxDepth(TreeNode* root) {
        return solve(root);
        
    }
};