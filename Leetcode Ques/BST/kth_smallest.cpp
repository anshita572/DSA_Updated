// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
//M1 
// TC : O(n)  SC: O(n)
class Solution {
public:
void inorder(TreeNode* root,vector<int>&ans)
    {if(root==NULL)
    {return;}
     inorder(root->left,ans);
     ans.push_back(root->val);
     inorder(root->right,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
       vector<int>ans;
       inorder(root,ans); 
       return ans[k-1];
    }
};
// M2

class Solution {
public:
    int solve(TreeNode* root, int k,int &i)
    {
        if(root==NULL)
        {return -1;}
        int l=solve(root->left,k,i);
        if(l!=-1)
        {
            return l;
        }
        i++;
        if(i==k)
        {return root->val;}
        return solve(root->right,k,i);
    }
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        return solve(root,k,i);
    }
};