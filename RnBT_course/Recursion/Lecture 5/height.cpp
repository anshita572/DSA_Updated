//https://leetcode.com/problems/maximum-depth-of-binary-tree/

//M1 : count while returning
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
//M2 : count while traversing
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
        {return 0;}
        int leftAns=1+maxDepth(root->left);
        int rightAns=1+maxDepth(root->right);
        int ans=max(leftAns,rightAns);
        return ans;
        
    }
};