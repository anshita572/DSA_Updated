//https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1#
//TC :O(n)
class Solution{
    public:
    pair<bool,int>findBalanced(Node*root)
    {
        if(root==NULL)
        {
            pair<bool,int>p=make_pair(true,0); //balanced:true,height:0
            return p;
        }
        pair<bool,int>left=findBalanced(root->left);
        pair<bool,int>right=findBalanced(root->right);
        bool leftAns=left.first;
        bool rightAns=right.first;
        bool difference=abs(left.second-right.second)<=1;
        pair<bool,int>ans;
        if(leftAns && rightAns && difference)
        {
            ans.first=1;
        }
        else
        {
            ans.first=0;
        }
        ans.second=max(left.second,right.second)+1;
        return ans;
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return findBalanced(root).first;
    }
};