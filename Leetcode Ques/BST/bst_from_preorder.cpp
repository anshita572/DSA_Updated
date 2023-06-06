// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
// TC : O(n) SC : O(n)
class Solution {
public:
    TreeNode*solve(vector<int>& preorder,int &i,int mini,int maxi)
    {
        if(i>=preorder.size())
        {return NULL;}
        if(preorder[i]<mini || preorder[i]>maxi)
        {return NULL;}
        TreeNode* root=new TreeNode (preorder[i]);
        i++;
        root->left = solve(preorder,i,mini,root->val);
        root->right= solve(preorder,i,root->val,maxi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        int mini=INT_MIN;
        int maxi=INT_MAX;
        return solve(preorder,i,mini,maxi);
    }
};