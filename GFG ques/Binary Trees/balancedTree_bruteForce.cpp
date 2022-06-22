//https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
//TC:O(n^2)
class Solution{
    public:
    int height(struct Node* node){
        if(node==NULL)
        {
            return 0;
        }
        int left=height(node->left);
        int right=height(node->right);
        int ans=max(left,right)+1;
        return ans;
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if(root==NULL)
        {
            return 1;
        }
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        bool difference=abs(height(root->left)-height(root->right))<=1;
        if(left && right && difference)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};