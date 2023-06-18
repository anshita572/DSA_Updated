// https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/
// TC : O(N) , SC : O(N)
class Solution {
public:
    int countNodes(TreeNode* root)
    {if(root==NULL)
    {return 0;}
    int ans=1+countNodes(root->left)+countNodes(root->right);
    return ans;
    }
    bool solve(TreeNode* root,int i,int count)
    {if(root==NULL)
     {return true;}
     if(i>=count)
     {return false;}
     else{
         bool left=solve(root->left,2*i+1,count);
         bool right=solve(root->right,2*i+2,count);
         return (left && right);
     }
}
    bool isCompleteTree(TreeNode* root) {
        int count=countNodes(root);
        return solve(root,0,count);
    }
};