//https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#
void solve(Node* root,int level,vector<int>&ans)
    {
        if(root==NULL)
        {return;}
        if(level==ans.size())
        {
            ans.push_back(root->data);
        }
         if(root->left)
        {
            solve(root->left,level+1,ans);
        }
          if(root->right)
        {
            solve(root->right,level+1,ans);
        }
    }
    vector<int> leftView(Node *root)
    {
       vector<int>ans;
        int level;
        solve(root,0,ans);
        return ans;
    }
