//https://practice.geeksforgeeks.org/problems/sum-tree/1#
//TC : O(n)
//SC :O(height) ,max height can be n
class Solution
{
    public:
    pair<bool,int> findSumTree(Node* root)
    {
        //base case
        if(root==NULL)
        {
            pair<bool,int>p=make_pair(true,0);
            return p;
        }
        //if leaf node then just pass its value
        if(root->left == NULL && root->right== NULL)
        {
            pair<bool,int>p=make_pair(true,root->data);
            return p;
        }
        pair<bool,int>left=findSumTree(root->left);//leftSum tree h ya nhi h
        pair<bool,int>right=findSumTree(root->right);//rightSum tree h ya nhi h
        
        bool leftAns=left.first;
        bool rightAns=right.first;
        int leftSum=left.second;
        int rightSum=right.second;
        bool condn=root->data==leftSum + rightSum;
        pair<bool,int>ans;
        if(leftAns && rightAns && condn)
        {
            ans.first=true;
            ans.second=root->data + leftSum + rightSum; // OR ans.second=2*root->data 
            
        }
        else
        {
            ans.first=false;
        }
       return ans;
        
    }
    bool isSumTree(Node* root)
    {
         return findSumTree(root).first;
    }
};
