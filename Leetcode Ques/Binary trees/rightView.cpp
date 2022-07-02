//https://leetcode.com/problems/binary-tree-right-side-view/
class Solution {
public:
    void solve(TreeNode* root,int level,vector<int>&ans)
    {
        if(root==NULL)
        {return;}
        if(level==ans.size())
        {
            ans.push_back(root->val);
        }
        if(root->right)
        {
            solve(root->right,level+1,ans);
        }
         if(root->left)
        {
            solve(root->left,level+1,ans);
        }
    }
    vector<int>rightSideView(TreeNode* root) {
        vector<int>ans;
        int level;
        solve(root,0,ans);
        return ans;
    }
};