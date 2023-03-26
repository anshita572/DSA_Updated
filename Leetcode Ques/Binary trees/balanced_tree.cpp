//https://leetcode.com/problems/balanced-binary-tree/description/
//Brute Force : TC:O(n2)
class Solution {
public:
int findHeight(TreeNode* root)
{
    if(root==NULL)
    {return 0;}
    int lh=1+findHeight(root->left);
    int rh=1+findHeight(root->right);
    return max(lh,rh);
}
bool solve(TreeNode* root)
{
    if(root == NULL)
    {return true;}
    int lh=findHeight(root->left);
    int rh=findHeight(root->right);
    bool op1=abs(lh-rh)<=1;
    // if(abs(lh-rh)<=1)
    // {op1=true;}
    bool op2=solve(root->left);
    bool op3=solve(root->right);
    if(op1 && op2 && op3)
    {return true;}
    return false;
}
    bool isBalanced(TreeNode* root) {
        return solve(root);
    }
};
//Optimised : TC : O(n)
class Solution {
public:
int solve(TreeNode* root)
{
    if(root==NULL)
    {return 0;}
    int lh=solve(root->left);
    if(lh==-1)
    {return -1;}
    int rh=solve(root->right);
    if(rh==-1)
    {return -1;}
    if(abs(lh-rh)>1)
    {return -1;}
    int height=1+max(lh,rh);
    return height;
}
    bool isBalanced(TreeNode* root) {
        if(solve(root)!=-1)
        {return true;}
        return false;
    }
};