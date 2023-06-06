// https://leetcode.com/problems/balance-a-binary-search-tree/
// TC : O(n) SC : O(n)
class Solution {
public:
    void inorder(TreeNode* root,vector<int>&ans)
    {
        if(root == NULL)
        {return;}
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    TreeNode* solve(int s,int e,vector<int>&ans)
    {if(s > e)
    {return NULL;}
    int mid=s+(e-s)/2;
    TreeNode*root=new TreeNode (ans[mid]);
    root->left=solve(s,mid-1,ans);
    root->right=solve(mid+1,e,ans);
    return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        return solve(0,ans.size()-1,ans);
        
    }
};