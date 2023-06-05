// https://www.codingninjas.com/codestudio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0
//TC : O(n) SC : O(n)
void inorder(TreeNode<int>* root,vector<int>&ans)
    {
        if(root == NULL)
        {return;}
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
TreeNode<int>* flatten(TreeNode<int>* root)
{vector<int>ans;
inorder(root,ans);
TreeNode<int>*newRoot=new TreeNode<int>(ans[0]);
TreeNode<int>*curr=newRoot;
for(int i=1;i<ans.size();i++)
{
    TreeNode<int>*temp=new TreeNode<int>(ans[i]);
    curr->left=NULL;
    curr->right=temp;
    curr=temp;
}
curr->right=NULL; //last node's right should also point to null
return newRoot;
    
}
