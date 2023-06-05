//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
// M1 : recursive
// Time: O(n) Space: O(n)
class Solution {
public:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{ if(root == NULL)
{return NULL;}
if(p->val < root->val && q->val < root->val)
{cout<<"left"<<endl;
    return lowestCommonAncestor(root->left,p,q);}
if(p->val > root->val && q->val > root->val)
{cout<<"right"<<endl;
    return lowestCommonAncestor(root->right,p,q);}
cout<<"hello"<<endl;
return root;
}
};
// M2 : iterative
// Time: O(n) Space: O(1)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    { while(root != NULL)
    {
        if(p->val < root->val && q->val < root->val)
        {root=root->left;}
        else if(p->val > root->val && q->val > root->val)
        {root=root->right;}
        else
        {return root;}
    }
        return root;
    }
};