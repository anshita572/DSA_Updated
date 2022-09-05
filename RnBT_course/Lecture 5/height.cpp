//https://leetcode.com/problems/maximum-depth-of-binary-tree/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
        {return 0;}
        int leftAns=maxDepth(root->left);
        int rightAns=maxDepth(root->right);
        int ans=1+max(leftAns,rightAns);
        return ans;
    }
};