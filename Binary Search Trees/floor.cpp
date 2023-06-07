// https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=0
// M1 : using inorder and sorting it in decreasing order and then finding the floor
// TC : O(nlogn) SC : O(n)
void inorder(TreeNode<int> * root,vector<int>&ans)
{
    if(root == NULL)
    {return;}
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}
int floorInBST(TreeNode<int> * root, int X)
{vector<int>ans;
inorder(root,ans);
sort(ans.begin(),ans.end(),greater<int>());
for(int i=0;i<ans.size();i++)
{if(ans[i]<=X)
{return ans[i];}
}
}
// M2 : optimised
// TC : O(h) SC : O(1)
int floorInBST(TreeNode<int> * root, int X)
{
    int floor=-1;
    while(root !=NULL)
    {
        if(root->val == X)
        {floor=root->val;
        return floor;}
        else if (root->val > X)
        {root=root->left;}
        else //if(root->val < X)
        {
            floor=root->val;
            root=root->right;
        }
    }
    return floor;
}