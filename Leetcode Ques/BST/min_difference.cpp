// https://leetcode.com/problems/minimum-absolute-difference-in-bst/editorial/
// TC : O(n) SC : O(h)
class Solution {
public:
void inorder(TreeNode* root,vector<int>&ans)
{
    if(root==NULL)
    {return;}
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
    
}
    int getMinimumDifference(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        int mini=INT_MAX;
        for(int i=0;i<ans.size()-1;i++)
        {
            mini=min(mini,(ans[i+1]-ans[i]));
        }
        return mini;
    }
};