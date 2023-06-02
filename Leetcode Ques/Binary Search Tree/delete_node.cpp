//https://leetcode.com/problems/delete-node-in-a-bst/description/
//TC : O(h) (O(n) in worst case)
class Solution {
public:
int minVal(TreeNode *root)
{
    TreeNode*temp=root;
    if(root==NULL)
    {return -1;}
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    int val=temp->val;
    return val;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
       if(root==NULL)
    {return NULL;}
    if(root->val == key)
    {
        //0 child
        if(root->left==NULL && root->right==NULL)
        {delete root;
         return NULL;
        }
        // 1 child
        //left child
        if(root->left != NULL && root->right==NULL)
        {TreeNode*temp=root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->left == NULL && root->right!=NULL)
        {TreeNode*temp=root->right;
            delete root;
            return temp;
        }
        // 2 children
        if(root->left!=NULL && root->right !=NULL)
        {
            int mini=minVal(root->right);
            root->val=mini;
            root->right=deleteNode(root->right,mini);
            return root;
        }
    }
    else if(key > root->val) //right
    {
        root->right= deleteNode(root->right,key);
        return root;
    }
    else //left
    {root->left= deleteNode(root->left,key);
        return root;
    }
    return root; 
    }
};