//https://leetcode.com/problems/binary-tree-inorder-traversal/description/

// https://takeuforward.org/data-structure/morris-inorder-traversal-of-a-binary-tree/

//TC : O(N)  SC : O(1)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode*curr=root;
        while(curr!=NULL)
        {
         if(curr->left == NULL)
        {ans.push_back(curr->val);
        curr=curr->right;}
        else //if(curr->left !=NULL)
        {
            TreeNode*prev=curr->left;
            while(prev->right!= NULL && prev->right !=curr)
            {
                prev=prev->right;
            }
            if(prev->right == NULL) //create thread
            {
                prev->right = curr;
                curr=curr->left;
            }
            else //if(prev->right!=NULL) i.e prev is already pointing to curr,then break the thread
            {prev->right=NULL;
            ans.push_back(curr->val);
            curr=curr->right;
            }
        }
        }
        return ans;
    }
};