//https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1/#
//TC :O(n)
//TC :O(height)
class Solution {
public:
void traverseLeft(Node *root,vector<int>&ans)
{
    if(root == NULL)
    {return;}
    if(root->left == NULL && root->right == NULL) //excluding leaf nodes
    {return;}
    ans.push_back(root->data);
    if(root->left)
    {traverseLeft(root->left,ans);}
    else                             //agar left h hi nhi then go right
    {traverseLeft(root->right,ans);} 
}
void traverseLeaf(Node *root,vector<int>&ans)
{    if(root == NULL)
      {return;}
      if(root->left == NULL && root->right == NULL) //if leaf node then push its data
        {ans.push_back(root->data);
            return;
        }
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
    
}
void traverseRight(Node *root,vector<int>&ans)
{
    if(root == NULL)
    {return;}
    if(root->left == NULL && root->right == NULL) //excluding leaf nodes
    {return;}
    if(root->right)
    {traverseRight(root->right,ans);}
    else
    {traverseRight(root->left,ans);}
    ans.push_back(root->data);
}
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(root==NULL)
        {
         return ans;   
        }
        ans.push_back(root->data);  // first of all,push root and then traverse left,leaf,right
        traverseLeft(root->left,ans); //left part traverse and store ans
        traverseLeaf(root->left,ans); //leaf nodes of left subtree
        traverseLeaf(root->right,ans);//leaf nodes of right subtree
        traverseRight(root->right,ans);//right part traverse and store ans
        return ans;
    }
};