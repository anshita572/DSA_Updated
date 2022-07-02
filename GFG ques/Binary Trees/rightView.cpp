//https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1#
class Solution
{
    public:
    void solve(Node* root,int level,vector<int>&ans)
    {
        if(root==NULL)
        {return;}
        if(level==ans.size())
        {
            ans.push_back(root->data);
        }
        if(root->right)
        {
            solve(root->right,level+1,ans);
        }
         if(root->left)
        {
            solve(root->left,level+1,ans);
        }
    }
    vector<int> rightView(Node *root)
    {
       vector<int>ans;
        int level;
        solve(root,0,ans);
        return ans;
    }
};
