// https://practice.geeksforgeeks.org/problems/largest-bst/1
// TC : O(n) SC : O(n)
class info{
public:
int maxi;
int mini;
bool isBST;
int size;
};
info solve(Node* root,int &ans)
{
    if(root == NULL)
    {
        return {INT_MIN,INT_MAX,true,0};
    }
    info left=solve(root->left,ans);
    info right=solve(root->right,ans);
    info currNode;
    currNode.size=left.size+right.size+1;
    currNode.maxi=max(root->data,right.maxi);
    currNode.mini=min(root->data,left.mini);
    if(left.isBST && right.isBST && root->data>left.maxi && root->data<right.mini)
    {currNode.isBST=true;
     ans=max(ans,currNode.size);}
    else
    {currNode.isBST=false;}
    // if(currNode.isBST==true)
    // {ans=max(ans,currNode.size);}
    return currNode;
}
class Solution{
    public:
    int largestBst(Node *root)
    {
    int maxSize=0;
   info temp=solve(root,maxSize);
   return maxSize;
    }
};