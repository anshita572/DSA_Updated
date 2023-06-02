// https://leetcode.com/problems/validate-binary-search-tree/description/
//TC : O(n)  SC: O(h)
//M1 : using inorder
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
    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        for(int i=1;i<ans.size();i++)
        {if(ans[i-1]>=ans[i])
              {return false;}
        }
        return true;
    }
};
// M2 : using min and max range
class Solution {
public:
    bool solve(TreeNode* root,long long int mini, long long int maxi)
    {
        if(root == NULL)
        {return true;}
        if(root->val >mini && root->val <maxi)
        {
            bool left=solve(root->left,mini,root->val);
            bool right=solve(root->right,root->val,maxi);
            return left && right;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,LLONG_MIN, LLONG_MAX);
    }
};